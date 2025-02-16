#ifndef __SYS_CONFIG_H__ 
#define __SYS_CONFIG_H__ 

#include "STC8H.h"
#include <stdint.h>
#include <math.h>      
#include <stdio.h>   
#include <stdbool.h>

#define     BIT0                        0x01
#define     BIT1                        0x02
#define     BIT2                        0x04
#define     BIT3                        0x08
#define     BIT4                        0x10
#define     BIT5                        0x20
#define     BIT6                        0x40
#define     BIT7                        0x80

//P_SW2 (0XBA) 
#define     P_SW2_EAXFR                 0X80

// default main fosc 48MHz
#define     MAIN_FOSC                   48000000L   //定义主时钟
#define     UART_BAUD(baud)             (65536 - (MAIN_Fosc / baud + 2) / 4)

void sys_init(void);

#endif // !