/*
 * SYSTICK_Interface.h
 *
 *  Created on: Aug 16, 2024
 *      Author: Dell
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "SYSTICK_Register.h"
#include "SYSTICK_Config.h"

void SYSTICK_Init(void);

void SYSTICK_delayMilliSec(u32 ms);
void SYSTICK_delayMicroSec(u32 us);

u32 SYSTICK_getRemainingTime(void);
u32 SYSTICK_getElapsedTime(void);

void SYSTICK_EnableInterrupt(void);

void SYSTICK_StartCountMilliSecIT(u32 ms,void(*ptr)(void));
void SYSTICK_StartCountMicroSecIT(u32 us,void(*ptr)(void));


#endif /* SYSTICK_INTERFACE_H_ */
