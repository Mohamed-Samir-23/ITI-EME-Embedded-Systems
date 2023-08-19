/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: SFIOR				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 15, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/

#ifndef _MSFIOR_INTERFACE_H_
#define _MSFIOR_INTERFACE_H_


typedef enum 
{
	 Free_Running_mode = 0,
	 Analog_Comparator,
	 External_Interrupt_Request,
	 Timer_Counter0_Compare_Match,
	 Timer_Counter0_Overflow,
	 Timer_Counter1_Compare_MatchB,
	 Timer_Counter1_Overflow,
	 Timer_Counter1_Capture_Event

}Trigger_MODE;



STD_error_t MSFIOR_voidSetTriggerSource
(
	Trigger_MODE ARG_udtTriggerMode
);


#endif
