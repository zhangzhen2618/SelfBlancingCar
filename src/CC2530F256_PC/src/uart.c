#include "uart.h"

void uart1Init(void){
	
	PERCFG &= ~(PERCFG_U1CFG); // Configure USART1 for Alternative 1 ==> Port P0  
    P0SEL |= BIT4 | BIT5; // configure the P0.4, P0.5 as alternative, RX=P0.5, TX=P0.4
    P2DIR |= BIT6; // P0, USART1 privit

    // Configure the baudrate as 115200
    U1BAUD = 216;
    U1GCR &= ~U1GCR_BAUD_E;
    U1GCR |= 11;

	U1CSR |= BIT7 | BIT6; // Set the mode of uart1 as uart, enable receive

    // URX1IE = 1; // uart1 RX interrupt enable

    // uart1_wptr = 0;
    // uart1_rptr = 0;
}

void uart1Send(uint8_t *txdata, uint16_t len){
    
    // clear and pending TX interrupt request 
    U1CSR &= ~U1CSR_TX_BYTE;

    for(uint16_t i = 0; i < len; i++){
        U1DBUF = txdata[i];
        // X_U1DBUF = 0x80;
        while (!(U1CSR & U1CSR_TX_BYTE));
        
        U1CSR &= ~U1CSR_TX_BYTE;
    }
}