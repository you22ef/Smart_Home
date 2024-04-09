/*
 * ADC_REG.h
 *
 *  Created on: 20 Oct 2023
 *      Author: raefa
 */

#ifndef MCAL_ADC_ADC_REG_H_
#define MCAL_ADC_ADC_REG_H_

#define ADMUX_REG 			*((volatile u8*)(0x27))			//ADC multiplexer selection register
#define ADMUX_REFS1			7								//reference selection bit 1
#define ADMUX_REFS0			6								//reference selection bit 0
#define ADMUX_ADLAR			5								//ADC left adjust result

#define ADCSRA_REG 			*((volatile u8*)(0x26))         //ADC control and status register A
#define ADCSRA_ADEN			7								//ADC enable
#define ADCSRA_ADSC			6								//Start conversion
#define ADCSRA_ADATE		5								//Auto trigger enable
#define ADCSRA_ADIF			4								//Interrupt flag
#define ADCSRA_ADIE			3								//Interrupt enable
#define ADCSRA_ADPS2		2								//Prescaler bit2
#define ADCSRA_ADPS1		1								//Prescaler bit1
#define ADCSRA_ADPS0		0								//Prescaler bit0

#define ADC_REG *((volatile u16*)(0x24))					//ADC Low&high register


#endif /* MCAL_ADC_ADC_REG_H_ */
