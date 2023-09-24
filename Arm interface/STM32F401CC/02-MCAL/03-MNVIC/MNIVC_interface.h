/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: NIVC					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 18, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/

#define _MNIVC_INTERFACE_H_
#define _MNIVC_INTERFACE_H_


typedef enum 
{
	WWDG=0,
	EXTI16_PVD,
	EXTI21_TAMP_STAMP,
	EXTI22_RTC_WKUP,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Stream0,
	DMA1_Stream1,
	DMA1_Stream2,
	DMA1_Stream3,
	DMA1_Stream4,
	DMA1_Stream5,
	DMA1_Stream6,
	ADC,
	TIM1_BRK_TIM9,
	TIM1_UP_TIM10,
	TIM1_TRG_COM_TIM11,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,
	I2C1_ER,
	I2C2_EV,
	I2C2_ER,
	SPI1,
	SPI2,
	USART1,
	EXTI17_RTC_Alarm,
	EXTI18_OTG_FS_WKUP,
	DMA1_Stream7,
	SDIO,
	SPI3,
	DMA2_Stream0,
	DMA2_Stream1,
	DMA2_Stream2,
	DMA2_Stream3,
	DMA2_Stream4,
	OTG_FS,
	DMA2_Stream5,
	DMA2_Stream6,
	DMA2_Stream7,
	USART6,
	I2C3_EV,
	FPU,
	SPI4,
	
}NIVC_SRC_t;


typedef enum 
{
	GROUP0,
	GROUP1,
	GROUP2,
	GROUP3,
	GROUP4,
	GROUP5,
	GROUP6,
	GROUP7,
	GROUP8,
	GROUP9,
	GROUP10,
	GROUP11,
	GROUP12,
	GROUP13,
	GROUP14,
	GROUP15,
	GROUP16,
	
} NIVC_GroupPriority_t;


typedef enum 
{
	SUB_GROUP0,
	SUB_GROUP1,
	SUB_GROUP2,
	SUB_GROUP3,
	SUB_GROUP4,
	SUB_GROUP5,
	SUB_GROUP6,
	SUB_GROUP7,
	SUB_GROUP8,
	SUB_GROUP9,
	SUB_GROUP10,
	SUB_GROUP11,
	SUB_GROUP12,
	SUB_GROUP13,
	SUB_GROUP14,
	SUB_GROUP15,
	SUB_GROUP16,
	
} NIVC_SubGroupPriority_t;



typedef enum 
{
	PRIGROUP_16GRU_0SUB=3,
	PRIGROUP_8GRU_2SUB,
	PRIGROUP_4GRU_4SUB,
	PRIGROUP_2GRU_8SUB,
	PRIGROUP_0GRU_16SUB,
	
} SCB_PriorityGroup_t;


STD_error_t NVIC_stderrorEnable
(
	NIVC_SRC_t ARG_udtSrc
);
STD_error_t NVIC_stderrorDisable
(
	NIVC_SRC_t ARG_udtSrc
);
STD_error_t NVIC_stderrorSetPending
(
	NIVC_SRC_t ARG_udtSrc
);
STD_error_t NVIC_stderrorClearPending
(
	NIVC_SRC_t ARG_udtSrc
);
STD_error_t NVIC_stderrorGetPending
(
	NIVC_SRC_t ARG_udtSrc ,
	u8* ARG_pu8PendingValue
);
STD_error_t NVIC_stderrorGetActive
(
	NIVC_SRC_t ARG_udtSrc ,
	u8* ARG_pu8ActiveValue
);
STD_error_t NVIC_stderrorSetPriorityGrouping
(
	NIVC_SRC_t ARG_udtSrc ,
	SCB_PriorityGroup_t ARG_udtGroupPriority
);

STD_error_t NVIC_stderrorSetInterruptPriority
(
	NIVC_SRC_t ARG_udtSrc ,
	NIVC_GroupPriority_t ARG_udtGroupPriority,
	NIVC_SubGroupPriority_t ARG_udtSubGroupPriority
);

STD_error_t NVIC_stderrorGetPriority
(
	NIVC_SRC_t ARG_udtSrc
	u8* ARG_pu8PriorityValue
);

STD_error_t NVIC_stderrorGetPriorityGrouping
(
	u8* ARG_pu8PriorityGroupingValue
);

#endif