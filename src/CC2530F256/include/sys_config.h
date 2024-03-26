#ifndef __SYS_CENFIG_H__
#define __SYS_CENFIG_H__

#include "cc2530.h"
#include "cc2530io_bitdef.h"
#include <stdint.h>
#include <stdbool.h>

#define     BIT0                                0x01
#define     BIT1                                0x02
#define     BIT2                                0x04
#define     BIT3                                0x08
#define     BIT4                                0x10
#define     BIT5                                0x20
#define     BIT6                                0x40
#define     BIT7                                0x80

#define     NULL_PTR                            0

#define     MAIN_FSOC                           32000000U

// all interrupts enable or disable 
#define     INT_EN()                            (EA = 1)
#define     INT_DISEN()                         (EA = 0)

// RF CORE error interrupt (INT 0)
#define     RF_ERR_INT_EN()                     (RFERRIE = 1)
#define     RF_ERR_INT_DISEN()                  (RFERRIE = 0)

// UART1_RX Interrupt (INT 3)
#define     UART1_RX_INI_EN()                   (URX1IE = 1)
#define     UART1_RX_INT_DISEN()                (URX1IE = 0)

// UART1_TX Interrupt (INT 14)
#define     UART1_TX_INT_EN()                   (IEN2 |= IEN2_UTX1IE)
#define     UART1_TX_INT_DISEN()                (IEN2 &= ~IEN2_UTX1IE)

// RF Interrupt (INT 16)
#define     RF_INT_DISEN()                      (IEN2 &= ~IEN2_RFIE)
#define     RF_INT_EN()                         (IEN2 |= IEN2_RFIE)

// init the system clock and other peripherals
void sys_init(void);

#endif // 