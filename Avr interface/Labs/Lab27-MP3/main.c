/*
 * main.c
 *
 *  Created on: Sep 3, 2023
 *      Author: Mohamed Samir
 */



/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"
#include <util/delay.h>
/* SWC Includes */
#include "HMP3MODULE_interface.h"
#include "HLCD_interface.h"

int main(void)
{
	HLCD_voidInit();
	HLCD_voidSendString("Wahawe Ya Wahawe");
	HLCD_voidSetCursor(1,0);
	HLCD_voidSendString("Play");
	HMP3MODULE_voidInit();
	HMP3MODULE_voidSelectVolume(1);
	while(1)
	{



	}

	return 0;
}
