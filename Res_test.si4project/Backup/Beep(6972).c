#include"Beep.h"


const u16 note[3][8]=
{
	{0,262,294,330,349,392,440,494},
	{0,523,578,659,698,784,880,988},
	{0,1046,1175,1318,1397,1568,1760,1976}
};

//节奏时长
u16 bpm184[]= {0,1304,652,326,162,81};
const u16 bpm75[] = {0,3200,1600,800,400,200,100};

void Beep_Init_Config ( void )
{
	P1M7 = 0XC1;                        //设置P22推挽输出

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

void BEEP_Play ( void )
{
	buzzer ( note[1][5],bpm75[4] );
	buzzer ( note[1][3],bpm75[4] );
	buzzer ( note[1][2],bpm75[4] );

	buzzer ( note[1][1],bpm75[2]+bpm75[5] );
	buzzer ( note[1][2],bpm75[4] );
	buzzer ( note[0][7],bpm75[4] );
	buzzer ( note[0][6],bpm75[4] );

	buzzer ( note[0][5],bpm75[2]+bpm75[5] );
	buzzer ( note[1][7],bpm75[4] );
	buzzer ( note[1][6],bpm75[4] );
	buzzer ( note[1][7],bpm75[4] );

	buzzer ( note[1][5],bpm75[4]+bpm75[6] );
	buzzer ( note[0][6],bpm75[5] );
	buzzer ( note[1][4],bpm75[4] );
	buzzer ( note[1][3],bpm75[4] );
	buzzer ( note[1][2],bpm75[5] );
	buzzer ( note[1][3],bpm75[5] );
	buzzer ( note[1][4],bpm75[5] );
	buzzer ( note[1][3],bpm75[5] );
	buzzer ( note[1][5],bpm75[4]+bpm75[6] );
	buzzer ( note[1][3],bpm75[5] );

	buzzer ( note[1][2],bpm75[5] );
	buzzer ( note[1][3],bpm75[5] );
	buzzer ( note[1][5],bpm75[5] );
	buzzer ( note[1][2],bpm75[5] );
	buzzer ( note[1][3],bpm75[5] );
	buzzer ( note[1][4],bpm75[5] );
	buzzer ( note[1][3],bpm75[5] );
	buzzer ( note[1][2],bpm75[5] );
	buzzer ( note[1][1],bpm75[4]+bpm75[6] );
	buzzer ( note[1][5],bpm75[4] );

	buzzer ( note[0][7],bpm75[4] );
	buzzer ( note[1][2],bpm75[4] );
	buzzer ( note[0][6],bpm75[4] );
	buzzer ( note[1][1],bpm75[4] );
	buzzer ( note[0][5],bpm75[3]+bpm75[6] );
	buzzer ( note[0][6],bpm75[5] );
	buzzer ( note[1][1],bpm75[5] );

	buzzer ( note[0][5],bpm75[1] );

	buzzer ( note[0][3],bpm75[3] );
	buzzer ( note[0][5],bpm75[4]+bpm75[5] );
	buzzer ( note[0][6],bpm75[5] );
	buzzer ( note[1][1],bpm75[4]+bpm75[5] );
	buzzer ( note[1][2],bpm75[5] );
	buzzer ( note[0][6],bpm75[5] );
	buzzer ( note[1][1],bpm75[5] );
	buzzer ( note[0][5],bpm75[4] );

	buzzer ( note[1][5],bpm75[4]+bpm75[4] );
	buzzer ( note[2][1],bpm75[4] );
	buzzer ( note[1][6],bpm75[5] );
	buzzer ( note[1][5],bpm75[5] );
	buzzer ( note[1][3],bpm75[5] );
	buzzer ( note[1][5],bpm75[5] );
	buzzer ( note[1][2],bpm75[2] );

	buzzer ( note[1][2],bpm75[4] );
	buzzer ( note[1][2],bpm75[5] );
	buzzer ( note[1][3],bpm75[5] );
	buzzer ( note[0][7],bpm75[4] );
	buzzer ( note[0][6],bpm75[4] );
	buzzer ( note[0][5],bpm75[4]+bpm75[5] );
	buzzer ( note[0][6],bpm75[5] );
	buzzer ( note[1][1],bpm75[4] );
	buzzer ( note[1][2],bpm75[4] );

	buzzer ( note[0][3],bpm75[4] );
	buzzer ( note[1][1],bpm75[4] );
	buzzer ( note[0][6],bpm75[5] );
	buzzer ( note[0][5],bpm75[5] );
	buzzer ( note[0][6],bpm75[5] );
	buzzer ( note[1][1],bpm75[5] );
	buzzer ( note[0][5],bpm75[2] );

	buzzer ( note[1][3],bpm75[4]+bpm75[5] );
	buzzer ( note[1][5],bpm75[5] );
	buzzer ( note[0][7],bpm75[4] );
	buzzer ( note[1][2],bpm75[4] );
	buzzer ( note[0][6],bpm75[5] );
	buzzer ( note[1][1],bpm75[5] );
	buzzer ( note[0][5],bpm75[4] );
	buzzer ( note[0][0],bpm75[3] );

	buzzer ( note[0][3],bpm75[5] );
	buzzer ( note[0][5],bpm75[5] );
	buzzer ( note[0][3],bpm75[4] );
	buzzer ( note[0][5],bpm75[5] );
	buzzer ( note[0][6],bpm75[5] );
	buzzer ( note[0][7],bpm75[5] );
	buzzer ( note[1][2],bpm75[5] );
	buzzer ( note[0][6],bpm75[3]+bpm75[4] );
	buzzer ( note[0][5],bpm75[5] );
	buzzer ( note[0][6],bpm75[5] );


	buzzer ( note[1][1],bpm75[4] );
	buzzer ( note[1][2],bpm75[5] );
	buzzer ( note[1][5],bpm75[4] );
	buzzer ( note[1][3],bpm75[4] );
	buzzer ( note[1][2],bpm75[4] );
	buzzer ( note[1][3],bpm75[5] );
	buzzer ( note[1][2],bpm75[5] );
	buzzer ( note[1][1],bpm75[4] );
	buzzer ( note[0][6],bpm75[5] );
	buzzer ( note[0][5],bpm75[5] );

	buzzer ( note[0][3],bpm75[3] );
	buzzer ( note[1][1],bpm75[3] );
	buzzer ( note[0][6],bpm75[5] );
	buzzer ( note[1][1],bpm75[5] );
	buzzer ( note[0][6],bpm75[5] );
	buzzer ( note[0][5],bpm75[5] );
	buzzer ( note[0][3],bpm75[5] );
	buzzer ( note[0][5],bpm75[5] );
	buzzer ( note[0][6],bpm75[5] );
	buzzer ( note[1][1],bpm75[5] );

	buzzer ( note[0][5],bpm75[3]+bpm75[4] );
	buzzer ( note[1][3],bpm75[5] );
	buzzer ( note[1][5],bpm75[5] );
	buzzer ( note[1][2],bpm75[5] );
	buzzer ( note[1][3],bpm75[5] );
	buzzer ( note[1][2],bpm75[5] );
	buzzer ( note[1][1],bpm75[5] );
	buzzer ( note[0][7],bpm75[4] );
	buzzer ( note[0][6],bpm75[4] );

	buzzer ( 196,bpm75[1] );
}


