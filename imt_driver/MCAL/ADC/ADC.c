/*
 * ADC.c
 *
 *  Created on: 20 Oct 2023
 *      Author: raefa
 */

#include "ADC.h"
#include "ADC_REG.h"
#include "../../LIB/BIT_MATH.h"
void ADC_init() {
	//set external reference
	SET_BIT(ADMUX_REG, ADMUX_REFS0);
	CLR_BIT(ADMUX_REG, ADMUX_REFS1);

	//Activate left adjust result
	SET_BIT(ADCSRA_REG, ADMUX_ADLAR);


	//Set prescaler to divide by 128
	SET_BIT(ADCSRA_REG, ADCSRA_ADPS2);
	SET_BIT(ADCSRA_REG, ADCSRA_ADPS1);
	SET_BIT(ADCSRA_REG, ADCSRA_ADPS0);

	//ENABLE preipheral
	SET_BIT(ADCSRA_REG, ADCSRA_ADEN);

}

u16 ADC_Read_channal(u8 channel) {

	//Clear first 5 bits in ADMUX_REG
	ADMUX_REG &= 0xE0;

	//Set the desired channel
	ADMUX_REG |= channel;

	//Start conversion
	SET_BIT(ADCSRA_REG, ADCSRA_ADSC);

	//Polling to the interrupt flag;
	while(GET_BIT(ADCSRA_REG,ADCSRA_ADIF) == 0);

	//Clear flag (set to 1)
	SET_BIT(ADCSRA_REG, ADCSRA_ADIF);

	return ADC_REG;
}
