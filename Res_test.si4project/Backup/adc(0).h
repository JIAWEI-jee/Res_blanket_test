#ifndef __ADC_H__
#define __ADC_H__

#include "HC89F303B.h"
#include "intrins.h"//nop

#define SUCCESS  1
#define EORROR   0

typedef enum
{
	K9011_MAX_TEMPER = 690,
	K9011_MIN_TEMPER = 600,
	K9011_MAX_HEAT = 135,
	K9011_MIN_HEAT = 132,        // 公差10cm

	K9018_MAX_TEMPER = 550,
	K9018_MIN_TEMPER = 450,
	K9018_MAX_HEAT = 294,
	K9018_MIN_HEAT = 282,      // 公差10cm

	K9028_MAX_TEMPER = 440,
	K9028_MIN_TEMPER = 380,
	K9028_MAX_HEAT = 86,
	K9028_MIN_HEAT = 81,      // 公差10cm

	K9017_MAX_TEMPER = 320,
	K9017_MIN_TEMPER = 280,
	K9017_MAX_HEAT = 185,
	K9017_MIN_HEAT = 160,    // 公差10cm

	K8104_MAX_TEMPER = 96,
	K8104_MIN_TEMPER = 81,
	K8104_MAX_HEAT = 30,
	K8104_MIN_HEAT = 26,     // 公差10cm
} SKU_MODE_RES;



typedef enum
{
	Res_test_OK = 0,
	Temper_test_fail,
	Heat_test_fail,
	No_Blanket
} Test_Std;

#define RT_0  P3_5
#define RT_1  P2_5

#define ADC_CAILI  4000
#define TIME2OFF   120

void ADC_Init_Config ( void );
u8 Cacl_Res ( u16* temper_res,u16* heat_res );
void Blanket_Cacl_Process ( void );

#endif
