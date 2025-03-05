#include "hal_uart.h"

void hal_uart1_config(uint16_t baud, uint8_t option, uint8_t pin_select){
	
    if (pin_select == UART1_PIN_ALT1) {
        PERCFG &= ~(PERCFG_U1CFG); // Configure USART1 for Alternative 1 ==> Port P0
        
        P0SEL |= BIT4 | BIT5; // configure the P0.4, P0.5 as alternative, RX=P0.5, TX=P0.4

        // P0, USART1 priority is 1st on P0
        P2DIR &= ~(P2DIR_PRIP0); // clear the bit
        P2DIR |= P2DIR_PRIP0_2; // set the bit

    }else if (pin_select == UART1_PIN_ALT2) {
        PERCFG |= PERCFG_U1CFG; // Configure USART1 for Alternative 2 ==> Port P1
        P1SEL |= BIT7 | BIT6; // configure the P1.7, P1.6 as alternative, RX=P1.7, TX=P1.6

        // P1 USART1 RX, TX ON P1 priority more than timer3
        P2SEL &= ~(P2SEL_PRI2P1); // clear the bit
    }else{
        // pin_sellect not right config, return
        return;
    }
    
    // Configure the baudrate as baud
    U1BAUD = baud >> 8;
    U1GCR &= ~U1GCR_BAUD_E;
    U1GCR |= baud;

    // U1UCR CONFIG
    U1UCR = option;

    // default enable the uart1 receive
	U1CSR |= U1CSR_MODE | U1CSR_RE; // Set the mode of uart1 as uart, enable receive
}

// transmit the data use uart1
void hal_uart1_transmit(uint8_t *txdata, uint16_t len){
    
    // clear and pending TX interrupt request 
    U1CSR &= ~U1CSR_TX_BYTE;

    for(uint16_t i = 0; i < len; i++){
        U1DBUF = txdata[i];
        // X_U1DBUF = 0x80;
        while (!(U1CSR & U1CSR_TX_BYTE));
        
        U1CSR &= ~U1CSR_TX_BYTE;
    }
}

// receive the data from  uart1
void hal_uart1_receive(uint8_t *rxdata, uint16_t len){
    // Enable UART1 RX
    U1CSR |= U1CSR_RE;
    uint16_t i = 0; 
    while( !(U1CSR&U1CSR_RX_BYTE) );
    while (i < len){
        if(U1CSR & U1CSR_RX_BYTE){
            *(rxdata + i) = U1DBUF;
            i++;
        }
    }
}