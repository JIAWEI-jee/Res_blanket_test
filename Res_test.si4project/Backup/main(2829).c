/**
*   1cai
*	@Examle Version		V1.0.2.0
*	@Demo 	Version		V1.0.2.0
*	@Date				2020.11.07
*	·¢ÈÈÌºµç×è²âÊÔ°å
**/


#define	ALLOCATE_EXTERN
#include "HC89F303B.h"
#include "LED.h"
#include "system_digital_tube.h"
u32 cnt = 0;

void main ( void )
{
	device_init ( );
	LED_Init_Config ( );
	Tube_Init_Config ( );
	Beep_Init_Config();
	tube_num.bit1 = 9;
	tube_num.bit2 = 0;
	tube_num.bit3 = 1;
	tube_num.bit4 = 2;
	while ( 1 )
	{
		//buzzer(u16 f,u16 time_ms);

		cnt++;
		if ( cnt>20 )
		{
			digital_tube_timer_handle ( tube_num );
			cnt = 0;
		}
	}
}

