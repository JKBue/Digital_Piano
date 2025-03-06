/*
 * Sound.c
 *
 *  Created on: Dec 10, 2024
 *      Author: aanha
 */
#include <stdint.h>
#include "tm4c123gh6pm.h"


void Sound_Init(void) {
    DAC_Init();
    SysTick_Init();
}

void Sound_Play(int curnote) {
    int period = 0;

    if (curnote == 523) {           // plays note c
        // 80m/523 (sytic count for whole sin wave) / by 32 to get count
        period = (80000000/523)/32;
    }
    else if (curnote == 392) {      // plays note g
        period = (80000000/392)/32;
    }
    else if (curnote == 294) {      // plays note d
        period = (80000000/294)/32;
    }
    else {
        period = 0;
    }

    NVIC_ST_RELOAD_R = period-1;
}
