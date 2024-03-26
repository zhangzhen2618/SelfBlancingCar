#include "rf.h"

// rf tx rx buffer
static uint8_t rf_tx_buf_[MPDU_MAX_PKG_LEN];
static uint8_t rf_rx_buf_[MPDU_MAX_PKG_LEN];

// rf tx mpdu_header ptr
MPDU_HEADER *tx_mpdu_header_ptr;
MPDU_HEADER *rx_mpdu_header_ptr;


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

void rf_DMA_init(void){

}

// set the tx package frame control filed
void rf_set_fcf(uint16_t fcf){
    tx_mpdu_header_ptr->fcf = fcf;
}

// rf set the tx package pan id and source address
void rf_set_src_panid_and_addr(uint16_t pandid, uint16_t src_addr){
    tx_mpdu_header_ptr->src_pan = pandid;
    tx_mpdu_header_ptr->src_addr = src_addr;

    // frame the filter set
    PANIDL = pandid;
    PANIDH = pandid >> 8;

    SHORTADDRL = src_addr;
    SHORTADDRH = src_addr >> 8;
}

// set tx package dest panid and dest adress
void rf_set_dest_panid_and_addr(uint16_t panid, uint16_t dest_addr){
    tx_mpdu_header_ptr->dest_pan = panid;
    tx_mpdu_header_ptr->dest_addr = dest_addr;
}

// set tx sequence number
void rf_set_tx_seq_num(uint16_t seq_num){
    tx_mpdu_header_ptr->seq_num = seq_num;
}


void rf_tx_seq_num_plus_1(void){
    tx_mpdu_header_ptr->seq_num++;
}

// init the setting rf DMA Setting
void rf_DMA_int(void){

}

void rf_DMA_transmit(uint8_t *data, uint16_t len){

}

bool rf_pkg_finshed(void){

}

uint8_t * rf_read_package(void){

}

// RF core error interrupter funcation
void rf_error_isr(void) __interrupt(RFERR_VECTOR) __using(RFERR_VECTOR){

}

// RF general interrupt funcation
void rf_isr(void) __interrupt(RF_VECTOR) __using(RF_VECTOR){

}