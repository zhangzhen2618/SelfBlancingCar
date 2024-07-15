#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "STC8H.h"
#include "sys_config.h"
#include "spi.h"
#include "imu.h"

static uint8_t tx_buf[] = "000 Hello world\n";
static uint8_t tx_count = 0;
static uint8_t checksum = 0;

void main(void){

    sys_init();
    
    spi_init();

    // Interrupt enable
    ES = 1;
    EA = 1;
    // IE2 |= 0x02;
    P5_4 = 0;
    P4_7 = 0;

    i2c_init();

    Init_ADXL345();

    uint8_t devid;

    while(1){

        // delay some time
        tx_buf[2] = tx_count % 10;
        tx_buf[1] = tx_count / 10 % 10;
        tx_buf[0] = tx_count / 100;
        tx_count++;
        
        tx_buf[4] = Single_Read_ADXL345(0X00);//读出的数据为0XE5,表示正确
        devid = Single_Read_ADXL345(0x00);
        uint8_t* imu_data_ptr = Multiple_read_ADXL345();
        memcpy(tx_buf + 5, imu_data_ptr, 6);
        P4_7 = 1;
        spi_send(0xAA);
        spi_send(sizeof(tx_buf) + 1);
        checksum = 0;
        for(uint8_t i = 0; i < sizeof(tx_buf); i++){
            checksum += tx_buf[i];
            spi_send(tx_buf[i]);
        }

        spi_send(checksum);

        P4_7 = 0;
        for(uint8_t i = 0; i < 0x01; i++)
            for(uint16_t j = 0; j != 0xffff; j++);

    }

}



