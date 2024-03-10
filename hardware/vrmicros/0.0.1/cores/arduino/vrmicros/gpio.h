#ifndef	__VRMICROS_GPIO
#define __VRMICROS_GPIO

#include "stm32f103xb.h"

#define INPUT	1
#define	INPUT_PULLUP	24
#define	INPUT_PULLDOWN	8
#define	OUTPUT	7

void pinMode(int, int);
void digitalWrite(int);
void digitalRead(int);

#endif