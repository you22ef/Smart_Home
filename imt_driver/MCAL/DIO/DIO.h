/*
 * DIO.h
 *
 *  Created on: 16 Sep 2023
 *      Author: raefa
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include "../../LIB/STD_TYPES.h"
// ports defined for passing to functions
#define GROUPA 1
#define GROUPB 2
#define GROUPC 3
#define GROUPD 4

// PINS number for passing to functions
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

// extern prototyps

void DIO_set_port_dir(u8 Groupnumber , u8 value);
void DIO_set_port(u8 Groupnumber , u8 value);
u8 DIO_get_port(u8 Groupnumber);

void DIO_set_pin_dir(u8 Groupnumber ,u8 pinNumber, u8 status);
void DIO_set_pin(u8 Groupnumber ,u8 pinNumber, u8 Out_status);
u8 DIO_get_pin(u8 Groupnumber ,u8 pinNumber);


#endif /* MCAL_DIO_DIO_H_ */
