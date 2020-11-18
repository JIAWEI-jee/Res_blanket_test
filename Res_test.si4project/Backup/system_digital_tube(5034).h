#ifndef __SYSTEM_DIGITAL_TUBE_H__
#define __SYSTEM_DIGITAL_TUBE_H__
#include "HC89F303B.h"

#define    DIGITAL_TUBE_A  P1_3
#define    DIGITAL_TUBE_B  P1_2
#define    DIGITAL_TUBE_C  P1_1
#define    DIGITAL_TUBE_D  P1_0
#define    DIGITAL_TUBE_E  P0_7
#define    DIGITAL_TUBE_F  P0_6
#define    DIGITAL_TUBE_G  P0_5

#define    SEG1            P1_4
#define    SEG2            P1_5
#define    SEG3            P1_4
#define    SEG4            P0_4

typedef enum
{
  DIGITAL_TUBE_PIN_ON = 0,
  DIGITAL_TUBE_PIN_OFF
} DIGITAL_TUBE_PIN_STD;


typedef struct digital_tube_value
{
	u8 bit1;
	u8 bit2;
	u8 bit3;
	u8 bit4;
	u8 ponit_time;
} digital_tube_value_t;

void Tube_Init_Config ( void );


#endif
