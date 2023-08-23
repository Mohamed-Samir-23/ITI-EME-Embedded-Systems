/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MADC				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 21, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/



#ifndef MADC_INTERFACE_H_
#define MADC_INTERFACE_H_


#define MADC_VREF_AREF 							0
#define MADC_VREF_AVCC 							1
#define MADC_VREF_2_56V 						3


#define MADC_SCHANNEL_ADC0 						0
#define MADC_SCHANNEL_ADC1 						1
#define MADC_SCHANNEL_ADC2 						2
#define MADC_SCHANNEL_ADC3 						3
#define MADC_SCHANNEL_ADC4 						4
#define MADC_SCHANNEL_ADC5 						5
#define MADC_SCHANNEL_ADC6						6
#define MADC_SCHANNEL_ADC7 						7

#define MADC_DCHANNEL_G10_ADC0_AND_ADC0			8
#define MADC_DCHANNEL_G10_ADC1_AND_ADC0 		9

#define MADC_DCHANNEL_G200_ADC0_AND_ADC0 		10
#define MADC_DCHANNEL_G200_ADC1_AND_ADC0 		11

#define MADC_DCHANNEL_G10_ADC2_AND_ADC2 		12
#define MADC_DCHANNEL_G10_ADC3_AND_ADC2 		13

#define MADC_DCHANNEL_G200_ADC2_AND_ADC2		14
#define MADC_DCHANNEL_G200_ADC3_AND_ADC2 		15

#define MADC_DCHANNEL_G1_ADC0_AND_ADC1			16
#define MADC_DCHANNEL_G1_ADC1_AND_ADC1 			17
#define MADC_DCHANNEL_G1_ADC2_AND_ADC1 			18
#define MADC_DCHANNEL_G1_ADC3_AND_ADC1 			19
#define MADC_DCHANNEL_G1_ADC4_AND_ADC1 			20
#define MADC_DCHANNEL_G1_ADC5_AND_ADC1 			21
#define MADC_DCHANNEL_G1_ADC6_AND_ADC1			22
#define MADC_DCHANNEL_G1_ADC7_AND_ADC1 			23

#define MADC_DCHANNEL_G1_ADC0_AND_ADC2			24
#define MADC_DCHANNEL_G1_ADC1_AND_ADC2 			25
#define MADC_DCHANNEL_G1_ADC2_AND_ADC2 			26
#define MADC_DCHANNEL_G1_ADC3_AND_ADC2 			27
#define MADC_DCHANNEL_G1_ADC4_AND_ADC2 			28
#define MADC_DCHANNEL_G1_ADC5_AND_ADC2 			29


#define MADC_TESTCHANNEL_VBG_1_22V 				30
#define MADC_TESTCHANNEL_GND_0V 				31


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
	u8 ARG_u8PreScalar,
	u16 ARG_u8Resolution
);

STD_error_t	MADC_stderrorReadADC
(
	u16* ARG_u8pADCReading,
	u8 ARG_u8Channel
);

/*
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

STD_error_t MADC_voidSetTriggerSource
(
	u8 ARG_u8TriggerMode
);
*/
#endif
