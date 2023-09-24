/*
 * main.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Mohamed Samir
 */


#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MUSART_interface.h"

int main()
{


	MUSART_stderrorInit
	(
		MUSART_TX_RX_MODE,
		MUSART_SINGLE_PROCESSOR ,
		MUSART_ASYNC_DOUBLE_SPEED,
		MUSART_INTERRUPT_DISABLE,
		MUSART_7BIT_DATA,
		MUSART_PARITY_DISABLE,
		MUSART_STOP_1BIT,
		MUSART_SAMPLE_DISABLE,
		9600
	);

	u8 data='a';

	while(1)
	{

			MUSART_stderrorSendDataSync(data);


			MUSART_stderrorReadDataSync((u16*)&data);




	}

	return 0;

}




