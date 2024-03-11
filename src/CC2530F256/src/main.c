#include "cc2530_lcd.h"
#include "buzzer.h"
#include "rf.h"

int main(){
    
    sys_init();
    buzzer_init();

	LCD_Init();

    RF_init();

    char str[] = "000: Hello world!!!\n";
    uint8_t data_size = sizeof(str) + 2 + 2;

    static uint8_t count = 0;

	while(1){	
        
        RF_SFLUSHTX();

        RF_ISTXON();

        str[2] = '0' + count % 10;
        str[1] = '0' + count / 10 % 10;
        str[0] = '0' + count / 100;
        count++;
        RFD = data_size;
        RFD = 0x41;
        RFD = 0x88;
        // RFD = 0x00;
        // RFD = 0X00;

        for(uint8_t i = 0; i < sizeof(str); i++){
            RFD = str[i];
        }
        while(!(RFIRQF1 & RFIRQF1_TXDONE) );

        RFIRQF1 = ~RFIRQF1_TXDONE;
        // delay_ms(100);
        LCD_Clear(RED);
        // delay_ms(1000);
        LCD_Clear(GREEN);
        // delay_ms(1000);	
        LCD_Clear(BLUE);
        // delay_ms(1000);
    }   
}