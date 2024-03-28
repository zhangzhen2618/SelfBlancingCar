#include "spi.h"

void spi0_init(uint16_t baud){

}

void spi0_dma_config(void){

}

void spi1_init(uint16_t baud){
    
}

void spi1_dma_config(void){

}


void spi0_rx_isr(void) __interrupt(URX0_VECTOR) __using(URX0_VECTOR){

}

void spi0_tx_isr(void) __interrupt(UTX0_VECTOR) __using(UTX0_VECTOR){

}

void spi1_rx_isr(void) __interrupt(URX1_VECTOR) __using(URX1_VECTOR){

}

void spi1_tx_isr(void) __interrupt(UTX1_VECTOR) __using(UTX1_VECTOR){
    
}