/*

* SPI_register.h
 *
 *  Created on: Dec 8, 2023
 *      Author: youssef atya
 */


#include "USART_Interface.h"
#include "USART_register.h"
#include <avr/io.h>
#include "../../LIB/STD_TYPES.h"
void uart_init(void)
{
	UCSRB = (1 << UCSRB_TXEN) | (1 << UCSRB_RXEN);                  // Enable the transmitting and receiving pins
	UCSRC = (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0) | (1 << UCSRC_URSEL); // Set the data size and enable writing to UCSRC
	UBRRL = 0x33;                                       // Define the baud rate
}

void uart_send(u8 ch)
{
	while(! (UCSRA & (1 << UCSRA_UDRE)));
	UDR = ch;
}

u8 uart_receive(void) {
    while (!(UCSRA & (1 << UCSRA_RXC))); // Wait for data to be received
    return UDR;                    // Get and return received data from buffer
}
