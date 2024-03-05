#include "sys_config.h"
#include "rf.h"
#include "uart.h"

int main(){
    
    sys_init();

    RF_init();
    
    uart1Init();

    char str[] = "Hello world!!!\n";
    uint8_t tx_buf[128];

	while(1){	
        

        RF_ISRXON();

        while(!(RFIRQF0 & RFIRQF0_RXPKTDONE));

        RFIRQF0 &= ~(RFIRQF0_RXPKTDONE);

        tx_buf[0] = RFD;

        for(uint8_t i = 1; i < tx_buf[0]; i++){
            tx_buf[i] = RFD;
        }

        uart1Send(tx_buf, tx_buf[0] + 1);


        for(uint16_t i = 0; i < 0xffff; i++);        
    }   
}