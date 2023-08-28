/*
 * main.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Mohamed Samir
 */

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_interface.h"
#include "MGIE_interface.h"
#include "MTIM0_interface.h"
#include <util/delay.h>


#define Test_ovf 1

#define Test_ctc 2

#define Test_pwm 3

#define Test_pwm_function 4


#define test Test_ovf

void toogle_led(void);

int main (void)
{

	MDIO_stderrorSetPinDirection(MDIO_PORTB,MDIO_PIN3,MDIO_OUTPUT);

	#if test ==Test_ovf
	MDIO_stderrorSetPinDirection(MDIO_PORTA,MDIO_PIN0,MDIO_OUTPUT);
	MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_LOW);
	/*overflow test*/
	MTIM0_stderrorInit(MTIM0_CS_PRESCALAR_8,MTIM0_MODE_NORMAL,MTIM0_HWPIN_DISCONNECTED);
	MTIM0_stderrorTimerDelay(MTIM0_INTERRUPT_OVF,toogle_led,0,1000);
	MTIM0_stderrorEnableInterrupt(MTIM0_INTERRUPT_OVF);
	MGIE_voidEnableGlobalInterrupt();
	MTIM0_stderrorStartTimer();

	#elif test ==Test_ctc
	MDIO_stderrorSetPinDirection(MDIO_PORTA,MDIO_PIN0,MDIO_OUTPUT);
	MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_LOW);
	/*ctc test*/
	MTIM0_stderrorInit(MTIM0_CS_PRESCALAR_8,MTIM0_MODE_CTC,MTIM0_HWPIN_DISCONNECTED);
	MTIM0_stderrorTimerDelay(MTIM0_INTERRUPT_OCM,toogle_led,250,1000);
	MTIM0_stderrorEnableInterrupt(MTIM0_INTERRUPT_OCM);
	MGIE_voidEnableGlobalInterrupt();
	MTIM0_stderrorStartTimer();
	#elif test ==Test_pwm_function
	MTIM0_stderrorFASTPWM(MTIM0_CS_PRESCALAR_64,50,MTIM0_HWPIN_NOVINVERTING_PWM);
	#elif test ==Test_pwm
	MTIM0_stderrorInit(MTIM0_CS_PRESCALAR_64,MTIM0_MODE_FASTPWM,MTIM0_HWPIN_NOVINVERTING_PWM);
	MTIM0_voidSetOCR(20);
	MTIM0_stderrorStartTimer();
	#else

	#endif
	while(1)
	{
		#if test ==Test_pwm
		u8 i;
		for(i=0;i<255;i++)
		{

			MTIM0_voidSetOCR(i);
			_delay_ms(10);
		}
		#else
		#endif

	}
	return 0;
}


void toogle_led(void)
{
	static u8 L_u8Flag=0;
	if(L_u8Flag==0)
	{

		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_HIGH);
		L_u8Flag=1;
	}
	else
	{
		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_LOW);
		L_u8Flag=0;
	}

}
