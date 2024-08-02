#ifndef __CRC_H__
#define __CRC_H__

#include <stdint.h>

#define DEFAULT_CRC_BITS                        16
#define DEFAULT_CRC_POLY                        0x3D65 // CRC POLY
#define DEFAULT_CRC_START_VALUE                 0X0000

// Generate the crc16 table
void crc16_init(uint8_t bits, uint16_t poly);

// calc the crc
uint16_t crc16_calc(uint8_t *data, uint8_t len, uint16_t crc);

#endif