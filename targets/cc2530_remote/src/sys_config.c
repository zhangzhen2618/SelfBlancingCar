#include "sys_config.h"
#include "hal_int.h"

static DMA_DESC *uart1_tx_dma_desc;
static DMA_DESC *uart1_rx_dma_desc;
static DMA_DESC *rf_dma_desc;

static DMA_DESC __xdata DMA_CH_CONFIG[DMA_CHANNEL_NUM]; // DAM 1-4 channel config

void sys_config(void){

    halMcuInit(); // config the system main clock source

    hal_dma_cfg_1234(DMA_CH_CONFIG); // address set

    uart1_config(); 

    sys_int_config();
}

void sys_int_config(void){

    UART1_RX_INI_EN();

    INT_EN();    
}

void uart1_config(void){

    hal_uart1_config(BAUD_MAX_2000000, UART1_8N1, UART1_PIN_ALT1);

    uart1_tx_dma_desc = DMA_CH_CONFIG + UART1_TX_DMA_CH;

    // redefine the parameter
    uart1_tx_dma_desc->DESTADDRH = (uint16_t)(&X_U1DBUF) >> 8;
    uart1_tx_dma_desc->DESTADDRL = (uint16_t)(&X_U1DBUF);
    
    // Use fixed length DMA transfer count;
    uart1_tx_dma_desc->VLEN = DMA_VLEN_FIXED;

    // Transfer a single word after each DMA trigger;
    uart1_tx_dma_desc->WORDSIZE = DMA_WORDSIZE_BYTE;
    uart1_tx_dma_desc->TMODE = DMA_TMODE_SINGLE;

    uart1_tx_dma_desc->TRIG = DMA_TRIG_UTX1;

    uart1_tx_dma_desc->SRCINC = DMA_SRCINC_1;
    uart1_tx_dma_desc->DESTINC = DMA_DESTINC_0;

    uart1_tx_dma_desc->IRQMASK = DMA_IRQMASK_ENABLE;
    uart1_tx_dma_desc->M8 = DMA_M8_USE_8_BITS;
    uart1_tx_dma_desc->PRIORITY = DMA_PRI_LOW;
}

// transmit the data based on dma use uart1
void uart1_dma_transmit(uint8_t *txdata, uint16_t len){
    
    uart1_tx_dma_desc->SRCADDRH = (uint16_t)(txdata) >> 8;
    uart1_tx_dma_desc->SRCADDRL = (uint16_t)(txdata) & 0x00ff;

    uart1_tx_dma_desc->LENH = (len >> 8) & 0xff;
    uart1_tx_dma_desc->LENL = (len) & 0xff;

    // DMAARM &= ~UART1_TX_DMA_CH_MASK; 
    DMAARM |= UART1_TX_DMA_CH_MASK;
    
    hal_dma_soft_trig(UART1_TX_DMA_CH_MASK);
}

void uart1_dma_trig(uint8_t *txdata, uint16_t len){
    // uart1_tx_dma_desc->SRCADDRH = (uint16_t)(txdata) >> 8;
    // uart1_tx_dma_desc->SRCADDRL = (uint16_t)(txdata) & 0x00ff;

    // uart1_tx_dma_desc->LENH = (len >> 8) & 0xff;
    // uart1_tx_dma_desc->LENL = (len) & 0xff;

    // DMAARM &= ~UART1_TX_DMA_CH_MASK;
    DMAARM |= UART1_TX_DMA_CH_MASK;
    
    hal_dma_soft_trig(UART1_TX_DMA_CH_MASK);
}

static uint8_t __xdata rx[] = "X_Hello world!000\n";
static uint8_t rx_len = sizeof(rx);
static uint8_t count = 0;

void uart1_rx_isr(void) __interrupt(URX1_VECTOR) __using(URX1_VECTOR){
    // rx[0] = U1DBUF;
    // rx[rx_len  - 3] = count % 10 + '0';
    // rx[rx_len  - 4] = count / 10 % 10 + '0';
    // rx[rx_len  - 5] = count / 100 + '0';
    // count++;
    // uart1_dma_transmit(rx, sizeof(rx));
    if(U1DBUF == 'A'){
        DMAARM |= UART1_TX_DMA_CH_MASK;
        
        hal_dma_soft_trig(UART1_TX_DMA_CH_MASK);
    }
}