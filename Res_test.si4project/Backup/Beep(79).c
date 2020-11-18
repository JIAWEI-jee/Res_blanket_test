#include "Beep.h"
#include "system_digital_tube.h"



//节奏时长

void Beep_Init_Config ( void )
{
	P1M7 = 0XC1;                        //设置P17推挽输出

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




