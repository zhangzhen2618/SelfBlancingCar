#include "buzzer.h"

#define     T1_DIV          32

void buzzer_init(void){
    // timer1 alt2, chanel 2, P1.0
    PERCFG |= PERCFG_T1CFG; // TIMER1 alt2
    P1SEL |= BIT0; // P1.0  peripheral funcation

    // TIMER1 DIV BY 32 and mode modulo
    T1CTL &= ~(T1CTL_DIV | T1CTL_MODE);
    T1CTL |= T1CTL_DIV_128 | T1CTL_MODE_MODULO; 

    // chanel toggle compare model, mode : 110
    T1CCTL2 &= ~(T1CCTL2_MODE | T1CCTL2_CMP);
    T1CCTL2 |= T1CCTL2_MODE | T1CCTL2_CMP2 | T1CCTL2_CMP1;

    T1CC0L = 0X00;
    T1CC0H = 0XFF;

    T1CC2L = 0X00;
    T1CC2H = 0X80;
}