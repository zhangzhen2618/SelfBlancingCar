#include "hal_mcu.h"
#include "crc.h"
#include "hal_int.h"
#include "hal_uart.h"
#include "sys_config.h"
#include "hal_rf.h"

void pkg_rx_done_cb(uint8_t *rx_data, uint8_t len);


int main(){
    
    sys_config(); // system config
    
    crc16_init(DEFAULT_CRC_BITS, DEFAULT_CRC_POLY);

    hal_RF_init();

    // FRMFILT0 &= ~BIT0;

    HAL_RF_SET_PANID(RF_PC_DEFAULT_PANDID);
    HAL_RF_SET_SHORTADDR(RF_PC_DEFAULT_SHORTADDR);

    // RF INT SET
    // RF_INT_EN();
    HAL_RF_INT_MASK_RXPKTDONE_SET();

    hal_RF_set_pkg_done_isr_fun(pkg_rx_done_cb);

    HAL_RF_CMD_ISRXON();

	while(1){	
        // count++;
        // if ((DMAARM & UART1_TX_DMA_CH_MASK) == 0){
        //     // hal_dma_clear_int_flag(UART1_TX_DMA_CH_MASK);
        //     tx[tx_len  - 3] = count % 10 + '0';
        //     tx[tx_len  - 4] = (count / 10) % 10 + '0';
        //     tx[tx_len  - 5] = count / 100 + '0';
        //     count++;
        //     uart1_dma_trig();
        //     // halMcuWaitUs(55);
        // }
        // hal_uart1_transmit(tx, sizeof(tx));
        // DMAARM |= UART1_TX_DMA_CH_MASK;
    

        // halMcuWaitMs(500);
        // hal_uart1_receive(rx, 1);
        // hal_uart1_transmit(rx, 1);
        // halMcuWaitMs(1000);
        // uart1_dma_transmit(0xA7, tx, sizeof(tx));
        // RF_send_pkg(tx, sizeof(tx));
    }   
}

void pkg_rx_done_cb(uint8_t *rx_data, uint8_t len){
    *(uint16_t*)(rx_data + rx_data[0] + 1) = 
        crc16_calc(rx_data + 1, rx_data[0], DEFAULT_CRC_START_VALUE);
    rx_data[0] += 2;
    uart1_dma_transmit(rx_data, len);
}
