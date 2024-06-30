#include "init.h"

void Error_Handler(void);

void Error_Handler(void)
{
  while (1)
  {
    
  }
}


void clock_init(){

	/*Enable HSE ON*/
	RCC->CR |= (1U << 16);  
	while (!(RCC->CR & (1U << 17)));

	/*Enable Power Clock Interface*/
	RCC->APB1ENR |= (1U << 28);

	/*Enable Prefetch Buffer*/
	FLASH->ACR |= (1U << 4);

	/*Config Flash Latency as 2 Wait States*/
	FLASH->ACR |=(2U << 0);
	
	/*Disable PLL*/
	RCC->CR &= ~(1U<<24);
	while ((RCC->CR & (1U << 25)));

	/*Select HSE as Clock Source*/
	RCC->CFGR |= (1U << (16));

	/*HSE Entry for PLL Not Divided*/
	RCC->CFGR &= ~(1U << (17));

	/*HSE Entry for PLL Not Divided*/
	RCC->CFGR |= (4U << (8));

	/*PLL Miltiply by 9*/
	RCC->CFGR |= (7U << (18));

	/*Enable PLL*/
	RCC->CR |= (1U << 24);
	while (!(RCC->CR & (1U << 25)));

	/*Select PLL as System Clock*/
	RCC->CFGR |= (2U << 0);
	while (!(RCC->CFGR & (2U << 2)));

	/*USBPRE Divided by 1.5*/
	RCC->CFGR &= ~(1U << 22);
}

void gpio_init(){
	/*Enable Clock to GPIOA, GPIOB, GPIOC*/
	RCC->APB2ENR |= (1U<<0);
	RCC->APB2ENR |= (1U<<2);
	RCC->APB2ENR |= (1U<<3);
	RCC->APB2ENR |= (1U<<4);
	RCC->APB2ENR |= (1U<<5);
}

void USB_enable(){

	/*Enable Clock to USB*/
	RCC->APB1ENR |= (1U<<23);
}
