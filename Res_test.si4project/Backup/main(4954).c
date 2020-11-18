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

	while ( 1 )
	{

	}
}

