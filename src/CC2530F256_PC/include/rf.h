#ifndef __RF_H__ 
#define __RF_H__ 
/*
* IEEE 802.15.4 protocol
*/
#include "cc2530.h"
#include "cc2530io_bitdef.h"
#include "sys_config.h"

// IEEE 802.15.4 defined constants (2.4 GHz logical channels)
#define     MIN_CHANNEL 				        11    // 2405 MHz
#define     MAX_CHANNEL                         26    // 2480 MHz
#define     CHANNEL_SPACING                     5     // MHz

#define     RFIRQF0_RXPKTDONE                   BIT6
#define     RFIRQF1_TXDONE                      BIT2

#define     RF_ISRXON()                         (RFST = 0XE3)
#define     RF_ISTXON()                         (RFST = 0XE9)

uint8_t RF_init(void);
// void RF_set_channel(uint8_t channel);

#endif // !