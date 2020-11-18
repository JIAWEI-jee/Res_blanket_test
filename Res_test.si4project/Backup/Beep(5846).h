#ifndef _BEEP_H
#define _BEEP_H
#include "HC89F303B.h"

#define  BEEP   P1_7

//void BEEP_Play(void);
void Beep_Init_Config(void);
//void buzzer(u16 f,u16 time_ms);
void set_Beep_pwm(u8 duty);

#endif


