/*
 * 7SEG.h
 *
 *  Created on: 16 Sep 2023
 *      Author: raefa
 */

#ifndef HAL_7SEG_7SEG_H_
#define HAL_7SEG_7SEG_H_
#include "../../LIB/STD_TYPES.h"

#define NUMBER0 0
#define NUMBER1 1
#define NUMBER2 2
#define NUMBER3 3
#define NUMBER4 4
#define NUMBER5 5
#define NUMBER6 6
#define NUMBER7 7
#define NUMBER8 8
#define NUMBER9 9

void SevenSeg_int();
void SevenSeg_dispaly(u8 number);

#endif /* HAL_7SEG_7SEG_H_ */
