#include "init.h"

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

	/*PREDIV1 Not Divided*/
	RCC->CFGR &= ~(1U << (17));

	/*PLL Miltiply by 9*/
	RCC->CFGR |= (7U << (18));

	/*Enable PLL*/
	RCC->CR |= (1U << 24);
	while (!(RCC->CR & (1U << 25)));

	/*Select PLL as System Clock*/
	RCC->CFGR |= (2U << 0);
	while (!(RCC->CFGR & (2U << 2)));
}

void gpio_init(){
	/*Enable clock to GPIOA, GPIOB, GPIOC*/
	RCC->APB2ENR |= (1U<<2);
	RCC->APB2ENR |= (1U<<3);
	RCC->APB2ENR |= (1U<<4);
}