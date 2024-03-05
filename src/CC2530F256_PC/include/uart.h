#ifndef __UART_H__
#define __UART_H__

#include "sys_config.h"

// init uart 1
void uart1Init(void);

void uart1Send(uint8_t *txdata, uint16_t len);

#endif // !