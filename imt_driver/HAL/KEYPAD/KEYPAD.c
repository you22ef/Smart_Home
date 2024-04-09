/*
 * KEYPAD.c
 *
 *  Created on: 23 Sep 2023
 *      Author: raefa
 */

#include "KEYPAD.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../HAL/LCD/LCD.h"
#include "avr/delay.h"
#define KEYPAD_GROUP GROUPC
#define ROWS 4
#define COLS 4
int keybad_col = 10;
int keybad_row = 0;
u8 InputUserName[5];
u8 InputPassword[5];
u8 keypad_arr[ROWS][COLS] =
{
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
		{'*','0','#','d'}
};
void keyPad_init()
{

	DIO_set_port_dir(KEYPAD_GROUP,0x0f);
	// 4 pins input
	DIO_set_port(KEYPAD_GROUP,0xff);

}
u8 KeyPad_get_pressed_key()
{
u8 cols_num = 0;
u8 Rows_num = 0;
u8 retNum = 0xff;

for (cols_num = 0; cols_num < 4 ; cols_num++)
{
	DIO_set_port(KEYPAD_GROUP,~(0b00000001 <<cols_num));
	for(Rows_num = 4 ; Rows_num < 8 ; Rows_num++ )
	{
		if(DIO_get_pin(KEYPAD_GROUP,Rows_num) == 0)
		{
			retNum = keypad_arr[Rows_num-4][cols_num];
			while(DIO_get_pin(KEYPAD_GROUP,Rows_num) == 0);
			_delay_ms(10);
			DIO_set_pin(KEYPAD_GROUP,cols_num,HIGH);
			return retNum;

		}
	}
}
return retNum;

}

u8 KeyPad_Set_Username(u8 key)
{
	static u8 count = 0;
	u8 UserName[] = "123AB";

	if(key != 0xff)
	{
		if(key == 'd')
		{
			InputUserName[keybad_col-10] = '\0';

			if(keybad_col>=10)
			{
				reset_LCD_position(keybad_col,keybad_row);
				LCD_goto_col_row(keybad_col,keybad_row);
				if(keybad_col>10)
				{
					keybad_col--;
				}

			}
			return 2;
		}
		else if(key == 'C')
		{
			u8 bool = 0;
			for(int i = 0;i<5;i++)
			{
				if(UserName[i] != InputUserName[i])
				{
					count++;
					if(count>3)
					{
						while(1)
						{

							LCD_goto_col_row(0,0);
							LCD_send_string("Welcome Crimenal");
							LCD_goto_col_row(0,1);
							LCD_send_string(":(");
							DIO_set_pin(GROUPA,PIN_2,HIGH);
							DIO_set_pin(GROUPA,PIN_3,LOW);
							DIO_set_pin(GROUPB,PIN_4,HIGH);
							DIO_set_pin(GROUPB,PIN_5,HIGH);
							DIO_set_pin(GROUPB,PIN_6,HIGH);
							DIO_set_pin(GROUPB,PIN_7,HIGH);
							u8 key2 = KeyPad_get_pressed_key();
							if(key2 =='5')
							{
								DIO_set_pin(GROUPB,PIN_4,LOW);
								DIO_set_pin(GROUPB,PIN_5,LOW);
								DIO_set_pin(GROUPB,PIN_6,LOW);
								DIO_set_pin(GROUPB,PIN_7,LOW);
								DIO_set_pin(GROUPA,PIN_2,LOW);
								DIO_set_pin(GROUPA,PIN_3,LOW);
								LCD_Clear();
								count =0;
								break;
							}

						}

					}
					LCD_Clear();
					LCD_goto_col_row(0,0);
					LCD_send_string("Wrong User Name");
					LCD_goto_col_row(0,1);
					LCD_send_string("Click d");
					while(KeyPad_get_pressed_key()!='d');
					LCD_Clear();
					bool = 1;
					keybad_col = 10;
					break;
				}
			}
			if(bool == 0)
			{
				LCD_Clear();
				keybad_col = 10;
				return 1;
			}
			else
			{
				return 0;
			}

		}

		InputUserName[keybad_col-10] = key;
		LCD_goto_col_row(keybad_col,keybad_row);
		if(keybad_col<15 )
		{
			keybad_col++;
		}
		LCD_send_data(key);
		return 3;

	}
}
u8 KeyPad_Set_Password(u8 key)
{
	static u8 count =0;
	u8 Password[] = "2684A";

		if(key != 0xff)
		{
			if(key == 'd')
			{
				InputPassword[keybad_col-10] = '\0';

				if(keybad_col>=10)
				{
					reset_LCD_position(keybad_col,keybad_row);
					LCD_goto_col_row(keybad_col,keybad_row);
					if(keybad_col>10)
					{
						keybad_col--;
					}

				}
				return 2;
			}
			else if(key == 'C')
			{
				u8 bool = 0;
				for(int i = 0;i<5;i++)
				{
					if(Password[i] != InputPassword[i])
					{
						count++;
						if(count>3)
						{
							while(1)
							{

								LCD_goto_col_row(0,0);
								LCD_send_string("Welcome Crimenal");
								LCD_goto_col_row(0,1);
								LCD_send_string(":(");
								DIO_set_pin(GROUPA,PIN_2,HIGH);
								DIO_set_pin(GROUPA,PIN_3,LOW);
								DIO_set_pin(GROUPB,PIN_4,HIGH);
								DIO_set_pin(GROUPB,PIN_5,HIGH);
								DIO_set_pin(GROUPB,PIN_6,HIGH);
								DIO_set_pin(GROUPB,PIN_7,HIGH);
								u8 key2 = KeyPad_get_pressed_key();
								if(key2 =='5')
								{
									DIO_set_pin(GROUPB,PIN_4,LOW);
									DIO_set_pin(GROUPB,PIN_5,LOW);
									DIO_set_pin(GROUPB,PIN_6,LOW);
									DIO_set_pin(GROUPB,PIN_7,LOW);
									DIO_set_pin(GROUPA,PIN_2,LOW);
									DIO_set_pin(GROUPA,PIN_3,LOW);
									LCD_Clear();
									count =0;
									break;
								}

							}

						}
						LCD_Clear();
						LCD_goto_col_row(0,0);
						LCD_send_string("Wrong Password");
						LCD_goto_col_row(0,1);
						LCD_send_string("Click d");
						while(KeyPad_get_pressed_key()!='d');
						LCD_Clear();
						bool = 1;
						keybad_col = 10;
						break;
					}
				}
				if(bool == 0)
				{
					LCD_Clear();
					LCD_goto_col_row(0,0);
					LCD_send_string("Welcom Youssef");
					_delay_ms(1000);
					LCD_Clear();
					return 1;
				}
				else
				{
					return 0;
				}

			}

			InputPassword[keybad_col-10] = key;
			LCD_goto_col_row(keybad_col,keybad_row);
			if(keybad_col<15 )
			{
				keybad_col++;
			}
			LCD_send_data('*');
			return 3;

		}

}
void KeyPad_display_7seg(u8 key)
{
	if(key != 0xff)
	{
		key = key - '0';
		SevenSeg_dispaly(key);

	}
}

