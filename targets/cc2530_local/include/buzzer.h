#ifndef __BUZZER_H__
#define __BUZZER_H__

#include "cc2530io_bitdef.h"
#include "cc2530.h"
#include "sys_config.h"


#define     buzzer_stop()           (T1CTL &= ~(T1CTL_MODE))
#define     buzzer_start()          (buzzer_stop(), T1CTL |= T1CTL_MODE_MODULO)  

void buzzer_init(void);

void buzzer_set_hz(uint16_t hz);

void buzzer_test(void (*delay_ms)(uint16_t hz));
#endif //f