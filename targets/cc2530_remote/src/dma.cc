#include "dma.h"

// bit 0 -> 7, indefied the used or not channel x
static uint8_t dma_channel_used = 0;

static DMA_DESC __xdata DMA_CH_CONFIG[DMA_CHANNEL_NUM];

// dma init
void dma_init(void){
    dma_channel_used = 0;

    // DMA channel 0 config adress
    DMA0CFGH = (uint16_t)DMA_CH_CONFIG >> 8;
    DMA0CFGL = (uint16_t)DMA_CH_CONFIG;

    // DMA channel 1-4 config start adress
    DMA1CFGH = (uint16_t)(DMA_CH_CONFIG + 1) >> 8;
    DMA1CFGL = (uint16_t)(DMA_CH_CONFIG + 1);
}

// arm the dma channel
void dma_arm_channel(uint8_t channel_num){
    DMAARM |= channel_num;
}

// disarm the dma channel
void dma_disarm_channel(uint8_t channel_num){
    DMAARM &= ~channel_num;
}

// get the free dma channel and return the DMA_DESC*
DMA_DESC* dma_get_free_channel(uint8_t *dma_channel){

    uint8_t i = 0;
    for(; i < DMA_CHANNEL_NUM; i++){
        
        if (dma_channel_used & (1 << i)){
            continue;
        }else{
            break;
        }

    }

    if (i == DMA_CHANNEL_NUM){
        return 0;
    }else{
        *dma_channel = 1 << i;
        dma_channel_used |= *dma_channel;
        return (DMA_CH_CONFIG + i);
    }
}

// dma channel is free or not
uint8_t dma_channel_is_used(uint8_t channel_num){
    if(dma_channel_used & channel_num){
        return 1;
    }else{
        return 0;
    }
}

void dma_free_channel(uint8_t channel_num){
    DMAARM &= ~channel_num; // disarm the dma channel
    dma_channel_used &= ~channel_num; // clear the flag of dma channel used
}


void dma_int_funcation(void) __interrupt(DMA_VECTOR) __using(DMA_VECTOR){
    
}