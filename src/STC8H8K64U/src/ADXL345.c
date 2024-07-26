
#include "ADXL345.h"

#define write_reg(reg, data_)                   i2c_write_singal_reg(ADXL345_DEFAULT_ADDRESS, reg, data_)
#define read_regs(reg, data_, size_)        i2c_read_regs(ADXL345_DEFAULT_ADDRESS, reg, data_, size_)
#define write_regs(reg, data_, size_)       i2c_write_regs(ADXL345_DEFAULT_ADDRESS, reg, data_, size_)

uint8_t ADXL345_getDeviceID(){
    uint8_t dev_id = 0;
    read_regs(ADXL345_RA_DEVID, &dev_id, 1);

    return dev_id;
}

void ADXL345_init(){
        
    write_reg(ADXL345_RA_DATA_FORMAT, 0x0B);   //测量范围,正负16g，13位模式
    write_reg(ADXL345_RA_BW_RATE, 0x08);   //速率设定为12.5 参考pdf13页
    write_reg(ADXL345_RA_POWER_CTL, 0x08);   //选择电源模式   参考pdf24页
    write_reg(ADXL345_RA_INT_ENABLE, 0x80);   //使能 DATA_READY 中断
    write_reg(ADXL345_RA_OFSX, 0x00);   //X 偏移量 根据测试传感器的状态写入pdf29页
    write_reg(ADXL345_RA_OFSY, 0x00);   //Y 偏移量 根据测试传感器的状态写入pdf29页
    write_reg(ADXL345_RA_OFSZ, 0x05);   //Z 偏移量 根据测试传感器的状态写入pdf29页
}

//get the ADXL345 xyz data
uint8_t ADXL345_get_xyz(uint8_t *xyz){
    return read_regs(ADXL345_RA_DATAX0, xyz, 6);
}