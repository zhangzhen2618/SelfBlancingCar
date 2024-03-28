#include "sys_config.h"
#include "rf.h"
#include "uart.h"
#include <stdio.h>

int main(){
    
    sys_init();

    RF_init();

    PANIDL = 0x22;
    PANIDH = 0x22;

    SHORTADDRL = 0x23;
    SHORTADDRH = 0x23;

    uart1_init(BAUD_MAX_2000000);
    uart1_dma_config();

    UART1_RX_INI_EN();
    INT_EN();

    static char str[64] = {0};
    static uint8_t tx_buf[MPDU_MAX_PKG_LEN];
    
    MPDU_HEADER *mpdu_header = (MPDU_HEADER *)(tx_buf);

    RXENABLE |= BIT7;

	while(1){	

        RF_SFLUSHRX();
        RF_ISRXON();

        while(!(RFIRQF0 & RFIRQF0_RXPKTDONE));

        RFIRQF0 &= ~(RFIRQF0_RXPKTDONE);

        uint8_t data_len = 0;
        data_len = RXFIFOCNT;

        for(uint8_t i = 0; i < data_len && i < 128; i++){
            tx_buf[i] = RFD;
        }

        uart1_dma_transmit(0xA7, tx_buf, 0x1fff);
    }   
}


