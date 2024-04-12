#ifndef __SYS_CENFIG_H__
#define __SYS_CENFIG_H__

#include "cc2530.h"
#include "cc2530io_bitdef.h"
#include <stdint.h>
#include <stdbool.h>

// define the some x_reg
SFRX(X_U1DBUF, 0X70F9);

// bit set
#define     BIT0                                0x01
#define     BIT1                                0x02
#define     BIT2                                0x04
#define     BIT3                                0x08
#define     BIT4                                0x10
#define     BIT5                                0x20
#define     BIT6                                0x40
#define     BIT7                                0x80

// 32MHz system clock baud rate configure
#define     BAUD_2400                           (59 << 8 | 6)
#define     BAUD_4800                           (59 << 8 | 7)
#define     BAUD_9600                           (59 << 8 | 8)
#define     BAUD_14400                          (216 << 8 | 8)
#define     BAUD_19200                          (59 << 8 | 9)
#define     BAUD_28800                          (216 << 8 | 9)
#define     BAUD_38400                          (59 << 8 | 10)
#define     BAUD_57600                          (216 << 8 | 10)
#define     BAUD_76800                          (59 << 8 | 11)
#define     BAUD_115200                         (216 << 8 | 11)
#define     BAUD_230400                         (216 << 8 | 12)
#define     BAUD_921600                         (216 << 8 | 14)
#define     BAUD_MAX_2000000                    (0 << 8 | 16)
#define     BAUD_SPI_MAX_4000000                (0 << 8 | 17)
#define     BAUD_SPITXONLY_MAX_16000000         (0 << 8 | 19)

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
#define     RF_INT_FLAG_CLEAR()                 (S1CON = 0X00)

// init the system clock and other peripherals
void sys_init(void);

#endif // 