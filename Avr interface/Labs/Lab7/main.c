/*
 * main.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Mohamed Samir
 */
#include "LBIT_math.h"
#include "LSTD_types.h"


/* SWC Include */
#include "HLCD_interface.h"
#include "HKEYPAD_interface.h"
#include<util/delay.h>


int main(void)
{

	HLCD_voidInit();

	//HLCD_voidClear();
	u8 L_u8charkeypad=0;
	s8 L_password=0;
	u8 arrpass[4]={0,0,0,0};
	while(1)
	{
		HLCD_voidSetCursor(0,0);
		HLCD_voidSendString("HackPointers");
		_delay_ms(1000);
		HLCD_voidClear();
		HLCD_voidSetCursor(0,0);
		HLCD_voidSendString("enter the pass :");
		HKPD_stderrorGetKey(&L_u8charkeypad);
		HLCD_voidSetCursor(1,0);
		HLCD_voidDisplayNumber(L_u8charkeypad);
		arrpass[0]=L_u8charkeypad;
		HKPD_stderrorGetKey(&L_u8charkeypad);
		HLCD_voidSetCursor(1,1);
		HLCD_voidDisplayNumber(L_u8charkeypad);
		arrpass[1]=L_u8charkeypad;
		HKPD_stderrorGetKey(&L_u8charkeypad);
		HLCD_voidSetCursor(1,2);
		HLCD_voidDisplayNumber(L_u8charkeypad);
		arrpass[2]=L_u8charkeypad;
		HKPD_stderrorGetKey(&L_u8charkeypad);
		HLCD_voidSetCursor(1,3);
		HLCD_voidDisplayNumber(L_u8charkeypad);
		arrpass[3]=L_u8charkeypad;
		_delay_ms(3000);
		HLCD_voidClear();

		if((arrpass[0]==5)&&(arrpass[1]==6)&&(arrpass[2]==7)&&(arrpass[3]==8))
		{
			HLCD_voidClear();
			HLCD_voidSetCursor(0,0);
			HLCD_voidSendString("Welcome");
		}
		else
		{
			HLCD_voidClear();
			HLCD_voidSetCursor(0,0);
			HLCD_voidSendString("wrong pass");

		}
		_delay_ms(3000);
		HLCD_voidClear();

	}

	return 0;
}
