/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: SFIOR				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 15, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MSFIOR_private.h"
#include "MSFIOR_interface.h"


STD_error_t MSFIOR_voidSetTriggerSource
(
	Trigger_MODE ARG_udtTriggerMode
)
{
	STD_error_t L_stderrorError=E_NOK;
	switch(ARG_udtTriggerMode)
	{
	case Free_Running_mode             :ADTS2 =0;ADTS1=0;ADTS0 =0;L_stderrorError = E_OK;break;
	case Analog_Comparator             :ADTS2 =0;ADTS1=0;ADTS0 =1;L_stderrorError = E_OK;break;
	case External_Interrupt_Request    :ADTS2 =0;ADTS1=1;ADTS0 =0;L_stderrorError = E_OK;break;
	case Timer_Counter0_Compare_Match  :ADTS2 =0;ADTS1=1;ADTS0 =1;L_stderrorError = E_OK;break;
	case Timer_Counter0_Overflow       :ADTS2 =1;ADTS1=0;ADTS0 =0;L_stderrorError = E_OK;break;
	case Timer_Counter1_Compare_MatchB :ADTS2 =1;ADTS1=0;ADTS0 =1;L_stderrorError = E_OK;break;
	case Timer_Counter1_Overflow       :ADTS2 =1;ADTS1=1;ADTS0 =0;L_stderrorError = E_OK;break;
	case Timer_Counter1_Capture_Event  :ADTS2 =1;ADTS1=1;ADTS0 =1;L_stderrorError = E_OK;break;
	default :L_stderrorError=E_NOK;break;
	}
	return L_stderrorError;
}
