/***********************************************************************************
  Filename:     hal_system.h

  Description:  hal system library header file

***********************************************************************************/

#ifndef __HAL_SYSTEM_H__
#define __HAL_SYSTEM_H__

/***********************************************************************************
* INCLUDES
*/
#include "hal_defs.h"

/***********************************************************************************
 * CONSTANTS AND DEFINES
 */
enum {                  // Input values to halMcuSetLowPowerMode()
    HAL_MCU_LPM_0,
    HAL_MCU_LPM_1,
    HAL_MCU_LPM_2,
    HAL_MCU_LPM_3,
    HAL_MCU_LPM_4
};


enum {                  // Return values of halMcuGetResetCause()
    HAL_MCU_RESET_CAUSE_POR,
    HAL_MCU_RESET_CAUSE_EXTERNAL,
    HAL_MCU_RESET_CAUSE_WATCHDOG
};


/***********************************************************************************
 * GLOBAL FUNCTIONS
 */

void halMcuInit(void);
void halMcuWaitUs(uint16_t usec);
void halMcuWaitMs(uint16_t msec);
void halMcuSetLowPowerMode(uint8_t mode);
void halMcuReset(void);
// uint8_t halMcuGetResetCause(void);

/**********************************************************************************/
#endif