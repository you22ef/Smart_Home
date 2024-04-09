/*
 * LCD.h
 *
 *  Created on: 22 Sep 2023
 *      Author: raefa
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#include "../../LIB/STD_TYPES.h"

void LCD_init();
void LCD_send_data(u8 data);
void LCD_send_command(u8 command);
void LCD_goto_col_row(u8 col, u8 row);
void LCD_Clear();
void LCD_send_string(u8 ptr[]);
void LCD_character(u8 chr,u8 coulmn,u8 row);
void reset_LCD_character(u8 chr);
void reset_LCD_position(u8 chr,u8 coulmn);
void fill_LCD_position(u8 coulmn,u8 row);
#endif /* HAL_LCD_LCD_H_ */
