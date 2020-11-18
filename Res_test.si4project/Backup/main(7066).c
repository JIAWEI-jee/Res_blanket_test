/**
*   1cai
*	@Examle Version		V1.0.2.0
*	@Demo 	Version		V1.0.2.0
*	@Date				2020.11.07
*	����̺������԰�
**/


#define	ALLOCATE_EXTERN
#include "HC89F303B.h"
#include "LED.h"
#include "system_digital_tube.h"
#include "Beep.h"
#include "timer.h"
#include "key.h"


void main ( void )
{
	device_init ( );
	EA = 1;//�������ж�
	LED_Init_Config ( );
	Tube_Init_Config ( );
	Beep_Init_Config();
	timer_Init_Config();
	Key_Init_Config ( );
	uart_init();
//	set_Beep_pwm ( 50 );
	while ( 1 )
	{

		if ( systick_10ms )
		{
			systick_10ms = 0;
			key_handle();
		}
	}
}

