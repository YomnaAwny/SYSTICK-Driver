/*
 * SYSTICK_Register.h
 *
 *  Created on: Aug 16, 2024
 *      Author: Dell
 */

#ifndef SYSTICK_REGISTER_H_
#define SYSTICK_REGISTER_H_

#define SYSTICK_BASE_ADD  0xE000E010

typedef volatile struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}SYSTICK_Reg;

#define SYSTICK     ((SYSTICK_Reg *)(SYSTICK_BASE_ADD))

#endif /* SYSTICK_REGISTER_H_ */
