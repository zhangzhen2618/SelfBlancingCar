#ifndef __CC2530F256_SPI_H__ 
#define __CC2530F256_SPI_H__ 

#include "sys_config.h"
#include "dma.h"

// USART0 control and status register
#define     USART0_AS_SPI()                      (U0CSR &= ~U0CSR_MODE)
#define     USART0_AS_UART()                     (U0CSR |= U0CSR_MODE)
#define     USART0_RX_ON()                       (U0CSR |= U0CSR_RE)
#define     USART0_RX_OFF()                      (U0CSR &= ~U0CSR_RE)

// USART1 control and status register
#define     USART1_RX_ON()                       (U1CSR |= U1CSR_RE)
#define     USART1_RX_OFF()                      (U1CSR &= ~U1CSR_RE)

// spi 0 alt1 init
void spi0_init(uint16_t baud);
// spi 0 dma init configure
void spi0_dma_config(void);
void spi0_transmit(uint8_t *tx_data, uint16_t len);

// spi 1 alt2 init
void spi1_init(uint16_t baud);
// spi 1 DMA init configure
void spi1_dma_config(void);
// spi 1 transmit
void spi1_transmit(uint8_t *tx_data, uint16_t len);
// spi1 write the byte
void spi1_write_byte(uint8_t tx_byte);

#endif // if!