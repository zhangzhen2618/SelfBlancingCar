#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#include "stdint.h"

/**
 * protocol |HEADER|PKG_LEN|PKG_NUM|PKG_ID|***PKG*****|CRC->2BYTES|
 */
#define PROTO_SYN_HEADER                                    0X22

// PACKAGE SIZE
#define PROTO_HEADER_SIZE                                   2
#define PROTO_CRC_SIZE                                      2

#define PROTO_SYN_INDEX                                     0
#define PROTO_LEN_INDEX                                     1
#define PROTO_NUM_INDEX                                     2
#define PROTO_CMD_INDEX                                     3
#define PROTO_DATA_INDEX                                    4

#define PROTO_BEGAIN(msg_name, id)                          static const unsigned char PROTO_ ##msg_name ##_ID = id;\
                                                                typedef struct 

#define PROTO_END(msg_name)                                 PROTO_##msg_name;\
                                                            static const unsigned char PROTO_##msg_name##_LEN \
                                                                = sizeof(PROTO_##msg_name)
                                                                
// define the heart
PROTO_BEGAIN(HEART, 0x00){
    uint32_t local_chip_id;
    uint32_t remote_chip_id;
    uint32_t control_chip_id;
}PROTO_END(HEART);

#endif // !__PROTOCOL_H__