#ifndef __RF_H__ 
#define __RF_H__ 
/*
* IEEE 802.15.4 protocol
*/
#include "cc2530.h"
#include "cc2530io_bitdef.h"
#include "sys_config.h"
#include <stdbool.h>

// Various radio settings
#define     AUTO_ACK                            0x20
#define     AUTO_CRC                            0x40

// IEEE 802.15.4 defined constants (2.4 GHz logical channels)
#define     MIN_CHANNEL 				        11    // 2405 MHz
#define     MAX_CHANNEL                         26    // 2480 MHz
#define     CHANNEL_SPACING                     5     // MHz

#define     RFIRQF0_RXPKTDONE                   BIT6
#define     RFIRQF1_TXDONE                      BIT2

#define     RF_SRXON()                          (RFST = 0XD3)
#define     RF_SFLUSHRX()                       (RFST = 0XDD)
#define     RF_SFLUSHTX()                       (RFST = 0XDE)
#define     RF_ISRXON()                         (RFST = 0XE3)
#define     RF_ISTXON()                         (RFST = 0XE9)

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
#define     FC_16BIT_DATA_NOACK_REQ              ((FC1_FRAME_TYPE_DATA | FC1_FRAME_PENDING) | \
                                                 (FC2_DEST_ADDR_MODE_16BIT_SHORT | \
                                                 FC2_SOURCE_ADDR_MODE_16BIT_SHORT) << 8)
// Data type, frame pending, short addr ack, fc
#define     FC_16BIT_DATA_ACK_REQ                FC_16BIT_DATA_NOACK_REQ | FC1_ACK_REQ

bool RF_init(void);

bool RF_build_header();
// void RF_set_channel(uint8_t channel);

#endif // !