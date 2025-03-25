#include "CC2530_LCD.h"
#include "buzzer.h"
#include "hal_rf.h"
#include <stdio.h>
#include <string.h>
#include "spi.h"

#include "crc.h"
#include "protocol.h"

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

    hal_RF_init();

    sys_set_clock_32mhz();

    // P0_INT_EN();
    // P0_0_INT_EN();
    // P0_0_INT_DISEN();
    INT_EN();

    static char str[] = "Hello world!!!\n";
    static uint8_t tx_buf[HAL_RF_MPDU_MAX_PKG_LEN] = {0};
    static uint8_t tx_count = 0;
    tx_buf[0] = 0x00; // pkg num
    tx_buf[1] = PROTO_HEART_ID;
    static PROTO_HEART *heart = (PROTO_HEART *)(tx_buf + 2);
    heart->local_chip_id = CHVER;
    heart->local_chip_id <<= 8;
    heart->local_chip_id |= CHIPID;
    heart->local_chip_id <<= 8;
    heart->local_chip_id |= CHIPINFO0;
    heart->local_chip_id <<= 8;
    heart->local_chip_id |= CHIPINFO1;

    // Packet overhead ((frame control field, sequence number, PAN ID,
    // destination and source) + (footer))
    // Note that the length byte itself is not included included in the packet length
    
    static MPDU_HEADER mpdu_header;
    
    HAL_RF_SET_PANID(RF_TE_DEFAULT_PANDID);
    HAL_RF_SET_SHORTADDR(RF_TE_DEFAULT_SHORTADDR);

    mpdu_header.seq_num = 0;
    mpdu_header.fcf = HAL_RF_FC_16BIT_DATA_ACK_REQ;
    mpdu_header.dest_pan = RF_PC_DEFAULT_PANDID;
    mpdu_header.dest_addr = RF_PC_DEFAULT_SHORTADDR;
    mpdu_header.src_pan = RF_TE_DEFAULT_PANDID;
    mpdu_header.src_addr = RF_TE_DEFAULT_SHORTADDR;

    // P0DIR = 0; // input
    // P0INP = 0; // pull up
    // P2INP &= (~BIT5);
    // P2INP |= BIT5; 
    // P2INP |= P2INP_PDUP0;
    buzzer_set_hz(1000);
    // buzzer_start();
	while(1){	

        // while (1){
        //     tx_count = 1;
            
        //     U0CSR &= ~U0CSR_RX_BYTE;
        //     while (!(U0CSR & U0CSR_RX_BYTE));
        //     // U0CSR &= ~U0CSR_RX_BYTE;
        //     tx_buf[tx_count++] = U0DBUF;
            
        //     if (tx_buf[1] != 0xAA){
        //         tx_buf[0]++;
        //         continue;
        //     }

            
        //     U0CSR &= ~U0CSR_RX_BYTE;
        //     while (!(U0CSR & U0CSR_RX_BYTE));
        //     // U0CSR &= ~U0CSR_RX_BYTE;

        //     tx_buf[tx_count++] = U0DBUF;

        //     do{
        //         U0CSR &= ~U0CSR_RX_BYTE;
        //         while (!(U0CSR & U0CSR_RX_BYTE));
        //         // U0CSR &= ~U0CSR_RX_BYTE;
        //         tx_buf[tx_count] = U0DBUF;
        //     }while((++tx_count) != tx_buf[2] && tx_count < HAL_RF_MPDU_MAX_PKG_LEN);
            

        //     mpdu_header.seq_num++;

        //     hal_RF_transmit(&mpdu_header, tx_buf, tx_buf[2] + 3);
            
        //     while(!(HAL_RF_INT_FLG_TXDONE_CHECK()));

        //     HAL_RF_INT_FLG_TXDONE_CLEAR();
        //     tx_buf[0] = 0;
        //     // break;
        // }
        hal_RF_transmit(&mpdu_header, tx_buf, PROTO_HEART_LEN + 2);
        tx_buf[0]++;
        // while(!(spi0_rx_dma_pkg_is_finished()));
        // static uint8_t *rx_buf_ptr;
        // rx_buf_ptr = spi0_get_rx_buf();
        // RF_transmit(&mpdu_header, rx_buf_ptr, *rx_buf_ptr);
        // if (P0_0){
        //     LCD_Clear(RED);
        // }else{
        //     LCD_Clear(GREEN);
        // }
        // buzzer_set_hz(2000);
        // buzzer_start();
        // buzzer_test(delay_ms);
        LCD_Clear(RED);
        // delay_ms(1000);
        LCD_Clear(GREEN);
        // delay_ms(1000);	
        LCD_Clear(BLUE);
        // delay_ms(1000);
    }   
}

