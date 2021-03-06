#include "system_digital_tube.h"

digital_tube_value_t tube_bit = {0,0,0,0,0};
digital_tube_value_t tube_num = {0,0,0,0,0};


void Tube_Init_Config ( void )
{
	P1M0 = 0XC1;                        //设置成推挽输出
	P1M1 = 0XC1;                        //设置成推挽输出
	P1M2 = 0XC1;                        //设置成推挽输出
	P1M3 = 0XC1;						//设置成推挽输出
	P1M4 = 0XC1; 					   //设置成推挽输出
	P1M5 = 0XC1; 					   //设置成推挽输出
	P1M6 = 0XC1;						  //设置成推挽输出
	P0M4 = 0XC1;						  //设置成推挽输出
	P0M5 = 0XC1; 					   //设置成推挽输出
	P0M6 = 0XC1;						  //设置成推挽输出
	P0M7 = 0XC1; 					   //设置成推挽输出
}

static void digital_tube_set_num ( u8 num )
{
	switch ( num )
	{
		case 0:
			DIGITAL_TUBE_A = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_B = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_C = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_D = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_E = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_F = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_G = DIGITAL_TUBE_PIN_OFF;
			break;

		case 1:
			DIGITAL_TUBE_A = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_B = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_C = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_D = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_E = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_F = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_G = DIGITAL_TUBE_PIN_OFF;
			break;

		case 2:
			DIGITAL_TUBE_A = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_B = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_C = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_D = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_E = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_F = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_G = DIGITAL_TUBE_PIN_ON;
			break;

		case 3:
			DIGITAL_TUBE_A = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_B = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_C = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_D = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_E = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_F = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_G = DIGITAL_TUBE_PIN_ON;
			break;

		case 4:
			DIGITAL_TUBE_A = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_B = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_C = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_D = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_E = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_F = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_G = DIGITAL_TUBE_PIN_ON;
			break;

		case 5:
			DIGITAL_TUBE_A = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_B = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_C = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_D = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_E = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_F = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_G = DIGITAL_TUBE_PIN_ON;
			break;

		case 6:
			DIGITAL_TUBE_A = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_B = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_C = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_D = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_E = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_F = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_G = DIGITAL_TUBE_PIN_ON;
			break;

		case 7:
			DIGITAL_TUBE_A = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_B = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_C = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_D = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_E = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_F = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_G = DIGITAL_TUBE_PIN_OFF;
			break;

		case 8:
			DIGITAL_TUBE_A = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_B = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_C = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_D = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_E = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_F = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_G = DIGITAL_TUBE_PIN_ON;
			break;

		case 9:
			DIGITAL_TUBE_A = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_B = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_C = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_D = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_E = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_F = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_G = DIGITAL_TUBE_PIN_ON;
			break;
		case 0xff:
			DIGITAL_TUBE_A = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_B = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_C = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_D = DIGITAL_TUBE_PIN_OFF;
			DIGITAL_TUBE_E = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_F = DIGITAL_TUBE_PIN_ON;
			DIGITAL_TUBE_G = DIGITAL_TUBE_PIN_ON;
			break;
	}


}

void digital_tube_timer_handle ( digital_tube_value_t tube,digital_tube_value_t value )
{
	if ( tube.bit1 == DIGITAL_TUBE_SET )
	{
		digital_tube_set_num ( value.bit1 );
		DIGITAL_BIT1_SET;
		DIGITAL_BIT2_CLEAR;
		DIGITAL_BIT3_CLEAR;
		DIGITAL_BIT4_CLEAR;
	}
	 if ( tube.bit2 == DIGITAL_TUBE_SET )
	{
		digital_tube_set_num ( value.bit2 );
		DIGITAL_BIT1_CLEAR;
		DIGITAL_BIT2_SET;
		DIGITAL_BIT3_CLEAR;
		DIGITAL_BIT4_CLEAR;

	}
	 if ( tube.bit3 == DIGITAL_TUBE_SET )
	{
		digital_tube_set_num ( value.bit3 );
		DIGITAL_BIT1_CLEAR;
		DIGITAL_BIT2_CLEAR;
		DIGITAL_BIT3_SET;
		DIGITAL_BIT4_CLEAR;

	}
	 if ( tube.bit4 == DIGITAL_TUBE_SET )
	{
		digital_tube_set_num ( value.bit4 );
		DIGITAL_BIT1_CLEAR;
		DIGITAL_BIT2_CLEAR;
		DIGITAL_BIT3_CLEAR;
		DIGITAL_BIT4_SET;

	}

}




