/*
 * TWI_interface.h
 *
 *  Created on: Feb 1, 2024
 *      Author: hp
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

typedef enum
{
	NoError,
	StartConditionErr,
	RepatedStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,

}TWI_ErrStatus;


void TWI_voidMasterInit(u8 Copy_u8S1aveAddress);

void TWI_voidSlaveInit(u8 Copy_u8S1aveAddress);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatedStart(void);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8S1aveAddress);

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8S1aveAddress);

TWI_ErrStatus TWI_MsterWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_MsterReadDataByte(u8 *Copy_u8DataByte);

void TWI_SendStopCondition(void);

#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
