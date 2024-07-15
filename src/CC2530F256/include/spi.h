#ifndef __CC2530F256_SPI_H__ 
#define __CC2530F256_SPI_H__ 

#include "sys_config.h"
#include "dma.h"

#define     SPI0_BUF_SIZE                        64

// USART0 control and status register
#define     USART0_AS_SPI()                      (U0CSR &= ~U0CSR_MODE)
#define     USART0_AS_UART()                     (U0CSR |= U0CSR_MODE)

#define     USART0_RX_ON()                       (U0CSR |= U0CSR_RE)
#define     USART0_RX_OFF()                      (U0CSR &= ~U0CSR_RE)

#define     USART0_SPI_AS_MASTER()               (U0CSR &= ~U0CSR_SLAVE)
#define     USART0_SPI_AS_SLAVE()                (U0CSR |= U0CSR_SLAVE)
// #define     USART0_SPI_AS_SLAVE()                (U0CSR |= U0CSR_SLAVE, P2INP |= P2INP_PDUP0)

#define     USART0_TX_FINSHED()                  (U0CSR & U0CSR_TX_BYTE)
#define     USART0_TX_CLEAR()                    (U0CSR &= ~U0CSR_TX_BYTE)

#define     USART0_RX_FINSHED()                  (U0CSR & U0CSR_RX_BYTE)
#define     USART0_RX_CLEAR()                    (U0CSR &= ~U0CSR_RX_BYTE)

#define     USART0_IS_BUSY()                     (U0CSR & U0CSR_ACTIVE)

// USART1 control and status register
#define     USART1_AS_SPI()                      (U1CSR &= ~U1CSR_MODE)
#define     USART1_AS_UART()                     (U1CSR |= U1CSR_MODE)

#define     USART1_RX_ON()                       (U1CSR |= U1CSR_RE)
#define     USART1_RX_OFF()                      (U1CSR &= ~U1CSR_RE)

#define     USART1_SPI_AS_MASTER()               (U1CSR &= ~U1CSR_SLAVE)
#define     USART1_SPI_AS_SLAVE()                (U1CSR |= U1CSR_SLAVE)

#define     USART1_TX_FINSHED()                  (U1CSR & U1CSR_TX_BYTE)
#define     USART1_TX_CLEAR()                    (U1CSR &= ~U1CSR_TX_BYTE)

#define     USART1_RX_FINSHED()                  (U1CSR & U1CSR_RX_BYTE)
#define     USART1_RX_CLEAR()                    (U1CSR &= ~U1CSR_RX_BYTE)

#define     USART1_IS_BUSY()                     (U1CSR & U1CSR_ACTIVE)

// P1_0 interrupt config
#define     P0_0_INT_EN()                        (P0IEN |= BIT0)
#define     P0_0_INT_DISEN()                     (P0IEN &= ~BIT0)

// spi 0 alt1 init
void spi0_init(uint16_t baud);

// spi 0 dma init configure
void spi0_dma_config(void);

void spi0_transmit(uint8_t *tx_data, uint16_t len);

// spi0 dma transmit pkg is finshed or not
bool spi0_rx_dma_pkg_is_finished(void);

// spi0 rx buff return
uint8_t* spi0_get_rx_buf(void);

// spi 1 alt2 init
void spi1_init(uint16_t baud);

// spi 1 DMA init configure
void spi1_dma_config(void);

// spi 1 transmit
void spi1_transmit(uint8_t *tx_data, uint16_t len);

// spi1 write the byte
void spi1_write_byte(uint8_t tx_byte);

// USART0 RX INTERRUPT FUNCATION
void spi0_rx_isr(void) __interrupt(URX0_VECTOR) __using(URX0_VECTOR);

// USART0 TX INTERRUPT FUNCATION
void spi0_tx_isr(void) __interrupt(UTX0_VECTOR) __using(UTX0_VECTOR);

// USART1 RX INTERRUPT FUNCATION
void spi1_rx_isr(void) __interrupt(URX1_VECTOR) __using(URX1_VECTOR);

// USART1 TX INTERRUPT FUNCATION
void spi1_tx_isr(void) __interrupt(UTX1_VECTOR) __using(UTX1_VECTOR);

// PORT_0 INTERRUPT FUNCATION
void port_0_isr(void) __interrupt(P0INT_VECTOR) __using(P0INT_VECTOR);
#endif // if!