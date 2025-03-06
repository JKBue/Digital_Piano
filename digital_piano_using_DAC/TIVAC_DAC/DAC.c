/*
 * DAC.c
 *
 *  Created on: Dec 4, 2024
 *      Author: aanha
 */
#include <stdint.h>
#include "tm4c123gh6pm.h"


void GPIOPortB_Init() {
    SYSCTL_RCGC2_R |= 0b10;                // 1) turns on clock E
    GPIO_PORTB_AMSEL_R &= ~(0xFF);            // 3) disable analog function on PE5-0
    GPIO_PORTB_PCTL_R &= ~(0xFF);             // 4) enable regular GPIO
    GPIO_PORTB_DIR_R |= 0xFF;                 // 5) outputs on PE5-0
    GPIO_PORTB_AFSEL_R &= ~(0xFF);            // 6) regular function on PE5-0
    GPIO_PORTB_DEN_R |= 0xFF;                 // 7) enable digital on PE5-0
}

void GPIOPortD_Init() {
    SYSCTL_RCGC2_R |= 0b1000;                 // 1) turns on clock D
    GPIO_PORTD_AMSEL_R &= ~(0xFF);            // 3) disable analog function on PD5-0
    GPIO_PORTD_PCTL_R &= ~(0xFF);             // 4) enable regular GPIO
    GPIO_PORTD_DIR_R |= 0xFF;                 // 5) outputs on PD5-0
    GPIO_PORTD_AFSEL_R &= ~(0xFF);            // 6) regular function on PD5-0
    GPIO_PORTD_DEN_R |= 0xFF;                 // 7) enable digital on PD5-0
}

void DAC_Init(void) {                         // main will call this function to init all the ports
    GPIOPortB_Init();
   // GPIOPortD_Init();
}

void DAC_Out(uint8_t data) {           // write 4-bit into ports to send data
    // clear (&=) and load (|=) bit into pins
    GPIO_PORTB_DATA_R &= ~(0b1111);   // pin 2 no worky

    //uint8_t dataLeft = data & 0b1100;  // will save the left two values
    //dataLeft = dataLeft << 1;          // moves over 1
    //uint8_t dataRight = data & 0b0011;
    //uint8_t newData = dataLeft | dataRight;

    GPIO_PORTB_DATA_R |= data;

}

