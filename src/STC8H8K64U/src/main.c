#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "STC8H.h"
#include "sys_config.h"
#include "spi.h"

#include "ADXL345.h"
#include "BMP180.h"

#include "uart.h"

#include "crc.h"

// static uint8_t tx_buf[30] = "000 Hello world\n";
static uint8_t tx_buf[32] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
static uint8_t tx_count = 0;
static uint8_t check_crc[2] = {0};

void main(void){

    sys_init();

    crc16_init(DEFAULT_CRC_BITS, DEFAULT_CRC_POLY);
    
    spi_init();

    // Interrupt enable
    ES = 1;
    EA = 1;
    // IE2 |= 0x02;
    P5_4 = 0;
    P4_7 = 0;
    
    uart_init();

    i2c_init();

    ADXL345_init();

    // uint8_t devid;

    // tx_buf[sizeof(tx_buf) - 1] = 0xEB;
    // tx_buf[sizeof(tx_buf) - 2] = 0xEB;

    while(1){

        // delay some time
        tx_buf[2] = tx_count % 10;
        tx_buf[1] = tx_count / 10 % 10;
        tx_buf[0] = tx_count / 100;
        tx_count++;
        
        // tx_buf[4] = Single_Read_ADXL345(0X00);//读出的数据为0XE5,表示正确
        tx_buf[4] = ADXL345_getDeviceID();
        ADXL345_get_xyz(tx_buf + 5);

        // BMP180
        tx_buf[11] = BMP180_getDeviceID();

        P4_7 = 1;
        *(uint16_t*)(check_crc) = crc16_calc(tx_buf, sizeof(tx_buf), DEFAULT_CRC_START_VALUE);
        spi_send(0xAA);
        spi_send(sizeof(tx_buf) + 2);
        for(uint8_t i = 0; i < sizeof(tx_buf); i++){
            spi_send(tx_buf[i]);
        }

        spi_send(check_crc[0]);
        spi_send(check_crc[1]);

        P4_7 = 0;

        for(uint8_t i = 0; i < 3; i++){
            uart_send(tx_buf[i]);
        }
        
        for(uint8_t i = 0; i < 0x02; i++)
            for(uint16_t j = 0; j != 0xffff; j++);

    }

}



