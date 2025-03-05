#include "hal_dma.h"

// bit 0 -> 7, indefied the used or not channel x
static uint8_t dma_channel_used = 0;
// dma configuration address
static DMA_DESC __xdata DMA_CH_CONFIG[DMA_CHANNEL_NUM];
// dama isr call back function
static ISR_FUNC_PTR __xdata dma_isr_func[DMA_CHANNEL_NUM] = {NULL};
// dma init
void hal_dma_init(void){
    dma_channel_used = 0;

    // DMA channel 0 config adress
    // DMA0CFGH = (uint16_t)DMA_CH_CONFIG >> 8;
    // DMA0CFGL = (uint16_t)DMA_CH_CONFIG;
    hal_dma_cfg_0(DMA_CH_CONFIG);

    // DMA channel 1-4 config start adress
    // DMA1CFGH = (uint16_t)(DMA_CH_CONFIG + 1) >> 8;
    // DMA1CFGL = (uint16_t)(DMA_CH_CONFIG + 1);
    hal_dma_cfg_1234(DMA_CH_CONFIG + 1);
}

/**
 * @brief get the free dma channel and return the DMA_DESC*
 * @param dma_channel the dma channel 0, 1, 2, 3, 4
 * @return DMA_DESC*
 */
DMA_DESC* hal_dma_get_channel(uint8_t dma_channel){

    return (DMA_CH_CONFIG + dma_channel);
}

/**
 * @brief set the dma channel isr function
 * @param dma_channel the dma channel 0, 1, 2, 3, 4
 * @param isr_func the isr function
 */
void hal_dma_set_ch_isr_func(uint8_t dma_channel, ISR_FUNC_PTR isr_func){
    dma_isr_func[dma_channel] = isr_func;
}

/**
 * @brief dma isr function, when the dma interrupt triggered, this function will be called
 * 
 */
void hal_dam_isr(void) __interrupt(DMA_VECTOR) __using(DMA_VECTOR){

    // check the channel interrupt flag, run the funcation
    for(uint8_t ch_num = 0; ch_num < DMA_CHANNEL_NUM; ch_num++){
        if(hal_dma_check_int_flag(1 >> ch_num)){
            if(dma_isr_func[ch_num] != NULL){
                dma_isr_func[ch_num]();
            }
        }
    }

    // clear the interrupt flag
    hal_dma_clear_all_int_flag();

}

