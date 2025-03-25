#include "sys_config.h"
#include "hal_int.h"

static HAL_DMA_DESC *uart1_tx_dma_desc;
static HAL_DMA_DESC *uart1_rx_dma_desc;
static HAL_DMA_DESC *rf_dma_desc;

static HAL_DMA_DESC __xdata DMA_CH_CONFIG[HAL_DMA_CHANNEL_NUM]; // DAM 1-4 channel config

// static uint8_t __xdata rx[] = "X_Hello world!000\n";
// static uint8_t rx_len = sizeof(rx);
static uint8_t __xdata tx[] = "Hello world!000\n";
static uint8_t __xdata rx[10];
static uint8_t __xdata tx_len = sizeof(tx);
static uint8_t count = 0;

void sys_config(void){ 
    
    halMcuInit(); // config the system main clock source
    
    hal_dma_cfg_1234(DMA_CH_CONFIG); // address set
    
    hal_uart1_config(BAUD_MAX_2000000, UART1_8N1, UART1_PIN_ALT1);
    uart1_tx_dma_config(); // config the uart tx dma
    // uart1_rx_dma_config(); // config the uart rx dma
    
    sys_int_config();
}

void sys_int_config(void){
    
    hal_usart1_rx_int_enable();
    
    // dma interrupt enabel
    hal_DMA_int_enable();
    
    // RF interrupt enable
    hal_RF_int_enable();

    hal_int_enable(); 
    
}

void uart1_tx_dma_config(void){
    
    uart1_tx_dma_desc = DMA_CH_CONFIG + UART1_TX_DMA_CH;
    
    // redefine the parameter
    uart1_tx_dma_desc->DESTADDRH = (uint16_t)(&X_U1DBUF) >> 8;
    uart1_tx_dma_desc->DESTADDRL = (uint16_t)(&X_U1DBUF);
    
    // uart1_tx_dma_desc->SRCADDRH = (uint16_t)(tx) >> 8;
    // uart1_tx_dma_desc->SRCADDRL = (uint16_t)(tx) & 0x00ff;
    
    uart1_tx_dma_desc->LENH = 0xff;
    uart1_tx_dma_desc->LENL = 0xff;

    // Use fixed length DMA transfer count;
    uart1_tx_dma_desc->VLEN = HAL_DMA_VLEN_1_P_VALOFFIRST_P_2;
    
    // Transfer a single word after each DMA trigger;
    uart1_tx_dma_desc->WORDSIZE = HAL_DMA_WORDSIZE_BYTE;
    uart1_tx_dma_desc->TMODE = HAL_DMA_TMODE_SINGLE;
    
    uart1_tx_dma_desc->TRIG = HAL_DMA_TRIG_UTX1;
    
    uart1_tx_dma_desc->SRCINC = HAL_DMA_SRCINC_1;
    uart1_tx_dma_desc->DESTINC = HAL_DMA_DESTINC_0;
    
    uart1_tx_dma_desc->IRQMASK = HAL_DMA_IRQMASK_ENABLE;
    uart1_tx_dma_desc->M8 = HAL_DMA_M8_USE_8_BITS;
    uart1_tx_dma_desc->PRIORITY = HAL_DMA_PRI_LOW;
}

void uart1_rx_dma_config(void){
    uart1_rx_dma_desc = DMA_CH_CONFIG + UART1_TX_DMA_CH;
    
    // redefine the parameter
    uart1_rx_dma_desc->DESTADDRH = (uint16_t)(&X_U1DBUF) >> 8;
    uart1_rx_dma_desc->DESTADDRL = (uint16_t)(&X_U1DBUF);

    // Use fixed length DMA transfer count;
    uart1_rx_dma_desc->VLEN = HAL_DMA_VLEN_1_P_VALOFFIRST;
    
    // Transfer a single word after each DMA trigger;
    uart1_rx_dma_desc->WORDSIZE = HAL_DMA_WORDSIZE_BYTE;
    uart1_rx_dma_desc->TMODE = HAL_DMA_TMODE_SINGLE;
    
    uart1_rx_dma_desc->TRIG = HAL_DMA_TRIG_UTX1;

    uart1_rx_dma_desc->SRCINC = HAL_DMA_SRCINC_1;
    uart1_rx_dma_desc->DESTINC = HAL_DMA_DESTINC_0;

    uart1_rx_dma_desc->IRQMASK = HAL_DMA_IRQMASK_ENABLE;
    uart1_rx_dma_desc->M8 = HAL_DMA_M8_USE_8_BITS;
    uart1_rx_dma_desc->PRIORITY = HAL_DMA_PRI_LOW;
}

// transmit the data based on dma use uart1
void uart1_dma_transmit(uint8_t *txdata){
    
    uart1_tx_dma_desc->SRCADDRH = (uint16_t)(txdata) >> 8;
    uart1_tx_dma_desc->SRCADDRL = (uint16_t)(txdata) & 0x00ff;

    // DMAARM &= ~UART1_TX_DMA_CH_MASK; 
    DMAARM |= UART1_TX_DMA_CH_MASK;
    
    U1DBUF = PROTO_SYN_HEADER;
    // hal_dma_soft_trig(UART1_TX_DMA_CH_MASK);
}

void uart1_dma_trig(){
    
    DMAARM |= UART1_TX_DMA_CH_MASK;
    
    hal_dma_soft_trig(UART1_TX_DMA_CH_MASK);
}



void uart1_rx_isr(void) __interrupt(URX1_VECTOR) __using(URX1_VECTOR){
    // rx[0] = U1DBUF;
    // rx[rx_len  - 3] = count % 10 + '0';
    // rx[rx_len  - 4] = count / 10 % 10 + '0';
    // rx[rx_len  - 5] = count / 100 + '0';
    // count++;
    // count++;
    tx[tx_len - 3] = count % 10 + '0';
    tx[tx_len - 4] = (count / 10) % 10 + '0';
    tx[tx_len - 5] = count / 100 + '0';
    // uart1_dma_trig(); 
    // uart1_dma_transmit(tx, tx_len);
    if(U1DBUF == 'A'){
        DMAARM |= UART1_TX_DMA_CH_MASK;
        
        hal_dma_soft_trig(UART1_TX_DMA_CH_MASK);
    }
}

void dma_isr(void) __interrupt(DMA_VECTOR) __using(DMA_VECTOR){
    
    hal_DMA_int_flag_clear(); // Clear the int flag
    if (hal_dma_check_ch_int_flag(UART1_TX_DMA_CH_MASK)){
        while(hal_dma_ready(UART1_TX_DMA_CH_MASK));
        count++;
        // tx[tx_len - 3] = count % 10 + '0';
        // tx[tx_len - 4] = (count / 10) % 10 + '0';
        // tx[tx_len - 5] = count / 100 + '0';
        // tx[tx_len - 6]++;
        // tx[tx_len - 3]++;
        // uart1_dma_trig();      
        // uart1_dma_transmit(tx, tx_len);
    } 

    DMAIRQ = 0;

}
