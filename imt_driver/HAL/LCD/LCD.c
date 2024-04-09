/*
 * LCD.c
 *
 *  Created on: 22 Sep 2023
 *      Author: raefa
 */

#include "LCD.h"
#include "LCD_CFG.h"
#include "avr/delay.h"

#define LCD_CLEAR 0x01
#define LCD_HOME 0x02
#define LCD_SET8BITFUNCTION 0x38
#define ENTER_MODE 0x06
#define DISPLAYON 0x0C

int question_mark[8]={0,14,17,2,4,4,0,4};
int yaa[8]={0,0x01,0x01,0x1f,0,0x06,0,0};
int waw[8]={0,0x1c,0x14,0x1f,0x04,0x04,0x1c,0};
int seen[8]={0,0x15,0x15,0x1f,0,0,0,0};
int faa[8]={0x04,0x0e,0x0a,0x0f,0x12,0x1e,0,0};
int plane[8]={0x10,0x18,0x1c,0x1f,0x1c,0x18,0x10,0};
int heart[8]={0,0x1b,0x1f,0x1f,0x0e,0x04,0,0};

void LCD_init() {
	DIO_set_port_dir(LCD_GROUP_DATA,0xff);
	DIO_set_pin_dir(LCD_GROUP_CONTROL, RS_PIN, OUTPUT);
	DIO_set_pin_dir(LCD_GROUP_CONTROL, E_PIN, OUTPUT);
	_delay_ms(30);
	LCD_send_command(LCD_HOME);
	_delay_ms(15);
	LCD_send_command(LCD_SET8BITFUNCTION);
	_delay_ms(1);
	LCD_send_command(DISPLAYON);
	_delay_ms(1);
	LCD_send_command(LCD_CLEAR);
	_delay_ms(15);
	LCD_send_command(ENTER_MODE);
	_delay_ms(2);
}
void LCD_send_data(u8 data) {
	DIO_set_pin(LCD_GROUP_CONTROL, RS_PIN, HIGH);
	_delay_ms(1);
	DIO_set_pin(LCD_GROUP_CONTROL, E_PIN, HIGH);
	_delay_ms(1);
	DIO_set_port(LCD_GROUP_DATA, data);
	_delay_ms(1);
	DIO_set_pin(LCD_GROUP_CONTROL, E_PIN, LOW);
	_delay_ms(10);
}
void LCD_send_command(u8 command) {
	DIO_set_pin(LCD_GROUP_CONTROL, RS_PIN, LOW);
	_delay_ms(1);
	DIO_set_pin(LCD_GROUP_CONTROL, E_PIN, HIGH);
	_delay_ms(1);
	DIO_set_port(LCD_GROUP_DATA, command);
	_delay_ms(1);
	DIO_set_pin(LCD_GROUP_CONTROL, E_PIN, LOW);
	_delay_ms(10);

}
void LCD_goto_col_row(u8 col, u8 row) {
	switch (row) {
	case 0:
		LCD_send_command(0x80 | col);
		break;
	case 1:
		LCD_send_command(0x80 | col + 0x40);
		break;

	}
}
void LCD_send_string(u8 ptr[])
{
	u8 i = 0;
	while(ptr[i] != '\0')
	{
		LCD_send_data(ptr[i]);
		i++;
	}
}
void LCD_character(u8 chr,u8 coulmn,u8 row)
{
	//LCD_send_command(64);// Address where customized character is to be stored
	int char_loc = 0;
	switch (chr)
	{
		case 'y':
			LCD_send_command(64);
			for(int i = 0;i<8;i++)
			{
				LCD_send_data(yaa[i]);
			}
			char_loc = 0;
			break;
		case 'w':
			LCD_send_command(72);
			for(int i = 0;i<8;i++)
			{
				LCD_send_data(waw[i]);
			}
			char_loc = 1;
			break;
		case 's':
			LCD_send_command(80);
			for(int i = 0;i<8;i++)
			{
				LCD_send_data(seen[i]);
			}
			char_loc = 2;
			break;
		case 'f':
			LCD_send_command(88);
			for(int i = 0;i<8;i++)
			{
				LCD_send_data(faa[i]);
			}
			char_loc = 3;
			break;
		case 'h':
			LCD_send_command(96);
			for(int i = 0;i<8;i++)
			{
				LCD_send_data(heart[i]);
			}
			char_loc = 4;
			break;
		case 'p':
			LCD_send_command(104);
			for(int i = 0;i<8;i++)
			{
				LCD_send_data(plane[i]);
			}
			char_loc = 5;
			break;
	}
	LCD_goto_col_row(coulmn,row);
	LCD_send_data(char_loc);
	//LCD_goto_col_row(0,0);  // Location of LCD where the character is to be displayed
	//LCD_send_data(0);  // Displaying the character created at address 0x64
}
void reset_LCD_character(u8 chr)
{
	switch (chr)
	{

		case 'y':
			LCD_send_command(64);
			for(int i = 0;i<8;i++)
			{
				LCD_send_data(0);
			}
			break;
		case 'w':
			LCD_send_command(72);
			for(int i = 0;i<8;i++)
			{
				LCD_send_data(0);
			}
			break;
		case 's':
			LCD_send_command(80);
			for(int i = 0;i<8;i++)
			{
				LCD_send_data(0);
			}
			break;
		case 'f':
			LCD_send_command(88);
			for(int i = 0;i<8;i++)
			{
				LCD_send_data(0);
			}
			break;
		case 'h':
			LCD_send_command(96);
			for(int i = 0;i<8;i++)
			{
				LCD_send_data(0);
			}
			break;
		case 'p':
			LCD_send_command(104);
			for(int i = 0;i<8;i++)
			{
				LCD_send_data(0);
			}
			break;
		case 'd':
			LCD_send_command(120);
			for(int i = 0;i<8;i++)
			{
				LCD_send_data(0);
			}
			break;
	}
}
void reset_LCD_position(u8 coulmn,u8 row)
{
	LCD_send_command(112);
	for(int i = 0;i<8;i++)
	{
		LCD_send_data(0);
	}
	LCD_goto_col_row(coulmn,row);
	LCD_send_data(6);
}
void fill_LCD_position(u8 coulmn,u8 row)
{
	LCD_send_command(120);
	for(int i = 0;i<8;i++)
	{
		LCD_send_data(0x1f);
	}
	LCD_goto_col_row(coulmn,row);
	LCD_send_data(7);
}
void LCD_Clear() {
	LCD_send_command(LCD_CLEAR);
}
