#include "rf.h"

// Various radio settings
#define AUTO_ACK                            0x20
#define AUTO_CRC                            0x40

uint8_t RF_init(void){
    /* RF settings SoC: CC2530 */
    // P1        = 0xEC; // port 1 
    // P0DIR     = 0x80; // port 0 direction 
    // P1DIR     = 0x13; // port 1 direction 
    FRMFILT0  = 0x0C; // frame filtering 
    CCACTRL0  = 0xF8; // cca threshold 
    FSCAL1    = 0x00; // tune frequency calibration 
    AGCCTRL1  = 0x15; // agc reference level 
    AGCCTRL2  = 0xFE; // agc gain override 
    TXFILTCFG = 0x09; // tx filter configuration 
    CHVER     = 0x00; // chip version 
    CHIPID    = 0x00; // chip id 

}