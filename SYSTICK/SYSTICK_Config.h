/*
 * SYSTICK_Config.h
 *
 *  Created on: Aug 16, 2024
 *      Author: Dell
 */

#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_

#define SYSTICK_AHB_DIV1    1
#define SYSTICK_AHB_DIV8    0

#define SYSTICK_CLK_SRC   SYSTICK_AHB_DIV8

/*AHB CLK in MHz*/
#define SYSTEM_CLK   16


#define SYSTICK_INTERUPT_PERIODIC     1
#define SYSTICK_INTERUPT_NON_PERIODIC 0

#define SYSTICK_INTERUPT  SYSTICK_INTERUPT_NON_PERIODIC

#endif /* SYSTICK_CONFIG_H_ */
