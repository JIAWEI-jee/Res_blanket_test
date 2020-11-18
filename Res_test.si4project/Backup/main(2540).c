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
#include "key.h"
#include "uart.h"
#include "adc.h"

u8 systick_1s_cnt = 0;

void main ( void )
{
	device_init ( );
	EA = 1;//开启总中断
	LED_Init_Config ( );
	Tube_Init_Config ( );
	Beep_Init_Config();
	timer_Init_Config();
	Key_Init_Config ( );
	ADC_Init_Config();
	uart_init();


	gm_printf ( "\r\n==================================\r\n" );
	gm_printf ( "test_soft V1.00.00 \r\n");
	gm_printf ( "\r\n==================================\r\n" );

//	set_Beep_pwm ( 20 );
	while ( 1 )
	{

		if ( systick_10ms )
		{
			systick_10ms = 0;
			key_handle();
			
			if(++systick_1s_cnt > 100)
			{
			   systick_1s_cnt = 0;
				
			}
			
		}
	}
}

