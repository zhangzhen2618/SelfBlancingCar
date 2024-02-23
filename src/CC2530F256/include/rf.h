#ifndef __RF_H__ 
#define __RF_H__ 

#include "cc2530.h"
#include "cc2530io_bitdef.h"
#include "sys_config.h"

// IEEE 802.15.4 defined constants (2.4 GHz logical channels)
#define     MIN_CHANNEL 				        11    // 2405 MHz
#define     MAX_CHANNEL                         26    // 2480 MHz
#define     CHANNEL_SPACING                     5     // MHz

typedef struct {
    uint16_t myAddr;
    uint16_t panId;
    uint8_t channel;
    uint8_t ackRequest;
} RF_CONFIG;

uint8_t RF_init(RF_CONFIG* pRfConfig);
void RF_set_channel(uint8_t channel);
uint8_t RF_send_packet(uint16_t destAddr, uint8_t* pPayload, uint8_t length);
uint8_t RF_packet_is_ready(void);
int8_t RF_get_rssi(void);
uint8_t RF_receive(uint8_t* pRxData, uint8_t len, int16_t* pRssi);
void RF_receive_on(void);
void RF_receive_off(void);

#endif // !