/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: KEYPAD			*/
/*  Layer		: HCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 9, 2023	*/
/*  Last Edit	: N/A				*/
/************************************/

/* Library Include */
#include "LBIT_math.h"
#include "LSTD_types.h"


/* SWC Include */
#include "MDIO_interface.h"
#include "HKEYPAD_config.h"
#include "HKEYPAD_private.h"
#include "HKEYPAD_interface.h"
#include "HLCD_interface.h"
#include<util/delay.h>
STD_error_t HKPD_stderrorGetKey(u8* ARG_pu8Value)
{
	STD_error_t L_stderrorError=E_NOK;
	u8 HKPD_charKeypad[ROW_NUM][COL_NUM]=KPD_BUTTONS_NUM;
	u8 L_u8Row,L_u8Col,L_u8Value;
	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_R0_PIN,MDIO_INPUT_PULLUP);
	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_R1_PIN,MDIO_INPUT_PULLUP);
	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_R2_PIN,MDIO_INPUT_PULLUP);
	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_R3_PIN,MDIO_INPUT_PULLUP);

	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_C0_PIN,MDIO_OUTPUT);
	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_C1_PIN,MDIO_OUTPUT);
	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_C2_PIN,MDIO_OUTPUT);
	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_C3_PIN,MDIO_OUTPUT);

	L_stderrorError=MDIO_stderrorSetPinValue(KEYPAD_C0_PIN,MDIO_LOW);
	L_stderrorError=MDIO_stderrorSetPinValue(KEYPAD_C1_PIN,MDIO_LOW);
	L_stderrorError=MDIO_stderrorSetPinValue(KEYPAD_C2_PIN,MDIO_LOW);
	L_stderrorError=MDIO_stderrorSetPinValue(KEYPAD_C3_PIN,MDIO_LOW);

	do{
		L_u8Row=0;
		L_u8Value=0;
		L_stderrorError=MDIO_stderrorGetPinValue(KEYPAD_R3_PIN,&L_u8Value);
		L_u8Row=L_u8Value;
		L_stderrorError=MDIO_stderrorGetPinValue(KEYPAD_R2_PIN,&L_u8Value);
		L_u8Row=L_u8Row<<1;
		L_u8Row=L_u8Row|L_u8Value;
		L_stderrorError=MDIO_stderrorGetPinValue(KEYPAD_R1_PIN,&L_u8Value);
		L_u8Row=L_u8Row<<1;
		L_u8Row=L_u8Row|L_u8Value;
		L_stderrorError=MDIO_stderrorGetPinValue(KEYPAD_R0_PIN,&L_u8Value);
		L_u8Row=L_u8Row<<1;
		L_u8Row=L_u8Row|L_u8Value;
		L_u8Row=((~L_u8Row)&0x0F);
	}while(0==L_u8Row);

	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_R0_PIN,MDIO_OUTPUT);
	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_R1_PIN,MDIO_OUTPUT);
	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_R2_PIN,MDIO_OUTPUT);
	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_R3_PIN,MDIO_OUTPUT);

	L_stderrorError=MDIO_stderrorSetPinValue(KEYPAD_R0_PIN,MDIO_LOW);
	L_stderrorError=MDIO_stderrorSetPinValue(KEYPAD_R1_PIN,MDIO_LOW);
	L_stderrorError=MDIO_stderrorSetPinValue(KEYPAD_R2_PIN,MDIO_LOW);
	L_stderrorError=MDIO_stderrorSetPinValue(KEYPAD_R3_PIN,MDIO_LOW);

	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_C0_PIN,MDIO_INPUT_PULLUP);
	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_C1_PIN,MDIO_INPUT_PULLUP);
	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_C2_PIN,MDIO_INPUT_PULLUP);
	L_stderrorError=MDIO_stderrorSetPinDirection(KEYPAD_C3_PIN,MDIO_INPUT_PULLUP);

	do{
		L_u8Col=0;
		L_u8Value=0;
		L_stderrorError=MDIO_stderrorGetPinValue(KEYPAD_C3_PIN,&L_u8Value);
		L_u8Col=L_u8Value;
		L_stderrorError=MDIO_stderrorGetPinValue(KEYPAD_C2_PIN,&L_u8Value);
		L_u8Col=L_u8Col<<1;
		L_u8Col=L_u8Col|L_u8Value;
		L_stderrorError=MDIO_stderrorGetPinValue(KEYPAD_C1_PIN,&L_u8Value);
		L_u8Col=L_u8Col<<1;
		L_u8Col=L_u8Col|L_u8Value;
		L_stderrorError=MDIO_stderrorGetPinValue(KEYPAD_C0_PIN,&L_u8Value);
		L_u8Col=L_u8Col<<1;
		L_u8Col=L_u8Col|L_u8Value;
		L_u8Col=((~L_u8Col)&0x0F);

	}while(0==L_u8Col);

	/*
	HLCD_voidSetCursor(0,0);
	HLCD_voidDisplayNumber(L_u8Row);
	HLCD_voidSetCursor(0,1);
	HLCD_voidDisplayNumber(L_u8Col);
	_delay_ms(2000);
	 */

	switch(L_u8Row)
	{
		case 1:L_u8Row=0;break;
		case 2:L_u8Row=1;break;
		case 4:L_u8Row=2;break;
		case 8:L_u8Row=3;break;
		default:L_u8Row=4;break;
	}
	switch(L_u8Col)
	{
		case 1:L_u8Col=0;break;
		case 2:L_u8Col=1;break;
		case 4:L_u8Col=2;break;
		case 8:L_u8Col=3;break;
		default:L_u8Col=4;break;
	}
	*ARG_pu8Value=HKPD_charKeypad[L_u8Row][L_u8Col];
	return L_stderrorError;
}
