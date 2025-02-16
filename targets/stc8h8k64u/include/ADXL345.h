#ifndef __ADXL345_H__
#define __ADXL345_H__

#include "i2c.h"

#define ADXL345_ADDRESS_ALT_LOW             0x53 // alt address pin low (GND)
#define ADXL345_ADDRESS_ALT_HIGH            0x1D // alt address pin high (VCC)

#define ADXL345_DEFAULT_ADDRESS             ADXL345_ADDRESS_ALT_LOW

#define ADXL345_RA_DEVID            		0X00
#define ADXL345_RA_RESERVED1        		0X01
#define ADXL345_RA_THRESH_TAP       		0X1D
#define ADXL345_RA_OFSX             		0X1E
#define ADXL345_RA_OFSY             		0X1F
#define ADXL345_RA_OFSZ             		0X20
#define ADXL345_RA_DUR              		0X21
#define ADXL345_RA_LATENT           		0X22
#define ADXL345_RA_WINDOW           		0X23
#define ADXL345_RA_THRESH_ACT       		0X24
#define ADXL345_RA_THRESH_INACT     		0X25
#define ADXL345_RA_TIME_INACT       		0X26
#define ADXL345_RA_ACT_INACT_CTL    		0X27
#define ADXL345_RA_THRESH_FF        		0X28
#define ADXL345_RA_TIME_FF          		0X29
#define ADXL345_RA_TAP_AXES         		0X2A
#define ADXL345_RA_ACT_TAP_STATUS   		0X2B
#define ADXL345_RA_BW_RATE          		0X2C
#define ADXL345_RA_POWER_CTL        		0X2D
#define ADXL345_RA_INT_ENABLE       		0X2E
#define ADXL345_RA_INT_MAP          		0X2F
#define ADXL345_RA_INT_SOURCE       		0X30
#define ADXL345_RA_DATA_FORMAT      		0X31
#define ADXL345_RA_DATAX0           		0X32
#define ADXL345_RA_DATAX1           		0X33
#define ADXL345_RA_DATAY0           		0X34
#define ADXL345_RA_DATAY1           		0X35
#define ADXL345_RA_DATAZ0           		0X36
#define ADXL345_RA_DATAZ1           		0X37
#define ADXL345_RA_FIFO_CTL         		0X38
#define ADXL345_RA_FIFO_STATUS      		0X39

#define ADXL345_AIC_ACT_AC_BIT     			7
#define ADXL345_AIC_ACT_X_BIT      			6
#define ADXL345_AIC_ACT_Y_BIT      			5
#define ADXL345_AIC_ACT_Z_BIT      			4
#define ADXL345_AIC_INACT_AC_BIT   			3
#define ADXL345_AIC_INACT_X_BIT    			2
#define ADXL345_AIC_INACT_Y_BIT    			1
#define ADXL345_AIC_INACT_Z_BIT    			0

#define ADXL345_TAPAXIS_SUP_BIT    			3
#define ADXL345_TAPAXIS_X_BIT      			2
#define ADXL345_TAPAXIS_Y_BIT      			1
#define ADXL345_TAPAXIS_Z_BIT      			0

#define ADXL345_TAPSTAT_ACTX_BIT   			6
#define ADXL345_TAPSTAT_ACTY_BIT   			5
#define ADXL345_TAPSTAT_ACTZ_BIT   			4
#define ADXL345_TAPSTAT_ASLEEP_BIT 			3
#define ADXL345_TAPSTAT_TAPX_BIT   			2
#define ADXL345_TAPSTAT_TAPY_BIT   			1
#define ADXL345_TAPSTAT_TAPZ_BIT   			0

#define ADXL345_BW_LOWPOWER_BIT    			4
#define ADXL345_BW_RATE_BIT        			3
#define ADXL345_BW_RATE_LENGTH     			4

#define ADXL345_RATE_3200          		 0b1111
#define ADXL345_RATE_1600          		 0b1110
#define ADXL345_RATE_800           		 0b1101
#define ADXL345_RATE_400           		 0b1100
#define ADXL345_RATE_200           		 0b1011
#define ADXL345_RATE_100           		 0b1010
#define ADXL345_RATE_50            		 0b1001
#define ADXL345_RATE_25            		 0b1000
#define ADXL345_RATE_12P5          		 0b0111
#define ADXL345_RATE_6P25          		 0b0110
#define ADXL345_RATE_3P13          		 0b0101
#define ADXL345_RATE_1P56          		 0b0100
#define ADXL345_RATE_0P78          		 0b0011
#define ADXL345_RATE_0P39          		 0b0010
#define ADXL345_RATE_0P20          		 0b0001
#define ADXL345_RATE_0P10          		 0b0000

#define ADXL345_PCTL_LINK_BIT      		 5
#define ADXL345_PCTL_AUTOSLEEP_BIT 		 4
#define ADXL345_PCTL_MEASURE_BIT   		 3
#define ADXL345_PCTL_SLEEP_BIT     		 2
#define ADXL345_PCTL_WAKEUP_BIT    		 1
#define ADXL345_PCTL_WAKEUP_LENGTH 		 2

#define ADXL345_WAKEUP_8HZ         		 0b00
#define ADXL345_WAKEUP_4HZ         		 0b01
#define ADXL345_WAKEUP_2HZ         		 0b10
#define ADXL345_WAKEUP_1HZ         		 0b11

#define ADXL345_INT_DATA_READY_BIT 		 7
#define ADXL345_INT_SINGLE_TAP_BIT 		 6
#define ADXL345_INT_DOUBLE_TAP_BIT 		 5
#define ADXL345_INT_ACTIVITY_BIT   		 4
#define ADXL345_INT_INACTIVITY_BIT 		 3
#define ADXL345_INT_FREE_FALL_BIT  		 2
#define ADXL345_INT_WATERMARK_BIT  		 1
#define ADXL345_INT_OVERRUN_BIT    		 0

#define ADXL345_FORMAT_SELFTEST_BIT		 7
#define ADXL345_FORMAT_SPIMODE_BIT 		 6
#define ADXL345_FORMAT_INTMODE_BIT 		 5
#define ADXL345_FORMAT_FULL_RES_BIT		 3
#define ADXL345_FORMAT_JUSTIFY_BIT 		 2
#define ADXL345_FORMAT_RANGE_BIT   		 1
#define ADXL345_FORMAT_RANGE_LENGTH		 2

#define ADXL345_RANGE_2G           		 0b00
#define ADXL345_RANGE_4G           		 0b01
#define ADXL345_RANGE_8G           		 0b10
#define ADXL345_RANGE_16G          		 0b11

#define ADXL345_FIFO_MODE_BIT      		 7
#define ADXL345_FIFO_MODE_LENGTH   		 2
#define ADXL345_FIFO_TRIGGER_BIT   		 5
#define ADXL345_FIFO_SAMPLES_BIT   		 4
#define ADXL345_FIFO_SAMPLES_LENGTH		 5

#define ADXL345_FIFO_MODE_BYPASS   		 0b00
#define ADXL345_FIFO_MODE_FIFO     		 0b01
#define ADXL345_FIFO_MODE_STREAM   		 0b10
#define ADXL345_FIFO_MODE_TRIGGER  		 0b11

#define ADXL345_FIFOSTAT_TRIGGER_BIT     7
#define ADXL345_FIFOSTAT_LENGTH_BIT      5
#define ADXL345_FIFOSTAT_LENGTH_LENGTH   6


// DEVID register
uint8_t ADXL345_getDeviceID();

#define ADXL345_testConnection()         (ADXL345_getDeviceID() == 0xE5)

// int the ADXL345
void ADXL345_init(void);

// get the ADXL345 acc x, y, z
uint8_t ADXL345_get_xyz(uint8_t *xyz);

#endif /* _ADXL345_H_ */
