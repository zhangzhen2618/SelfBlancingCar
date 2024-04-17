#include "spi.h"

#include "STC8H.h"
#include <stdint.h>
#include <stdbool.h>

#include "sys_config.h"

static uint8_t tx_buf[] = "000 Hello world\n";
static uint8_t tx_count = 0;
static uint8_t checksum = 0;

void main(void){

    sys_init();
    
    spi_init();

    // Interrupt enable
    // ES = 1;
    // EA = 1;
    // IE2 |= 0x02;
    P5_4 = 0;

    while(1){
        // delay some time
        tx_buf[2] = tx_count % 10;
        tx_buf[1] = tx_count / 10 % 10;
        tx_buf[0] = tx_count / 100;
        tx_count++;
        
        spi_send(0xAA);
        spi_send(sizeof(tx_buf) + 1);
        checksum = 0;
        for(uint8_t i = 0; i < sizeof(tx_buf); i++){
            checksum += tx_buf[i];
            spi_send(tx_buf[i]);
        }

        spi_send(checksum);

        for(uint8_t i = 0; i < 0x0f; i++)
            for(uint16_t j = 0; j != 0xffff; j++);
    }

}



