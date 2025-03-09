#ifndef __HAL_INT_H__ 
#define __HAL_INT_H__ 
#include "hal_defs.h"

// all interrupts enable or disable 
#define     hal_int_enable()                            (EA = 1)
#define     hal_int_disable()                           (EA = 0)

// RF CORE error interrupt (INT 0)
#define     hal_RF_err_int_enable()                     (RFERRIE = 1)
#define     hal_RF_err_int_disable()                    (RFERRIE = 0)
#define     hal_RF_err_int_flag_check()                 (RFERRIF)

// USART0_RX Interrupt (INT 2)
#define     hal_usart0_rx_int_enable()                  (URX0IE = 1)
#define     hal_usart0_rx_int_disable()                 (URX0IE = 0)
#define     hal_usart0_rx_int_flag_check()              (URX0IF)

// USART1_RX Interrupt (INT 3)
#define     hal_usart1_rx_int_enable()                  (URX1IE = 1)
#define     hal_usart1_rx_int_disable()                 (URX1IE = 0)
#define     hal_usart1_rx_int_flag_check()              (URX1IF)

// USART0_TX Interrupt (INT 7)
#define     hal_usart0_tx_int_enable()                  (IEN2 |= IEN2_UTX0IE)
#define     hal_usart0_tx_int_disable()                 (IEN2 &= ~IEN2_UTX0IE)
#define     hal_usart0_tx_int_flag_check()              (UTX0IF)
#define     hal_usart0_tx_int_flag_clear()              (UTX0IF = 0)

// USART0_RX Interrupt (INT 8)

// DMA transimit complete (INT 8)
#define     hal_DMA_int_enable()                        (DMAIE = 1)
#define     hal_DMA_int_disable()                       (DMAIE = 0)
#define     hal_DMA_int_flag_check()                    (DMAIF)
#define     hal_DMA_int_flag_clear()                    (DMAIF = 0)

#define     hal_P0_int_enable()                         (P0IE = 1)
#define     hal_P0_int_disable()                        (P0IE = 0)
#define     hal_P0_int_flag_check()                     (P0IF)
#define     hal_P0_int_flag_clear()                     (P0IF = 0)

// UART1_TX Interrupt (INT 14)
#define     hal_usart1_tx_int_enable()                   (IEN2 |= IEN2_UTX1IE)
#define     hal_usart1_tx_int_disable()                  (IEN2 &= ~IEN2_UTX1IE)
#define     hal_usart1_tx_int_flag_check()               (UTX1IF)
#define     hal_usart1_tx_int_flag_clear()               (UTX1IF = 0)

// RF Interrupt (INT 16)
#define     hal_RF_int_disable()                        (IEN2 &= ~IEN2_RFIE)
#define     hal_RF_int_enable()                         (IEN2 |= IEN2_RFIE)
#define     hal_RF_int_flag_check()                     (S1CON)
#define     hal_RF_int_flag_clear()                     (S1CON = 0X00)

#endif // !__HAL_INT_H__ 