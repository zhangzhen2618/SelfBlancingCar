#ifndef __STC8H8K64U_I2C_H__ 
#define __STC8H8K64U_I2C_H__ 

#include "sys_config.h"

// config the I2C controller
void i2c_init();

void i2c_start();
void i2c_stop();
void i2c_send_ACK(bool ack);
bool i2c_recv_ACK();
void i2c_write_byte(uint8_t dat);
uint8_t i2c_read_byte();

void i2c_start_write_byte_ack(uint8_t byte);
void i2c_write_byte_ack(uint8_t byte);
uint8_t i2c_read_byte_ack();
uint8_t i2c_read_byte_nak();

void I2C_isr() __interrupt(I2C_VECTOR) __using(I2C_VECTOR);

#endif // ! 