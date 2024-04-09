/*
 * USART_REG.h
 *
 *  Created on: Nov 27, 2023
 *      Author: youssef atya
 */

#ifndef MCAL_USART_USART_REG_H_
#define MCAL_USART_USART_REG_H_

#define UDR 			((volatile u8)0x2C)


#define UCSRA 			((volatile u8)0x2B)   //USART Control and Status Register A
#define UCSRA_RXC 				  7				//USART Receive Complete
#define UCSRA_TXC 				  6				//USART Transmit Complete
#define UCSRA_UDRE 				  5				//USART Data Register Empty
#define UCSRA_FE 				  4				//Frame Error
#define UCSRA_DOR 				  3				//Data OverRun
#define UCSRA_PE 				  2				//Parity Error
#define UCSRA_U2X 				  1				//Double the USART Transmission Speed
#define UCSRA_MPCM 				  0				//Multi-processor Communication Mode


#define UCSRB 			((volatile u8)0x2A)   //USART Control and Status Register B
#define UCSRB_RXCIE 			  7				//Receive Complete Interrupt Enable
#define UCSRB_TXCIE				  6				//Transmit Complete Interrupt Enable
#define UCSRB_UDRIE			  	  5				//USART Data Register Empty Interrupt Enable
#define UCSRB_RXEN 				  4				//Receiver Enable
#define UCSRB_TXEN 				  3				//Transmitter Enable
#define UCSRB_UCSZ2 			  2				//Character Size
#define UCSRB_RXB8 				  1				//Receive Data Bit 8
#define UCSRB_TXB8 				  0				//Transmit Data Bit 8


#define UCSRC 			((volatile u8)0x40)   //USART Control and Status Register C
#define UCSRC_URSEL 			  7				//Register Select
#define UCSRC_UMSEL				  6				//USART Mode Select
#define UCSRC_UPM1			  	  5				//Parity Mode bit1
#define UCSRC_UPM0 				  4				//Parity Mode bit0
#define UCSRC_USBS				  3				//Stop Bit Select
#define UCSRC_UCSZ0 			  2				//Character Size bit1
#define UCSRC_UCSZ1 			  1				//Character Size bit2
#define UCSRC_UCPOL 			  0				//Clock Polarity


#define UBRRH 			((volatile u8)0x40)   //USART Baud Rate Register High
#define UBRRH_URSEL 			  7				//Register Select
#define UBRRH_UBRR3				  3				//Baud Rate
#define UBRRH_UBRR2			  	  2				//Baud Rate
#define UBRRH_UBRR1				  1				//Baud Rate
#define UBRRH_UBRR0				  0				//Baud Rate


#define UBRRL 			((volatile u8)0x29)   //USART Baud Rate Register Low
#define UBRRL_UBRRL7 			  7				//Baud Rate
#define UBRRL_UBRRL6 			  6				//Baud Rate
#define UBRRL_UBRRL5 			  5				//Baud Rate
#define UBRRL_UBRRL4 			  4				//Baud Rate
#define UBRRL_UBRRL3 			  3				//Baud Rate
#define UBRRL_UBRRL2 			  2				//Baud Rate
#define UBRRL_UBRRL1 			  1				//Baud Rate
#define UBRRL_UBRRL0 			  0				//Baud Rate




#endif /* MCAL_USART_USART_REG_H_ */
