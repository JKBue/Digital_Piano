/*
 * Piano.c
 *
 *  Created on: Dec 9, 2024
 *      Author: aanha
 */
#include <stdint.h>
#include "tm4c123gh6pm.h"


void GPIOPortE_Init() {
    SYSCTL_RCGC2_R |= 0b10000;                   // 1) turns on clock B
    GPIO_PORTE_AMSEL_R &= ~(0xFF);            // 3) disable analog function on PB5-0
    GPIO_PORTE_PCTL_R &= ~(0xFF);             // 4) enable regular GPIO
    GPIO_PORTE_DIR_R &= ~(0xFF);                 // 5) outputs on PB5-0
    GPIO_PORTE_AFSEL_R &= ~(0xFF);            // 6) regular function on PB5-0
    GPIO_PORTE_DEN_R |= 0xFF;                 // 7) enable digital on PB5-0
}
/*void GPIOPortB_Init() {
    SYSCTL_RCGC2_R |= 0b10000;                // 1) turns on clock E
    GPIO_PORTE_AMSEL_R &= ~(0xFF);            // 3) disable analog function on PE5-0
    GPIO_PORTE_PCTL_R &= ~(0xFF);             // 4) enable regular GPIO
    GPIO_PORTE_DIR_R &= ~(0xFF);                 // 5) outputs on PE5-0
    GPIO_PORTE_AFSEL_R &= ~(0xFF);            // 6) regular function on PE5-0
    GPIO_PORTE_DEN_R |= 0xFF;                 // 7) enable digital on PE5-0
}*/

void Piano_Init(void) {
    //GPIOPortE_Init();
    GPIOPortE_Init();
}

int Piano_In(void) {
    int note = 0;
    if (GPIO_PORTE_DATA_R == 0b001) { // pin 0 pressed
        note = 523;     // c
    }
    else if (GPIO_PORTE_DATA_R == 0b010) { // pin 1 pressed
        note = 392;    // g
    }
    else if (GPIO_PORTE_DATA_R == 0b100) { // pin 2 pressed
        note = 294;    // d
    }

    return note;
}



