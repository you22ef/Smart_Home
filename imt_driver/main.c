/*
 * main.c

 *
 *  Created on: 16 Sep 2023
 *      Author: raefa
 */
#include <stdio.h>
#include "MCAL/DIO/DIO.h"
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "avr/delay.h"
#include "avr/io.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/ADC/ADC.h"
#include "MCAL/USART/USART_Interface.h"
#include "HAL/KEYPAD/KEYPAD.h"
#include "MCAL/SPI/SPI_interface.h"
#include "HAL/GIE/GIE_interface.h"

u8 SetUserName();
u8 SetPassword();
u8 Options();
u8 result;
u8 arr[22];
int main()
{

	DIO_set_pin_dir(GROUPB,PIN_4,OUTPUT);
	DIO_set_pin_dir(GROUPB,PIN_5,OUTPUT);
	DIO_set_pin_dir(GROUPB,PIN_6,OUTPUT);
	DIO_set_pin_dir(GROUPB,PIN_7,OUTPUT);
	DIO_set_pin_dir(GROUPA,PIN_0,INPUT);
	DIO_set_pin_dir(GROUPA,PIN_1,INPUT);
	DIO_set_pin_dir(GROUPA,PIN_2,OUTPUT);
	DIO_set_pin_dir(GROUPA,PIN_3,OUTPUT);



	ADC_init();
	LCD_init();
	keyPad_init();
	u8 resultUserName = 0;
	u8 resultPassword= 0;

	PWM_voidInit();
	DIO_set_pin_dir(GROUPB,PIN_3,OUTPUT);
	while(1)
	{


		if(resultUserName != 1)
		{
			resultUserName = SetUserName();
		}

		if(resultUserName == 1 && resultPassword != 1)
		{
			resultPassword = SetPassword();
		}
		if(resultPassword == 1)
		{
			Options();

		}



	}

}

u8 Options()
{

	LCD_goto_col_row(0,0);
	LCD_send_string("1-LedOn");
	LCD_goto_col_row(0,1);
	LCD_send_string("2-LedOff");
	LCD_goto_col_row(7,0);
	LCD_send_string("3-LDRLed");
	LCD_goto_col_row(9,1);
	LCD_send_string("4-More");
	u8 key = KeyPad_get_pressed_key();
	if(key=='1')
	{
		DIO_set_pin(GROUPB,PIN_4,HIGH);
		DIO_set_pin(GROUPB,PIN_5,HIGH);
		DIO_set_pin(GROUPB,PIN_6,HIGH);
		DIO_set_pin(GROUPB,PIN_7,HIGH);
	}
	else if(key == '2')
	{
		DIO_set_pin(GROUPB,PIN_4,LOW);
		DIO_set_pin(GROUPB,PIN_5,LOW);
		DIO_set_pin(GROUPB,PIN_6,LOW);
		DIO_set_pin(GROUPB,PIN_7,LOW);
	}
	else if(key == '3')
	{
		LCD_Clear();
		while(1)
		{
			result = ADC_Read_channal(0);
			sprintf(arr,"light = %d ",result);
			LCD_goto_col_row(0,0);
			LCD_send_string(arr);
			key = KeyPad_get_pressed_key();
			LCD_goto_col_row(0,1);
			LCD_send_string("Press 1 to Exit");
			if(result<100)
			{
				DIO_set_pin(GROUPB,PIN_4,HIGH);
				DIO_set_pin(GROUPB,PIN_5,HIGH);
				DIO_set_pin(GROUPB,PIN_6,HIGH);
				DIO_set_pin(GROUPB,PIN_7,HIGH);
			}
			else if(result>=100 && result<200)
			{
				DIO_set_pin(GROUPB,PIN_4,HIGH);
				DIO_set_pin(GROUPB,PIN_5,HIGH);
				DIO_set_pin(GROUPB,PIN_6,HIGH);
				DIO_set_pin(GROUPB,PIN_7,LOW);
			}
			else if(result>=200)
			{
				DIO_set_pin(GROUPB,PIN_4,LOW);
				DIO_set_pin(GROUPB,PIN_5,LOW);
				DIO_set_pin(GROUPB,PIN_6,HIGH);
				DIO_set_pin(GROUPB,PIN_7,HIGH);
			}
			if(key =='1')
			{
				break;
			}
		}
		DIO_set_pin(GROUPB,PIN_4,LOW);
		DIO_set_pin(GROUPB,PIN_5,LOW);
		DIO_set_pin(GROUPB,PIN_6,LOW);
		DIO_set_pin(GROUPB,PIN_7,LOW);
		LCD_Clear();

	}
	else if(key == '4')
	{
		LCD_Clear();
		while(1)
		{
			LCD_goto_col_row(0,0);
			LCD_send_string("5-DCON");
			LCD_goto_col_row(0,1);
			LCD_send_string("6-DC OFF");
			LCD_goto_col_row(6,0);
			LCD_send_string("7-AdjustDc");
			LCD_goto_col_row(9,1);
			LCD_send_string("8-BACK");

			key = KeyPad_get_pressed_key();
			if(key == '5')
			{
				PWM_voidSetCompMatchValue(150);
			}
			else if(key == '6')
			{
				PWM_voidSetCompMatchValue(0);
			}
			else if(key == '7')
			{
				LCD_Clear();
				while(1)
				{
					result = ADC_Read_channal(1);
					sprintf(arr,"HEAT = %d ",result);
					LCD_goto_col_row(0,0);
					LCD_send_string(arr);
					key = KeyPad_get_pressed_key();
					LCD_goto_col_row(0,1);
					LCD_send_string("Press 1 to Exit");
					if(result>=50)
					{
						PWM_voidSetCompMatchValue(255);
						_delay_ms(1000);
					}
					else
					{
						PWM_voidSetCompMatchValue(150);
					}
					if(key =='1')
					{
						LCD_Clear();
						PWM_voidSetCompMatchValue(0);
						break;
					}
				}
			}
			else if(key == '8')
			{
				break;
			}
		}
	}


}

u8 SetUserName()
{


		LCD_goto_col_row(0,0);
		LCD_send_string("User Name:");

		u8 key = KeyPad_get_pressed_key();
		u8 result = KeyPad_Set_Username(key);
		if(result == 1)
		{

			return 1;
		}
		return 0;
}

u8 SetPassword()
{
	LCD_goto_col_row(0,0);
	LCD_send_string("Password :");
	u8 key = KeyPad_get_pressed_key();
	u8 result = KeyPad_Set_Password(key);
	if(result == 1)
	{

		return 1;
	}

}
