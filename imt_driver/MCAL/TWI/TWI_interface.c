/*

* TWI_interface.c
 *
 *  Created on: Feb 1, 2024
 *      Author: Youssef Atya
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TWI_register.h"
#include "TWI_private.h"
#include "TWI_interface.h"

/*pass 0 in the slaveaddress argument if master will not be addressed*/
void TWI_voidMasterInit(u8 Copy_u8S1aveAddress)
{
	/*Set Clock frequancy to 400kbps*/
	/*Set TWDR to 2*/
	TWDR = 2;


	/*Set Clock frequancy to 400kbps*/
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	if(Copy_u8S1aveAddress !=0)
	{
		TWAR = Copy_u8S1aveAddress<<1;
	}

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);

}

void TWI_voidSlaveInit(u8 Copy_u8S1aveAddress)
{
	/*Initialize the node address*/
	TWAR = Copy_u8S1aveAddress<<1;

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);

}

TWI_ErrStatus TWI_SendStartCondition(void)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Send start condition on the bus*/
	SET_BIT(TWCR, TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR, TWCR_TWINT);

	/*wait until the interrupt flag is raised again and the previous operation is complete*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check the operation status in the status register */
	if((TWSR & 0xF8) != START_ACK)
	{
		Local_ErrStatus = StartConditionErr;
	}
	else
	{
		/*Do Nothing*/
	}

	return Local_ErrStatus;


}

TWI_ErrStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Send start condition on the bus*/
	SET_BIT(TWCR, TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR, TWCR_TWINT);

	/*wait until the interrupt flag is raised again and the previous operation is complete*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check the operation status in the status register */
	if((TWSR & 0xF8) != REP_START_ACK)
	{
		Local_ErrStatus = RepatedStartErr;
	}
	else
	{
		/*Do Nothing*/
	}

	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8S1aveAddress)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Clear the start condition bit*/
	CLR_BIT(TWCR, TWCR_TWSTA);

	/*Set the slave address in 7 MSB in the data register*/
	TWDR = Copy_u8S1aveAddress<<1;

	CLR_BIT(TWDR,0); /*For write request*/

	/*Clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR, TWCR_TWINT);

	/*wait until the interrupt flag is raised again and the previous operation is complete*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check the operation status in the status register */
	if((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrStatus = SlaveAddressWithWriteErr;
	}
	else
	{
		/*Do Nothing*/
	}

	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8S1aveAddress)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Clear the start condition bit*/
	CLR_BIT(TWCR, TWCR_TWSTA);

	/*Set the slave address in 7 MSB in the data register*/
	TWDR = Copy_u8S1aveAddress<<1;

	SET_BIT(TWDR,0); /*For read request*/

	/*Clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR, TWCR_TWINT);

	/*wait until the interrupt flag is raised again and the previous operation is complete*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check the operation status in the status register */
	if((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrStatus = SlaveAddressWithReadErr;
	}
	else
	{
		/*Do Nothing*/
	}

	return Local_ErrStatus;
}

TWI_ErrStatus TWI_MsterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Write the data byte*/
	TWDR = Copy_u8DataByte;

	/*Clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR, TWCR_TWINT);

	/*wait until the interrupt flag is raised again and the previous operation is complete*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check the operation status in the status register */
	if((TWSR & 0xF8) != MSTR_WR_BYTE_ACK)
	{
		Local_ErrStatus = MasterWriteByteErr;
	}
	else
	{
		/*Do Nothing*/
	}

	return Local_ErrStatus;
}

TWI_ErrStatus TWI_MsterReadDataByte(u8 *Copy_u8DataByte)
{

	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Enable master generating acknowledge bit after receiving the data*/
	SET_BIT(TWCR,TWCR_TWEA);

	/*Clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR, TWCR_TWINT);

	/*wait until the interrupt flag is raised again and the previous operation is complete*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check the operation status in the status register */
	if((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_ErrStatus = MasterReadByteErr;
	}
	else
	{
		/*Read the received data*/
		*Copy_u8DataByte = TWDR;
	}

	return Local_ErrStatus;
}

void TWI_SendStopCondition(void)
{
	/*Generate stop condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTO);

	/*Clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR, TWCR_TWINT);

}
