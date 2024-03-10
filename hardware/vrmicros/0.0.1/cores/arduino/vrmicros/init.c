#include "init.h"

void clock_init(){

	RCC->CR |= (1U<<0); // Enable HSI
	RCC->CR |= (1U<<16); // Enable HSE
	RCC->CR |= (1U<<24); // Enable PLL

	RCC->CFGR |= (1U<<0); // Select HSE As System Clock

	/*Select AHB Prescaler As Not Divided*/
	RCC->CFGR &= ~(1U<<4);
	RCC->CFGR &= ~(1U<<5);
	RCC->CFGR &= ~(1U<<6);
	RCC->CFGR &= ~(1U<<7);

	/*Select APB1 Prescaler As Divided by 2*/
	RCC->CFGR &= ~(1U<<8);
	RCC->CFGR &= ~(1U<<9);
	RCC->CFGR |= (1U<<10);

	/*Select APB2 Prescaler As Divided by 1*/
	RCC->CFGR &= ~(1U<<13);
	RCC->CFGR &= ~(1U<<12);
	RCC->CFGR &= ~(1U<<11);

	/*Select ADC Prescaler As Divided by 2*/
	RCC->CFGR &= ~(1U<<14);
	RCC->CFGR &= ~(1U<<15);

	/*Select PLL Clock Source As HSE*/
	RCC->CFGR |= (1U<<16);

	/*Select HSE for PLL Clock Source As Not Divided*/
	RCC->CFGR &= ~(1U<<17);

	/*Select PLL Multiply by 9*/
	RCC->CFGR &= ~(1U<<21);
	RCC->CFGR |= (1U<<20);
	RCC->CFGR |= (1U<<19);
	RCC->CFGR |= (1U<<18);

	/*Select USB Prescaler As Divided by 1*/
	RCC->CFGR |= (1U<<22);

	/*Select Microcontroller Out As No Clock*/
	RCC->CFGR &= ~(1U<<24);
	RCC->CFGR &= ~(1U<<25);
	RCC->CFGR &= ~(1U<<26);
}

void gpio_init(){
	/*Enable clock to GPIOA, GPIOB, GPIOC*/
	RCC->APB2ENR |= (1U<<2);
	RCC->APB2ENR |= (1U<<3);
	RCC->APB2ENR |= (1U<<4);
}