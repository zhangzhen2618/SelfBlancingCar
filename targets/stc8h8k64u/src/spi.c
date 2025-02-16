#include "spi.h"

void spi_send(uint8_t dat){
    // IE2 &= ~0x02;
    SPSTAT = 0xC0;
    SPDAT = dat;
    while(!(SPSTAT & 0x80));
}

void spi_init(void){
    P_SW1 = 0;
    SPCTL = 0xD6;
    SPSTAT = 0xC0;   
}
