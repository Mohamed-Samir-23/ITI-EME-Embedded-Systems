/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MADC				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 21, 2023	*/
/*  Last Edit	: August 25, 2023	*/
/************************************/


#ifndef _MADC_PRIVATE_H_
#define _MADC_PRIVATE_H_

#define 	MADC_Enable 				1u
#define 	MADC_Disable 				0u

#define 	MADC_ADMUX         			*((volatile u8*) 0x27)
#define  	MUX0                     	0
#define  	MUX1                     	1
#define  	MUX2                    	2
#define  	MUX3                     	3
#define  	MUX4                    	4
#define  	ADLAR                    	5
#define  	REFS0                    	6
#define  	REFS1                    	7


#define 	MADC_ADCSRA           		*((volatile u8*) 0x26)
#define   	ADPS0                		0
#define   	ADPS1                		1
#define   	ADPS2                		2
#define   	ADIE                 		3
#define   	ADIF                 		4
#define   	ADATE                		5
#define   	ADSC                 		6
#define   	ADEN                 		7


#ifndef SFIOR_REG
#define 	SFIOR_REG         			*((volatile u8*)0x50)
#endif

#define   	ADTS0           			5
#define   	ADTS1           			6
#define   	ADTS2           			7

#define  	ADCH_REG              		*((volatile u8*)0x25)

#define  	ADCL_REG              		*((volatile u8*)0x24)

#define  	ADCLH_REG              		*((volatile u16*)0x24)


#define 	RefVoltage_MASK				0x3F

#define 	PRESCALAR_MASK				0xF8

#define 	CHANNEL_MASK				0xE0


#define 	IDEL 						0
#define 	BUSY 						1

#define 	RESELUTION_256				1 
#define 	RESELUTION_1024				2 

#define 	SINGLE_CHANNEL_ASYNC		1

#define 	CHAINE_CHANNEL_ASYNC		2

#endif 
