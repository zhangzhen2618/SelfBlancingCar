#include "sys_config.h"
#include "rf.h"
#include "uart.h"
#include <stdio.h>

void pkg_rx_done_cb(uint8_t *rx_data, uint8_t len);

int main(){
    
    sys_init();

    RF_init();

    dma_init();

    // FRMFILT0 &= ~BIT0;

    RF_SET_PANID(RF_PC_DEFAULT_PANDID);
    RF_SET_SHORTADDR(RF_PC_DEFAULT_SHORTADDR);

    uart1_init(BAUD_MAX_2000000);
    uart1_dma_config();

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
    uart1_dma_transmit(0xA7, rx_data, len);
}
