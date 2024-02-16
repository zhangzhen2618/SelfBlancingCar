#include "cc2530_lcd.h"
#include "buzzer.h"

int main(){
    
    sys_init();
    buzzer_init();

    P1DIR = 0xfe;

    PERCFG |= PERCFG_U1CFG;
    P1SEL |= BIT5 | BIT6;
    // SPI0 has Priority, default

    U1GCR |= U1GCR_ORDER; // MSB First
    // Configure the baudrate as 115200
    U1BAUD = 0;
    U1GCR &= ~U0GCR_BAUD_E;
    U1GCR |= 17;

	// P1INP =	BIT7 | BIT3 | BIT5 | BIT6; 
    // P1DIR |= BIT7 | BIT3 | BIT5 | BIT6;
    
	LCD_Init();

	while(1){	
        LCD_Clear(RED);delay_ms(3000);	
        LCD_Clear(GREEN);delay_ms(3000);	
        LCD_Clear(BLUE);delay_ms(3000);
        // P1_0 = !P1_0;
        // for(uint16_t i = 0; i < 1000; i++);
    }   
}