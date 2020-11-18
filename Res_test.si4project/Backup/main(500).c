/**
*   1cai
*	@Examle Version		V1.0.2.0
*	@Demo 	Version		V1.0.2.0
*	@Date				2020.11.07
*	∑¢»»Ã∫µÁ◊Ë≤‚ ‘∞Â
**/


#define	ALLOCATE_EXTERN
#include "HC89F303B.h"
#include "LED.h"
#include "system_digital_tube.h"


void main ( void )
{
	device_init ( );
	LED_Init_Config ( );
	Tube_Init_Config (  );
  tube_bit.bit1 = 0;
	tube_bit.bit2 = 1;
	tube_bit.bit3 = 0;
	tube_bit.bit4 = 0;
	tube_num.bit1 = 2;
	tube_num.bit2 = 3;
	tube_num.bit3 = 4;
	tube_num.bit4 = 5;
	while ( 1 )
	{
    digital_tube_timer_handle ( tube_bit,tube_num );
	}
}

