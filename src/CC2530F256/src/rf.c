#include "rf.h"

bool RF_init(void){
    /* RF settings SoC: CC2530 */

    FRMCTRL0 = 0x00;
    FRMCTRL0 |= AUTO_CRC | AUTO_ACK;
    FRMCTRL1  = 0x00; // frame handling 

    // FRMFILT0  = 0x0C; // frame filtering 

    CCACTRL0  = 0xF8; // cca threshold 
    FSCAL1    = 0x00; // tune frequency calibration 
    AGCCTRL1  = 0x15; // agc reference level 
    AGCCTRL2  = 0xFE; // agc gain override 
    TXFILTCFG = 0x09; // tx filter configuration 


    PANIDL = 0x22;
    PANIDH = 0x22;

    SHORTADDRL = 0x23;
    SHORTADDRH = 0x23;

    // return true;
} 

/* build the 802.15.4 header 
* Frame Control: 2 bytes
* Sequence Number: 1 bytes
* Adressing fields and Auxiliary Security Header: 0 ~ depened on the Frame Control

*/
bool RF_build_header(void){
}