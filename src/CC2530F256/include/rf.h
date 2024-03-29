#ifndef __RF_H__ 
#define __RF_H__ 
/*
* IEEE 802.15.4 protocol
*/
#include "cc2530.h"
#include "cc2530io_bitdef.h"
#include "sys_config.h"
#include <stdbool.h>

// RF COMMAND
#define     RF_SRXON()                          (RFST = 0XD3)
#define     RF_SFLUSHRX()                       (RFST = 0XDD)
#define     RF_SFLUSHTX()                       (RFST = 0XDE)
#define     RF_ISRXON()                         (RFST = 0XE3)
#define     RF_ISTXON()                         (RFST = 0XE9)

// RF set the pand_id
#define     RF_SET_PANID(addr)                  (PANIDL = addr, PANIDH = addr >> 8)
#define     RF_SET_SHORTADDR(addr)              (SHORTADDRL = addr, SHORTADDRH = addr >> 8)

#define     RF_BROADCAST_PANID                  0XFFFF
#define     RF_BROADCAST_SHORTADDR              0XFFFF

// default the pandid and short address, just for test, don't care
#define     RF_TE_DEFAULT_PANDID                0X1234
#define     RF_TE_DEFAULT_SHORTADDR             0X5678

#define     RF_PC_DEFAULT_PANDID                0X4321
#define     RF_PC_DEFAULT_SHORTADDR             0X8765

// Various radio settings
#define     AUTO_ACK                            0x20
#define     AUTO_CRC                            0x40

// IEEE 802.15.4 defined constants (2.4 GHz logical channels)
#define     MIN_CHANNEL 				        11    // 2405 MHz
#define     MAX_CHANNEL                         26    // 2480 MHz
#define     CHANNEL_SPACING                     5     // MHz

// RF Interrupt flag
#define     RFIRQF1_TXDONE                      BIT2
#define     RFIRQF0_RXPKTDONE                   BIT6


// 802.15.4 FCS(Frame Control), description
#define     FC1_FRAME_TYPE                      (BIT0 | BIT1 | BIT2)
#define     FC1_FRAME_TYPE_BEACON               0X00
#define     FC1_FRAME_TYPE_DATA                 0X01
#define     FC1_FRAME_TYPE_ACK                  0X02
#define     FC1_FRAME_TYPE_MAC_CMD              0X03

#define     FC1_SECURITY_EN                     BIT3
#define     FC1_FRAME_PENDING                   BIT4
#define     FC1_ACK_REQ                         BIT5
#define     FC1_PAN_ID_COMPRESSION              BIT6

#define     FC2_DEST_ADDR_MODE                  (BIT2 | BIT3)
#define     FC2_DEST_ADDR_MODE_NONE             (0 << 2)
#define     FC2_DEST_ADDR_MODE_16BIT            (2 << 2)
#define     FC2_DEST_ADDR_MODE_64BIT            (3 << 2)

#define     FC2_FRAME_VERSION                   (BIT4 | BIT5)

#define     FC2_SRC_ADDR_MODE                   (BIT6 | BIT7)
#define     FC2_SRC_ADDR_MODE_NONE              (0 << 6)
#define     FC2_SRC_ADDR_MODE_16BIT             (2 << 6)
#define     FC2_SRC_ADDR_MODE_64BIT             (3 << 6)

// Data type, frame pending, short addr noack, fc
#define     FC_16BIT_DATA_NOACK_REQ              ((FC1_FRAME_TYPE_DATA | FC1_FRAME_PENDING | FC1_PAN_ID_COMPRESSION) | \
                                                 (FC2_DEST_ADDR_MODE_16BIT | FC2_SRC_ADDR_MODE_16BIT) << 8)
// Data type, frame pending, short addr ack, fc
#define     FC_16BIT_DATA_ACK_REQ                FC_16BIT_DATA_NOACK_REQ | FC1_ACK_REQ

// MPDU header length mpdu_len: 1, FCF: 2, SEQ: 1, DEST_PAN: 2, DEST_ADDR: 2, SRC_PAN: 2, SRC_ADDR: 2
#define     MPDU_HEADER_LEN                      (2 + 1 + 2 + 2 + 2 + 2)
// 16bits crc FCS
#define     MPDU_FCS_LEN                         2

#define     MPDU_MAX_PKG_LEN                     128

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
    // uint8_t *data_ptr;
}MPDU_HEADER;

void RF_init(void);

// set the frame control field
void rf_set_fcf(uint16_t fcf);

// set the tx the pand id and pan address
void rf_set_src_panid_and_addr(uint16_t panid, uint16_t src_addr);

// set the tx the dest pand id and dest address
void rf_set_dest_panid_and_addr(uint16_t pandid, uint16_t dest_addr);

// set the tx sequence number
void rf_set_tx_seq_num(uint16_t seq_num);

// set the tx sequence number plus + 1
void rf_tx_seq_num_plus_1(void);

// rf DMA init
void rf_DMA_init(void);

// rf DMA transmit
void rf_DMA_transmit(uint8_t *data, uint16_t len);

// rf receive flag
bool rf_pkg_finshed(void);

// rf read package from buffer (just inclde the mpdu payload field)
// return the mpdu pkg uint8_t point
uint8_t * rf_read_package(void);
#endif // !