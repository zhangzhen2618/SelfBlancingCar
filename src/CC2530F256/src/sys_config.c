#include "sys_config.h"

void sys_init(void){
    
	// set the system clock as 32MHz
    CLKCONCMD &= ~CLKCON_OSC; 
	while( CLKCONSTA & CLKCON_OSC);
	CLKCONCMD &= ~CLKCONSTA_CLKSPD; 
}