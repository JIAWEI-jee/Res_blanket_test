#ifndef __SYSTEM_DIGITAL_TUBE_H__
#define __SYSTEM_DIGITAL_TUBE_H__
#include "HC89F303B.h"

typedef struct digital_tube_value
{
	uint8_t bit1;
	uint8_t bit2;
	uint8_t bit3;
	uint8_t bit4;
	uint32_t ponit_time;
} digital_tube_value_t;



#endif
