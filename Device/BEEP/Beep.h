#ifndef _BEEP_H
#define _BEEP_H
#include "HC89F303B.h"

#define  BEEP   P1_7


typedef enum
{
 BEEP_ERROR = 0,
 BEEP_OK,
}BEEP_STD;

typedef struct BEEP_VALUE
{
 u8 beep_std;
 u8 beep_std_of;
}BEEP_VALUE_T;
	
extern BEEP_VALUE_T beep;
void Beep_Init_Config(void);
void set_Beep_pwm(u8 duty);
void beep_Blink ( void );

#endif


