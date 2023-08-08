/*
 * main.c
 *
 *  Created on: Aug 8, 2023
 *      Author: Mohamed Samir
 */

/* Library Include */
#include "LBIT_math.h"
#include "LSTD_types.h"


/* SWC Include */
#include "HLCD_interface.h"

int main(void)
{

	HLCD_voidInit();
	/*
	HLCD_voidSendChar('S');
	HLCD_voidSendChar('A');
	HLCD_voidSendChar('M');
	HLCD_voidSendChar('I');
	HLCD_voidSendChar('R');
	*/
	//HLCD_voidSendString("MOHAMED SAMIR");
	char L_Mchar[]={
			  0x00,
			  0x0F,
			  0x09,
			  0x09,
			  0x09,
			  0x1F,
			  0x00,
			  0x00
			};
	char L_7char[]={
			  0x00,
			  0x0E,
			  0x02,
			  0x02,
			  0x02,
			  0x1F,
			  0x00,
			  0x00
			};
	char L_Dchar[]={
			  0x00,
			  0x02,
			  0x02,
			  0x02,
			  0x02,
			  0x1F,
			  0x00,
			  0x00
			};
	char L_Schar[]={
			  0x00,
			  0x15,
			  0x15,
			  0x15,
			  0x15,
			  0x1F,
			  0x00,
			  0x00
			};
	char L_SMchar[]={
			  0x00,
			  0x0E,
			  0x0A,
			  0x0A,
			  0x0A,
			  0x1F,
			  0x00,
			  0x00
			};
	char L_Yechar[]={
			  0x00,
			  0x00,
			  0x04,
			  0x04,
			  0x04,
			  0x1F,
			  0x00,
			  0x0A
			};
	char L_Rchar[]={
			  0x00,
			  0x00,
			  0x00,
			  0x00,
			  0x00,
			  0x03,
			  0x04,
			  0x08
			};
	HLCD_voidWriteCustom(L_Rchar,0);
	HLCD_voidWriteCustom(L_Yechar,1);
	HLCD_voidWriteCustom(L_SMchar,2);
	HLCD_voidWriteCustom(L_Schar,3);
	HLCD_voidWriteCustom(L_Dchar,4);
	HLCD_voidWriteCustom(L_Mchar,5);
	HLCD_voidWriteCustom(L_7char,6);
	HLCD_voidWriteCustom(L_Mchar,7);


	HLCD_voidSendChar(0);
	HLCD_voidSendChar(1);
	HLCD_voidSendChar(2);
	HLCD_voidSendChar(3);
	HLCD_voidSendChar(' ');
	HLCD_voidSendChar(4);
	HLCD_voidSendChar(5);
	HLCD_voidSendChar(6);
	HLCD_voidSendChar(7);

	while(1)
	{


	}
	return 0;
}


