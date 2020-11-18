#include "timer.h"
#include "system_digital_tube.h"

u8 systick_10ms = 0;
u16 systick_2ms = 0;
void timer_Init_Config(void)
{
	    TCON1 = 0x00;						//Tx0定时器时钟为Fosc/12
		TMOD = 0x00;						//16位重装载定时器/计数器
		//定时10ms
		//反推初值	= 65536 - ((10/1000) / (1/(Fosc / Timer分频系数)))
		//			= 65536 - ((10/1000) / (1/(16000000 / 12)))
		//			= 65536 - 13333
		//			= 0xCBEC
		// TH0 = 0xCB;
		// TL0 = 0xEB;							//T0定时时间10ms  16MHZ
		TH0 = 0xF5;
		TL0 = 0x96; 						//T0定时时间2ms  16MHZ
		TF0 = 0;//清除中断标志
		ET0 = 1;//打开T0中断
		TR0 = 1;//使能T0


}
void Timer0Interrupt (void) interrupt TIMER0_VECTOR
{
    systick_2ms++;
	if(++systick_2ms % 5 == 0)
    { 
    systick_10ms = 1;
	  }
    if(systick_2ms > 0xfff0)
		systick_2ms = 0;
    digital_tube_timer_handle ( tube_num );
	  TF0 = 0;//清除中断标志
	//具体代码
}


