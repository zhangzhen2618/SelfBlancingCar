#ifndef __UART_H__
#define __UART_H__

#include "sys_config.h"
#include "dma.h"

#define     UART1_BUF_SIZE                      64

// init uart 1
void uart1_init(uint16_t baud);

// init uart 1 dma config
void uart1_dma_config(void);

// transmit the data using uart1
void uart1_transmit(uint8_t *txdata, uint16_t len);

// receive the data from uart1
uint8_t uart1_receive(uint8_t *rxdata, uint8_t len);

// transmit the data based on dma use uart1
void uart1_dma_transmit(uint8_t start_byte, uint8_t *txdata, uint16_t len);

// uart1 rx isr funcation
void uart1_rx_isr(void) __interrupt(URX1_VECTOR) __using(URX1_VECTOR);

#endif // !