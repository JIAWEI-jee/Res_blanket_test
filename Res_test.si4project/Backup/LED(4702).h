#ifndef _LED_H
#define _LED_H

#include "HC89F303B.h"

#define LED0  P2_0
#define LED1  P2_1
#define LED2  P2_2

typedef enum
{
 LED_FAST_BLINK = 1,
 LED_SLOW_BLINK,
 LED_ON_LIGHT,
 LED_OFF_LIGHT,
 LED_ALL_OFF
}Led_mode;

typedef enum
{
 RED = 1,
 GREEN,
 BLUE
}Led_ID;

#endif
