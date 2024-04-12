#include "spi.h"

void spi0_init(uint16_t baud){

}

void spi0_dma_config(void){

}

// spi pending transmit woring as master mode
void spi0_transmit(uint8_t *tx_data, uint16_t len){


}
// SPI1 ALT2, PORT1 
void spi1_init(uint16_t baud){
    
    // SPI1 ALT1
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
        U1CSR &= ~U1CSR_TX_BYTE;
        U1DBUF = *(tx_data + i);
        while(!(U1CSR & U1CSR_TX_BYTE));
    }
}

// write the byte to the spi1, master  mode
void spi1_write_byte(uint8_t byte){
    U1CSR &= ~U1CSR_TX_BYTE;
    U1DBUF = byte;
    while(!(U1CSR & U1CSR_TX_BYTE));
}


void spi0_rx_isr(void) __interrupt(URX0_VECTOR) __using(URX0_VECTOR){

}

void spi0_tx_isr(void) __interrupt(UTX0_VECTOR) __using(UTX0_VECTOR){

}

void spi1_rx_isr(void) __interrupt(URX1_VECTOR) __using(URX1_VECTOR){

}

void spi1_tx_isr(void) __interrupt(UTX1_VECTOR) __using(UTX1_VECTOR){
    
}