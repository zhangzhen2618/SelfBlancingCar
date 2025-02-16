#include "i2c.h"

// I2C master model, cmd
#define     I2C_IDLE()                        (I2CMSCR = 0X80)
#define     I2C_START()                       (I2CMSCR = 0X81)
#define     I2C_SEND()                        (I2CMSCR = 0X82)
#define     I2C_ACK_RECV()                    (I2CMSCR = 0X83)
#define     I2C_RECV()                        (I2CMSCR = 0X84)
#define     I2C_ACK_SEND()                    (I2CMSCR = 0X85)
#define     I2C_STOP()                        (I2CMSCR = 0X86)

#define     I2C_START_SEND_ACK()              (I2CMSCR = 0X89)
#define     I2C_SEND_ACK()                    (I2CMSCR = 0X8A)
#define     I2C_RECV_ACK()                    (I2CMSCR = 0X8B)
#define     I2C_RECV_NAK()                    (I2CMSCR = 0X8C)

static volatile bool I2C_busy;

void i2c_init(){

    P_SW2 |= 0x10; // let I2C, SCL --> P2.5, SDA --> P2.4

    I2CCFG = 0xE0; // i2c master
    I2CMSST = 0x00;
}

void i2c_start(){
    I2C_busy = 1;
    I2C_START();
    while(I2C_busy);
}

void i2c_stop(){
    I2C_busy = 1;
    I2C_STOP();
    while (I2C_busy);
}

void i2c_send_ACK(bool ack){

    if (ack){
        I2CMSST = 0x01;
    }else{
        I2CMSST = 0x00;
    }
    I2C_busy = 1;
    I2C_ACK_SEND();
    while(I2C_busy);
}

bool i2c_recv_ACK(){
    I2C_busy = 1;
    I2C_ACK_RECV();
    while(I2C_busy);
    return 1;
}

void i2c_write_byte(uint8_t byte){
    I2CTXD = byte;
    I2C_busy = 1;
    I2C_SEND();
    while(I2C_busy);
    // i2c_recv_ACK();
    // ADXL345_RecvACK();
}

uint8_t i2c_read_byte(){
    I2C_busy = 1;
    I2C_RECV();
    while(I2C_busy);
    return I2CRXD;
}

void i2c_start_write_byte_ack(uint8_t byte){
    I2C_busy = 1;
    I2CTXD = byte;
    I2C_START_SEND_ACK();
    while (I2C_busy);   
}

void i2c_write_byte_ack(uint8_t byte){

    I2C_busy = 1;

    I2CTXD = byte;
    I2C_SEND_ACK();

    while (I2C_busy);
}

uint8_t i2c_read_byte_ack(){
    I2C_busy = 1;
    I2C_RECV_ACK();
    while(I2C_busy);
    return I2CRXD;
}
uint8_t i2c_read_byte_nak(){
    I2C_busy = 1;
    I2C_RECV_NAK();
    while(I2C_busy);
    return I2CRXD;
}

uint8_t i2c_write_singal_reg(uint8_t addr, uint8_t reg, uint8_t data_){
    // start, write the addr and receive the ack
    I2C_busy = 1;
    I2CTXD = addr << 1;
    I2C_START_SEND_ACK();
    while(I2C_busy);

    // write the reg
    I2C_busy = 1;
    I2CTXD = reg;
    I2C_SEND_ACK();
    while(I2C_busy);

    // write the data
    I2C_busy = 1;
    I2CTXD = data_;
    I2C_SEND_ACK();
    while(I2C_busy);

    // stop
    I2C_busy = 1;
    I2C_STOP();
    while(I2C_busy);

    return 0;
}
uint8_t i2c_read_regs(uint8_t addr, uint8_t reg, uint8_t *data_, uint8_t size){
        
    // start, write the addr and receive the ack
    I2C_busy = 1;
    I2CTXD = addr << 1;
    I2C_START_SEND_ACK();
    while(I2C_busy);

    // write the reg
    I2C_busy = 1;
    I2CTXD = reg;
    I2C_SEND_ACK();
    while(I2C_busy);

    // write the read address
    I2C_busy = 1;
    I2CTXD = (addr << 1) | 1;
    I2C_START_SEND_ACK();
    while(I2C_busy);

    // read the data
    uint8_t i = 0;

    for(; i < size -1; i++){
        I2C_busy = 1;
        I2C_RECV_ACK();
        while(I2C_busy);
        data_[i] = I2CRXD;
    }

    I2C_busy = 1;
    I2C_RECV_NAK();
    while(I2C_busy);
    data_[i] = I2CRXD;

    // stop
    I2C_busy = 1;
    I2C_STOP();
    while(I2C_busy);

    return 0;
}

uint8_t i2c_write_regs(uint8_t addr, uint8_t reg, uint8_t *data_, uint8_t size){

    // start, write the addr and receive the ack
    I2C_busy = 1;
    I2CTXD = addr << 1;
    I2C_START_SEND_ACK();
    while(I2C_busy);

    // write the reg
    I2C_busy = 1;
    I2CTXD = reg;
    I2C_SEND_ACK();
    while(I2C_busy);

    // write the data
    for(uint8_t i = 0; i < size; i++){
        I2C_busy = 1;
        I2CTXD = data_[i];
        I2C_SEND_ACK();
        while(I2C_busy);
    }

    // stop
    I2C_busy = 1;
    I2C_STOP();
    while(I2C_busy);

    return 0;
}


void I2C_isr() __interrupt(I2C_VECTOR) __using(I2C_VECTOR){
    if (I2CMSST & 0x40){
        I2CMSST &= ~0x40;
        I2C_busy = 0;
    }
}