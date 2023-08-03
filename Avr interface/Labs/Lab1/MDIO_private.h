/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: DIO				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 3, 2023	*/
/*  Last Edit	: N/A				*/
/************************************/

#ifndef _MDIO_PRIVATE_H_
#define _MDIO_PRIVATE_H_

typedef struct
{
	u8 const PIN;
	u8 DDR;
	u8 PORT;
	
}GPIO_t;


#define GPIOD  ((volatile GPIO_t * const)(0X30))
#define GPIOC  ((volatile GPIO_t * const)(0X33))
#define GPIOB  ((volatile GPIO_t * const)(0X36))
#define GPIOA  ((volatile GPIO_t * const)(0X39))



#endif
