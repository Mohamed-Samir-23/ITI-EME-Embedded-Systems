/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: LCD				*/
/*  Layer		: HCAL				*/
/*  Version		: 1.1				*/
/*  Date		: August 8, 2023	*/
/*  Last Edit	: August 9, 2023	*/
/************************************/

/* Library Include */
#include "LBIT_math.h"
#include "LSTD_types.h"


/* SWC Include */
#include "MDIO_interface.h"
#include "HLCD_config.h"
#include "HLCD_private.h"
#include "HLCD_interface.h"
#include<util/delay.h>

void HLCD_voidInit(void)
{
	MDIO_stderrorSetPortDirection(LCD_DATA_PORT,0xFF);
	MDIO_stderrorSetPortValue(LCD_DATA_PORT,MDIO_LOW);
	MDIO_stderrorSetPinDirection(LCD_CONTROL_PORT,LCD_RS_PIN,MDIO_OUTPUT);
	MDIO_stderrorSetPinDirection(LCD_CONTROL_PORT,LCD_RW_PIN,MDIO_OUTPUT);
	MDIO_stderrorSetPinDirection(LCD_CONTROL_PORT,LCD_E_PIN,MDIO_OUTPUT);
	HLCD_voidSendCmd(0x33);   /* Send command 0x33*/
	HLCD_voidSendCmd(0x32);   /* Send command 0x32*/
	HLCD_voidSendCmd(0x38);
	_delay_us(50);
	HLCD_voidSendCmd(0x0C);
	_delay_us(50);
	HLCD_voidSendCmd(0x01);
	_delay_ms(2);
	HLCD_voidSendCmd(0x06);
}
void HLCD_voidSendChar(char ARG_u8Data)
{
	/*control preparation*/
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,MDIO_HIGH);
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,MDIO_LOW);
	_delay_ms(1);
	/*enable preparation & send Data*/
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,MDIO_HIGH);
	_delay_ms(1);
	MDIO_stderrorSetPortValue(LCD_DATA_PORT,ARG_u8Data);
	_delay_ms(1);
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,MDIO_LOW);
	_delay_ms(2);

}

void HLCD_voidSendCmd(u8 ARG_u8Cmd)
{
	/*control preparation*/
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,MDIO_LOW);
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,MDIO_LOW);

	/*enable preparation & send cmd*/
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,MDIO_HIGH);
	_delay_ms(1);
	MDIO_stderrorSetPortValue(LCD_DATA_PORT,ARG_u8Cmd);
	_delay_ms(1);
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,MDIO_LOW);

}
void HLCD_voidSendString(const char * ARG_ccharpString)
{
	if(ARG_ccharpString != NULL_POINTER )
	{
		u8 L_u8i=0;
		do{
			HLCD_voidSendChar(ARG_ccharpString[L_u8i]);
			L_u8i++;
		}while(ARG_ccharpString[L_u8i] != '\0' );
	}

}
void HLCD_voidSetCursor(u8 ARG_u8Row,u8 ARG_u8Col)
{

	HLCD_voidSendCmd((0x80+ARG_u8Col+((ARG_u8Row*4)<<4)));
}
void HLCD_voidWriteCustom(const char * ARG_ccharpString,u8 ARG_u8Location)
{
	u8 L_u8address =0;


	if(ARG_u8Location<8)
	{
		L_u8address=ARG_u8Location*8;
		/*0-1-D5-D4-D3-D2-D1-D0 TO GO TO CGRAM D5-D0 LOCATION 0-7*/
		SET_BIT(L_u8address,6);
		HLCD_voidSendCmd(L_u8address);
		u8 L_u8i;
		for(L_u8i=0;L_u8i<8;L_u8i++)
		{
			HLCD_voidSendChar(ARG_ccharpString[L_u8i]);
		}
		HLCD_voidSendCmd(0x02);/*return home*/

	}
	else
	{


	}

}

void HLCD_voidClear(void)
{
	HLCD_voidSendCmd(0x01);//clear
}



void HLCD_voidDisplayNumber(u8 ARG_u8Num)
{
	/* String to hold the ascii result */
	char Result[21];
	/* 10 for decimal */
	itoa((int)ARG_u8Num,Result,10);
	HLCD_voidSendString(Result);
}
