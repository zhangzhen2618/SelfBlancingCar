#include "crc.h"

#define crclen                  256

static uint16_t _crctab[crclen];
static uint8_t  _bits;
static uint16_t _bitmask;
static uint16_t _poly;

void crc16_init(uint8_t bits, uint16_t poly) {

    if (bits == _bits && poly == _poly)
        return;
    
    _poly = poly;
    _bits = bits;
    _bitmask = (1 << _bits) - 1;
    
    uint16_t highbit = 1 << (_bits - 1);
    uint16_t crc;
    for (uint16_t i = 0; i < crclen; i++){
        crc = i << (bits - 8);
        for (uint8_t j = 0; j < 8; j++){
            crc = (crc << 1) ^ ((crc & highbit) ? poly : 0);
        }
        _crctab[i] = crc;
    }
}

uint16_t crc16_calc(uint8_t *crc_data, uint8_t len, uint16_t crc){
    while (len--){
        crc = (crc << 8) ^ _crctab[((crc >> (_bits - 8)) ^ (uint16_t) *crc_data++) & 0x00FF];
    }
    return crc & _bitmask;
}
