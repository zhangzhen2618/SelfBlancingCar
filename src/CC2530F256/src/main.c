#include "cc2530_lcd.h"
#include "buzzer.h"

int main(){
    
    sys_init();
    buzzer_init();

	LCD_Init();

	while(1){	
        
        LCD_Clear(RED);delay_ms(1000);
        LCD_Clear(GREEN);delay_ms(1000);	
        LCD_Clear(BLUE);delay_ms(1000);
    }   
}