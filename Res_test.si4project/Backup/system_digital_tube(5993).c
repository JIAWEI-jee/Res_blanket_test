#include "system_digital_tube.h"


void Tube_Init_Config ( void )
{
	P1M0 = 0XC1;                        //设置成推挽输出
	P1M1 = 0XC1;                        //设置成推挽输出
	P1M2 = 0XC1;                        //设置成推挽输出
	P1M0 = 0XC1;						//设置成推挽输出
	P1M1 = 0XC1; 					   //设置成推挽输出
	P1M0 = 0XC1; 					   //设置成推挽输出
	P1M1 = 0XC1;						  //设置成推挽输出
	P1M2 = 0XC1;						  //设置成推挽输出
	P2M2 = 0XC1; 					   //设置成推挽输出
}

