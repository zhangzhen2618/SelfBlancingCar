#include "cc2530_lcd.h"
#include "buzzer.h"
#include "rf.h"
#include <stdio.h>
#include <string.h>

int main(){
    
    sys_init();
    buzzer_init();
	LCD_Init();

    RF_init();

    static char str[] = "Hello world!!!\n";
    // Packet overhead ((frame control field, sequence number, PAN ID,
    // destination and source) + (footer))
    // Note that the length byte itself is not included included in the packet length
    
    static MPDU_HEADER mpdu_header;
    // mpdu_header.len = MPDU_HEADER_LEN + sizeof(str) + MPDU_FCS_LEN;

    RF_SET_PANID(RF_TE_DEFAULT_PANDID);
    RF_SET_SHORTADDR(RF_TE_DEFAULT_SHORTADDR);

    mpdu_header.seq_num = 0;
    mpdu_header.fcf = FC_16BIT_DATA_ACK_REQ;
    mpdu_header.dest_pan = RF_PC_DEFAULT_PANDID;
    mpdu_header.dest_addr = RF_PC_DEFAULT_SHORTADDR;
    mpdu_header.src_pan = RF_TE_DEFAULT_PANDID;
    mpdu_header.src_addr = RF_TE_DEFAULT_SHORTADDR;

	while(1){	
        
        RF_ISTXON();

        mpdu_header.seq_num++;

        RF_transmit(&mpdu_header, str, sizeof(str));
        
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