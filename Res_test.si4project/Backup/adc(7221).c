#include "adc.h"




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

	P2M6 = 0XC1;        //设置P26推挽输出
	P2M7 = 0XC1;        //设置P27推挽输出
	ADCC0 = 0x83;		//打开ADC转换电源			00 VDD
//											01 内部4V
//											10 内部3V
//											11 内部2V
//1、 内部参考电压选择为 2V 时， VDD 电压须高于 2.7V；
//    内部参考电压选择为 3V 时， VDD 电压须高于 3.5V；
//    内部参考电压选择为 4V 时， VDD 电压须高于4.5V。
//2、 系统进入掉电模式前，建议将 ADC 参考电压选择非 VDD，可以进一步降低系统功耗。
	delay_us ( 20 );						//延时20us，确保ADC系统稳定
	ADCC2 = 0x4B;						//转换结果12位数据，数据右对齐，ADC时钟16分频 16M/16 = 1MHz
}

static u16 get_adc_val_ch0 ( void )
{
	u16 adc_val = 0;
	ADCC1 = 0x00;                   //CH0

	ADCC0 |= 0x40;					//启动ADC转换
	while ( ! ( ADCC0&0x20 ) );			//等待ADC转换结束
	ADCC0 &=~ 0x20;					//清除标志位
	adc_val = ADCR;					//获取ADC的值
	return adc_val;
}

static u16 get_adc_val_ch1 ( void )
{
	u16 adc_val = 0;
	ADCC1 = 0x01;                   //CH0

	ADCC0 |= 0x40;					//启动ADC转换
	while ( ! ( ADCC0&0x20 ) );			//等待ADC转换结束
	ADCC0 &=~ 0x20;					//清除标志位
	adc_val = ADCR;					//获取ADC的值


	// ADC_printf("P01_ADC = %d \r\n",adc_val);
	return adc_val;
}

static u16 get_adc_val_ch2 ( void )
{
	u16 adc_val = 0;
	ADCC1 = 0x02;                   //CH0

	ADCC0 |= 0x40;					//启动ADC转换
	while ( ! ( ADCC0&0x20 ) );			//等待ADC转换结束
	ADCC0 &=~ 0x20;					//清除标志位
	adc_val = ADCR;					//获取ADC的值

	return adc_val;
}

static u16 get_adc_val_ch3 ( void )
{
	u16 adc_val = 0;
	ADCC1 = 0x03;                   //CH0

	ADCC0 |= 0x40;					//启动ADC转换
	while ( ! ( ADCC0&0x20 ) );			//等待ADC转换结束
	ADCC0 &=~ 0x20;					//清除标志位
	adc_val = ADCR;					//获取ADC的值
	// ADC_printf("P01_ADC = %d \r\n",adc_val);
	return adc_val;
}





