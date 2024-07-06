/**
 * ************************************************************************
 * @file     	timebase.c
 * @brief    	Timebase for STM32F103x8
 * @version  	V0.0.1
 * @date     	30 March 2024
 * @author		Wattanai Pongtham <wattanaipongtham@gmail.com>
 * ************************************************************************
 */

#include "timebase.h"

volatile uint32_t g_curr_tick;
volatile uint32_t g_curr_tick_p;

void delay(uint32_t delay){
	uint32_t tick_start = get_tick();
	uint32_t wait = delay;

	if(wait < MAX_DELAY){

		wait += (uint32_t)TICK_FREQ;

	}

	while((get_tick() - tick_start) < wait){}

}

uint32_t get_tick(void){

	__disable_irq();
	g_curr_tick_p = g_curr_tick;
	__enable_irq();

	return g_curr_tick_p;
}

static void tick_increment(void){

	g_curr_tick += 1;

}

void timebase_init(void){

	/*Disable global interrupts*/
	__disable_irq();

	/*Load timer with clock cycle per second*/
	SysTick->LOAD = ONE_SEC_VALUE - 1;

	/*Reset count down value to 0*/
	SysTick->VAL = 0;

	/*Use processor clock source*/
	SysTick->CTRL = CTRL_CLKSRC;

	/*Enable interrupt*/
	SysTick->CTRL |= CTRL_TICKINT;

	/*Enable systick*/
	SysTick->CTRL |= CTRL_EN;

	while(!(SysTick->CTRL & CTRL_EN)){}

	/*Enable global interrupts*/
	__enable_irq();
}

void SysTick_Handler(void){
	tick_increment();
}
