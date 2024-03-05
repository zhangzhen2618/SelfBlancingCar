#include "sys_config.h"

void sys_init(void){
    
    CLKCONCMD &= ~CLKCON_OSC; //设置系统时钟源为32MHz
	while( CLKCONSTA & CLKCON_OSC);
	CLKCONCMD &= ~CLKCONSTA_CLKSPD; //当前系统时钟频率为32MHz
}