#include "Beep.h"
#include "system_digital_tube.h"
u8 pwm_period = 0;
void set_Beep_pwm(u8 duty)
{
	u32 tep = (u32)duty*pwm_period/100;
	PWM3D = tep;
}



//节奏时长

void Beep_Init_Config ( void )
{
	P1M7 = 0XC1;                        //设置P17推挽输出
    PWM3_MAP = 0x00;					//PWM3ӳ��P00��
    	pwm_period = (31250/200)-1;			//31250 = 4000000/128
	PWM3P = pwm_period;					//PWM����  
	//set_pwm(10);
	PWM3C = 0x91; 						//ʹ��PWM3���ر��жϣ����������ʱ��128��Ƶ 111
}
void buzzer ( u16 f,u16 time_ms ) //发声，f音调，time_ms维持时间Voice, f tone, time_ Ms duration
{
	u16 time = ( MAIN_Fosc / 9600 ) *time_ms;
	u16 C= MAIN_Fosc/ ( 8*f );
	u16 x=0;
	for ( ; time>0; time-- )
	{
		if ( x>C )
		{
			BEEP=0;
			x=0;
		}
		else
		{
			x++;
			BEEP=1;
		}
	}
	BEEP=1;
}




