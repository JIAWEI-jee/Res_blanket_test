#ifndef __SYSTEM_DIGITAL_TUBE_H__
#define __SYSTEM_DIGITAL_TUBE_H__
#include "HC89F303B.h"


#define    DIGITAL_TUBE_A  P1_3
#define    DIGITAL_TUBE_B  P1_2
#define    DIGITAL_TUBE_C  P1_0
#define    DIGITAL_TUBE_D  P0_7
#define    DIGITAL_TUBE_E  P0_6
#define    DIGITAL_TUBE_F  P1_1
#define    DIGITAL_TUBE_G  P0_5

#define    SEG1            P1_4
#define    SEG2            P1_5
#define    SEG3            P1_6
#define    SEG4            P0_4


#define DIGITAL_BIT1_SET      do{SEG1 = 1;}while(0)
#define DIGITAL_BIT1_CLEAR    do{SEG1 = 0;}while(0)

#define DIGITAL_BIT2_SET      do{SEG2 = 1;}while(0)
#define DIGITAL_BIT2_CLEAR    do{SEG2 = 0;}while(0)

#define DIGITAL_BIT3_SET      do{SEG3 = 1;}while(0)
#define DIGITAL_BIT3_CLEAR    do{SEG3 = 0;}while(0)

#define DIGITAL_BIT4_SET      do{SEG4 = 1;}while(0)
#define DIGITAL_BIT4_CLEAR    do{SEG4 = 0;}while(0)


typedef enum
{
	DIGITAL_TUBE_PIN_ON = 0,
	DIGITAL_TUBE_PIN_OFF
} DIGITAL_TUBE_PIN_STD;


typedef enum
{
	DIGITAL_TUBE_ON = 1,
	DIGITAL_TUBE_OFF,
	DIGITAL_TUBE_TEMPER_ERROR,
	DIGITAL_TUBE_HEAT_ERROR,

} TUBE_std_set;


typedef struct digital_tube_value
{
	u8 bit1;
	u8 bit2;
	u8 bit3;
	u8 bit4;
	u8 SKU_std;
	u8 tube_std;
} digital_tube_value_t;

extern digital_tube_value_t tube_num;

void Tube_Init_Config ( void );
void digital_tube_timer_handle ( digital_tube_value_t value );


#endif
