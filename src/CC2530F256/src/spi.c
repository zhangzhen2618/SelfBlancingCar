#include "spi.h"
#include "CC2530_LCD.h"

static uint8_t spi0_rx_buf[SPI0_BUF_SIZE];
static volatile bool spi0_rx_ptr = 0;
static volatile bool spi0_pkg_flag = 0;

static DMA_DESC *spi0_rx_dma_desc;
static uint8_t spi0_rx_dma_ch_num;

// default as slave mode
void spi0_init(uint16_t baud){

    // config the P0_0 the rasing edge interrupt
    P0DIR &= ~BIT0; // P0_0 input
    P0INP &= ~BIT0; // P0_0 pull_up
    // let the cs pin as 0
    
    P2INP |= P2INP_PDUP0;
    
    // USART0 SPI ALT1, 
    PERCFG &= ~PERCFG_U0CFG;

    // MISO->P0_2, MOSI->P0_3, CS->P0_4, SCLK->P0_5
    P0SEL |= BIT2 | BIT3 | BIT5;

    // SPI0 has Priority, default
    USART0_AS_SPI();

    // as slave
    USART0_SPI_AS_SLAVE();

    // rx enable
    USART0_RX_ON();

    U0GCR |= U0GCR_ORDER | U0GCR_CPHA; // MSB First

    // Configure the baudrate as baud
    U0BAUD = baud >> 8;
    U0GCR &= ~U1GCR_BAUD_E;
    U0GCR |= baud;


    // P0_0_INT_EN();
}

void spi0_dma_config(void){
    // spi0 rx dma config
    spi0_rx_dma_desc = dma_get_free_channel(&spi0_rx_dma_ch_num);

    // redefine the parameter
    spi0_rx_dma_desc->SRCADDRH = (uint16_t)(&X_U0DBUF) >> 8;
    spi0_rx_dma_desc->SRCADDRL = (uint16_t)(&X_U0DBUF);

    // spi0_rx dma dest address config
    spi0_rx_dma_desc->DESTADDRH = (uint16_t)(spi0_rx_buf) >> 8;
    spi0_rx_dma_desc->DESTADDRH = (uint16_t)(spi0_rx_buf);
    
    // Use first byte + 1  DMA transfer count;
    spi0_rx_dma_desc->VLEN = DMA_VLEN_1_P_VALOFFIRST;

    // the max bytes, 0xff, 255 
    spi0_rx_dma_desc->LENL = 0xff;

    // Transfer a single word after each DMA trigger;
    spi0_rx_dma_desc->WORDSIZE = DMA_WORDSIZE_BYTE;
    spi0_rx_dma_desc->TMODE = DMA_TMODE_SINGLE;

    spi0_rx_dma_desc->TRIG = DMA_TRIG_URX0;

    spi0_rx_dma_desc->SRCINC = DMA_SRCINC_0;
    // dest address inc 1
    spi0_rx_dma_desc->DESTINC = DMA_DESTINC_1;

    spi0_rx_dma_desc->IRQMASK = DMA_IRQMASK_DISABLE;
    spi0_rx_dma_desc->M8 = DMA_M8_USE_8_BITS;
    spi0_rx_dma_desc->PRIORITY = DMA_PRI_LOW;
}


// spi pending transmit woring as master mode
void spi0_transmit(uint8_t *tx_data, uint16_t len){
    for(uint16_t i = 0; i < len; i++){
        USART0_TX_CLEAR();
        U0DBUF = *(tx_data + i);
        while(!USART0_TX_FINSHED());
    }
}

// spi0 dma transmit pkg is finshed or not
bool spi0_rx_dma_pkg_is_finished(void){
    if (DMAIRQ & spi0_rx_dma_ch_num){
        DMAIRQ &= ~spi0_rx_dma_ch_num;
        return true;
    }else{
        return false;
    }
    
}

// spi0 rx buff return
uint8_t* spi0_get_rx_buf(void){
    return spi0_rx_buf;
}

// SPI1 ALT2, PORT1 
void spi1_init(uint16_t baud){
    
    // SPI1 ALT2
    PERCFG |= PERCFG_U1CFG;

    // P1_5, P1_6 as alt funcation
    P1SEL |= BIT5 | BIT6;
    // SPI0 has Priority, default

    U1GCR |= U1GCR_ORDER; // MSB First

    // Configure the baudrate as baud
    U1BAUD = baud >> 8;
    U1GCR &= ~U0GCR_BAUD_E;
    U1GCR |= baud;
}

void spi1_dma_config(void){

}

void spi1_transmit(uint8_t *tx_data, uint16_t len){

    for(uint16_t i = 0; i < len; i++){
        USART1_TX_CLEAR();
        U1DBUF = *(tx_data + i);
        while(!USART1_TX_FINSHED());
    }
}

// write the byte to the spi1, master  mode
void spi1_write_byte(uint8_t byte){
    USART1_TX_CLEAR();
    U1DBUF = byte;
    while(!USART1_TX_FINSHED());
}


void spi0_rx_isr(void) __interrupt(URX0_VECTOR) __using(URX0_VECTOR){

}

void spi0_tx_isr(void) __interrupt(UTX0_VECTOR) __using(UTX0_VECTOR){

}

void spi1_rx_isr(void) __interrupt(URX1_VECTOR) __using(URX1_VECTOR){

}

void spi1_tx_isr(void) __interrupt(UTX1_VECTOR) __using(UTX1_VECTOR){

}

// port_0 interrupt funcation for spi communication
void port_0_isr(void) __interrupt(P0INT_VECTOR) __using(P0INT_VECTOR){

    P0_INT_DISEN();
    // receive started 
    if (P0IFG & BIT0){
        P0_0_INT_DISEN();
        // start the dam receive
        // DMAARM &= ~spi0_rx_dma_ch_num;
        // DMAARM |= spi0_rx_dma_ch_num;
        uint8_t rx_index = 0;
        U0CSR &= ~U0CSR_RX_BYTE;
        while (!(U0CSR & U0CSR_RX_BYTE));
        U0CSR &= ~U0CSR_RX_BYTE;
        spi0_rx_buf[rx_index++] = U0DBUF;

        for(uint8_t i = 0; i < spi0_rx_buf[0]; i++){
            U0CSR &= ~U0CSR_RX_BYTE;
            while (!(U0CSR & U0CSR_RX_BYTE));
            U0CSR &= ~U0CSR_RX_BYTE;
            spi0_rx_buf[rx_index++] = U0DBUF;
        }
        
        P0_0_INT_EN();
    }

    // Clear the flag of interrupt
    P0IFG = 0;
    P0_INT_EN();
}
