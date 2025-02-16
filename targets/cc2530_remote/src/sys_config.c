#include "sys_config.h"

void sys_init(void){
    
	// set the system clock as 32MHz
}

void sys_set_clock_32mhz(void){

    CLKCONCMD &= ~CLKCON_OSC; 
	while( CLKCONSTA & CLKCON_OSC);
	CLKCONCMD &= ~CLKCONSTA_CLKSPD; 
}