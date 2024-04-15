#ifndef __SYS_CONFIG_H__ 
#define __SYS_CONFIG_H__ 

#include "stc8h_bitdef.h"
#include "STC8H.h"

// default main fosc 48MHz
#define     MAIN_FOSC                   48000000L   //定义主时钟
#define     UART_BAUD(baud)             (65536 - (MAIN_Fosc / baud + 2) / 4)

void sys_init(void);

#endif // !