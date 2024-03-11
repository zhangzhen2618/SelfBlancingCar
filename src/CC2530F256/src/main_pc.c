#include "sys_config.h"
#include "rf.h"
#include "uart.h"
#include <stdio.h>

int main(){
    
    sys_init();

    RF_init();
    
    uart1Init();

    static char str[] = "Hello world!!!\n";
    static uint8_t tx_buf[128];

    RXENABLE |= BIT7;

	while(1){	

        // RF_SRXON();

        // RF_SFLUSHRX();
        RF_ISRXON();

        while(!(RFIRQF0 & RFIRQF0_RXPKTDONE));

        RFIRQF0 &= ~(RFIRQF0_RXPKTDONE);

        // RF_ISRXON();

        // tx_buf[0] = 0xff;

        uint8_t data_len = 0;
        data_len = RXFIFOCNT;

        tx_buf[0] = RFD;

        
        for(uint8_t i = 1; i < tx_buf[0] && i < 128; i++){
            tx_buf[i] = RFD;
        }
        
        uint8_t str_len = sprintf(str, "%d:%d:%d:%X:%X\n", data_len, tx_buf[0], tx_buf[1], CHVER, CHIPID);
        // uart1Send(tx_buf + 3, tx_buf[0] -4);
        // str[2] = '0' + data_len % 10;
        // str[1] = '0' + data_len / 10 % 10;
        // str[0] = '0' + data_len / 100;
        // str[3] = ':';
        // str[6] = '0' + tx_buf[0] % 10;
        // str[5] = '0' + tx_buf[0] / 10 % 10;
        // str[4] = '0' + tx_buf[0] / 100;
        // str[7] = ':';
        // str[10] = '0' + tx_buf[1] % 10;
        // str[9] = '0' + tx_buf[1] / 10 % 10;
        // str[8] = '0' + tx_buf[1] / 100;
        // str[11] = '\n';
        
        uart1Send(str, str_len);
        uart1Send(tx_buf + 3, data_len - 5);
        // RF_ISRXON();
        // if(tx_buf[0] != 0x19)
        //     continue;

        // uart1Send(tx_buf, tx_buf[0] + 1);


        // for(uint16_t i = 0; i < 0xffff; i++);        
    }   
}