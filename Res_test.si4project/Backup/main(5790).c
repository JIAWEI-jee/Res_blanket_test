/**
*   1cai
*	@Examle Version		V1.0.2.0
*	@Demo 	Version		V1.0.2.0
*	@Date				2020.11.07
*	发热毯电阻测试板
**/


#define	ALLOCATE_EXTERN
#include "HC89F303B.h"
#include "LED.h"
#include "system_digital_tube.h"
#include "Beep.h"
#include "timer.h"

u16  = 0;

void main ( void )
{
	device_init ( );
	EA = 1;//开启总中断
	LED_Init_Config ( );
	Tube_Init_Config ( );
	Beep_Init_Config();
	timer_Init_Config();
	tube_num.bit1 = 9;
	tube_num.bit2 = 0;
	tube_num.bit3 = 1;
	tube_num.bit4 = 2;

	set_Beep_pwm ( 50 );
	while ( 1 )
	{
		//buzzer(50,10);


		if ( systick_10ms )
		{ systick_10ms = 0;
			digital_tube_timer_handle ( tube_num );
			
		}
	}
}

