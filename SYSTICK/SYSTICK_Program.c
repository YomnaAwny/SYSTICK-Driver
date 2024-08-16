/*
 * SYSTICK_Program.c
 *
 *  Created on: Aug 16, 2024
 *      Author: Dell
 */


#include "SYSTICK_Interface.h"


void SYSTICK_Init(void)
{
#if SYSTICK_CLK_SRC == SYSTICK_AHB_DIVD1
	SYSTICK->CTRL |=(1<<2);
#elif SYSTICK_CLK_SRC == SYSTICK_AHB_DIVD8
	SYSTIC->CTRL &=~(1<<2);
#endif
}

void SYSTICK_delayMilliSec(u32 ms)
{
#if SYSTICK_CLK_SRC == SYSTICK_AHB_DIV1
	SYSTICK->LOAD = SYSTEM_CLK * ms*1000 -1;
#elif SYSTICK_CLK_SRC == SYSTICK_AHB_DIV8
	SYSTICK->LOAD = SYSTEM_CLK/8 * ms*1000 -1;
#endif

	SYSTICK->CTRL |=(1<<0);//enable counter
	while(!(SYSTICK->CTRL &(1<<16)>>16));
	SYSTICK->CTRL &=~(1<<0);//stop counter

}
void SYSTICK_delayMicroSec(u32 us)
{
#if SYSTICK_CLK_SRC == SYSTICK_AHB_DIV1
	SYSTICK->LOAD = SYSTEM_CLK * us*1000 -1;
#elif SYSTICK_CLK_SRC == SYSTICK_AHB_DIV8
	SYSTICK->LOAD = SYSTEM_CLK/8 * us*1000 -1;
#endif

	SYSTICK->CTRL |=(1<<0);//enable counter
	while(!(SYSTICK->CTRL &(1<<16)>>16));
	SYSTICK->CTRL &=~(1<<0);//stop counter
}

void SYSTICK_getRemainingTime(void)
{
	return SYSTICK->VAL;
}
void SYSTICK_getElapsedTime(void)
{
	return ((SYSTICK->LOAD)-(SYSTICK->VAL));
}

void SYSTICK_EnableInterrupt(void)
{
	SYSTICK->CTRL |=(1<<1);
}

void (*SYSTICK_CallBack)(void);

void SYSTICK_StartCountMilliSecIT(u32 ms,void(*ptr)(void)){

	    SYSTICK_CallBack= ptr;
	    SYSTICK_delayMicroSec(ms+1);
	    SYSTICK_EnableInterrupt();


}
void SYSTICK_StartCountMicroSecIT(u32 us,void(*ptr)(void))
{
	SYSTICK_CallBack= ptr;
	SYSTICK_delayMicroSec(us+1);
	SYSTICK_EnableInterrupt();

}

void SysTick_Handler(void){

	SYSTICK_CallBack();

#if SYSTICK_INTERUPT == SYSTICK_INTERUPT_NON_PERIODIC
		SYSTICK->CTRL &=~(1<<0);//stop counter
        SYSTICK->CTRL &=~(1<<1);
#endif
}
