#include "sys_config.h"
#include "rf.h"
#include "uart.h"
#include <stdio.h>

#include "crc.h"

void pkg_rx_done_cb(uint8_t *rx_data, uint8_t len);

int main(){
    
    sys_init();
    
    crc16_init(DEFAULT_CRC_BITS, DEFAULT_CRC_POLY);

    RF_init();

    dma_init();

    // FRMFILT0 &= ~BIT0;

    RF_SET_PANID(RF_PC_DEFAULT_PANDID);
    RF_SET_SHORTADDR(RF_PC_DEFAULT_SHORTADDR);

    uart1_init(BAUD_MAX_2000000);
    uart1_dma_config();

    sys_set_clock_32mhz();

    UART1_RX_INI_EN();
    INT_EN();

    // RF INT SET
    RF_INT_EN();
    RF_IRQM0_RXPKTDONE_SET();

    RF_set_pkg_done_isr_fun(pkg_rx_done_cb);

    RF_ISRXON();

	while(1){	

    }   
}

void pkg_rx_done_cb(uint8_t *rx_data, uint8_t len){
    *(uint16_t*)(rx_data + rx_data[0] + 1) = 
        crc16_calc(rx_data + 1, rx_data[0], DEFAULT_CRC_START_VALUE);
    rx_data[0] += 2;
    uart1_dma_transmit(0xA7, rx_data, len);
}
