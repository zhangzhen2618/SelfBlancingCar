#ifndef __HAL_RF_H__ 
#define __HAL_RF_H__ 
/*
* IEEE 802.15.4 protocol
*/
#include "hal_defs.h"
#include "hal_int.h"
#include "hal_bitdef.h"

// RFIRQF0
#define HAL_RF_INT_FLG_SFD_CHECK()                                  (RFIRQF0 & BIT1)
#define HAL_RF_INT_FLG_SFD_CLEAR()                                  (RFIRQF0 &= ~BIT1)
#define HAL_RF_INT_FLG_FIFO_CHECK()                                 (RFIRQF0 & BIT2)
#define HAL_RF_INT_FLG_FIFO_CLEAR()                                 (RFIRQF0 &= ~BIT2)
#define HAL_RF_INT_FLG_SRC_MATCH_DONE_CHECK()                       (RFIRQF0 & BIT3)
#define HAL_RF_INT_FLG_SRC_MATCH_DONE_CLEAR()                       (RFIRQF0 &= ~BIT3)
#define HAL_RF_INT_FLG_SRC_MATCH_FOUND_CHECK()                      (RFIRQF0 & BIT4)
#define HAL_RF_INT_FLG_SRC_MATCH_FOUND_CLEAR()                      (RFIRQF0 &= ~BIT4)
#define HAL_RF_INT_FLG_FRAME_ACCEPTED_CHECK()                       (RFIRQF0 & BIT5)
#define HAL_RF_INT_FLG_FRAME_ACCEPTED_CLEAR()                       (RFIRQF0 &= ~BIT5)
#define HAL_RF_INT_FLG_RXPKTDONE_CHECK()                            (RFIRQF0 & BIT6)
#define HAL_RF_INT_FLG_RXPKTDONE_CLEAR()                            (RFIRQF0 &= ~BIT6)
#define HAL_RF_INT_FLG_RXMASKZERO_CHECK()                           (RFIRQF0 & BIT7)
#define HAL_RF_INT_FLG_RXMASKZERO_CLEAR()                           (RFIRQF0 &= ~BIT7)

// RFIRQF1
#define HAL_RF_INT_FLG_TXACKDONE_CHECK()                            (RFIRQF1 & BIT0)
#define HAL_RF_INT_FLG_TXACKDONE_CLEAR()                            (RFIRQF1 &= ~BIT0)
#define HAL_RF_INT_FLG_TXDONE_CHECK()                               (RFIRQF1 & BIT1)
#define HAL_RF_INT_FLG_TXDONE_CLEAR()                               (RFIRQF1 &= ~BIT1)
#define HAL_RF_INT_FLG_RFIDLE_CHECK()                               (RFIRQF1 & BIT2)
#define HAL_RF_INT_FLG_RFIDLE_CLEAR()                               (RFIRQF1 &= ~BIT2)
#define HAL_RF_INT_FLG_CSP_MANINT_CHECK()                           (RFIRQF1 & BIT3)
#define HAL_RF_INT_FLG_CSP_MANINT_CLEAR()                           (RFIRQF1 &= ~BIT3)
#define HAL_RF_INT_FLG_CSP_STOP_CHECK()                             (RFIRQF1 & BIT4)
#define HAL_RF_INT_FLG_CSP_STOP_CLEAR()                             (RFIRQF1 &= ~BIT4)
#define HAL_RF_INT_FLG_CSPWAIT_CHECK()                              (RFIRQF1 & BIT5)
#define HAL_RF_INT_FLG_CSPWAIT_CLEAR()                              (RFIRQF1 &= ~BIT5)

// RFERRF
#define HAL_RF_INT_FLG_NOLOCK_CHECK()                               (RFERRF & BIT0)
#define HAL_RF_INT_FLG_NOLOCK_CLEAR()                               (RFERRF &= ~BIT0)
#define HAL_RF_INT_FLG_RXABO_CHECK()                                (RFERRF & BIT1)
#define HAL_RF_INT_FLG_RXABO_CLEAR()                                (RFERRF &= ~BIT1)
#define HAL_RF_INT_FLG_RXOVERF_CHECK()                              (RFERRF & BIT2)
#define HAL_RF_INT_FLG_RXOVERF_CLEAR()                              (RFERRF &= ~BIT2)
#define HAL_RF_INT_FLG_RXUNDERF_CHECK()                             (RFERRF & BIT3)
#define HAL_RF_INT_FLG_RXUNDERF_CLEAR()                             (RFERRF &= ~BIT3)
#define HAL_RF_INT_FLG_TXOVERF_CHECK()                              (RFERRF & BIT4)
#define HAL_RF_INT_FLG_TXOVERF_CLEAR()                              (RFERRF &= ~BIT4)
#define HAL_RF_INT_FLG_TXUNDERF_CHECK()                             (RFERRF & BIT5)
#define HAL_RF_INT_FLG_TXUNDERF_CLEAR()                             (RFERRF &= ~BIT5)
#define HAL_RF_INT_FLG_STROBEERR_CHECK()                            (RFERRF & BIT6)
#define HAL_RF_INT_FLG_STROBEERR_CLEAR()                            (RFERRF &= ~BIT6)

// RF Interrupt masks
// RFIRQM0
#define HAL_RF_INT_MASK_SFD_SET()                                   (RFIRQM0 |= BIT1)
#define HAL_RF_INT_MASK_SFD_RESET()                                 (RFIRQM0 &= ~BIT1)
#define HAL_RF_INT_MASK_FIFO_SET()                                  (RFIRQM0 |= BIT2)
#define HAL_RF_INT_MASK_FIFO_RESET()                                (RFIRQM0 &= ~BIT2)
#define HAL_RF_INT_MASK_SRC_MATCH_DONE_SET()                        (RFIRQM0 |= BIT3)
#define HAL_RF_INT_MASK_SRC_MATCH_DONE_RESET()                      (RFIRQM0 &= ~BIT3)
#define HAL_RF_INT_MASK_SRC_MATCH_FOUND_SET()                       (RFIRQM0 |= BIT4)
#define HAL_RF_INT_MASK_SRC_MATCH_FOUND_RESET()                     (RFIRQM0 &= ~BIT4)
#define HAL_RF_INT_MASK_FRAME_ACCEPTED_SET()                        (RFIRQM0 |= BIT5)
#define HAL_RF_INT_MASK_FRAME_ACCEPTED_RESET()                      (RFIRQM0 &= ~BIT5)
#define HAL_RF_INT_MASK_RXPKTDONE_SET()                             (RFIRQM0 |= BIT6)
#define HAL_RF_INT_MASK_RXPKTDONE_RESET()                           (RFIRQM0 &= ~BIT6)
#define HAL_RF_INT_MASK_RXMASKZERO_SET()                            (RFIRQM0 |= BIT7)
#define HAL_RF_INT_MASK_RXMASKZERO_RESET()                          (RFIRQM0 &= ~BIT7)
// RFIRQM1
#define HAL_RF_INT_MASK_TXACKDONE_SET()                             (RFIRQM1 |= BIT0)
#define HAL_RF_INT_MASK_TXACKDONE_RESET()                           (RFIRQM1 &= ~BIT0)
#define HAL_RF_INT_MASK_TXDONE_SET()                                (RFIRQM1 |= BIT1)
#define HAL_RF_INT_MASK_TXDONE_RESET()                              (RFIRQM1 &= ~BIT1)
#define HAL_RF_INT_MASK_RFIDLE_SET()                                (RFIRQM1 |= BIT2)
#define HAL_RF_INT_MASK_RFIDLE_RESET()                              (RFIRQM1 &= ~BIT2)
#define HAL_RF_INT_MASK_CSP_MANINT_SET()                            (RFIRQM1 |= BIT3)
#define HAL_RF_INT_MASK_CSP_MANINT_RESET()                          (RFIRQM1 &= ~BIT3)
#define HAL_RF_INT_MASK_CSP_STOP_SET()                              (RFIRQM1 |= BIT4)
#define HAL_RF_INT_MASK_CSP_STOP_RESET()                            (RFIRQM1 &= ~BIT4)
#define HAL_RF_INT_MASK_CSPWAIT_SET()                               (RFIRQM1 |= BIT5)
#define HAL_RF_INT_MASK_CSPWAIT_RESET()                             (RFIRQM1 &= ~BIT5)
// RFERRM
#define HAL_RF_INT_MASK_NOLOCK_SET()                                (RFERRM |= BIT0)
#define HAL_RF_INT_MASK_NOLOCK_RESET()                              (RFERRM &= ~BIT0)
#define HAL_RF_INT_MASK_RXABO_SET()                                 (RFERRM |= BIT1)
#define HAL_RF_INT_MASK_RXABO_RESET()                               (RFERRM &= ~BIT1)
#define HAL_RF_INT_MASK_RXOVERF_SET()                               (RFERRM |= BIT2)
#define HAL_RF_INT_MASK_RXOVERF_RESET()                             (RFERRM &= ~BIT2)
#define HAL_RF_INT_MASK_RXUNDERF_SET()                              (RFERRM |= BIT3)
#define HAL_RF_INT_MASK_RXUNDERF_RESET()                            (RFERRM &= ~BIT3)
#define HAL_RF_INT_MASK_TXOVERF_SET()                               (RFERRM |= BIT4)
#define HAL_RF_INT_MASK_TXOVERF_RESET()                             (RFERRM &= ~BIT4)
#define HAL_RF_INT_MASK_TXUNDERF_SET()                              (RFERRM |= BIT5)
#define HAL_RF_INT_MASK_TXUNDERF_RESET()                            (RFERRM &= ~BIT5)
#define HAL_RF_INT_MASK_STROBEERR_SET()                             (RFERRM |= BIT6)
#define HAL_RF_INT_MASK_STROBEERR_RESET()                           (RFERRM &= ~BIT6)

// RF disable the filter
#define HAL_RF_DISABLE_FILTER()                                     (FRMFILT0 &= ~BIT0)
#define HAL_RF_ENABLE_FILTER()                                      (FRMFILT0 |= BIT0)

// RF COMMAND
#define HAL_RF_CMD_SRXON()                                          (RFST = 0XD3)
#define HAL_RF_CMD_STXON()                                          (RFST = 0XD9)
#define HAL_RF_CMD_SFLUSHRX()                                       (RFST = 0XDD)
#define HAL_RF_CMD_SFLUSHTX()                                       (RFST = 0XDE)
#define HAL_RF_CMD_ISRXON()                                         (RFST = 0XE3)
#define HAL_RF_CMD_ISTXON()                                         (RFST = 0XE9)

// RF set the pand_id
#define HAL_RF_SET_PANID(addr)                                      (PANIDH = addr, PANIDL = addr >> 8)
#define HAL_RF_SET_SHORTADDR(addr)                                  (SHORTADDRH = addr, SHORTADDRL = addr >> 8)

#define RF_BROADCAST_PANID                                          0XFFFF
#define RF_BROADCAST_SHORTADDR                                      0XFFFF

// default the pandid and short address, just for test, don't care
#define RF_TE_DEFAULT_PANDID                0X1234
#define RF_TE_DEFAULT_SHORTADDR             0X5678

#define RF_PC_DEFAULT_PANDID                0X4321
#define RF_PC_DEFAULT_SHORTADDR             0X8765

// Various radio settings
#define     AUTO_ACK                                                0x20
#define     AUTO_CRC                                                0x40

// IEEE 802.15.4 defined constants (2.4 GHz logical channels)
#define HAL_RF_MIN_CHANNEL 				                            11  // 2405 MHz
#define HAL_RF_MAX_CHANNEL                                          26  // 2480 MHz
#define HAL_RF_CHANNEL_SPACING                                      5   // MHz

// 802.15.4 FCS(Frame Control), description
#define HAL_RF_FC1_FRAME_TYPE                                       (BIT0 | BIT1 | BIT2)
#define HAL_RF_FC1_FRAME_TYPE_BEACON                                0X00
#define HAL_RF_FC1_FRAME_TYPE_DATA                                  0X01
#define HAL_RF_FC1_FRAME_TYPE_ACK                                   0X02
#define HAL_RF_FC1_FRAME_TYPE_MAC_CMD                               0X03

#define HAL_RF_FC1_SECURITY_EN                                      BIT3
#define HAL_RF_FC1_FRAME_PENDING                                    BIT4
#define HAL_RF_FC1_ACK_REQ                                          BIT5
#define HAL_RF_FC1_PAN_ID_COMPRESSION                               BIT6

#define HAL_RF_FC2_DEST_ADDR_MODE                                   (BIT2 | BIT3)
#define HAL_RF_FC2_DEST_ADDR_MODE_NONE                              (0 << 2)
#define HAL_RF_FC2_DEST_ADDR_MODE_16BIT                             (2 << 2)
#define HAL_RF_FC2_DEST_ADDR_MODE_64BIT                             (3 << 2)

#define HAL_RF_FC2_FRAME_VERSION                                    (BIT4 | BIT5)

#define HAL_RF_FC2_SRC_ADDR_MODE                                    (BIT6 | BIT7)
#define HAL_RF_FC2_SRC_ADDR_MODE_NONE                               (0 << 6)
#define HAL_RF_FC2_SRC_ADDR_MODE_16BIT                              (2 << 6)
#define HAL_RF_FC2_SRC_ADDR_MODE_64BIT                              (3 << 6)

// Data type, frame pending, short addr noack, fc
#define HAL_RF_FC_16BIT_DATA_NOACK_REQ                              ((HAL_RF_FC1_FRAME_TYPE_DATA | \
                                                                     HAL_RF_FC1_FRAME_PENDING | \
                                                                     HAL_RF_FC1_PAN_ID_COMPRESSION) | \
                                                                    (HAL_RF_FC2_DEST_ADDR_MODE_16BIT | \
                                                                     HAL_RF_FC2_SRC_ADDR_MODE_16BIT) << 8)
// Data type, frame pending, short addr ack, fc
#define HAL_RF_FC_16BIT_DATA_ACK_REQ                                (HAL_RF_FC_16BIT_DATA_NOACK_REQ | HAL_RF_FC1_ACK_REQ)

// MPDU header length mpdu_len: 1, FCF: 2, SEQ: 1, DEST_PAN: 2, DEST_ADDR: 2, SRC_PAN: 2, SRC_ADDR: 2
#define HAL_RF_MPDU_HEADER_LEN                                      (2 + 1 + 2 + 2 + 2 + 2)
// 16bits crc FCS
#define HAL_RF_MPDU_FCS_LEN                                         2

#define HAL_RF_MPDU_MAX_PKG_LEN                                     130

/* build the 802.15.4 header 
* Frame Control: 2 bytes
* Sequence Number: 1 bytes
* Adressing fields and Auxiliary Security Header: 0 ~ depened on the Frame Control
*/

typedef struct{
    uint8_t len;
    uint16_t fcf;
    uint8_t seq_num;
    uint16_t dest_pan;
    uint16_t dest_addr;
    uint16_t src_pan;
    uint16_t src_addr;
}MPDU_HEADER;

typedef void (*RF_RECEIVE_CB)(uint8_t *, uint8_t len);

// init rf parameter
void hal_RF_init(void);

// set the rf pkg done isr callback funcation
void hal_RF_set_pkg_done_isr_fun(RF_RECEIVE_CB rx_cb);

// write the data to the rf tx buff
void hal_RF_transmit(MPDU_HEADER *mpdu_header_ptr, uint8_t *tx_data, uint8_t data_len);

// RF core error interrupter funcation
void hal_RF_error_isr(void) __interrupt(RFERR_VECTOR);

// RF general interrupt funcation
void hal_RF_isr(void) __interrupt(RF_VECTOR);


/***********************************************************************************
* GLOBAL FUNCTIONS
*/

// Generic RF interface
// uint8_t hal_rf_init(void);
// uint8_t hal_rf_set_tx_power(uint8_t power);
// uint8_t hal_rf_transmit(void);
// void  hal_rf_set_gain(uint8_t gainMode);     // With CC2590/91 only

// uint8_t hal_rf_get_chip_id(void);
// uint8_t hal_rf_get_chip_ver(void);
// uint8_t hal_rf_get_random_byte(void);
// uint8_t hal_rf_get_rssi_offset(void);

// void  hal_rf_write_tx_buf(uint8_t* pData, uint8_t length);
// void  hal_rf_read_rx_buf(uint8_t* pData, uint8_t length);
// void  hal_rf_wait_transceiver_ready(void);
// uint8_t hal_rf_read_memory(uint16_t addr, uint8_t* pData, uint8_t length);
// uint8_t hal_rf_write_memory(uint16_t addr, uint8_t* pData, uint8_t length);

// void  hal_rf_receive_on(void);
// void  hal_rf_receive_off(void);
// void  hal_rf_disable_rx_interrupt(void);
// void  hal_rf_enable_rx_interrupt(void);
// void  hal_rf_rx_interrupt_config(ISR_FUNC_PTR pfISR);



// // IEEE 802.15.4 specific interface
// void  hal_rf_set_channel(uint8_t channel);
// void  hal_rf_set_short_addr(uint16_t shortAddr);
// void  hal_rf_set_pan_id(uint16_t PanId);
#endif // !