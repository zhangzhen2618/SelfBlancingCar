#ifndef __STC8H8K64_IMU_H__ 
#define __STC8H8K64_IMU_H__ 

#include "sys_config.h"
#include "i2c.h"

void Init_ADXL345(void);             //初始化ADXL345

void  Single_Write_ADXL345(uint8_t REG_Address,uint8_t REG_data);   //单个写入数据
uint8_t Single_Read_ADXL345(uint8_t REG_Address);                   //单个读取内部寄存器数据

uint8_t* Multiple_read_ADXL345(void);

#endif // ! 