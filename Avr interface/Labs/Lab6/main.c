/*
 * main.c
 *
 *  Created on: Aug 9, 2023
 *      Author: moham
 */
/* Library Include */
#include "LBIT_math.h"
#include "LSTD_types.h"


/* SWC Include */
#include "HLCD_interface.h"
#include<util/delay.h>
char a[8]={0x00,0x00,0x00,0x01,0x01,0x02,0x02,0x1C};

char b[8]={0x10,0x10,0x10,0x00,0x00,0x00,0x00,0x00};

char c[8]={0x00,0x01,0x02,0x04,0x04,0x08,0x08,0x08};

char d[8]={0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

char e[8]={0x00,0x10,0x08,0x04,0x04,0x02,0x02,0x02};


char f[8]={0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00};


char g[8]={0x00,0x00,0x00,0x10,0x10,0x08,0x08,0x07};





int main ()
{
	u32 t=200;
	HLCD_voidInit();
	HLCD_voidWriteCustom(a,0);
	HLCD_voidWriteCustom(b,1);
	HLCD_voidWriteCustom(c,2);
	HLCD_voidWriteCustom(d,3);
	HLCD_voidWriteCustom(e,4);
	HLCD_voidWriteCustom(f,5);
	HLCD_voidWriteCustom(g,6);
	HLCD_voidSetCursor(1,0);
	HLCD_voidSendChar(0);//a

	HLCD_voidSetCursor(1,1);
	HLCD_voidSendChar(1);//b
	HLCD_voidSetCursor(0,1);
	HLCD_voidSendChar(2);//c
	HLCD_voidSetCursor(0,2);
	HLCD_voidSendChar(3);//d
	HLCD_voidSetCursor(0,3);
	HLCD_voidSendChar(4);//e
	HLCD_voidSetCursor(1,3);
	HLCD_voidSendChar(5);//f
	HLCD_voidSetCursor(1,4);
	HLCD_voidSendChar(6);//g

	/*--------------------------*/
	HLCD_voidSetCursor(1,5);
	HLCD_voidSendChar(0);//a
	_delay_ms(t);
	HLCD_voidSetCursor(1,6);
	HLCD_voidSendChar(1);//b
	_delay_ms(t);
	HLCD_voidSetCursor(0,6);
	HLCD_voidSendChar(2);//c
	_delay_ms(t);
	HLCD_voidSetCursor(0,7);
	HLCD_voidSendChar(3);//d
	_delay_ms(t);
	HLCD_voidSetCursor(0,8);
	HLCD_voidSendChar(4);//e
	_delay_ms(t);
	HLCD_voidSetCursor(1,8);
	HLCD_voidSendChar(5);//f
	_delay_ms(t);
	HLCD_voidSetCursor(1,9);
	HLCD_voidSendChar(6);//g

	/*--------------------------*/
	HLCD_voidSetCursor(1,10);
	HLCD_voidSendChar(0);//a
	_delay_ms(t);
	HLCD_voidSetCursor(1,11);
	HLCD_voidSendChar(1);//b
	_delay_ms(t);
	HLCD_voidSetCursor(0,11);
	HLCD_voidSendChar(2);//c
	_delay_ms(t);
	HLCD_voidSetCursor(0,12);
	HLCD_voidSendChar(3);//d
	_delay_ms(t);
	HLCD_voidSetCursor(0,13);
	HLCD_voidSendChar(4);//e
	_delay_ms(t);
	HLCD_voidSetCursor(1,13);
	HLCD_voidSendChar(5);//f
	_delay_ms(t);
	HLCD_voidSetCursor(1,14);
	HLCD_voidSendChar(6);//g
	_delay_ms(t);
	/*--------------------------*/
	HLCD_voidSetCursor(1,15);
	HLCD_voidSendChar(0);//a
	_delay_ms(t);
	HLCD_voidSetCursor(1,16);
	HLCD_voidSendChar(1);//b
	_delay_ms(t);

	while(1)
	{
		LCD_udtShiftRight();
		//HLCD_voidSendCmd(0x80+((0x27)-1));
		HLCD_voidSendCmd(0x80+0x40+((0x27)));//0x27
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendChar(6);//g
		_delay_ms(t);

		LCD_udtShiftRight();
		HLCD_voidSendCmd(0x80+0x40+((0x27)-1));
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendChar(5);//f
		_delay_ms(t);

		LCD_udtShiftRight();
		HLCD_voidSendCmd(0x80+((0x27)-1));
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendChar(4);//e
		_delay_ms(t);
		LCD_udtShiftRight();
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendCmd(0x80+((0x27)-2));
		HLCD_voidSendChar(3);//d
		_delay_ms(t);
		LCD_udtShiftRight();
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendCmd(0x80+((0x27)-3));
		HLCD_voidSendChar(2);//c
		_delay_ms(t);
		LCD_udtShiftRight();
		HLCD_voidSendCmd(0x80+0x40+((0x27)-3));
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendChar(1);//b
		_delay_ms(t);
		LCD_udtShiftRight();
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendCmd(0x80+0x40+((0x27)-4));
		HLCD_voidSendChar(0);//a
		_delay_ms(t);
		LCD_udtShiftRight();

		//HLCD_voidSendCmd(0x80+((0x27)-1));
		HLCD_voidSendCmd(0x80+0x40+((0x27)-5));//0x27
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendChar(6);//g
		_delay_ms(t);

		LCD_udtShiftRight();
		HLCD_voidSendCmd(0x80+0x40+((0x27)-6));
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendChar(5);//f
		_delay_ms(t);

		LCD_udtShiftRight();
		HLCD_voidSendCmd(0x80+((0x27)-6));
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendChar(4);//e
		_delay_ms(t);
		LCD_udtShiftRight();
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendCmd(0x80+((0x27)-7));
		HLCD_voidSendChar(3);//d
		_delay_ms(t);
		LCD_udtShiftRight();
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendCmd(0x80+((0x27)-8));
		HLCD_voidSendChar(2);//c
		_delay_ms(t);
		LCD_udtShiftRight();
		HLCD_voidSendCmd(0x80+0x40+((0x27)-8));
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendChar(1);//b
		_delay_ms(t);
		LCD_udtShiftRight();
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendCmd(0x80+0x40+((0x27)-9));
		HLCD_voidSendChar(0);//a
		_delay_ms(t);
		LCD_udtShiftRight();

		//HLCD_voidSendCmd(0x80+((0x27)-1));
		HLCD_voidSendCmd(0x80+0x40+((0x27)-10));//0x27
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendChar(6);//g
		_delay_ms(t);

		LCD_udtShiftRight();
		HLCD_voidSendCmd(0x80+0x40+((0x27)-11));
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendChar(5);//f
		_delay_ms(t);

		LCD_udtShiftRight();
		HLCD_voidSendCmd(0x80+((0x27)-11));
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendChar(4);//e
		_delay_ms(t);
		LCD_udtShiftRight();
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendCmd(0x80+((0x27)-12));
		HLCD_voidSendChar(3);//d
		_delay_ms(t);
		LCD_udtShiftRight();
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendCmd(0x80+((0x27)-13));
		HLCD_voidSendChar(2);//c
		_delay_ms(t);
		LCD_udtShiftRight();
		HLCD_voidSendCmd(0x80+0x40+((0x27)-13));
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendChar(1);//b
		_delay_ms(t);
		LCD_udtShiftRight();
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendCmd(0x80+0x40+((0x27)-14));
		HLCD_voidSendChar(0);//a
		_delay_ms(t);

		LCD_udtShiftRight();

		//HLCD_voidSendCmd(0x80+((0x27)-1));
		HLCD_voidSendCmd(0x80+0x40+((0x27)-15));//0x27
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendChar(6);//g
		_delay_ms(t);

		LCD_udtShiftRight();
		HLCD_voidSendCmd(0x80+0x40+((0x27)-16));
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendChar(5);//f
		_delay_ms(t);

		LCD_udtShiftRight();
		HLCD_voidSendCmd(0x80+((0x27)-16));
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendChar(4);//e
		_delay_ms(t);
		LCD_udtShiftRight();
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendCmd(0x80+((0x27)-17));
		HLCD_voidSendChar(3);//d
		_delay_ms(t);
		LCD_udtShiftRight();
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendCmd(0x80+((0x27)-18));
		HLCD_voidSendChar(2);//c
		_delay_ms(t);
		LCD_udtShiftRight();
		HLCD_voidSendCmd(0x80+0x40+((0x27)-18));
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendChar(1);//b
		_delay_ms(t);
		LCD_udtShiftRight();
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendCmd(0x80+0x40+((0x27)-19));
		HLCD_voidSendChar(0);//a
		_delay_ms(t);
		LCD_udtShiftRight();

		//HLCD_voidSendCmd(0x80+((0x27)-1));
		HLCD_voidSendCmd(0x80+0x40+((0x27)-20));//0x27
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendChar(6);//g
		_delay_ms(t);

		LCD_udtShiftRight();
		HLCD_voidSendCmd(0x80+0x40+((0x27)-21));
		//HLCD_voidSetCursor(1,0);
		HLCD_voidSendChar(5);//f
		_delay_ms(t);

		LCD_udtShiftRight();
		HLCD_voidSendCmd(0x80+((0x27)-21));
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendChar(4);//e
		_delay_ms(t);
		LCD_udtShiftRight();
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendCmd(0x80+((0x27)-22));
		HLCD_voidSendChar(3);//d
		_delay_ms(t);
		LCD_udtShiftRight();
		//HLCD_voidSetCursor(0,0);
		HLCD_voidSendCmd(0x80+((0x27)-23));
		HLCD_voidSendChar(2);//c
		_delay_ms(t);
	}

	return 0;

}
