/*
 * KEYPAD.h
 *
 *  Created on: 23 Sep 2023
 *      Author: raefa
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_
#include "../../LIB/STD_TYPES.h"
void keyPad_init();
u8 KeyPad_get_pressed_key();
u8 KeyPad_Set_Username(u8 key);
void KeyPad_display_7seg(u8 key);
u8 KeyPad_Set_Password(u8 key);

#endif /* HAL_KEYPAD_KEYPAD_H_ */
