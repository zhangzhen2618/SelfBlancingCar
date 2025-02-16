#ifndef __BMP180_H__
#define __BMP180_H__

#include "i2c.h"

#define BMP180_ADDRESS                          0x77

#define BMP180_REGISTER_CAL_AC1 		        0xAA //!< R   Calibration data (16 bits)
#define BMP180_REGISTER_CAL_AC2 		        0xAC //!< R   Calibration data (16 bits)
#define BMP180_REGISTER_CAL_AC3 		        0xAE //!< R   Calibration data (16 bits)
#define BMP180_REGISTER_CAL_AC4 		        0xB0 //!< R   Calibration data (16 bits)
#define BMP180_REGISTER_CAL_AC5 		        0xB2 //!< R   Calibration data (16 bits)
#define BMP180_REGISTER_CAL_AC6 		        0xB4 //!< R   Calibration data (16 bits)
#define BMP180_REGISTER_CAL_B1 		            0xB6 //!< R   Calibration data (16 bits)
#define BMP180_REGISTER_CAL_B2 		            0xB8 //!< R   Calibration data (16 bits)
#define BMP180_REGISTER_CAL_MB 		            0xBA //!< R   Calibration data (16 bits)
#define BMP180_REGISTER_CAL_MC 		            0xBC //!< R   Calibration data (16 bits)
#define BMP180_REGISTER_CAL_MD 		            0xBE //!< R   Calibration data (16 bits)

#define BMP180_REGISTER_CHIPID 		            0xD0 //!< Register that contains the chip ID
#define BMP180_REGISTER_VERSION 		        0xD1 //!< Register that contains the chip version
#define BMP180_REGISTER_SOFTRESET 		        0xE0 //!< Register for doing a soft reset
#define BMP180_REGISTER_CONTROL 		        0xF4 //!< Control register
#define BMP180_REGISTER_TEMPDATA 		        0xF6 //!< Temperature data register
#define BMP180_REGISTER_PRESSUREDATA 		    0xF6 //!< Pressure data register
#define BMP180_REGISTER_READTEMPCMD 		    0x2E //!< Read temperature control register value
#define BMP180_REGISTER_READPRESSURECMD 		0x34 //!< Read pressure control register value

/*!
 * @brief BMP180 mode settings
 */
typedef enum {
    BMP180_MODE_ULTRALOWPOWER = 0,
    BMP180_MODE_STANDARD = 1,
    BMP180_MODE_HIGHRES = 2,
    BMP180_MODE_ULTRAHIGHRES = 3
} bmp085_mode_t;
/*=========================================================================*/

// /*!
//  * @brief Calibration data
//  */
typedef struct {
    int16_t ac1;  //!< R calibration coefficient (16-bits)
    int16_t ac2;  //!< R calibration coefficient (16-bits)
    int16_t ac3;  //!< R calibration coefficient (16-bits)
    uint16_t ac4; //!< R calibration coefficient (16-bits)
    uint16_t ac5; //!< R calibration coefficient (16-bits)
    uint16_t ac6; //!< R calibration coefficient (16-bits)
    int16_t b1;   //!< R calibration coefficient (16-bits)
    int16_t b2;   //!< R calibration coefficient (16-bits)
    int16_t mb;   //!< R calibration coefficient (16-bits)
    int16_t mc;   //!< R calibration coefficient (16-bits)
    int16_t md;   //!< R calibration coefficient (16-bits)
} bmp180_calib_data;

uint8_t BMP180_getDeviceID();
#endif
