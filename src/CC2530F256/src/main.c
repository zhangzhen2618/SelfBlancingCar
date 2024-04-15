#include "CC2530_LCD.h"
#include "buzzer.h"
#include "rf.h"
#include <stdio.h>
#include <string.h>
#include "spi.h"

// These values will give a baud rate of approx. 1.002930 Mbps for 26 MHz clock
#define SPI_BAUD_M  60
#define SPI_BAUD_E  15

// Define size of buffer and number of bytes to recieve
#define BUFFER_SIZE 0x05

/***********************************************************************************
* LOCAL VARIABLES
*/

// Slave's recieve buffer
static uint8_t rxBufferSlave[BUFFER_SIZE];

int main(){
    
    sys_init();
    buzzer_init();
	
    spi0_init(BAUD_SPITXONLY_MAX_16000000);

    spi1_init(BAUD_SPITXONLY_MAX_16000000);
    
    LCD_Init(spi1_write_byte);

    RF_init();

    P2INP |= P2INP_PDUP0;

    static char str[] = "Hello world!!!\n";
    static uint8_t tx_buf[MPDU_MAX_PKG_LEN] = {0};
    static uint8_t tx_count = 0;

    // Packet overhead ((frame control field, sequence number, PAN ID,
    // destination and source) + (footer))
    // Note that the length byte itself is not included included in the packet length
    
    static MPDU_HEADER mpdu_header;
    // mpdu_header.len = MPDU_HEADER_LEN + sizeof(str) + MPDU_FCS_LEN;

    RF_SET_PANID(RF_TE_DEFAULT_PANDID);
    RF_SET_SHORTADDR(RF_TE_DEFAULT_SHORTADDR);

    mpdu_header.seq_num = 0;
    mpdu_header.fcf = FC_16BIT_DATA_ACK_REQ;
    mpdu_header.dest_pan = RF_PC_DEFAULT_PANDID;
    mpdu_header.dest_addr = RF_PC_DEFAULT_SHORTADDR;
    mpdu_header.src_pan = RF_TE_DEFAULT_PANDID;
    mpdu_header.src_addr = RF_TE_DEFAULT_SHORTADDR;

	while(1){	
        
        // RF_ISTXON();
        while (1){
            tx_count = 1;
            
            U0CSR &= ~U0CSR_RX_BYTE;
            while (!(U0CSR & U0CSR_RX_BYTE));
            U0CSR &= ~U0CSR_RX_BYTE;
            tx_buf[tx_count++] = U0DBUF;
            
            if (tx_buf[1] != 0xAA){
                tx_buf[0]++;
                continue;
            }

            
            while (!(U0CSR & U0CSR_RX_BYTE));
            U0CSR &= ~U0CSR_RX_BYTE;

            tx_buf[tx_count++] = U0DBUF;

            do{
                while (!(U0CSR & U0CSR_RX_BYTE));
                U0CSR &= ~U0CSR_RX_BYTE;
                tx_buf[tx_count] = U0DBUF;
            }while((tx_count++) != tx_buf[2] + 2 && tx_count < MPDU_MAX_PKG_LEN);

            mpdu_header.seq_num++;

            RF_transmit(&mpdu_header, tx_buf, tx_buf[2] + 3);
            
            while(!(RF_IRQF1_TXDONE_GET()));

            RF_IRQF1_TXDONE_CLEAR();
            tx_buf[0] = 0;
            // break;
        }
        
        
        // buzzer_set_hz(2000);
        // buzzer_test(delay_ms);
        // delay_ms(100);
        LCD_Clear(RED);
        // delay_ms(1000);
        LCD_Clear(GREEN);
        // delay_ms(1000);	
        LCD_Clear(BLUE);
        // delay_ms(1000);
    }   
}

