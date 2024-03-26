#include "uart.h"

static DMA_DESC *uart1_rx_dma_desc;
static uint8_t uart1_rx_dma_ch_num;
static DMA_DESC *uart1_tx_dma_desc;
static uint8_t uart1_tx_dma_ch_num;

static uint8_t uart1_rx_buf[UART1_BUF_SIZE];
static uint8_t uart1_tx_buf[UART1_BUF_SIZE];

void uart1_init(uint16_t baud){
	
	PERCFG &= ~(PERCFG_U1CFG); // Configure USART1 for Alternative 1 ==> Port P0  
    P0SEL |= BIT4 | BIT5; // configure the P0.4, P0.5 as alternative, RX=P0.5, TX=P0.4
    P2DIR |= BIT6; // P0, USART1 privit

    // Configure the baudrate as 115200
    U1BAUD = baud >> 8;
    U1GCR &= ~U1GCR_BAUD_E;
    U1GCR |= baud;

	U1CSR |= BIT7 | BIT6; // Set the mode of uart1 as uart, enable receive
}

// uart1 dam config
void uart1_dma_config(void){
    uart1_rx_dma_desc = dma_get_free_channel(&uart1_rx_dma_ch_num);
    uart1_tx_dma_desc = dma_get_free_channel(&uart1_tx_dma_ch_num);
}

// transmit the data use uart1
void uart1_transmit(uint8_t *txdata, uint16_t len){
    
    // clear and pending TX interrupt request 
    U1CSR &= ~U1CSR_TX_BYTE;

    for(uint16_t i = 0; i < len; i++){
        U1DBUF = txdata[i];
        // X_U1DBUF = 0x80;
        while (!(U1CSR & U1CSR_TX_BYTE));
        
        U1CSR &= ~U1CSR_TX_BYTE;
    }
}

// receive the data from  uart1
uint8_t uart1_receive(uint8_t *rxdata, uint8_t len){
    // Enable UART1 RX
    U1CSR |= U1CSR_RE;
    uint8_t i = 0; 
    while( !(U1CSR&U1CSR_RX_BYTE) );
    while (i < len){
        if(U1CSR & U1CSR_RX_BYTE){
            *(rxdata + i) = U1DBUF;
            i++;
        }
    }
    return len;
}

// transmit the data based on dma use uart1
void uart1_transmit_dma(uint8_t *txdata, uint16_t len){
    // uart1_rx_dma_desc->SRCADDRH = (uint16)(tx_buf) >> 8;
    uart1_rx_dma_desc->SRCADDRH = (uint16_t)(txdata) >> 8;
    uart1_rx_dma_desc->SRCADDRL = (uint16_t)(txdata) & 0x00ff;

    uart1_rx_dma_desc->DESTADDRH = 0x70;
    uart1_rx_dma_desc->DESTADDRL = U1DBUF;
    uart1_rx_dma_desc->LENH = (len >> 8) & 0xff;
    uart1_rx_dma_desc->LENL = (len) & 0xff;

    // Use fixed length DMA transfer count;
    uart1_rx_dma_desc->VLEN = DMA_VLEN_FIXED;

    // Transfer a single word after each DMA trigger;
    uart1_rx_dma_desc->WORDSIZE = DMA_WORDSIZE_BYTE;
    uart1_rx_dma_desc->TMODE = DMA_TMODE_SINGLE;

    uart1_rx_dma_desc->TRIG = DMA_TRIG_UTX1;

    uart1_rx_dma_desc->SRCINC = DMA_SRCINC_1;
    uart1_rx_dma_desc->DESTINC = DMA_DESTINC_0;

    uart1_rx_dma_desc->IRQMASK = DMA_IRQMASK_ENABLE;
    uart1_rx_dma_desc->M8 = DMA_M8_USE_8_BITS;
    uart1_rx_dma_desc->PRIORITY = DMA_PRI_LOW;

    DMAARM &= ~uart1_tx_dma_ch_num;
    DMAARM |= uart1_tx_dma_ch_num;

    U1DBUF = txdata[0];
}

// uart1 tx isr funcation
void uart1_tx_isr(void) __interrupt(UTX1_VECTOR) __using(UTX1_VECTOR){

}

// uart1 rx isr funcation
void uart1_rx_isr(void) __interrupt(URX1_VECTOR) __using(URX1_VECTOR){

}
