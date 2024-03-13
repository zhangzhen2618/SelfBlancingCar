#include "sys_config.h"
#include "rf.h"
#include "uart.h"
#include <stdio.h>

int main(){
    
    sys_init();

    RF_init();
    
    uart1Init();

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

        uint8_t str_len = sprintf(str, "mpdu pkg len : %d\n", mpdu_header->len);
        uart1Send(str, str_len);
        str_len = sprintf(str, "fcf : %X\n", mpdu_header->fcf);
        uart1Send(str, str_len);
        str_len = sprintf(str, "mpdu pkg seq : %d\n", mpdu_header->seq_num);
        uart1Send(str, str_len);
        str_len = sprintf(str, "dest pan : %X\n", mpdu_header->dest_pan);
        uart1Send(str, str_len);
        str_len = sprintf(str, "dest addr : %X\n", mpdu_header->dest_addr);
        uart1Send(str, str_len);
        str_len = sprintf(str, "src pan : %X\n", mpdu_header->src_pan);
        uart1Send(str, str_len);
        str_len = sprintf(str, "src addr : %X\n", mpdu_header->src_addr);
        uart1Send(str, str_len);
        str_len = sprintf(str, "data : ");
        uart1Send(str, str_len);
        uart1Send((uint8_t *)(mpdu_header) + sizeof(MPDU_HEADER), mpdu_header->len - MPDU_HEADER_LEN - 1 - MPDU_FCS_LEN);
    }   
}