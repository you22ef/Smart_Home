/*

 * Timer_program.c
 *
 *  Created on: Feb 6, 2024
 *      Author: Atya
 */

#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "Timer_register.h"
#include "Timer_private.h"

static void(*TIMER0_pvCallBackFunc)(void) = NULL;

void Timer0_voidInit(void)
{
	/*Choose CTC mode*/
	CLR_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);

	/*Output compare match interrupt enable*/
	SET_BIT(TIMSK, TIMSK_OCIE0);

	/*Set compare match value to 250*/
	OCR0 = 250;

	/*Prescaler: Division by 8 (like enable timer)*/
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);
}


u8 Timer0_u8SetCallBack(void (*Copy_pvCallBackFunc) (void))
{
	u8 Local_u8ErrorStatus = OK;

	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(*TIMER0_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}

//void LED(void)
//{
//	static u16 Local_u16Counter=0;
//	static u8 Local_u8Counter=0;
//	Local_u16Counter++;
//	if(Local_u16Counter == 4000)//every 1 sec do something
//	{
//
//	}
//}

