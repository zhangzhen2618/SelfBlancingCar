#ifndef __HAL_UART_H__
#define __HAL_UART_H__

#include "hal_mcu.h"

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
#define     BAUD_SPI_MAX_4000000                (0 << 8 | 17)
#define     BAUD_SPITXONLY_MAX_16000000         (0 << 8 | 19)

// This the normal uart config, 8bit, no parity, 1 stop bit, no flow control
// the more setting read the U1UCR register, in datasheet
#define     UART1_8N1                           (U1UCR_STOP) // 8bit, no parity, 1 stop bit

#define     UART1_PIN_ALT1                      0
#define     UART1_PIN_ALT2                      1
/**
 * 
 * @brief uart1 config
 *
 * @param baudrate setting, in the hal_uart1, you can see the options
 * @param option about UXUCR Register setting, include parity, 
 *                  stop bit, data length, etc. detals : doc swru191F about U1UCR REG
 * @param pin_select pin select: rx, tx, rts and cts , 
 *                         alt0: p0.5, p0.4, p0.3, p0.2 
 *                         alt1: p1.7, p1.6, p1.5, p1.4
 */
void hal_uart1_config(uint16_t baud, uint8_t options, uint8_t pin_select);

// transmit the data use uart1
void hal_uart1_transmit(uint8_t *txdata, uint16_t len);

// receive the data from  uart1
void hal_uart1_receive(uint8_t *rxdata, uint16_t len);
#endif // !__HAL_UART_H__