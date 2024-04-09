/*===================================================================================================*/
/*  File        : USART_Interface.h                                                                  */
/*  Description : This interface file includes USART Driver prototypes and declarations for Atmega32 */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                        */
/*  Date        : 11/4/2023                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                          */
/*  Git account : https://github.com/ahmedbahaa11                                                    */
/*  mail        : ahmedbahaataha7@gmil.com                                                           */
/*===================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

void uart_init(void);
void uart_send(u8 ch);
u8 uart_receive(void);

#endif
