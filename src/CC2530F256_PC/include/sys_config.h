#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

#include "cc2530.h"
#include "cc2530io_bitdef.h"
#include <stdint.h>
#include <stdbool.h>

#define     MAIN_FSOC                   32000000U

#define     BIT0                        0x01
#define     BIT1                        0x02
#define     BIT2                        0x04
#define     BIT3                        0x08
#define     BIT4                        0x10
#define     BIT5                        0x20
#define     BIT6                        0x40
#define     BIT7                        0x80

#define     SUCCESS                     0
#define     FAILED                      1
#define     NULL                        (void *)0

#define     HI_UINT16(a)                (((uint16_t)(a) >> 8) & 0xFF)
#define     LO_UINT16(a)                ((uint16_t)(a) & 0xFF)

#define     INT_ON()                    (EA = 1)
#define     INT_OFF()                   (EA = 0)

#define     RF_RX_INT_OFF()             (RFIRQM0 &= ~BIT6, IEN2 &= ~BIT0)
#define     RF_RX_INT_ON()              (RFIRQM0 |= BIT6, IEN2 |= BIT0)

void sys_init(void);

#endif // 