#include "BMP180.h"

#define write_reg(reg, data_)               i2c_write_singal_reg(BMP180_ADDRESS, reg, data_)
#define read_regs(reg, data_, size_)        i2c_read_regs(BMP180_ADDRESS, reg, data_, size_)
#define write_regs(reg, data_, size_)       i2c_write_regs(BMP180_ADDRESS, reg, data_, size_)

uint8_t BMP180_getDeviceID(void){
    
    uint8_t id;
    read_regs(BMP180_REGISTER_CHIPID, &id, 1);

    return id;
}