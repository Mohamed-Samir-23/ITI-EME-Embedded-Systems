/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MADC				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 15, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/


#ifndef _MADC_PRIVATE_H_
#define _MADC_PRIVATE_H_


typedef union 
{

	volatile u8 ALL_REG;
	struct 
	{
		volatile u8 BIT0 :1;
		volatile u8 BIT1 :1;
		volatile u8 BIT2 :1;
		volatile u8 BIT3 :1;
		volatile u8 BIT4 :1;
		volatile u8 BIT5 :1;
		volatile u8 BIT6 :1;
		volatile u8 BIT7 :1;
		
	}BITS;
	
}ADC_t;


#define MADC_Enable 					1u
#define MADC_Disable 					0u

#define MADC_ADMUX         				((ADC_t*) 0x27)
#define  	MUX0                     	MADC_ADMUX->BITS.BIT0
#define  	MUX1                     	MADC_ADMUX->BITS.BIT1
#define  	MUX2                    	MADC_ADMUX->BITS.BIT2
#define  	MUX3                     	MADC_ADMUX->BITS.BIT3
#define  	MUX4                    	MADC_ADMUX->BITS.BIT4
#define  	ADLAR                    	MADC_ADMUX->BITS.BIT5
#define  	REFS0                    	MADC_ADMUX->BITS.BIT6
#define  	REFS1                    	MADC_ADMUX->BITS.BIT7


#define 	MADC_ADCSRA           		((ADC_t*) 0x26)
#define   	ADPS0                		MADC_ADCSRA->BITS.BIT0
#define   	ADPS1                		MADC_ADCSRA->BITS.BIT1
#define   	ADPS2                		MADC_ADCSRA->BITS.BIT2
#define   	ADIE                 		MADC_ADCSRA->BITS.BIT3
#define   	ADIF                 		MADC_ADCSRA->BITS.BIT4
#define   	ADATE                		MADC_ADCSRA->BITS.BIT5
#define   	ADSC                 		MADC_ADCSRA->BITS.BIT6
#define   	ADEN                 		MADC_ADCSRA->BITS.BIT7



#define SFIOR_REG         				((ADC_t*)0x50)
#define   PSR10           				SFIOR_REG->BITS.BIT0
#define   PSR2            				SFIOR_REG->BITS.BIT1
#define   PUD             				SFIOR_REG->BITS.BIT2
#define   ACME            				SFIOR_REG->BITS.BIT3
#define   ADTS0           				SFIOR_REG->BITS.BIT5
#define   ADTS1           				SFIOR_REG->BITS.BIT6
#define   ADTS2           				SFIOR_REG->BITS.BIT7





#define  ADCH_REG              			*((volatile u8*)0x25)
#define  ADCL_REG              			*((volatile u8*)0x24)







#endif 
