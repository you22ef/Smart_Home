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


void PWM_voidInit(void)
{

	/*Choose Fast PWM mode*/
	SET_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);

	/*Clear on compare match , set on top*/
	SET_BIT(TCCR0,5);
	CLR_BIT(TCCR0,4);

	/*Prescaler: Division by 64 (like enable timer)*/
	SET_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

}


void PWM_voidSetCompMatchValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}




