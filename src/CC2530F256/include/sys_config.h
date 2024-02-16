#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

#include "cc2530.h"
#include "cc2530io_bitdef.h"

#define     MAIN_FSOC       32000000U

#define     BIT0            0x01
#define     BIT1            0x02
#define     BIT2            0x04
#define     BIT3            0x08
#define     BIT4            0x10
#define     BIT5            0x20
#define     BIT6            0x40
#define     BIT7            0x80

void sys_init(void);

#endif // 