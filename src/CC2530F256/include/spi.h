#ifndef __CC2530F256_SPI_H__ 
#define __CC2530F256_SPI_H__ 

#include "sys_config.h"
#include "dma.h"

// spi 0 alt1 init
void spi0_init(uint16_t baud);
void spi0_dma_config(void);

// spi 1 alt2 init
void spi1_init(uint16_t baud);
void spi1_dma_config(void);

#endif // if!