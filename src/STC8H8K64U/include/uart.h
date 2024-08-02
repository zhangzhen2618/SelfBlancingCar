#ifndef __UART_H__
#define __UART_H__

#include "sys_config.h"

#define     BRT(x)      (65536 - (MAIN_FOSC / x + 2) / 4)

void uart_init(void);

void uart_send(char dat);

void Uartlsr() __interrupt(UART1_VECTOR) __using(UART1_VECTOR);

#endif