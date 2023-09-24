/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: RCC					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 15, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/


#ifndef _MRCC_INTERFACE_H_
#define _MRCC_INTERFACE_H_

typedef enum
{
	AHB1=0,
	AHB2,
	APB1,
	APB2
	
}RCC_Bus_t;

typedef enum
{
	HSE_Crystal=0,
	HSE_RC,
	HSI,
	PLL_HSE,
	PLL_HSI,
	
}RCC_ClkSrc_t;

typedef enum
{
	APB_PreScaler1=0,
	APB_PreScaler2=4,
	APB_PreScaler4,
	APB_PreScaler8,
	APB_PreScaler16,

}RCC_APBPreScaler_t;


typedef enum
{
	AHB_PreScaler1=0,
	AHB_PreScaler2=8,
	AHB_PreScaler4,
	AHB_PreScaler8,
	AHB_PreScaler16,
	AHB_PreScaler64,
	AHB_PreScaler128,
	AHB_PreScaler256,
	AHB_PreScaler512
	
}RCC_AHBPreScaler_t;

typedef enum
{
	GPIOA_PER=		0,
	GPIOB_PER=		1,
	GPIOC_PER=		2,
	GPIOD_PER=		3,
	GPIOE_PER=		4,
	GPIOH_PER=		7,
	CRC_PER=		12,
	DMA1_PER=		21,
	DMA2_PER=		22,
	OTGFS_PER=		7,
	TIM2_PER=		0,
	TIM3_PER=		1,
	TIM4_PER=		2,
	TIM5_PER=		3,
	WWDG_PER=		11,
	SPI2_PER=		14,
	SPI3_PER=		15,
	USART2_PER=		17,
	I2C1_PER=		21,
	I2C2_PER=		22,
	I2C3_PER=		23,
	PWR_PER=		28,
	TIM1_PER=		0,
	USART1_PER=		4,
	USART6_PER=		5,
	ADC1_PER=		8,
	SDIO_PER=		11,
	SPI1_PER=		12,
	SPI4_PER=		13,
	SYSCFG_PER=		14,
	TIM9_PER=		16,
	TIM10_PER=		17,
	TIM11_PER=		18,
	
}RCC_PeripheraName_t;


STD_error_t MRCC_stderrorInit 
(
	RCC_ClkSrc_t 		ARG_udtClkSrc ,
	RCC_AHBPreScaler_t 	ARG_udtAHBPreScaler,
	RCC_APBPreScaler_t 	ARG_udtAPB1PreScaler,
	RCC_APBPreScaler_t 	ARG_udtAPB2PreScaler
);

STD_error_t MRCC_stderrorSetPllClockFreq
(
	u8 	ARG_u8PLLM,
	u16 ARG_u16PLLN,
	u8 	ARG_u8PLLP,
	u8 	ARG_u8PLLQ
);

void MRCC_voidInit
(
	void
);

STD_error_t RCC_EnablePeripheralClk
(
	RCC_Bus_t 			ARG_udtBus,
	RCC_PeripheraName_t ARG_udtPeripheraName
);

STD_error_t RCC_DisablePeripheralClk
(
	RCC_Bus_t 			ARG_udtBus,
	RCC_PeripheraName_t ARG_udtPeripheraName
);

#endif
