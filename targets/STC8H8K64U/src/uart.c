#include "uart.h"

volatile bool busy;

void uart_init(void){
    SCON = 0x50; // 模式1，接收使能
    T2L = BRT(115200);
    T2H = BRT(115200) >> 8;
    
    AUXR = 0X15;
    busy = 0;
}

void Uartlsr() __interrupt(UART1_VECTOR) __using(UART1_VECTOR){
    if (TI){
        TI = 0;
        busy = 0;
    }

    if (RI){
        RI = 0;
    }
}

void uart_send(char dat){
    while (busy);
    busy = 1;
    SBUF = dat; 
}

void uart_send_str(char *str){
    while(*str){
        uart_send(*str++);
    }
}
