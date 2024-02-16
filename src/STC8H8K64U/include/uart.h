#ifndef __UART_H__
#define __UART_H__

#include "sys_config.h"

#define     BRT(x)      (65536 - (MAIN_FOSC / x + 2) / 4)

void uart_init(void);

#endif