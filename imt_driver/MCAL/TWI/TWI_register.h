/*
 * TWI_register.h
 *
 *  Created on: Jan 29, 2024
 *      Author: hp
 */

#ifndef MCAL_TWI_TWI_REGISTER_H_
#define MCAL_TWI_TWI_REGISTER_H_

#define	TWCR	*((volatile u8*)0x56)	/*TWI Control register*/

#define	TWCR_TWINT	7					/*Interrupt Flag*/
#define	TWCR_TWEA	6					/*Enable Acknowledge*/
#define	TWCR_TWSTA	5					/*Start Conditiciln*/
#define	TWCR_TWSTO	4					/*Stop Condition*/
#define	TWCR_TWWC	3					/*Write Collision*/
#define	TWCR_TWEN	2					/*Enable*/
#define	TWCR_TWIE	0					/*Interrupt Enable*/

#define TWDR	*((volatile u8*)0x23)	/*TWI Data Register*/

#define TWAR	*((volatile u8*)0x22)	/*TWI Address Register*/
#define TWAR_TWGCE 0					/*General Call recognition Enable*/

#define TWSR	*((volatile u8*)0x21)	/*TWI Status Register*/
#define TWSR_TWPS0 0 					/*Prescaler BitO*/
#define TWSR_TWPS1 1					/*Prescaler Bitl*/

#define TWBR	*((volatile u8*)0x20)	/*TWI Bit Rate Register*/


#endif /* MCAL_TWI_TWI_REGISTER_H_ */
