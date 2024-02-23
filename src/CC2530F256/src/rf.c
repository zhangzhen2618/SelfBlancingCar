#include "rf.h"

// Various radio settings
#define AUTO_ACK                            0x20
#define AUTO_CRC                            0x40

#define PKT_LEN_MIC                         8
#define PKT_LEN_SEC                         PKT_LEN_UNSEC + PKT_LEN_MIC
#define PKT_LEN_AUTH                        8
#define PKT_LEN_ENCR                        24

// Packet overhead ((frame control field, sequence number, PAN ID,
// destination and source) + (footer))
// Note that the length byte itself is not included included in the packet length
#define BASIC_RF_PACKET_OVERHEAD_SIZE       ((2 + 1 + 2 + 2 + 2) + (2))
#define BASIC_RF_MAX_PAYLOAD_SIZE	        (127 - BASIC_RF_PACKET_OVERHEAD_SIZE - BASIC_RF_AUX_HDR_LENGTH - BASIC_RF_LEN_MIC)
#define BASIC_RF_ACK_PACKET_SIZE	        5
#define BASIC_RF_FOOTER_SIZE                2
#define BASIC_RF_HDR_SIZE                   10

// The time it takes for the acknowledgment packet to be received after the
// data packet has been transmitted.
#define BASIC_RF_ACK_DURATION		        (0.5 * 32 * 2 * ((4 + 1) + (1) + (2 + 1) + (2)))
#define BASIC_RF_SYMBOL_DURATION	        (32 * 0.5)

// The length byte
#define BASIC_RF_PLD_LEN_MASK               0x7F

// Frame control field
#define BASIC_RF_FCF_NOACK                  0x8841
#define BASIC_RF_FCF_ACK                    0x8861
#define BASIC_RF_FCF_ACK_BM                 0x0020
#define BASIC_RF_FCF_BM                     (~BASIC_RF_FCF_ACK_BM)
#define BASIC_RF_SEC_ENABLED_FCF_BM         0x0008

// Frame control field LSB
#define BASIC_RF_FCF_NOACK_L                LO_uint16_t(BASIC_RF_FCF_NOACK)
#define BASIC_RF_FCF_ACK_L                  LO_uint16_t(BASIC_RF_FCF_ACK)
#define BASIC_RF_FCF_ACK_BM_L               LO_uint16_t(BASIC_RF_FCF_ACK_BM)
#define BASIC_RF_FCF_BM_L                   LO_uint16_t(BASIC_RF_FCF_BM)
#define BASIC_RF_SEC_ENABLED_FCF_BM_L       LO_uint16_t(BASIC_RF_SEC_ENABLED_FCF_BM)

// Auxiliary Security header
#define BASIC_RF_AUX_HDR_LENGTH             5
#define BASIC_RF_LEN_AUTH                   BASIC_RF_PACKET_OVERHEAD_SIZE + BASIC_RF_AUX_HDR_LENGTH - BASIC_RF_FOOTER_SIZE
#define BASIC_RF_SECURITY_M                 2
#define BASIC_RF_LEN_MIC                    8

// Footer
#define BASIC_RF_CRC_OK_BM                  0x80

/***********************************************************************************
* TYPEDEFS
*/
// The receive struct
typedef struct {
    uint8_t seqNumber;
    uint16_t srcAddr;
    uint16_t srcPanId;
    int8_t length;
    uint8_t* pPayload;
    uint8_t ackRequest;
    int8_t rssi;
    volatile uint8_t isReady;
    uint8_t status;
} RF_RX_INFO;

// Tx state
typedef struct {
    uint8_t txSeqNumber;
    volatile uint8_t ackReceived;
    uint8_t receiveOn;
    uint32_t frameCounter;
} RF_TX_STATE;


// Basic RF packet header (IEEE 802.15.4)
typedef struct {
    uint8_t   packetLength;
    uint8_t   fcf0;           // Frame control field LSB
    uint8_t   fcf1;           // Frame control field MSB
    uint8_t   seqNumber;
    uint16_t  panId;
    uint16_t  destAddr;
    uint16_t  srcAddr;
} RF_PACKET_HEADER;


/***********************************************************************************
* LOCAL VARIABLES
*/
static RF_RX_INFO  rxi = { 0xFF }; // Make sure sequence numbers are
static RF_TX_STATE txState = { 0x00 }; // initialised and distinct.

static RF_CONFIG* pConfig;
static uint8_t txMpdu[BASIC_RF_MAX_PAYLOAD_SIZE + BASIC_RF_PACKET_OVERHEAD_SIZE + 1];
static uint8_t rxMpdu[128];

/***********************************************************************************
* GLOBAL VARIABLES
*/


/***********************************************************************************
* LOCAL FUNCTIONS
*/

static void RF_read_rx_buf(uint8_t* pData, uint8_t length){
    // Read data
    while (length>0) {
        *pData++= RFD;
        length--;
    }
}

/***********************************************************************************
* @fn          basicRfBuildHeader
*
* @brief       Builds packet header according to IEEE 802.15.4 frame format
*
* @param       buffer - Pointer to buffer to write the header
*              destAddr - destination short address
*              payloadLength - length of higher layer payload
*
* @return      uint8_t - length of header
*/
static uint8_t RF_build_header(
    uint8_t* buffer, uint16_t destAddr, uint8_t payloadLength){

    RF_PACKET_HEADER *pHdr;
    uint16_t fcf;

    pHdr= (RF_PACKET_HEADER *)buffer;

    // Populate packet header
    pHdr->packetLength = payloadLength + BASIC_RF_PACKET_OVERHEAD_SIZE;
    //pHdr->frameControlField = pConfig->ackRequest ? BASIC_RF_FCF_ACK : BASIC_RF_FCF_NOACK;
    fcf= pConfig->ackRequest ? BASIC_RF_FCF_ACK : BASIC_RF_FCF_NOACK;
    pHdr->fcf0 = LO_UINT16(fcf);
    pHdr->fcf1 = HI_UINT16(fcf);
    pHdr->seqNumber= txState.txSeqNumber;
    pHdr->panId= pConfig->panId;
    pHdr->destAddr= destAddr;
    pHdr->srcAddr= pConfig->myAddr;

    // Make sure bytefields are network byte order
    // UINT16_HTON(pHdr->panId);
    // UINT16_HTON(pHdr->destAddr);
    // UINT16_HTON(pHdr->srcAddr);

    return BASIC_RF_HDR_SIZE;
}


/***********************************************************************************
* @fn          basicRfBuildMpdu
*
* @brief       Builds mpdu (MAC header + payload) according to IEEE 802.15.4
*              frame format
*
* @param       destAddr - Destination short address
*              pPayload - pointer to buffer with payload
*              payloadLength - length of payload buffer
*
* @return      uint8_t - length of mpdu
*/
static uint8_t RF_build_mpdu(uint16_t destAddr, uint8_t* pPayload, uint8_t payloadLength){

    uint8_t hdrLength, n;

    hdrLength = RF_build_header(txMpdu, destAddr, payloadLength);

    for(n=0;n<payloadLength;n++){
        txMpdu[hdrLength+n] = pPayload[n];
    }
    
    return hdrLength + payloadLength; // total mpdu length
}


/***********************************************************************************
* @fn          basicRfRxFrmDoneIsr
*
* @brief       Interrupt service routine for received frame from radio
*              (either data or acknowlegdement)
*
* @param       rxi - file scope variable info extracted from the last incoming
*                    frame
*              txState - file scope variable that keeps tx state info
*
* @return      none
*/
static void RF_rx_frame_done_isr(void) __interrupt(RF_VECTOR){

    RF_PACKET_HEADER *pHdr;
    uint8_t *pStatusWord;

    // Map header to packet buffer
    pHdr= (RF_PACKET_HEADER*)rxMpdu;

    // Clear interrupt and disable new RX frame done interrupt
    RF_RX_INT_OFF();

    // Enable all other interrupt sources (enables interrupt nesting)
    INT_ON();

    // Read payload length.
    RF_read_rx_buf(&pHdr->packetLength,1);
    pHdr->packetLength &= BASIC_RF_PLD_LEN_MASK; // Ignore MSB
    
    // Is this an acknowledgment packet?
    // Only ack packets may be 5 bytes in total.
    if (pHdr->packetLength == BASIC_RF_ACK_PACKET_SIZE) {

        // Read the packet
        RF_read_rx_buf(&rxMpdu[1], pHdr->packetLength);

        // Make sure byte fields are changed from network to host byte order

        rxi.ackRequest = !!(pHdr->fcf0 & BASIC_RF_FCF_ACK_BM_L);

        // Read the status word and check for CRC OK
        pStatusWord= rxMpdu + 4;

        // Indicate the successful ACK reception if CRC and sequence number OK
        if ((pStatusWord[1] & BASIC_RF_CRC_OK_BM) && (pHdr->seqNumber == txState.txSeqNumber)) {
            txState.ackReceived = true;
        }

        // No, it is data
    } else {

        // It is assumed that the radio rejects packets with invalid length.
        // Subtract the number of bytes in the frame overhead to get actual payload.

        rxi.length = pHdr->packetLength - BASIC_RF_PACKET_OVERHEAD_SIZE;

        RF_read_rx_buf(&rxMpdu[1], pHdr->packetLength);

        // Make sure byte fields are changed from network to host byte order

        rxi.ackRequest = !!(pHdr->fcf0 & BASIC_RF_FCF_ACK_BM_L);

        // Read the source address
        rxi.srcAddr= pHdr->srcAddr;

        // Read the packet payload
        rxi.pPayload = rxMpdu + BASIC_RF_HDR_SIZE;

        // Read the FCS to get the RSSI and CRC
        pStatusWord= rxi.pPayload+rxi.length;
        
        rxi.rssi = pStatusWord[0];

        // Notify the application about the received data packet if the CRC is OK
        // Throw packet if the previous packet had the same sequence number
        if( (pStatusWord[1] & BASIC_RF_CRC_OK_BM) && (rxi.seqNumber != pHdr->seqNumber) ) {
            // If security is used check also that authentication passed
            if ( ((pHdr->fcf0 & (BASIC_RF_FCF_BM_L)) == BASIC_RF_FCF_NOACK_L) ) {
                rxi.isReady = true;
            }              
        }
        rxi.seqNumber = pHdr->seqNumber;
    }
  
    // Enable RX frame done interrupt again
    // halIntOff();
    INT_OFF();
    RF_RX_INT_ON();
    // halRfEnableRxInterrupt();
}


/***********************************************************************************
* GLOBAL FUNCTIONS
*/

void RF_set_channel(uint8_t channel){

    FREQCTRL = (MIN_CHANNEL + (channel - MIN_CHANNEL) * CHANNEL_SPACING);
}


/***********************************************************************************
* @fn          basicRfInit
*
* @brief       Initialise basic RF datastructures. Sets channel, short address and
*              PAN id in the chip and configures interrupt on packet reception
*
* @param       pRfConfig - pointer to BASIC_RF_CONFIG struct.
*                          This struct must be allocated by higher layer
*              txState - file scope variable that keeps tx state info
*              rxi - file scope variable info extracted from the last incoming
*                    frame
*
* @return      none
*/
uint8_t RF_init(RF_CONFIG* pRfConfig)
{
    if (halRfInit()==FAILED)
        return FAILED;
    // Enable auto ack and auto crc
    FRMCTRL0 |= (AUTO_ACK | AUTO_CRC);

    // Recommended RX settings
    TXFILTCFG = 0x09;
    AGCCTRL1 = 0x15;
    FSCAL1 = 0x00;

    // Enable random generator -> Not implemented yet

    // Enable RX interrupt
    RF_RX_INT_ON();
    // halRfEnableRxInterrupt();
    // halIntOff();
    INT_OFF();

    // Set the protocol configuration
    pConfig = pRfConfig;
    rxi.pPayload   = NULL;

    txState.receiveOn = true;
    txState.frameCounter = 0;

    // Set channel
    RF_set_channel(pConfig->channel);

    // Write the short address and the PAN ID to the CC2520 RAM
    // halRfSetShortAddr(pConfig->myAddr);
    // halRfSetPanId(pConfig->panId);

    // Set up receive interrupt (received data or acknowlegment)
    // RF_rx_interrupt_config(basicRfRxFrmDoneIsr);

    INT_ON();

    return SUCCESS;
}


/***********************************************************************************
* @fn          basicRfSendPacket
*
* @brief       Send packet
*
* @param       destAddr - destination short address
*              pPayload - pointer to payload buffer. This buffer must be
*                         allocated by higher layer.
*              length - length of payload
*              txState - file scope variable that keeps tx state info
*              mpdu - file scope variable. Buffer for the frame to send
*
* @return      basicRFStatus_t - SUCCESS or FAILED
*/
uint8_t basicRfSendPacket(uint16_t destAddr, uint8_t* pPayload, uint8_t length)
{
    uint8_t mpduLength;
    uint8_t status;

    // Turn on receiver if its not on
    if(!txState.receiveOn) {
        halRfReceiveOn();
    }

    // Check packet length
    length = min(length, BASIC_RF_MAX_PAYLOAD_SIZE);

    // Wait until the transceiver is idle
    halRfWaitTransceiverReady();

    // Turn off RX frame done interrupt to avoid interference on the SPI interface
    halRfDisableRxInterrupt();

    mpduLength = basicRfBuildMpdu(destAddr, pPayload, length);

    #ifdef SECURITY_CCM
    halRfWriteTxBufSecure(txMpdu, mpduLength, length, BASIC_RF_LEN_AUTH, BASIC_RF_SECURITY_M);
    txState.frameCounter++;     // Increment frame counter field
    #else
    halRfWriteTxBuf(txMpdu, mpduLength);
    #endif

    // Turn on RX frame done interrupt for ACK reception
    halRfEnableRxInterrupt();

    // Send frame with CCA. return FAILED if not successful
    if(halRfTransmit() != SUCCESS) {
        status = FAILED;
    }

    // Wait for the acknowledge to be received, if any
    if (pConfig->ackRequest) {
        txState.ackReceived = false;

        // We'll enter RX automatically, so just wait until we can be sure that the ack reception should have finished
        // The timeout consists of a 12-symbol turnaround time, the ack packet duration, and a small margin
        halMcuWaitUs((12 * BASIC_RF_SYMBOL_DURATION) + (BASIC_RF_ACK_DURATION) + (2 * BASIC_RF_SYMBOL_DURATION) + 10);

        // If an acknowledgment has been received (by RxFrmDoneIsr), the ackReceived flag should be set
        status = txState.ackReceived ? SUCCESS : FAILED;

    } else {
        status = SUCCESS;
    }

    // Turn off the receiver if it should not continue to be enabled
    if (!txState.receiveOn) {
        halRfReceiveOff();
    }

    if(status == SUCCESS) {
        txState.txSeqNumber++;
    }

#ifdef SECURITY_CCM
    halRfIncNonceTx();          // Increment nonce value
#endif

    return status;

}


/***********************************************************************************
* @fn          basicRfPacketIsReady
*
* @brief       Check if a new packet is ready to be read by next higher layer
*
* @param       none
*
* @return      uint8_t - true if a packet is ready to be read by higher layer
*/
uint8_t basicRfPacketIsReady(void)
{
    return rxi.isReady;
}


/**********************************************************************************
* @fn          basicRfReceive
*
* @brief       Copies the payload of the last incoming packet into a buffer
*
* @param       pRxData - pointer to data buffer to fill. This buffer must be
*                        allocated by higher layer.
*              len - Number of bytes to read in to buffer
*              rxi - file scope variable holding the information of the last
*                    incoming packet
*
* @return      uint8_t - number of bytes actually copied into buffer
*/
uint8_t basicRfReceive(uint8_t* pRxData, uint8_t len, int16_t* pRssi)
{
    // Accessing shared variables -> this is a critical region
    // Critical region start
    halIntOff();
    memcpy(pRxData, rxi.pPayload, min(rxi.length, len));
    if(pRssi != NULL) {
        if(rxi.rssi < 128){
            *pRssi = rxi.rssi - halRfGetRssiOffset();
        }
        else{
            *pRssi = (rxi.rssi - 256) - halRfGetRssiOffset();
        }
    }
    rxi.isReady = false;
    halIntOn();

    // Critical region end

    return min(rxi.length, len);
}


/**********************************************************************************
* @fn          basicRfGetRssi
*
* @brief       Copies the payload of the last incoming packet into a buffer
*
* @param       none

* @return      int8_t - RSSI value
*/
int8_t basicRfGetRssi(void)
{
    if(rxi.rssi < 128){
        return rxi.rssi - halRfGetRssiOffset();
    }
    else{
        return (rxi.rssi - 256) - halRfGetRssiOffset();
    }
}

/***********************************************************************************
* @fn          basicRfReceiveOn
*
* @brief       Turns on receiver on radio
*
* @param       txState - file scope variable
*
* @return      none
*/
void basicRfReceiveOn(void)
{
    txState.receiveOn = true;
    halRfReceiveOn();
}


/***********************************************************************************
* @fn          basicRfReceiveOff
*
* @brief       Turns off receiver on radio
*
* @param       txState - file scope variable
*
* @return      none
*/
void basicRfReceiveOff(void)
{
    txState.receiveOn = false;
    halRfReceiveOff();
}