#include "gpio.h"

// pin = 4bit-port,4bit-pin
// Assum PC13 = 1000 1101
void pinMode(int pin, int mode){
	volatile unsigned int * gpioRegister = GPIOA_BASE + (pin << 8);

	if((pin & 0x0F) - 7 > 0){

	}
	*gpioRegister |= (1U<<0);
}