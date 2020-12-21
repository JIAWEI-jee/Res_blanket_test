#include "adc.h"
#include "uart.h"
#include "system_digital_tube.h"
#include "key.h"
#include "LED.h"
#include "Beep.h"


//const u16 SKU_RES_Table = [];

u16 systick_2min = 0;


void delay_us ( u16 us ) //16MHz
{
	while ( --us )
	{
		_nop_();
		_nop_();
	}
}

void ADC_Init_Config ( void )
{
	P0M0 = 0x01;		//P00设置为模拟输入
	P0M1 = 0x01;        //P01设置为模拟输入
	P0M2 = 0x01;		//P02设置为模拟输入
	P0M3 = 0x01;        //P03设置为模拟输入
	P2M7 = 0x01;        //P27设置为模拟输入

	P3M5 = 0XC1;        //设置P35推挽输出
	P2M5 = 0XC1;        //设置P25推挽输出
	ADCC0 = 0x81;		//打开ADC转换电源			00 VDD
//											01 内部4V
//											10 内部3V
//											11 内部2V
//1、 内部参考电压选择为 2V 时， VDD 电压须高于 2.7V；
//    内部参考电压选择为 3V 时， VDD 电压须高于 3.5V；
//    内部参考电压选择为 4V 时， VDD 电压须高于4.5V。
//2、 系统进入掉电模式前，建议将 ADC 参考电压选择非 VDD，可以进一步降低系统功耗。
	delay_us ( 20 );						//延时20us，确保ADC系统稳定
	ADCC2 = 0x4B;						//转换结果12位数据，数据右对齐，ADC时钟16分频 16M/16 = 1MHz
	RT_0 = 1;
	RT_1 = 1;
}

static u16 get_adc_val_chRL ( void )
{
	u16 adc_val = 0;
	ADCC1 = 0x0f;                   //CH15

	ADCC0 |= 0x40;					//启动ADC转换
	while ( ! ( ADCC0&0x20 ) );			//等待ADC转换结束
	ADCC0 &=~ 0x20;					//清除标志位
	adc_val = ADCR;					//获取ADC的值
	delay_us ( 20 );
	return adc_val;
}

static u8 get_ADC_value_chRL ( u16* u_RL )
{
	float temp = 0;
	temp = ( float ) get_adc_val_chRL ( );
//  KEY_printf ( "chRL_adc = %f \r\n",temp ); //pjw set
	if ( temp > 4090 )
	{
		return EORROR;
	}
	temp = ( float ) ( temp/4095*ADC_CAILI );
	temp = temp/1000;
	temp = temp/0.124;
	KEY_printf ( "chRL_r = %f \r\n",temp ); //pjw set
	*u_RL = ( u16 ) temp;
	if ( temp >= 32 )
	{
		return EORROR;
	}

	return SUCCESS;
}

static u16 get_adc_val_ch0 ( void )
{
	u16 adc_val = 0;
	ADCC1 = 0x00;                   //CH0

	ADCC0 |= 0x40;					//启动ADC转换
	while ( ! ( ADCC0&0x20 ) );			//等待ADC转换结束
	ADCC0 &=~ 0x20;					//清除标志位
	adc_val = ADCR;					//获取ADC的值
	delay_us ( 20 );
	return adc_val;
}

static u16 get_adc_val_ch1 ( void )
{
	u16 adc_val = 0;
	ADCC1 = 0x01;                   //CH1

	ADCC0 |= 0x40;					//启动ADC转换
	while ( ! ( ADCC0&0x20 ) );			//等待ADC转换结束
	ADCC0 &=~ 0x20;					//清除标志位

	adc_val = ADCR;					//获取ADC的值

	delay_us ( 20 );
	// ADC_printf("P01_ADC = %d \r\n",adc_val);
	return adc_val;
}

static u16 get_adc_val_ch2 ( void )
{
	u16 adc_val = 0;
	ADCC1 = 0x02;                   //CH2

	ADCC0 |= 0x40;					//启动ADC转换
	while ( ! ( ADCC0&0x20 ) );			//等待ADC转换结束
	ADCC0 &=~ 0x20;					//清除标志位
	adc_val = ADCR;					//获取ADC的值
	delay_us ( 20 );
	return adc_val;
}

static u16 get_adc_val_ch3 ( void )
{
	u16 adc_val = 0;
	ADCC1 = 0x03;                   //CH3

	ADCC0 |= 0x40;					//启动ADC转换
	while ( ! ( ADCC0&0x20 ) );			//等待ADC转换结束
	ADCC0 &=~ 0x20;					//清除标志位
	adc_val = ADCR;					//获取ADC的值
	delay_us ( 20 );
	// ADC_printf("P01_ADC = %d \r\n",adc_val);
	return adc_val;
}

static void get_ADC_value_ch02ch3 ( u16* ch0_value,u16* ch1_value,u16* ch2_value,u16* ch3_value )
{
	*ch0_value = get_adc_val_ch0 ();
	*ch1_value = get_adc_val_ch1 ();
	*ch2_value = get_adc_val_ch2 ();
	*ch3_value = get_adc_val_ch3 ();
}


static void Voltg_calc ( u16* ch0_v,u16* ch1_v,u16* ch2_v,u16* ch3_v )
{
	u16 ch0_ad_value = 0,ch1_ad_value = 0,ch2_ad_value = 0,ch3_ad_value = 0;
	float temp = 0;
	get_ADC_value_ch02ch3 ( &ch0_ad_value,&ch1_ad_value,&ch2_ad_value,&ch3_ad_value );
//   ADC_printf ( "ch0_ad = %d ch1_ad = %d ch2_ad = %d ch3_ad = %d \r\n",ch0_ad_value,ch1_ad_value,ch2_ad_value,ch3_ad_value ); //pjw set

	temp = ( float ) ch0_ad_value/4095*ADC_CAILI;
//	KEY_printf ( "adv0f = %f \r\n",temp ); //pjw set
	* ch0_v = ( u16 ) temp;
//	KEY_printf ( "rtemper1 = %d \r\n",*ch0_v ); //pjw set

	temp = 0;

	temp = ( float ) ch1_ad_value/4095;
//	KEY_printf ( "adv1_temp = %f \r\n",temp ); //pjw set
	temp = temp*ADC_CAILI;
	* ch1_v = ( u16 ) temp;
//	KEY_printf ( "rtemper2 = %d \r\n",*ch1_v ); //pjw set

	temp = 0;

	temp = ( float ) ch2_ad_value/4095*ADC_CAILI;
//	KEY_printf ( "adv2f = %f \r\n",temp ); //pjw set
	* ch2_v = ( u16 ) temp;
//	KEY_printf ( "heat1 = %d \r\n",*ch2_v ); //pjw set

	temp = 0;

	temp = ( float ) ch3_ad_value/4095*ADC_CAILI;
//	KEY_printf ( "adv3f = %f \r\n",temp ); //pjw set
	* ch3_v = ( u16 ) temp;
//	KEY_printf ( "heat2 = %d \r\n",*ch3_v ); //pjw set

}

u8 Cacl_Res ( u16* temper_res,u16* heat_res )
{
	float temp =0,res = 0;
	u16 ch0 = 0,ch1 = 0,ch2 = 0,ch3 = 0;
	Voltg_calc ( &ch0,&ch1,&ch2,&ch3 );

//	ADC_printf ( "ch0 = %d ch1 = %d ch2 = %d ch3 = %d \r\n",ch0,ch1,ch2,ch3 ); //pjw set
	if ( ( ch1 < 90 ) || ( ch3 < 90 ) )
	{
		return EORROR;
	}

	temp = (  ( ( float ) ch0 /1000 ) - ( ( float ) ch1/1000 ) ) / ( ( ( float ) ch1/1000 ) /510 );
	ADC_printf ( "temper_res = %f \r\n",temp ); //pjw set
	*temper_res = ( u16 ) temp;
//	ADC_printf ( "temper_res = %d \r\n",* temper_res ); //pjw set

	temp = (  ( ( float ) ch2 /1000 ) - ( ( float ) ch3/1000 ) ) / ( ( ( float ) ch3/1000 ) /510 );
	ADC_printf ( "heat_res = %f \r\n",temp ); //pjw set
	*heat_res = ( u16 ) temp;
//	ADC_printf ( "heat_res = %d \r\n",* heat_res ); //pjw set

	return SUCCESS;
}
u8 SKU_Res_test ( void )
{
	u16 Temper_res = 0,Heat_res = 0;
	if ( Cacl_Res ( &Temper_res,&Heat_res ) == SUCCESS )
	{
		systick_2min = 0;
		switch ( tube_num.SKU_std )
		{
			case K9011:
			case K9019:
			case K9029:
			case K9014:
			case K9045:
				if ( ( Temper_res > K9011_MIN_TEMPER ) && ( Temper_res < K9011_MAX_TEMPER ) )
				{
					if ( ( Heat_res >K9011_MIN_HEAT ) && ( Heat_res < K9011_MAX_HEAT ) )
					{
						return Res_test_OK;
					}
					else
					{
						return Heat_test_fail;
					}
				}
				else
				{
					return Temper_test_fail;
				}
				break;
			case K9018:
			case K9025:
				if ( ( Temper_res > K9018_MIN_TEMPER ) && ( Temper_res < K9018_MAX_TEMPER ) )
				{
					if ( ( Heat_res > K9018_MIN_HEAT ) && ( Heat_res < K9018_MAX_HEAT ) )
					{
						return Res_test_OK;
					}
					else
					{
						return Heat_test_fail;
					}
				}
				else
				{
					return Temper_test_fail;
				}
				break;
			case K9028:
				if ( ( Temper_res > K9028_MIN_TEMPER ) && ( Temper_res < K9028_MAX_TEMPER ) )
				{
					if ( ( Heat_res > K9028_MIN_HEAT ) && ( Heat_res < K9028_MAX_HEAT ) )
					{
						return Res_test_OK;
					}
					else
					{
						return Heat_test_fail;
					}
				}
				else
				{
					return Temper_test_fail;
				}
				break;
			case K9017:
				if ( ( Temper_res > K9017_MIN_HEAT ) && ( Temper_res < K9017_MAX_TEMPER ) )
				{
					if ( ( Heat_res > K9017_MIN_HEAT ) && ( Heat_res < K9017_MAX_HEAT ) )
					{
						return Res_test_OK;
					}
					else
					{
						return Heat_test_fail;
					}
				}
				else
				{
					return Temper_test_fail;
				}
				break;
			case K8104:
			case K8105:
				if ( ( Temper_res > K8104_MIN_HEAT ) && ( Temper_res < K8104_MAX_TEMPER ) )
				{
					if ( ( Heat_res > K8104_MIN_HEAT ) && ( Heat_res < K8104_MAX_HEAT ) )
					{
						return Res_test_OK;
					}
					else
					{
						return Heat_test_fail;
					}
				}
				else
				{
					return Temper_test_fail;
				}
				break;
		}
	}
	else
	{
		return No_Blanket;
	}
}

void Blanket_Cacl_Process ( void )
{
	get_ADC_value_chRL();

	if ( tube_num.tube_std ==  OFF )
	{
		LED2 = 1;
		LED1 = 1;
		LED0 = 1;
	}
	else
	{

		switch ( SKU_Res_test () )
		{
			case Res_test_OK:
				LED1 = 0;
				LED0 = 1;
				LED2 = 1;
				beep.beep_std = BEEP_OK;
				beep.beep_std_of = 1;
				break;
			case Temper_test_fail:
			case Heat_test_fail:
				LED1 = 1;
				LED2 = 1;
				LED0 = 0;
				beep.beep_std = BEEP_ERROR;
				beep.beep_std_of = 1;
				break;
			case No_Blanket:
				LED2 = !LED2;
				LED1 = 1;
				LED0 = 1;
				break;
		}
		if ( ++systick_2min > TIME2OFF )
		{
			systick_2min = 0;
			tube_num.tube_std = OFF;
		}
	}

}


