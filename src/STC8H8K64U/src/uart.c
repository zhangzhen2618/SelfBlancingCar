#include "uart.h"
#include <stdio.h>

void uart_init(void){
    SCON = 0x50; // 模式1，接收使能
    T2L = BRT(115200);
    T2H = BRT(115200) >> 8;
    
    AUXR = 0X15;
}

void Uartlsr() __interrupt(UART1_VECTOR) __using(UART1_VECTOR){
    if (TI){
        TI = 0;
    }

    if (RI){
        RI = 0;
    }
}