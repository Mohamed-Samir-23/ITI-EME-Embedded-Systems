/*
 * main.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed Samir
 */


/* Library Include */
#include "LBIT_math.h"
#include "LSTD_types.h"
#include "util/delay.h"
/* SWC Include */
#include "MADC_interface.h"
#include "MDIO_interface.h"
#include "MTIM_interface.h"
#include "MEXTI_interface.h"
#include "MGIE_interface.h"

#include "HLCD_interface.h"

void step1(void);
void step2(void);
void step3(void);


u8 Ready =0;
u16 Ton;
u16 Toff;
u16 Period;
u16 Frequency;
u8 DutyCycle;



int main(void)
{
	char Freq[]="Freq: ";
	char Duty[]="Duty: ";
	char FreqValue[10]="";
	char DutyValue[10]="";
	//char Clear[]="            ";
	u8 L_u8ADCValue=0;
	MDIO_stderrorSetPinDirection(MDIO_PORTB,MDIO_PIN3,MDIO_OUTPUT);
	MADC_stderrorInit(MADC_VREF_AVCC,MADC_PreScalar_2);
	MADC_voidEnableADC();
	MTIM_stderrorIint(MTIM_TIMER0,MTIM_CS_PRESCALAR_256,MTIM_MODE_PHASECORRECTPWM, MTIM_HWPIN_NOVINVERTING_PWM);
	MTIM_stderrorStartTimer(MTIM_TIMER0);

	HLCD_voidInit();

	MTIM_stderrorIint(MTIM_TIMER1,MTIM_CS_PRESCALAR_8,MTIM_MODE_NORMAL, MTIM_HWPIN_DISCONNECTED);
	MEXTI_stderrorInit(MEXTI_INT0,MEXTI_MODE_RISING);
	MEXTI_stderrorSetCallBack(step1,MEXTI_INT0);
	MEXTI_stderrorEnableInterrupt(MEXTI_INT0);
	MGIE_voidEnableGlobalInterrupt();

	//HLCD_voidSendString("MOHAMED SAMIR");
	while(1)
	{
		MADC_stderrorReadADC(&L_u8ADCValue,MADC_CHANNEL_ADC0);
		MTIM_stderrorSetOCR(MTIM_TIMER0,L_u8ADCValue);

		if(1==Ready)
		{
			Ton=Ton/1000;
			Toff=Toff/1000;
			Period = Toff+ Ton;
			Frequency=(1.0/(f32)Period)*1000;
			DutyCycle=((f32)Ton/Period)*100;
			//HLCD_voidClear();
			HLCD_voidSetCursor(0,0);
			HLCD_voidSendString(Freq);
			//itoa((u16)Frequency,FreqValue,10);
			HLCD_voidDisplayNumber(Frequency);
//			HLCD_voidSendString(Clear);
			HLCD_voidSendString(FreqValue);
			HLCD_voidSendString(" Hz.");
			HLCD_voidSetCursor(1,0);
			HLCD_voidSendString(Duty);
			//itoa((u16)DutyCycle,DutyValue,10);
			HLCD_voidDisplayNumber(DutyCycle);
//			HLCD_voidSendString(Clear);
			HLCD_voidSendString(DutyValue);
			HLCD_voidSendString(" %");
		}
		_delay_ms(1000);

	}

	return 0;
}



void step1(void)
{
	MTIM_stderrorStartTimer(MTIM_TIMER1);
	MEXTI_stderrorInit(MEXTI_INT0,MEXTI_MODE_FALLING);
	MEXTI_stderrorSetCallBack(step2,MEXTI_INT0);


}
void step2(void)
{
	MTIM_stderrorGetTimerValue(&Ton,MTIM_TIMER1);
	MTIM_stderrorSetTimerValue(MTIM_TIMER1,0x0000);
	MEXTI_stderrorInit(MEXTI_INT0,MEXTI_MODE_RISING);
	MEXTI_stderrorSetCallBack(step3,MEXTI_INT0);
	Ready=0;
}
void step3(void)
{

	MTIM_stderrorGetTimerValue(&Toff,MTIM_TIMER1);
	MTIM_stderrorStopTimer(MTIM_TIMER1);
	MTIM_stderrorSetTimerValue(MTIM_TIMER1,0x0000);
	MEXTI_stderrorSetCallBack(step1,MEXTI_INT0);
	Ready=1;



}



