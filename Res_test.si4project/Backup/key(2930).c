#include "key.h"
#include "system_digital_tube.h"


void Key_Init_Config ( void )
{
	P3M5 = 0x61;                        //P35上拉输入
	P2M5 = 0x61;                        //P25上拉输入
}

static unsigned char KEY_UP_Driver ( void )
{
	static unsigned char key_state = 0;
	static unsigned int key_time = 0;
	unsigned char key_press, key_return;

	key_return = N_KEY;

	key_press = KEY_1;
	switch ( key_state )
	{
		case KEY_STATE_0:
			if ( key_press == 0 )
			{
				key_time = 0;
				key_state = KEY_STATE_1;
			}
			break;

		case KEY_STATE_1:
			if ( key_press == 0 )
			{
				key_time++;
				if ( key_time>=SINGLE_KEY_TIME )
				{
					key_state = KEY_STATE_2;
				}
			}
			else
			{
				key_state = KEY_STATE_0;
			}
			break;

		case KEY_STATE_2:
			if ( key_press == 1 )
			{
				key_return = KEY_1_SHORT;
				key_state = KEY_STATE_0;
			}
			else
			{
				key_time++;

				if ( key_time >= LONG_KEY_TIME )
				{
					key_return = KEY_1_LONG;
					key_state = KEY_STATE_3;
				}
			}
			break;

		case KEY_STATE_3:
			if ( key_press == 1 )
			{
				key_state = KEY_STATE_0;
			}
			break;

		default:
			key_state = KEY_STATE_0;
			break;
	}

	return key_return;

}


static unsigned char KEY_Down_Driver ( void )
{
	static unsigned char key_state = 0;
	static unsigned int key_time = 0;
	unsigned char key_press, key_return;

	key_return = N_KEY;

	key_press = KEY_2;
	switch ( key_state )
	{
		case KEY_STATE_0:
			if ( key_press == 0 )
			{
				key_time = 0;
				key_state = KEY_STATE_1;
			}
			break;

		case KEY_STATE_1:
			if ( key_press == 0 )
			{
				key_time++;
				if ( key_time>=SINGLE_KEY_TIME )
				{
					key_state = KEY_STATE_2;
				}
			}
			else
			{
				key_state = KEY_STATE_0;
			}
			break;

		case KEY_STATE_2:
			if ( key_press == 1 )
			{
				key_return = KEY_2_SHORT;
				key_state = KEY_STATE_0;
			}
			else
			{
				key_time++;

				if ( key_time >= LONG_KEY_TIME )
				{
					key_return = KEY_2_LONG;
					key_state = KEY_STATE_3;
				}
			}
			break;

		case KEY_STATE_3:
			if ( key_press == 1 )
			{
				key_state = KEY_STATE_0;
			}
			break;

		default:
			key_state = KEY_STATE_0;
			break;
	}

	return key_return;

}


static u8 key_scanf ( void )
{
	u8 key_up = 0,key_down = 0;
	key_up = KEY_UP_Driver();
	key_down = KEY_Down_Driver();
	if ( key_up == KEY_1_SHORT )
	{
		return KEY_UP_SHORT_STD;
	}
	else if ( key_up == KEY_1_LONG )
	{
		return KEY_UP_LONG_STD;
	}
	if ( key_down == KEY_2_SHORT )
	{
		return KEY_DOWN_SHORT_STD;
	}
	else if ( key_down == KEY_2_LONG )
	{
		return KEY_DOWN_LONG_STD;
	}
	return N_KEY;
}

static void Key_SKU_display ( void )
{
		tube_num.SKU_std++;
		if ( tube_num.SKU_std > SKU_MAX )
		{
			tube_num.SKU_std = 1;
		}
	
	switch ( tube_num.SKU_std )
	{
		case 1:
			tube_num.bit1 = 9;
			tube_num.bit2 = 0;
			tube_num.bit3 = 1;
			tube_num.bit4 = 1;
			break;
		case 2:
			tube_num.bit1 = 9;
			tube_num.bit2 = 0;
			tube_num.bit3 = 1;
			tube_num.bit4 = 8;
			break;
		case 3:
			tube_num.bit1 = 9;
			tube_num.bit2 = 0;
			tube_num.bit3 = 1;
			tube_num.bit4 = 9;

			break;
		case 4:
			tube_num.bit1 = 9;
			tube_num.bit2 = 0;
			tube_num.bit3 = 2;
			tube_num.bit4 = 5;
			break;
		case 5:
			tube_num.bit1 = 9;
			tube_num.bit2 = 0;
			tube_num.bit3 = 2;
			tube_num.bit4 = 9;
			break;
		case 6:
			tube_num.bit1 = 8;
			tube_num.bit2 = 1;
			tube_num.bit3 = 0;
			tube_num.bit4 = 4;
			break;
		case 7:
			tube_num.bit1 = 8;
			tube_num.bit2 = 1;
			tube_num.bit3 = 0;
			tube_num.bit4 = 5;
			break;
		case 8:
			tube_num.bit1 = 9;
			tube_num.bit2 = 0;
			tube_num.bit3 = 2;
			tube_num.bit4 = 8;
			break;
		case 9:
			tube_num.bit1 = 9;
			tube_num.bit2 = 0;
			tube_num.bit3 = 1;
			tube_num.bit4 = 4;
			break;
		case 10:
			tube_num.bit1 = 9;
			tube_num.bit2 = 0;
			tube_num.bit3 = 1;
			tube_num.bit4 = 7;
			break;
	}
}


void key_handle ( void )
{
	u8 value = 0;
	value = key_scanf ();
	switch ( value )
	{
		case KEY_UP_SHORT_STD:
			 Key_SKU_display ();
			break;
		case KEY_UP_LONG_STD:
			tube_num.tube_std = DIGITAL_TUBE_ON;
			break;
		case KEY_DOWN_SHORT_STD:
			
			break;
		case KEY_DOWN_LONG_STD:
			tube_num.tube_std = DIGITAL_TUBE_OFF;
			break;
	}

}

