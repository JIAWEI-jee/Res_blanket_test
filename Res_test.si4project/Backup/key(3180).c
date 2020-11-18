#include "key.h"


void Key_Init_Config(void)
{
    P3M5 = 0x61;                        //P35上拉输入
	P2M5 = 0x61;                        //P25上拉输入
}

