/*
 * Timer_register.h
 *
 *  Created on: Feb 6, 2024
 *      Author: hp
 */

#ifndef MCAL_TIMERS_TIMER_REGISTER_H_
#define MCAL_TIMERS_TIMER_REGISTER_H_

#define TCCR0			*((volatile u8*)0x53)		/*Timer0 control reister*/
#define TCCR0_WGM00		6							/*Wavefoem generation Mode bit0*/
#define TCCR0_WGM01		3							/*Waveform generation mode bitl*/
#define TCCR0_CS02		2							/*Prescaler bit2*/
#define TCCR0_CS01		1							/*Prescaler bitl*/
#define TCCR0_CS00		0							/*Prescaler bit0*/


#define OCR0			*((volatile u8*)0x5C)		/*Output compare register 0*/

#define TIMSK			*((volatile u8*)0x59)		/*Timer mask*/
#define TIMSK_OCIE0		1							/*Output compare 0 interrupt enable*/

#define TCCR1A  		*((volatile u8*)0x4f)		/*Timer 1A control register*/
#define TCCR1B  		*((volatile u8*)0x4e)		/*Timer 1A control register*/


#define ICR1  			*((volatile u16*)0x46)
#define OCR1A 			*((volatile u16*)0x4a)

#define TCCR1A_WGM10 	0
#define TCCR1A_WGM11 	1

#define TCCR1A_COM1A1 	7
#define TCCR1A_COM1A0 	6

#define TCCR1B_WGM13	4
#define TCCR1B_WGM12	3

#define PRESCALLER_MASK	0b11111000
#define DIVIDE_BY_8		2


#endif /* MCAL_TIMERS_TIMER_REGISTER_H_ */
