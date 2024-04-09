/*
 * 7Seg.c
 *
 *  Created on: 16 Sep 2023
 *      Author: raefa
 */


#include "7SEG.h"
#include "7SEG_Cfg.h"
#include "../../MCAL/DIO/DIO.h"
#define NUMBERS_COUNT 10
u8 seven_seg_arr[NUMBERS_COUNT] =
{
0x3f,0x06,0x5b,
0x4f,0x66,0x6d,
0x7d,0x07,0x7f
,0x6f
};
void SevenSeg_int()
{
DIO_set_port_dir(SEVEN_SEGMENT_GROUP,0xff);
#if SEVEN_SEGMENT_TYPE == CATHOD
DIO_set_port(SEVEN_SEGMENT_GROUP,seven_seg_arr[NUMBER0]);
#elif SEVEN_SEGMENT_TYPE == ANODE
DIO_set_port(SEVEN_SEGMENT_GROUP,0xff);
#endif
}
void SevenSeg_dispaly(u8 number)
{
#if SEVEN_SEGMENT_TYPE == CATHOD
	DIO_set_port(SEVEN_SEGMENT_GROUP,seven_seg_arr[number]);
#elif SEVEN_SEGMENT_TYPE == ANODE
DIO_set_port(SEVEN_SEGMENT_GROUP,~seven_seg_arr[number]);
#endif
}
