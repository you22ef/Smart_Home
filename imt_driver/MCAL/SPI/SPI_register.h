/*

* SPI_register.h
 *
 *  Created on: Dec 8, 2023
 *      Author: youssef atya
 */

#ifndef MCAL_SPI_SPI_REGISTER_H_
#define MCAL_SPI_SPI_REGISTER_H_

#define SPDR			*((volatile u8*)0x2F) 			/*SPI Data Register*/

#define SPSR			*((volatile u8*)0x2E)			/*SPI Status Register*/
#define SPSR_SPIF			      7						/*SPI Interrupt flag*/
#define SPSR_SPI2X				  0						/*Prescaler bit 2*/

#define SPCR			*((volatile u8*)0x2D)			/*SPI control Register*/
#define SPCR_SPE			      6						/*SPI enable*/
#define SPCR_MSTR			      4						/*Master bit*/
#define SPCR_SPR1			   	  1						/*Prescaler bit 1*/
#define SPCR_SPR0				  0						/*Prescaler bit 0*/




#endif /* MCAL_SPI_SPI_REGISTER_H_ */
