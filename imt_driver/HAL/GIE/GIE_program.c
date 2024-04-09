/*
 * GIE_program.c
 *
 *  Created on: Oct 19, 2023
 *      Author: hp
 */

#include "GIE_interface.h"
#include "GIE_register.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}
