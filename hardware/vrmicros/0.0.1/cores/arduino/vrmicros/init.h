#ifndef __VRMICROS_INIT
#define __VRMICROS_INIT

#include "stm32f103xb.h"

void Error_Handler(void);
void clock_init(void);
void gpio_init(void);
void USB_enable(void);

#endif