#include "buzzer.h"

#define     BUZZER_T1_DIV         128 

void buzzer_init(void){
    // timer1 alt2, chanel 2, P1.0
    PERCFG |= PERCFG_T1CFG; // TIMER1 alt2
    P1SEL |= BIT0; // P1.0  peripheral funcation
    // P2SEL |= P2SEL_PRI1P1; // timer4 have priority, not affect the 

    // TIMER1 DIV BY 128 and mode modulo
    T1CTL &= ~(T1CTL_DIV | T1CTL_MODE);
    T1CTL |= T1CTL_DIV_128; 

    // chanel toggle compare model, mode : 110
    T1CCTL2 &= ~(T1CCTL2_MODE | T1CCTL2_CMP);
    T1CCTL2 |= T1CCTL2_MODE | T1CCTL2_CMP2 | T1CCTL2_CMP1;
}

void buzzer_set_hz(uint16_t hz){
    // buzzer_start();
    
    static uint16_t t1cc0 = 0XFFFF;
    static uint16_t t1cc2 = 0X8000;
    t1cc0 =  MAIN_FSOC / BUZZER_T1_DIV / hz;
    t1cc2 =  MAIN_FSOC / BUZZER_T1_DIV / 2 / hz;

    T1CC0L = t1cc0 & 0xFF;
    T1CC0H = t1cc0 >> 8;

    T1CC2L = t1cc2 & 0XFF;
    T1CC2H = t1cc2 >> 8;

}

void buzzer_test(void (*delay_ms)(uint16_t hz)){

    static uint16_t hz = 0;
    static uint16_t tone[] = {247,262,294,330,349,392,440,294,523,587,659,698,784,1000};//音频数据表
    static uint8_t music[]={3,5,8,6,5,13,//音调
	                3,5,6,8,5,13,
	                8,10,9,8,9,8,6,8,5,13,
					3,5,6,5,6,8,9,5,6,13,
					3,2,1,2,13,
					2,2,3,5,5,8,2,3,5,13};
	static uint8_t time[] ={2,2,2,2,6,4,//时间  
				2,2,2,2,6,4,
                6,2,4,4,2,2,2,2,6,4,
				6,2,4,2,2,4,2,2,6,4,
				2,2,4,6,4,
				4,2,2,4,4,4,2,2,6,4};
    hz = 0;

    for (uint16_t i = 0; i < sizeof(music); i++){
        buzzer_start();
        buzzer_set_hz(tone[music[hz]] + 15);
        delay_ms(time[hz]*150);
        buzzer_stop();
        delay_ms(time[hz++]*10);
    }
}