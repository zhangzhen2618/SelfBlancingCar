#include "hal_rf.h"

// rf tx buffer
static RF_RECEIVE_CB rf_pkg_done_cb = NULL;

void hal_RF_init(void){

    // now using the default the frame fliter

    FRMCTRL0 = AUTO_CRC | AUTO_ACK;
    FRMCTRL1 = 0x00; // frame handling 

    /* RF settings SoC: CC2530 */
    // setting from the TI smartRF studio 7
    CCACTRL0  = 0xF8; // cca threshold 
    FSCAL1    = 0x00; // tune frequency calibration 
    AGCCTRL1  = 0x15; // agc reference level 
    AGCCTRL2  = 0xFE; // agc gain override 
    TXFILTCFG = 0x09; // tx filter configuration

    FREQCTRL = 0x10; //chanel 2

    
} 

// rx pkt done callback funcation
void hal_RF_set_pkg_done_isr_fun(RF_RECEIVE_CB rx_cb){

    if (rx_cb != NULL){
        rf_pkg_done_cb = rx_cb;
    }
}

// write the data to the rf tx buff
void hal_RF_transmit(MPDU_HEADER *mpdu_header_ptr, uint8_t *tx_data, uint8_t data_len){

    HAL_RF_CMD_ISTXON();
    
    mpdu_header_ptr->len = HAL_RF_MPDU_HEADER_LEN + HAL_RF_MPDU_FCS_LEN + data_len;
    uint8_t *mpdu_h_ptr = (uint8_t *)mpdu_header_ptr;

    // clear rf tx data buffer
    HAL_RF_CMD_SFLUSHTX();
    
    for(uint8_t i = 0; i < sizeof(MPDU_HEADER); i++){
        RFD = *(mpdu_h_ptr + i);
    }

    for(uint8_t i = 0; i < data_len; i++){
        RFD = *(tx_data + i);
    }
}

// RF core error interrupter funcation
void hal_RF_error_isr(void) __interrupt(RFERR_VECTOR){
    RFERRF = 0;
    HAL_RF_CMD_ISRXON();
}


// RF general interrupt funcation
void hal_RF_isr(void) __interrupt(RF_VECTOR){
    
    hal_RF_int_flag_clear();

    if (HAL_RF_INT_FLG_RXPKTDONE_CHECK()){
        static uint8_t rx_buffer[HAL_RF_MPDU_MAX_PKG_LEN];
        static uint8_t data_len;

        data_len = RXFIFOCNT;

        for(uint8_t i = 0; i < data_len; i++){
            rx_buffer[i] = RFD;
        }

        HAL_RF_CMD_SFLUSHRX();
        
        rf_pkg_done_cb(rx_buffer, HAL_RF_MPDU_MAX_PKG_LEN);
    }

    if (HAL_RF_INT_FLG_TXDONE_CHECK()){
        HAL_RF_CMD_ISRXON();
    }

    // clear the RFIRQF
    RFIRQF0 = 0;
    RFIRQF1 = 0;
}