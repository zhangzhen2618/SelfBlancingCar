#include "spi.h"

// default as slave mode
void spi0_init(uint16_t baud){

    // USART0 SPI ALT1, 
    PERCFG &= ~PERCFG_U0CFG;

    // MISO->P0_2, MOSI->P0_3, CS->P0_4, SCLK->P0_5
    P0SEL |= BIT2 | BIT3 | BIT5;

    // let the cs pin as 0
    P2INP |= P2INP_PDUP0;
    
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

}

void spi0_dma_config(void){

}

// spi pending transmit woring as master mode
void spi0_transmit(uint8_t *tx_data, uint16_t len){
    for(uint16_t i = 0; i < len; i++){
        USART0_TX_CLEAR();
        U0DBUF = *(tx_data + i);
        while(!USART0_TX_FINSHED());
    }
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