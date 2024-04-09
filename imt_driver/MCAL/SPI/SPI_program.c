/*
 * SPI_program.c
 *
 *  Created on: Dec 8, 2023
 *      Author: youssef Atya
 */

#include "SPI_interface.h"
#include "SPI_register.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
void SPI_voidInitMaster(void)
{
	/*Master initialization*/
	SET_BIT(SPCR,SPCR_MSTR);

	/*Clock prescaler : divid by 16*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidInitSlave(void)
{
	/*Slave initialization*/
	CLR_BIT(SPCR,SPCR_MSTR);

	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);

}

u8 SPI_u8Transceive(u8 Copy_u8Data)
{
	/*Send the data*/
	SPDR = Copy_u8Data;

	/*Wait (busy waiting) until transfer complete*/
	while(GET_BIT(SPSR,SPSR_SPIF)==0);

	/*Get the exchange data*/
	return SPDR;
}
