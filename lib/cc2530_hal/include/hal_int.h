#ifndef __HAL_INT_H__ 
#define __HAL_INT_H__ 
#include "hal_defs.h"

// all interrupts enable or disable 
#define     INT_EN()                            (EA = 1)
#define     INT_DISEN()                         (EA = 0)

// RF CORE error interrupt (INT 0)
#define     RF_ERR_INT_EN()                     (RFERRIE = 1)
#define     RF_ERR_INT_DISEN()                  (RFERRIE = 0)

// USART0_RX Interrupt (INT 2)
#define     USART0_INT_EN()                     (URX0IE = 1)
#define     USART0_INT_DISEN()                  (URX0IE = 0)

// UART1_RX Interrupt (INT 3)
#define     UART1_RX_INI_EN()                   (URX1IE = 1)
#define     UART1_RX_INT_DISEN()                (URX1IE = 0)

// USART0_TX Interrupt (INT 7)
#define     USART0_TX_INT_EN()                  (IEN2 |= IEN2_UTX0IE)
#define     USART0_TX_INT_DISEN()               (IEN2 &= ~IEN2_UTX0IE)

#define     P0_INT_EN()                         (P0IE = 1)
#define     P0_INT_DISEN()                      (P0IE = 0)

// UART1_TX Interrupt (INT 14)
#define     UART1_TX_INT_EN()                   (IEN2 |= IEN2_UTX1IE)
#define     UART1_TX_INT_DISEN()                (IEN2 &= ~IEN2_UTX1IE)

// RF Interrupt (INT 16)
#define     RF_INT_DISEN()                      (IEN2 &= ~IEN2_RFIE)
#define     RF_INT_EN()                         (IEN2 |= IEN2_RFIE)
#define     RF_INT_FLAG_CLEAR()                 (S1CON = 0X00)

#endif // !__HAL_INT_H__ 