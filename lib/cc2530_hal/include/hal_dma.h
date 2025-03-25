#ifndef __HAL_DMA_H__
#define __HAL_DMA_H__

#include "hal_defs.h"

#define HAL_DMA_CHANNEL_NUM                             5

//DMA Trigger signal
#define HAL_DMA_TRIG_NONE                               0    // No trigger, setting DMAREQ.DMAREQx bit starts transfer
#define HAL_DMA_TRIG_PREV                               1    // DMA channel is triggered by completion of previous channel
#define HAL_DMA_TRIG_T1_CH0                             2    // Timer 1, compare, channel 0
#define HAL_DMA_TRIG_T1_CH1                             3    // Timer 1, compare, channel 1
#define HAL_DMA_TRIG_T1_CH2                             4    // Timer 1, compare, channel 2
#define HAL_DMA_TRIG_T2_EVENT1                          5    // Timer 2, event pulse 1
#define HAL_DMA_TRIG_T2_EVENT2                          6    // Timer 2, event pulse 2
#define HAL_DMA_TRIG_T3_CH0                             7    // Timer 3, compare, channel 0
#define HAL_DMA_TRIG_T3_CH1                             8    // Timer 3, compare, channel 1
#define HAL_DMA_TRIG_T4_CH0                             9    // Timer 4, compare, channel 0
#define HAL_DMA_TRIG_T4_CH1                             10   // Timer 4, compare, channel 1
#define HAL_DMA_TRIG_ST                                 11   // Sleep Timer compare
#define HAL_DMA_TRIG_IOC_0                              12   // Port 0 I/O pin input transition
#define HAL_DMA_TRIG_IOC_1                              13   // Port 1 I/O pin input transition
#define HAL_DMA_TRIG_URX0                               14   // USART0 RX complete
#define HAL_DMA_TRIG_UTX0                               15   // USART0 TX complete
#define HAL_DMA_TRIG_URX1                               16   // USART1 RX complete
#define HAL_DMA_TRIG_UTX1                               17   // USART1 TX complete
#define HAL_DMA_TRIG_FLASH                              18   // Flash data write complete
#define HAL_DMA_TRIG_RADIO                              19   // RF packet byte received/transmit
#define HAL_DMA_TRIG_ADC_CHALL                          20   // ADC end of a conversion in a sequence, sample ready
#define HAL_DMA_TRIG_ADC_CH0                            21   // ADC end of conversion channel 0 in sequence, sample ready
#define HAL_DMA_TRIG_ADC_CH1                            22   // ADC end of conversion channel 1 in sequence, sample ready
#define HAL_DMA_TRIG_ADC_CH2                            23   // ADC end of conversion channel 2 in sequence, sample ready
#define HAL_DMA_TRIG_ADC_CH3                            24   // ADC end of conversion channel 3 in sequence, sample ready
#define HAL_DMA_TRIG_ADC_CH4                            25   // ADC end of conversion channel 4 in sequence, sample ready
#define HAL_DMA_TRIG_ADC_CH5                            26   // ADC end of conversion channel 5 in sequence, sample ready
#define HAL_DMA_TRIG_ADC_CH6                            27   // ADC end of conversion channel 6 in sequence, sample ready
#define HAL_DMA_TRIG_ADC_CH7                            28   // ADC end of conversion channel 7 in sequence, sample ready
#define HAL_DMA_TRIG_ENC_DW                             29   // AES encryption processor requests download input data
#define HAL_DMA_TRIG_ENC_UP                             30   // AES encryption processor requests upload output data
#define HAL_DMA_TRIG_DBG_BW                             31   // Debug interface burst write

// DMA channel number
#define HAL_DMA_CHANNEL_0                	            0
#define HAL_DMA_CHANNEL_1                	            1
#define HAL_DMA_CHANNEL_2                	            2
#define HAL_DMA_CHANNEL_3                	            3
#define HAL_DMA_CHANNEL_4                	            4

// DMA channel number mask
#define HAL_DMA_CHANNEL_0_mask             	            0x01
#define HAL_DMA_CHANNEL_1_mask             	            0x02
#define HAL_DMA_CHANNEL_2_mask             	            0x04
#define HAL_DMA_CHANNEL_3_mask             	            0x08
#define HAL_DMA_CHANNEL_4_mask             	            0x10

// DMA arm channel_num must be one of the above HAL_DMA_CHANNEL_x
#define hal_dma_arm(ch_mask)       	                (DMAARM |= (ch_mask)) // DMA arm
#define hal_dma_disarm(ch_mask)   	                (DMAARM &= ~(ch_mask)) // DMA disarm
// DMA ready is ready or not for the next transmit, 0 : means ready, 1: means not ready
#define hal_dma_ready(ch_mask)   	                (DMAARM & (ch_mask))

// DMA interrupt flag 
#define hal_dma_check_ch_int_flag(ch_mask)          (DMAIRQ & (ch_mask))
// DMA clear interrupt flag
#define hal_dma_clear_ch_int_flag(ch_mask)          (DMAIRQ &= ~(ch_mask))
// Clear all interrupt flag
#define hal_dma_clear_all_int_flag()                (DMAIRQ = 0)

// DMA softwore trigger, channel_num must be one of the above HAL_DMA_CHANNEL_x
#define hal_dma_soft_trig(ch_mask)                  (DMAREQ |= (ch_mask)) // DMA software trigger

#define hal_dma_cfg_0(cfg_adr)                      (DMA0CFGH = (uint16_t)(cfg_adr) >> 8, DMA0CFGL = (uint16_t)(cfg_adr))
#define hal_dma_cfg_1234(cfg_adr)                   (DMA1CFGH = (uint16_t)(cfg_adr) >> 8, DMA1CFGL = (uint16_t)(cfg_adr))

// DMA configure define
#define HAL_DMA_VLEN_FIXED               	            0x00 // Use LEN for transfer count
#define HAL_DMA_VLEN_1_P_VALOFFIRST      	            0x01 // Transfer the first byte + the number of bytes indicated by the first byte
#define HAL_DMA_VLEN_VALOFFIRST          	            0x02 // Transfer the number of bytes indicated by the first byte (starting with the first byte)
#define HAL_DMA_VLEN_1_P_VALOFFIRST_P_1  	            0x03 // Transfer the first byte + the number of bytes indicated by the first byte + 1 more byte
#define HAL_DMA_VLEN_1_P_VALOFFIRST_P_2  	            0x04 // Transfer the first byte + the number of bytes indicated by the first byte + 2 more bytes

#define HAL_DMA_WORDSIZE_BYTE            	            0x00 // Transfer a byte at a time
#define HAL_DMA_WORDSIZE_WORD            	            0x01 // Transfer a 16-bit word at a time

#define HAL_DMA_TMODE_SINGLE             	            0x00 // Transfer a single byte/word after each DMA trigger
#define HAL_DMA_TMODE_BLOCK              	            0x01 // Transfer block of data (length len) after each DMA trigger
#define HAL_DMA_TMODE_SINGLE_REPEATED    	            0x02 // Transfer single byte/word (after len transfers, rearm DMA)
#define HAL_DMA_TMODE_BLOCK_REPEATED     	            0x03 // Transfer block of data (after len transfers, rearm DMA)

#define HAL_DMA_SRCINC_0                 	            0x00 // Increment source pointer by 0 bytes/words after each transfer
#define HAL_DMA_SRCINC_1                 	            0x01 // Increment source pointer by 1 bytes/words after each transfer
#define HAL_DMA_SRCINC_2                 	            0x02 // Increment source pointer by 2 bytes/words after each transfer
#define HAL_DMA_SRCINC_M1                	            0x03 // Decrement source pointer by 1 bytes/words after each transfer

#define HAL_DMA_DESTINC_0                	            0x00 // Increment destination pointer by 0 bytes/words after each transfer
#define HAL_DMA_DESTINC_1                	            0x01 // Increment destination pointer by 1 bytes/words after each transfer
#define HAL_DMA_DESTINC_2                	            0x02 // Increment destination pointer by 2 bytes/words after each transfer
#define HAL_DMA_DESTINC_M1               	            0x03 // Decrement destination pointer by 1 bytes/words after each transfer

#define HAL_DMA_IRQMASK_DISABLE          	            0x00 // Disable interrupt generation
#define HAL_DMA_IRQMASK_ENABLE           	            0x01 // Enable interrupt generation upon DMA channel done

#define HAL_DMA_M8_USE_8_BITS            	            0x00 // Use all 8 bits for transfer count
#define HAL_DMA_M8_USE_7_BITS            	            0x01 // Use 7 LSB for transfer count

#define HAL_DMA_PRI_LOW                  	            0x00 // Low, CPU has priority
#define HAL_DMA_PRI_GUARANTEED           	            0x01 // Guaranteed, DMA at least every second try
#define HAL_DMA_PRI_HIGH                 	            0x02 // High, DMA has priority
#define HAL_DMA_PRI_ABSOLUTE             	            0x03 // Highest, DMA has priority. Reserved for DMA port access.

typedef struct {
    uint8_t SRCADDRH;
    uint8_t SRCADDRL;
    uint8_t DESTADDRH;
    uint8_t DESTADDRL;

    uint8_t LENH : 5;
    uint8_t VLEN : 3;
    
    uint8_t LENL : 8;

    uint8_t TRIG : 5;
    uint8_t TMODE : 2;
    uint8_t WORDSIZE : 1;

    uint8_t PRIORITY : 2;
    uint8_t M8 : 1;
    uint8_t IRQMASK : 1;
    uint8_t DESTINC : 2;
    uint8_t SRCINC : 2;
} HAL_DMA_DESC;

// // init dma 
// void hal_dma_init(void);

// // register the the dma channel isr funcation
// void hal_dma_set_ch_isr(uint8_t dma_channel, ISR_FUNC_PTR isr_func);

// // dma interrupt funcation
// void hal_dma_int_funcation(void) __interrupt(DMA_VECTOR) __using(DMA_VECTOR);

#endif