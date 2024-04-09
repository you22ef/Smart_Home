/*
 * SPI_interface.h
 *
 *  Created on: Dec 8, 2023
 *      Author: hp
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

void SPI_voidInitMaster(void);

void SPI_voidInitSlave(void);

u8 SPI_u8Transceive(u8 Copy_u8Data);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
