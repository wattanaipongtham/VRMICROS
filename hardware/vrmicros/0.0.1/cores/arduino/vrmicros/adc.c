/**
 * ************************************************************************
 * @file     	adc.c
 * @brief    	Analog to Digital Conversion For STM32F103x8 using
 * 				Using single conversion
 * @version  	V0.0.1
 * @date     	6 May 2024
 * @author		Wattanai Pongtham <wattanaipongtham@gmail.com>
 * ************************************************************************
 */
#include "pin.h"
#include "adc.h"
int analogRead(int portPin){

	/*Point to GPIO Port*/
	GPIO_TypeDef *gpioRegister = ((GPIO_TypeDef *)(GPIOA_BASE + ((portPin & GPIOPort_Msk) << 4)));

	/*Check if GPIO Register High*/
	if((portPin & GPIOPin_Msk) - 7 > 0){

		/*Set Analog Mode to GPIO_CRH*/
		gpioRegister->CRH &= ~(0xF << ((((portPin & GPIOPin_Msk) - 7) * 4) - 4));

	}else{

		/*Set Analog Mode to GPIO_CRL*/
		gpioRegister->CRL &= ~(0xF << ((((portPin & GPIOPin_Msk)) * 4) - 4));

	}

	/*Enable ADC1*/
	RCC->APB2ENR |= (1U << 9);

	/*Disable Scan Mode*/
	ADC1->CR1 &= ~(1U << 8);

	/*Select Single Mode*/
	ADC1->CR2 &= ~(1U << 1);

	/**/
	ADC1->SQR3 |= ((portPin & GPIOPin_Msk) << 0);
}