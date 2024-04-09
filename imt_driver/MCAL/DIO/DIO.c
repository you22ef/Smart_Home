/*
 * DIO.c
 *
 *  Created on: 16 Sep 2023
 *      Author: raefa
 */

#ifndef MCAL_DIO_DIO_C_
#define MCAL_DIO_DIO_C_

#include "DIO.h"
#include "DIO_Reg.h"
#include "../../LIB/BIT_MATH.h"

void DIO_set_port_dir(u8 Groupnumber, u8 value) {
	switch (Groupnumber) {
	case GROUPA:
		DDRA_REG = value;
		break;
	case GROUPB:
		DDRB_REG = value;
		break;
	case GROUPC:
		DDRC_REG = value;
		break;
	case GROUPD:
		DDRD_REG = value;
		break;
	}
}

void DIO_set_port(u8 Groupnumber, u8 value) {
	switch (Groupnumber) {
	case GROUPA:
		PORTA_REG = value;
		break;
	case GROUPB:
		PORTB_REG = value;
		break;
	case GROUPC:
		PORTC_REG = value;
		break;
	case GROUPD:
		PORTD_REG = value;
		break;
	}
}
u8 DIO_get_port(u8 Groupnumber) {
	u8 status = 0;
	switch (Groupnumber) {
	case GROUPA:
		status = PINA_REG;
		break;
	case GROUPB:
		status = PINB_REG;
		break;
	case GROUPC:
		status = PINC_REG;
		break;
	case GROUPD:
		status = PIND_REG;
		break;
	}
	return status;
}

void DIO_set_pin_dir(u8 Groupnumber, u8 pinNumber, u8 status) {
	if (status == OUTPUT) {
		switch (Groupnumber) {
		case GROUPA:
			SET_BIT(DDRA_REG, pinNumber);
			break;
		case GROUPB:
			SET_BIT(DDRB_REG, pinNumber);
			break;
		case GROUPC:
			SET_BIT(DDRC_REG, pinNumber);
			break;
		case GROUPD:
			SET_BIT(DDRD_REG, pinNumber);
			break;
		}
	} else if (status == INPUT) {
		switch (Groupnumber) {
		case GROUPA:
			CLR_BIT(DDRA_REG, pinNumber);
			break;
		case GROUPB:
			CLR_BIT(DDRB_REG, pinNumber);
			break;
		case GROUPC:
			CLR_BIT(DDRC_REG, pinNumber);
			break;
		case GROUPD:
			CLR_BIT(DDRD_REG, pinNumber);
			break;
		}
	}
}
void DIO_set_pin(u8 Groupnumber, u8 pinNumber, u8 Out_status) {
	if (Out_status == HIGH) {
		switch (Groupnumber) {
		case GROUPA:
			SET_BIT(PORTA_REG, pinNumber);
			break;
		case GROUPB:
			SET_BIT(PORTB_REG, pinNumber);
			break;
		case GROUPC:
			SET_BIT(PORTC_REG, pinNumber);
			break;
		case GROUPD:
			SET_BIT(PORTD_REG, pinNumber);
			break;
		}
	} else if (Out_status == LOW) {
		switch (Groupnumber) {
		case GROUPA:
			CLR_BIT(PORTA_REG, pinNumber);
			break;
		case GROUPB:
			CLR_BIT(PORTB_REG, pinNumber);
			break;
		case GROUPC:
			CLR_BIT(PORTC_REG, pinNumber);
			break;
		case GROUPD:
			CLR_BIT(PORTD_REG, pinNumber);
			break;
		}
	}
}
u8 DIO_get_pin(u8 Groupnumber, u8 pinNumber) {
	u8 status = 0;
	switch (Groupnumber) {
	case GROUPA:
		status = GET_BIT(PINA_REG, pinNumber);
		break;
	case GROUPB:
		status = GET_BIT(PINB_REG, pinNumber);
		break;
	case GROUPC:
		status = GET_BIT(PINC_REG, pinNumber);
		break;
	case GROUPD:
		status = GET_BIT(PIND_REG, pinNumber);
		break;
	}
	return status;
}
#endif /* MCAL_DIO_DIO_C_ */
