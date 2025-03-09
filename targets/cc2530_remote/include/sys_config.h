#ifndef __SYS_CENFIG_H__
#define __SYS_CENFIG_H__

#include "hal_dma.h"
#include "hal_uart.h"
#include "hal_mcu.h"
#include "crc.h"
#include "protocol.h"

// DMA channel config
#define UART1_TX_DMA_CH                             DMA_CHANNEL_1
#define UART1_RX_DMA_CH                             DMA_CHANNEL_2
#define RF_DMA_CH                                   DMA_CHANNEL_3

#define UART1_TX_DMA_CH_MASK                        (1 << (UART1_TX_DMA_CH + 1))
#define UART1_RX_DMA_CH_MASK                        (1 << (UART1_RX_DMA_CH + 1))
#define RF_DMA_CH_MASK                              (1 << (RF_DMA_CH + 1))

/**
 * @brief system config, about the dma, uart config
 */
void sys_config(void);

// enable the system interrupt
void sys_int_config(void);

// about the uart1 config, include the dma config
void uart1_config(void);

// uart1_dma transmit
void uart1_dma_transmit(uint8_t *txdata, uint16_t len);

// using the last config, rearm the dma transmit
void uart1_dma_trig(void);

// uart1 rx isr funcation
void uart1_rx_isr(void) __interrupt(URX1_VECTOR) __using(URX1_VECTOR);

// dma isr funcation
void dma_isr(void) __interrupt(DMA_VECTOR) __using(DMA_VECTOR);
#endif