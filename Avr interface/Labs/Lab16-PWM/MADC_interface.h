/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MADC				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 15, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/



#ifndef MADC_INTERFACE_H_
#define MADC_INTERFACE_H_


#define MADC_VREF_AREF 							1
#define MADC_VREF_AVCC 							2
#define MADC_VREF_2_56V 						3


#define MADC_CHANNEL_ADC0 						1
#define MADC_CHANNEL_ADC1 						2
#define MADC_CHANNEL_ADC2 						3
#define MADC_CHANNEL_ADC3 						4
#define MADC_CHANNEL_ADC4 						5
#define MADC_CHANNEL_ADC5 						6
#define MADC_CHANNEL_ADC6						7
#define MADC_CHANNEL_ADC7 						8


#define MADC_PreScalar_2 						1
#define MADC_PreScalar_4 						2
#define MADC_PreScalar_8 						3
#define MADC_PreScalar_16 						4
#define MADC_PreScalar_32 						5
#define MADC_PreScalar_64 						6
#define MADC_PreScalar_128						7

#define Free_Running_mode 						1
#define Analog_Comparator						2
#define External_Interrupt_Request				3
#define Timer_Counter0_Compare_Match			4
#define Timer_Counter0_Overflow					5
#define Timer_Counter1_Compare_MatchB			6
#define Timer_Counter1_Overflow					7
#define Timer_Counter1_Capture_Event			8

STD_error_t MADC_stderrorInit
(
	u8 ARG_u8RefVoltage, 
	u8 ARG_u8PreScalar
);

void MADC_voidEnableADC
(
	void
);

void MADC_voidDisableADC
(
	void
);

void MADC_voidEnableInterrupt
(
	void
);

void MADC_voidDisableInterrupt
(
	void
);

STD_error_t	MADC_stderrorStartConversion
(
	u8 ARG_u8Channel
);

void MADC_voidFlagPolling
(
	void
);

void MADC_voidClearFlag
(
	void
);

STD_error_t	MADC_stderrorReadADC
(
	u8* ARG_u8pADCReading,
	u8 ARG_u8Channel
);


STD_error_t MADC_voidSetTriggerSource
(
	u8 ARG_u8TriggerMode
);

#endif
