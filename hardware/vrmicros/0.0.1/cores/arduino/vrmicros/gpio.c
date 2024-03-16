#include "gpio.h"

// PC10(8A) = 1000 1010
// PULLUP 	= 0001 1000
void pinMode(int portPin, int mode){

	/*Point to GPIO Port*/
	GPIO_TypeDef *gpioRegister = ((GPIO_TypeDef *)(GPIOA_BASE + ((portPin & GPIOPort_Msk) << 4)));

	/*Check if GPIO Register High*/
	if((portPin & GPIOPin_Msk) - 7 > 0){

		/*Set GPIO Mode to GPIO_CRH*/
		gpioRegister->CRH &= ~(0xF << ((((portPin & GPIOPin_Msk) - 7) * 4) - 4));
		gpioRegister->CRH |= ((mode & MODE_Msk) << ((((portPin & GPIOPin_Msk) - 7) * 4) - 4));

	}else{

		/*Set GPIO Mode to GPIO_CRL*/
		gpioRegister->CRH &= ~(0xF << ((((portPin & GPIOPin_Msk) - 7) * 4) - 4));
		gpioRegister->CRL |= ((mode & MODE_Msk) << ((((portPin & GPIOPin_Msk) - 7) * 4) - 4));

	}

	/*Check if INPUT_PULLUP/DOWN*/
		if((mode & MODE_Msk) == 8){
			if(mode & PULLUP_PULLDOWN_Msk){
				gpioRegister->ODR |= (1U << (portPin & GPIOPin_Msk));
			}else{
				gpioRegister->ODR &= ~(1U << (portPin & GPIOPin_Msk));
			}
		}

}

void digitalWrite(int portPin, int state){

	/*Point to GPIO Port*/
	GPIO_TypeDef *gpioRegister = ((GPIO_TypeDef *)(GPIOA_BASE + ((portPin & GPIOPort_Msk) << 4)));

	/*Set state to Pin*/
	if(state){
		gpioRegister->ODR |= (1U << (portPin & GPIOPin_Msk));
	}
	else{
		gpioRegister->ODR &= ~(1U << (portPin & GPIOPin_Msk));
	}
}

int digitalRead(int portPin){

	/*Point to GPIO Port*/
	GPIO_TypeDef *gpioRegister = ((GPIO_TypeDef *)(GPIOA_BASE + ((portPin & GPIOPort_Msk) << 4)));

	return (gpioRegister->IDR & (1U << (portPin & GPIOPin_Msk)));

}