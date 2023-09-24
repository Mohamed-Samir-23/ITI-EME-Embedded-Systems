/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: LED MATRIX			*/
/*  Layer		: HAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 23, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/

/* Library Include */
#include "LSTD_types.h"

/* SWC Include */
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"
#include "HLEDMATRIX_config.h"
#include "HLEDMATRIX_private.h"
#include "HLEDMATRIX_interface.h"

void  HLEDMATRIX_voidInit
(
	void
)
{
	
	MRCC_stderrorInit
	(
		HLEDMATRIX_CLKSRC,
		HLEDMATRIX_AHBPRESCALER,
		HLEDMATRIX_APB1PRESCALER,
		HLEDMATRIX_APB2PRESCALER
	);
	RCC_EnablePeripheralClk
	(
		HLEDMATRIX_PERIPHERALCLK_ROW
	);
	RCC_EnablePeripheralClk
	(
		HLEDMATRIX_PERIPHERALCLK_COL
	);
	
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_ROW0_PIN,OUTPUT);
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_ROW1_PIN,OUTPUT);
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_ROW2_PIN,OUTPUT);
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_ROW3_PIN,OUTPUT);
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_ROW4_PIN,OUTPUT);
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_ROW5_PIN,OUTPUT);
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_ROW6_PIN,OUTPUT);
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_ROW7_PIN,OUTPUT);
	
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_COL0_PIN,OUTPUT);
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_COL1_PIN,OUTPUT);
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_COL2_PIN,OUTPUT);
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_COL3_PIN,OUTPUT);
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_COL4_PIN,OUTPUT);
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_COL5_PIN,OUTPUT);
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_COL6_PIN,OUTPUT);
	MGPIO_stderrorPinModeSelect(HLEDMATRIX_COL7_PIN,OUTPUT);
	
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_ROW0_PIN,PUSH_PULL);
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_ROW1_PIN,PUSH_PULL);
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_ROW2_PIN,PUSH_PULL);
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_ROW3_PIN,PUSH_PULL);
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_ROW4_PIN,PUSH_PULL);
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_ROW5_PIN,PUSH_PULL);
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_ROW6_PIN,PUSH_PULL);
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_ROW7_PIN,PUSH_PULL);

	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_COL0_PIN,PUSH_PULL);
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_COL1_PIN,PUSH_PULL);
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_COL2_PIN,PUSH_PULL);
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_COL3_PIN,PUSH_PULL);
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_COL4_PIN,PUSH_PULL);
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_COL5_PIN,PUSH_PULL);
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_COL6_PIN,PUSH_PULL);
	MGPIO_stderrorSetOutputPintype(HLEDMATRIX_COL7_PIN,PUSH_PULL);
}


STD_error_t HLEDMATRIX_stderrorDisplay
(
	u8 * ARG_pu8Data
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_pu8Data != NULL_POINTER)
	{
		u8 L_u8i;
		
		for(L_u8i=0;L_u8i<8;L_u8i++)
		{
			HLEDMATRIX_voidDisableAllCol();
			
			HLEDMATRIX_voidSetRowValue(ARG_pu8Data[L_u8i]);
			
			switch(L_u8i)
			{
				
				case 0:	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL0_PIN,LOW); break;
				case 1:	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL1_PIN,LOW); break;
				case 2:	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL2_PIN,LOW); break;
				case 3:	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL3_PIN,LOW); break;
				case 4:	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL4_PIN,LOW); break;
				case 5:	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL5_PIN,LOW); break;
				case 6:	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL6_PIN,LOW); break;
				case 7:	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL7_PIN,LOW); break;
				default : break;
			}
			MSYSTICK_stderrorSetBusyWait(2500);
		}
		L_stderrorError = E_OK;
	}
	else
	{
		L_stderrorError = E_NULL_POINTER;
	}
	
	return L_stderrorError;
}




static void  HLEDMATRIX_voidDisableAllCol
(
	void
)
{
	/*Disable all COLUMNS*/
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL0_PIN,HIGH);
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL1_PIN,HIGH);
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL2_PIN,HIGH);
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL3_PIN,HIGH);
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL4_PIN,HIGH);
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL5_PIN,HIGH);
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL6_PIN,HIGH);
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_COL7_PIN,HIGH);
}


static void  HLEDMATRIX_voidSetRowValue
(
	u8 ARG_u8Data
)
{
	
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_ROW0_PIN,((ARG_u8Data>>0U)&1U));
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_ROW1_PIN,((ARG_u8Data>>1U)&1U));
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_ROW2_PIN,((ARG_u8Data>>2U)&1U));
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_ROW3_PIN,((ARG_u8Data>>3U)&1U));
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_ROW4_PIN,((ARG_u8Data>>4U)&1U));
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_ROW5_PIN,((ARG_u8Data>>5U)&1U));
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_ROW6_PIN,((ARG_u8Data>>6U)&1U));
	MGPIO_stderrorSetPinValueBSSR(HLEDMATRIX_ROW7_PIN,((ARG_u8Data>>7U)&1U));

}