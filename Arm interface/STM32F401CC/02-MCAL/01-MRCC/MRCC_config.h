/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: RCC					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 15, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/


#ifndef _MRCC_CONFIG_H_
#define _MRCC_CONFIG_H_

/**

  *RCC_ClkSrc can be one of the following values:
  *	HSE_Crystal-> 1
  *	HSE_RC------> 2
  *	HSI---------> 3
  *	PLL_HSE-----> 4
  *	PLL_HSI-----> 5
	
*/
#define RCC_ClkSrc	1

/**

  *RCC_AHBPreScaler can be one of the following values:
  *	AHB_PreScaler1		=	0
  *	AHB_PreScaler2		=	8
  *	AHB_PreScaler4		=	9
  *	AHB_PreScaler8		=	10
  *	AHB_PreScaler16		=	11
  *	AHB_PreScaler64		=	12
  *	AHB_PreScaler128	=	13
  *	AHB_PreScaler256	=	14
  *	AHB_PreScaler512	=	15

*/
#define RCC_AHBPreScaler 8

/**

  *RCC_APB1PreScaler can be one of the following values:
  *	APB1_PreScaler1		=	0
  *	APB1_PreScaler2		=	4
  *	APB1_PreScaler4		=	5
  *	APB1_PreScaler8		=	6
  *	APB1_PreScaler16	=	7

*/
#define RCC_APB1PreScaler 8

/**

  *RCC_APB2PreScaler can be one of the following values:
  *	APB2_PreScaler1		=	0
  *	APB2_PreScaler2		=	4
  *	APB2_PreScaler4		=	5
  *	APB2_PreScaler8		=	6
  *	APB2_PreScaler16	=	7

*/
#define RCC_APB2PreScaler 8

/**

  *RCC_PLLM	can be one of the following values:
  *	2<= PLLM <= 63

*/
#define RCC_PLLM	8

/**

  *RCC_PLLN	can be one of the following values:
  *	192<= PLLN <= 432

*/	
#define RCC_PLLN 192

/**

  *PLLP	can be one of the following values:
  *	PLLP = 2, 4, 6, 8

*/		
#define RCC_PLLP	2

/**

  *PLLQ	can be one of the following values:
  *	2<= PLLQ <= 15

*/
#define RCC_PLLQ	2


#endif