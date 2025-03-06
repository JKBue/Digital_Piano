

/**
 * main.c
 */
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "PLL.h"
#include "DAC.h"
#include "Piano.h"
#include "Sound.h"

int main(void)
{
  //uint8_t Data = 1;  // 0 to 15 DAC output

  PLL_Init(Bus80MHz);  // set system clock to 80 MHz

  //DAC_Init();
  Piano_Init();
  Sound_Init();

  int curNote = 0;

  while(1) {
    //DAC_Out(Data);    was used to test DAC
    curNote = Piano_In();
    Sound_Play(curNote);
    //Data = 0x0F & (Data+1);  // 0, 1, 2, ..., 14, 15, 0, 1, 2, ...
  }
}
