#include "cc2530_lcd.h"
#include "buzzer.h"

#define IRQ_TXDONE                 0x02

int main(){
    
    sys_init();
    buzzer_init();

	LCD_Init();

    /* RF settings SoC: CC2530 */
    // P1        = 0xEC; // port 1 
    // P0DIR     = 0x80; // port 0 direction 
    // P1DIR     = 0x13; // port 1 direction 
    FRMCTRL1  = 0x00; // frame handling 
    CCACTRL0  = 0xF8; // cca threshold 
    FSCAL1    = 0x00; // tune frequency calibration 
    AGCCTRL1  = 0x15; // agc reference level 
    AGCCTRL2  = 0xFE; // agc gain override 
    TXFILTCFG = 0x09; // tx filter configuration 
    CHVER     = 0x00; // chip version 
    CHIPID    = 0x00; // chip id 

    FRMCTRL0 |= BIT6 | BIT5; // auto crc and ack

    char str[] = "Hello world!!!";
    uint8_t data_size = sizeof(str) + 2 + 2;

    RFD = data_size;
    RFD = 0x41;
    RFD = 0x88;
    // RFD = 0x00;
    // RFD = 0X00;

    for(uint8_t i = 0; i < sizeof(str); i++){
        RFD = str[i];
    }
    

	while(1){	
        
        RFST = 0XE9;
        while(!(RFIRQF1 & IRQ_TXDONE) );

        RFIRQF1 = ~IRQ_TXDONE;
        // delay_ms(100);
        LCD_Clear(RED);
        // delay_ms(1000);
        LCD_Clear(GREEN);
        // delay_ms(1000);	
        LCD_Clear(BLUE);
        // delay_ms(1000);
    }   
}