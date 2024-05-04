#ifndef __TIMEBASE_H__
#define __TIMEBASE_H__

#include <stdint.h>
#include "stm32f103xb.h"

#define	CTRL_EN			(1U<<0)
#define	CTRL_TICKINT	(1U<<1)
#define	CTRL_CLKSRC		(1U<<2)
#define	CTRL_CNTFLG		(1U<<16)

#define	ONE_SEC_VALUE	72000

#define TICK_FREQ		1

#define MAX_DELAY		0xFFFFFFFF

void timebase_init(void);
void delay(uint32_t);
uint32_t get_tick(void);
static void tick_increment(void);

volatile uint32_t g_curr_tick;
volatile uint32_t g_curr_tick_p;

#endif