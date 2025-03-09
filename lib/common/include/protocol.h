#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#include "stdint.h"

/**
 * protocol |HEADER|PKG_LEN|PKG_NUM|PKG_ID|***PKG*****|CRC->2BYTES|
 */
#define PROTO_SYN_HEADER                                    0X22

#define PROTO_BEGAIN(msg_name, id)                          static unsigned char PROTO_ ##msg_name ##_ID = id;\
                                                                typedef struct 

#define PROTO_END(msg_name)                                 PROTO_##msg_name;\
                                                            static const unsigned char PROTO_##msg_name##_LEN \
                                                                = sizeof(PROTO_##msg_name)
                                                                
// define the heart
PROTO_BEGAIN(HEART, 0x00){
    uint8_t time;
}PROTO_END(HEART);

#endif // !__PROTOCOL_H__