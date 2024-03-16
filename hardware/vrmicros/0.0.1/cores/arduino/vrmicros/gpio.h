#ifndef	__VRMICROS_GPIO
#define __VRMICROS_GPIO

#include "stm32f103xb.h"

#define GPIOPin_Msk			0x0F
#define GPIOPort_Msk		0xF0
#define MODE_Msk			0x0F
#define PULLUP_PULLDOWN_Msk	0xF0

#define PC10	0x8A
#define PC13	0x8D

#define INPUT	4
#define	INPUT_PULLUP	24
#define	INPUT_PULLDOWN	8
#define	OUTPUT	7

#define	HIGH	1
#define	LOW 	0

void pinMode(int, int);
void digitalWrite(int, int);
int digitalRead(int);

#endif