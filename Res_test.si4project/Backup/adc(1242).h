#ifndef __ADC_H__
#define __ADC_H__

#include "HC89F303B.h"
#include "intrins.h"//nop

#define RT_0  P2_6
#define RT_1  P2_7

void ADC_Init_Config(void);
void Cacl_Res ( u16* temper_res,u16* heat_res );

#endif
