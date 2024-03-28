#ifndef __UART_H__
#define __UART_H__

#include "sys_config.h"
#include "dma.h"

#define     UART1_BUF_SIZE                      64

// 32MHz system clock baud rate configure
#define     BAUD_2400                           (59 << 8 | 6)
#define     BAUD_4800                           (59 << 8 | 7)
#define     BAUD_9600                           (59 << 8 | 8)
#define     BAUD_14400                          (216 << 8 | 8)
#define     BAUD_19200                          (59 << 8 | 9)
#define     BAUD_28800                          (216 << 8 | 9)
#define     BAUD_38400                          (59 << 8 | 10)
#define     BAUD_57600                          (216 << 8 | 10)
#define     BAUD_76800                          (59 << 8 | 11)
#define     BAUD_115200                         (216 << 8 | 11)
#define     BAUD_230400                         (216 << 8 | 12)
#define     BAUD_921600                         (216 << 8 | 14)
#define     BAUD_MAX_2000000                    (0 << 8 | 16)

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