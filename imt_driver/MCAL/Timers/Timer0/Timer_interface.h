/*
 * Timer_interface.h
 *
 *  Created on: Feb 6, 2024
 *      Author: hp
 */

#ifndef MCAL_TIMERS_TIMER_INTERFACE_H_
#define MCAL_TIMERS_TIMER_INTERFACE_H_

#include "../../../LIB/STD_TYPES.h"

void Timer0_voidInit(void);


u8 Timer0_u8SetCallBack(void (*Copy_pvCallBackFunc) (void));

void Timer0_voidSetCompMatchValue(u8 Copy_u8Value);

#endif /* MCAL_TIMERS_TIMER_INTERFACE_H_ */
