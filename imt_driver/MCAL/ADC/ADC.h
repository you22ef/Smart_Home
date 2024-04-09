/*
 * ADC.h
 *
 *  Created on: 20 Oct 2023
 *      Author: raefa
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "../../LIB/STD_TYPES.h"

void ADC_init();
u16 ADC_Read_channal(u8 channel);


#endif /* MCAL_ADC_ADC_H_ */
