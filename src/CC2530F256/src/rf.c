#include "rf.h"

bool RF_init(void){
    /* RF settings SoC: CC2530 */
    // P1        = 0xEC; // port 1 
    // P0DIR     = 0x80; // port 0 direction 
    // P1DIR     = 0x13; // port 1 direction 
    // FRMCTRL1  = 0x00; // frame handling 
    // CCACTRL0  = 0xF8; // cca threshold 
    // FSCAL1    = 0x00; // tune frequency calibration 
    // AGCCTRL1  = 0x15; // agc reference level 
    // AGCCTRL2  = 0xFE; // agc gain override 
    // TXFILTCFG = 0x09; // tx filter configuration 
    // CHVER     = 0x00; // chip version 
    // CHIPID    = 0x00; // chip id 

    // FRMCTRL0 |= BIT6 | BIT5; // auto crc and ack
    // FRMCTRL0 |= AUTO_CRC | AUTO_ACK;
    FRMFILT0  = 0x0C; // frame filtering 
    CCACTRL0  = 0xF8; // cca threshold 
    FSCAL1    = 0x00; // tune frequency calibration 
    AGCCTRL1  = 0x15; // agc reference level 
    AGCCTRL2  = 0xFE; // agc gain override 
    TXFILTCFG = 0x09; // tx filter configuration 

    // return true;
} 

/* build the 802.15.4 header 
* Frame Control: 2 bytes
* Sequence Number: 1 bytes
* Adressing fields and Auxiliary Security Header: 0 ~ depened on the Frame Control

*/
bool RF_build_header(void){
}