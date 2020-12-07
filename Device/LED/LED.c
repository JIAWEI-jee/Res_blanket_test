#include "LED.h"


void device_init ( void )
{
	/************************************系统初始化****************************************/
	// CLKSWR = 0x51;						//选择内部高频RC为系统时钟，内部高频RC 2分频，Fosc=16MHz
	CLKSWR = 0x51;  //8分频 32/8 = 4M
	CLKDIV = 0x01;						//Fosc 1分频得到Fcpu，Fcpu=16MHz
							//P02设置为非施密特数字输入
}


void LED_Init_Config ( void )
{
	P2M0 = 0XC1;                        //设置P20推挽输出
	P2M1 = 0XC1;                        //设置P21推挽输出
	P2M2 = 0XC1;                        //设置P22推挽输出
	LED0 = 1;
	LED1 = 1;
	LED2 = 1;
}

 void LED_All_off(void)
{
	LED0 = 1;
	LED1 = 1;
	LED2 = 1;
}

 void LED_All_on(void)
{
	LED0 = 0;
	LED1 = 0;
	LED2 = 0;
}


static void LED_Toggle_Set ( Led_ID ledx )
{
	
	switch ( ledx )
	{
		case RED:
			LED0 = !LED0;
			break;
		case GREEN:
			LED1 = !LED1;
			break;
		case YELLOW:
			LED2 = !LED2;
			break;
	}

}



