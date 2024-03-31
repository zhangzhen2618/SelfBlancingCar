#include "sys_config.h"
#include "rf.h"
#include "uart.h"
#include <stdio.h>

int main(){
    
    sys_init();

    RF_init();

    dma_init();

    PANIDL = 0x22;
    PANIDH = 0x22;

    SHORTADDRL = 0x23;
    SHORTADDRH = 0x23;

    uart1_init(BAUD_MAX_2000000);
    uart1_dma_config();

    UART1_RX_INI_EN();
    INT_EN();

    static uint8_t str[64] = "hAHello world!!\n";
    static uint8_t tx_buf[MPDU_MAX_PKG_LEN];
    
    MPDU_HEADER *mpdu_header = (MPDU_HEADER *)(tx_buf);

    RXENABLE |= BIT7;

    static DMA_DESC __xdata DMA_CH_CONFIG[5];

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

        static uint8_t tx[64] = "AHello world!\n0123456789";
        tx[0] = 13;
        uart1_dma_transmit('A', tx, 64);
    }   
}

