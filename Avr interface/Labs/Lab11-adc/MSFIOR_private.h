/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: SFIOR				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 15, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/

#ifndef MSFIOR_PRIVATE_H_
#define MSFIOR_PRIVATE_H_


typedef union {

	volatile u8 ALL_REG;
	struct 
	{
		volatile u8 BIT0 	:1;
		volatile u8 BIT1 	:1;
		volatile u8 BIT2 	:1;
		volatile u8 BIT3 	:1;
		volatile u8 REVESED	:1;
		volatile u8 BIT5 	:1;
		volatile u8 BIT6 	:1;
		volatile u8 BIT7 	:1;
		
	}BITS;

}SFIOR_t;



#define SFIOR_REG         ((SFIOR_t*)0x50)


#define   PSR10           SFIOR_REG->BITS.BIT0
#define   PSR2            SFIOR_REG->BITS.BIT1
#define   PUD             SFIOR_REG->BITS.BIT2
#define   ACME            SFIOR_REG->BITS.BIT3
#define   ADTS0           SFIOR_REG->BITS.BIT5
#define   ADTS1           SFIOR_REG->BITS.BIT6
#define   ADTS2           SFIOR_REG->BITS.BIT7




#endif 
