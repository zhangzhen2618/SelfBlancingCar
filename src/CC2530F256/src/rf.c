#include "rf.h"

// rf tx buffer

void RF_init(void){

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
} 

// write the data to the rf tx buff
void RF_write_data_to_buf(MPDU_HEADER *mpdu_header_ptr, uint8_t *tx_data, uint8_t data_len){

    mpdu_header_ptr->len = MPDU_HEADER_LEN + data_len;
    uint8_t *mpdu_h_ptr = (uint8_t *)mpdu_header_ptr;

    // clear rf tx data buffer
    RF_SFLUSHTX();
    
    for(uint8_t i = 0; i < MPDU_HEADER_LEN; i++){
        RFD = *(mpdu_h_ptr + i);
    }

    for(uint8_t i = 0; i < data_len; i++){
        RFD = *(tx_data + i);
    }
}

// RF core error interrupter funcation
void rf_error_isr(void) __interrupt(RFERR_VECTOR) __using(RFERR_VECTOR){

}

// RF general interrupt funcation
void rf_isr(void) __interrupt(RF_VECTOR) __using(RF_VECTOR){

}