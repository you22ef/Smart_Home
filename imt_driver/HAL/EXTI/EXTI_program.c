/*
 * EXTI_program.c
 *
 *  Created on: Oct 19, 2023
 *      Author: hp
 */

#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_config.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void EXTI_voidint0Inti(void)
{
	/*Set sense control for INT0 to falling edge*/
#if INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE == FALLING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error "Wrong INT0_SENSE configuration option"
#endif

	/*Specific interrupt enable for INT0*/
#if INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong INT0_INITIAL_STATE in option"
#endif
}

void EXTI_voidint1Inti(void)
{
	/*Set sense control for INT0 to falling edge*/
#if INT1_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);

	SET_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE == FALLING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
#error "Wrong INT1_SENSE configuration option"
#endif

	/*Specific interrupt enable for INT0*/
#if INT1_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);
#elif INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);
#else
#error "Wrong INT1_INITIAL_STATE in option"
#endif
}

/*
void EXTI_voidint1Inti(void)
{

	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(GICR,GICR_INT1);
}
*/
void EXTI_voidint2Inti(void)
{
	/*Set sense control for INT2 to falling edge*/
	SET_BIT(MCUCSR,MCUCSR_INT2);
	/*Specific interrupt enable for INT2*/
	SET_BIT(GICR,GICR_INT2);
}
