#ifndef _KEY_H
#define _KEY_H
#include "HC89F303B.h"

#define KEY_1 	P3_5
#define KEY_2 	P2_5

#define KEY_STATE_0         0       //按键状态
#define KEY_STATE_1         1
#define KEY_STATE_2         2
#define KEY_STATE_3         3

#define LONG_KEY_TIME       200    //长按时间
#define SINGLE_KEY_TIME     5      // 短按时间

#define N_KEY         0             //没有按键按下

#define KEY_1_SHORT  4
#define KEY_1_LONG   5
#define KEY_2_SHORT  6
#define KEY_2_LONG   7
#define SKU_MAX      10

typedef enum KEY_STD
{
	KEY_UP_SHORT_STD = 1,
	KEY_UP_LONG_STD,
	KEY_DOWN_SHORT_STD,
	KEY_DOWN_LONG_STD
};


typedef enum SKU
{
	K9011 = 1,
	K9018,
	K9019,
	K9025,
	K9029,
	K8104,
	K8105,
	K9028,
	K9014,
	K9017,
};

void key_handle(void);
void Key_Init_Config ( void );


#endif


