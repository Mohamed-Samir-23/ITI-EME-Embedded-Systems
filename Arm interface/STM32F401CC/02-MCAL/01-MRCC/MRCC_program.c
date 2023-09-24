/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: RCC					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 15, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/

/* Library Include */
#include "LSTD_types.h"

/* SWC Include */
#include "MRCC_config.h"
#include "MRCC_private.h"
#include "MRCC_interface.h"

static u8 MRCC_u8PllCk=0;

STD_error_t MRCC_stderrorInit 
(
	RCC_ClkSrc_t 		ARG_udtClkSrc ,
	RCC_AHBPreScaler_t 	ARG_udtAHBPreScaler,
	RCC_APBPreScaler_t 	ARG_udtAPB1PreScaler,
	RCC_APBPreScaler_t 	ARG_udtAPB2PreScaler
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if((ARG_udtClkSrc<=4)&&(((ARG_udtAHBPreScaler>=8)&&(ARG_udtAHBPreScaler<=15))||(ARG_udtAHBPreScaler=0))&&(((ARG_udtAPB1PreScaler>=4)&&(ARG_udtAPB1PreScaler<=7))||(ARG_udtAPB1PreScaler=0))&&(((ARG_udtAPB2PreScaler>=4)&&(ARG_udtAPB2PreScaler<=7))||(ARG_udtAPB2PreScaler=0)))
	{
		switch(ARG_udtClkSrc)
		{
			case HSE_Crystal:
			{
				MRCC_u8PllCk=0;
				/*Enable HSE*/
				RCC_CR|=(1U<<HSEON);
				while((((RCC_CR>>HSERDY)&1))==0);
				/*Disable bypass*/
				RCC_CR	&=~(1U<<HSEBYP);
				/*SYSCLK equal to HSE*/
				RCC_CFGR=(RCC_CFGR&(~(3U<<SW)))|(HSE_FLAG);
				while((((RCC_CFGR>>SWS)&3U))!=1U);
				break;
			}
			case HSE_RC:
			{
				MRCC_u8PllCk=0;
				/*Enable HSE*/
				RCC_CR|=(1U<<HSEON);
				while((((RCC_CR>>HSERDY)&1))==0);
				/*Enable bypass*/
				RCC_CR|=(1U<<HSEBYP);
				/*SYSCLK equal to HSE*/
				RCC_CFGR=(RCC_CFGR&(~(3U<<SW)))|(HSE_FLAG);
				while((((RCC_CFGR>>SWS)&3U))!=1U);
				break;
			}
			case HSI:
			{
				MRCC_u8PllCk=0;
				/*Enable HSI*/
				RCC_CR|=(1U<<HSION);
				while((((RCC_CR>>HSIRDY)&1))==0);
				/*SYSCLK equal to HSI*/
				RCC_CFGR=(RCC_CFGR&(~(3U<<SW)));
				while((((RCC_CFGR>>SWS)&3U))!=0);
				break;
			}
			case PLL_HSE:
			{
				MRCC_u8PllCk=1;
				/*Enable HSE*/
				RCC_CR|=(1U<<HSEON);
				while((((RCC_CR>>HSERDY)&1))==0);
				/*PLL HSE SELECT*/
				RCC_PLLCFGR|=(1U<<PLLSRC);
				break;
			}
			case PLL_HSI:
			{
				MRCC_u8PllCk=1;
				/*Enable HSI*/
				RCC_CR|=(1U<<HSION);
				while((((RCC_CR>>HSIRDY)&1))==0);
				/*PLL HSI SELECT*/
				RCC_PLLCFGR	&=~(1U<<PLLSRC);
				break;
			}
			default : 
			{
				/*nothing*/
				break;
			}
		}
		
		
		RCC_CFGR=(RCC_CFGR&AHB_FLAG)|(ARG_udtAHBPreScaler<<HPRE);
		RCC_CFGR=(RCC_CFGR&APB1_FLAG)|(ARG_udtAPB1PreScaler<<PPRE1);
		RCC_CFGR=(RCC_CFGR&APB2_FLAG)|(ARG_udtAPB2PreScaler<<PPRE2);
		
		L_stderrorError = E_OK;
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}

STD_error_t MRCC_stderrorSetPllClockFreq
(
	u8 	ARG_u8PLLM,
	u16 ARG_u16PLLN,
	u8 	ARG_u8PLLP,
	u8 	ARG_u8PLLQ
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if((MRCC_u8PllCk==1)&&((ARG_u8PLLM>=2)&&(ARG_u8PLLM<=63))&&((ARG_u16PLLN>=192)&&(ARG_u16PLLN<=432))&&((ARG_u8PLLP%2==0)&&(ARG_u8PLLP<=8)&&(ARG_u8PLLP!=0))&&((ARG_u8PLLQ>=2)&&(ARG_u8PLLQ<=15)))
	{
		/*Set PLLM, PLLN, PLLP, PLLQ*/
		RCC_PLLCFGR=(RCC_PLLCFGR&PLL_FLAG)|(ARG_u8PLLM<<PLLM)|(ARG_u16PLLN<<PLLN)|(ARG_u8PLLP<<PLLP)|(ARG_u8PLLQ<<PLLQ);
		/*Enable PLL*/
		RCC_CR|=(1U<<PLLRON);
		while((((RCC_CR>>PLLRDY)&1))==0);
		/*SYSCLK equal to PLL*/
		RCC_CFGR=(RCC_CFGR&(~(3U<<SW)))|PLL_SYS_FLAG;
		while((((RCC_CFGR>>SWS)&3U))!=2U);
		L_stderrorError = E_OK;
	}
	else
	{
		L_stderrorError=E_NOK;	
	}
	
	return L_stderrorError;
}

void MRCC_voidInit
(
	void
)
{
	
	#if RCC_ClkSrc ==	1 
	
	/*Enable HSE*/
	RCC_CR|=(1U<<HSEON);
	while((((RCC_CR>>HSERDY)&1))==0);
	/*Disable bypass*/
	RCC_CR	&=~(1U<<HSEBYP);
	/*SYSCLK equal to HSE*/
	RCC_CFGR=(RCC_CFGR&(~(3U<<SW)))|(HSE_FLAG);
	while((((RCC_CFGR>>SWS)&3U))!=1U);
	/*Set PreScaller*/
	RCC_CFGR=(RCC_CFGR&AHB_FLAG)|(RCC_AHBPreScaler<<HPRE);
	RCC_CFGR=(RCC_CFGR&APB1_FLAG)|(RCC_APB1PreScaler<<PPRE1);
	RCC_CFGR=(RCC_CFGR&APB2_FLAG)|(RCC_APB2PreScaler<<PPRE2);
	
	#elif RCC_ClkSrc ==	2

	/*Enable HSE*/
	RCC_CR|=(1U<<HSEON);
	while((((RCC_CR>>HSERDY)&1))==0);
	/*Enable bypass*/
	RCC_CR|=(1U<<HSEBYP);
	/*SYSCLK equal to HSE*/
	RCC_CFGR=(RCC_CFGR&(~(3U<<SW)))|(HSE_FLAG);
	while((((RCC_CFGR>>SWS)&3U))!=1U);
	/*Set PreScaller*/
	RCC_CFGR=(RCC_CFGR&AHB_FLAG)|(RCC_AHBPreScaler<<HPRE);
	RCC_CFGR=(RCC_CFGR&APB1_FLAG)|(RCC_APB1PreScaler<<PPRE1);
	RCC_CFGR=(RCC_CFGR&APB2_FLAG)|(RCC_APB2PreScaler<<PPRE2);
	
	#elif RCC_ClkSrc ==	3
	
	/*Enable HSI*/
	RCC_CR|=(1U<<HSION);
	while((((RCC_CR>>HSIRDY)&1))==0);
	/*SYSCLK equal to HSI*/
	RCC_CFGR=(RCC_CFGR&(~(3U<<SW)));
	while((((RCC_CFGR>>SWS)&3U))!=0);
	/*Set PreScaller*/
	RCC_CFGR=(RCC_CFGR&AHB_FLAG)|(RCC_AHBPreScaler<<HPRE);
	RCC_CFGR=(RCC_CFGR&APB1_FLAG)|(RCC_APB1PreScaler<<PPRE1);
	RCC_CFGR=(RCC_CFGR&APB2_FLAG)|(RCC_APB2PreScaler<<PPRE2);
	
	#elif RCC_ClkSrc ==	4
		#if (((RCC_PLLM>=2)&&(RCC_PLLM<=63))&&((RCC_PLLN>=192)&&(RCC_PLLN<=432))&&((RCC_PLLP%2==0)&&(RCC_PLLP<=8)&&(RCC_PLLP!=0))&&((RCC_PLLQ>=2)&&(RCC_PLLQ<=15)))
		/*Enable HSE*/
		RCC_CR|=(1U<<HSEON);
		while((((RCC_CR>>HSERDY)&1))==0);
		/*PLL HSE SELECT*/
		RCC_PLLCFGR|=(1U<<PLLSRC);
		/*Set PreScaller*/
		RCC_CFGR=(RCC_CFGR&AHB_FLAG)|(RCC_AHBPreScaler<<HPRE);
		RCC_CFGR=(RCC_CFGR&APB1_FLAG)|(RCC_APB1PreScaler<<PPRE1);
		RCC_CFGR=(RCC_CFGR&APB2_FLAG)|(RCC_APB2PreScaler<<PPRE2);
		/*Set PLLM, PLLN, PLLP, PLLQ*/
		RCC_PLLCFGR=(RCC_PLLCFGR&PLL_FLAG)|(RCC_PLLM<<PLLM)|(RCC_PLLN<<PLLN)|(RCC_PLLP<<PLLP)|(RCC_PLLQ<<PLLQ);
		/*Enable PLL*/
		RCC_CR|=(1U<<PLLRON);
		while((((RCC_CR>>PLLRDY)&1))==0);
		/*SYSCLK equal to PLL*/
		RCC_CFGR=(RCC_CFGR&(~(3U<<SW)))|PLL_SYS_FLAG;
		while((((RCC_CFGR>>SWS)&3U))!=2U);
		#else
			
		#error Wrong Parameters
		
		#endif
	
	#elif RCC_ClkSrc ==	5
	
		#if (((RCC_PLLM>=2)&&(RCC_PLLM<=63))&&((RCC_PLLN>=192)&&(RCC_PLLN<=432))&&((RCC_PLLP%2==0)&&(RCC_PLLP<=8)&&(RCC_PLLP!=0))&&((RCC_PLLQ>=2)&&(RCC_PLLQ<=15)))
		/*Enable HSI*/
		RCC_CR|=(1U<<HSION);
		while((((RCC_CR>>HSIRDY)&1))==0);
		/*PLL HSI SELECT*/
		RCC_PLLCFGR	&=~(1U<<PLLSRC);
		/*Set PreScaller*/
		RCC_CFGR=(RCC_CFGR&AHB_FLAG)|(RCC_AHBPreScaler<<HPRE);
		RCC_CFGR=(RCC_CFGR&APB1_FLAG)|(RCC_APB1PreScaler<<PPRE1);
		RCC_CFGR=(RCC_CFGR&APB2_FLAG)|(RCC_APB2PreScaler<<PPRE2);
		/*Set PLLM, PLLN, PLLP, PLLQ*/
		RCC_PLLCFGR=(RCC_PLLCFGR&PLL_FLAG)|(RCC_PLLM<<PLLM)|(RCC_PLLN<<PLLN)|(RCC_PLLP<<PLLP)|(RCC_PLLQ<<PLLQ);
		/*Enable PLL*/
		RCC_CR|=(1U<<PLLRON);
		while((((RCC_CR>>PLLRDY)&1))==0);
		/*SYSCLK equal to PLL*/
		RCC_CFGR=(RCC_CFGR&(~(3U<<SW)))|PLL_SYS_FLAG;
		while((((RCC_CFGR>>SWS)&3U))!=2U);
		#else
			
		#error Wrong Parameters
		
		#endif
	
	#else
		
	#error Wrong Selection
	
	#endif
	
	
}


STD_error_t RCC_EnablePeripheralClk
(
	RCC_Bus_t 			ARG_udtBus,
	RCC_PeripheraName_t ARG_udtPeripheraName
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	switch(ARG_udtBus)
	{
		case AHB1:
		{
			RCC_AHB1ENR|=(1U<<ARG_udtPeripheraName);
			L_stderrorError=E_OK;
			break;
		}
		case AHB2:
		{
			RCC_AHB2ENR|=(1U<<ARG_udtPeripheraName);
			L_stderrorError=E_OK;
			break;
		}
		case APB1:
		{
			RCC_APB1ENR|=(1U<<ARG_udtPeripheraName);
			L_stderrorError=E_OK;
			break;
		}
		case APB2:
		{
			RCC_APB2ENR|=(1U<<ARG_udtPeripheraName);
			L_stderrorError=E_OK;
			break;
		}
		
		default:
		{
			L_stderrorError=E_NOK;
			break;
		}
			
	}
	return L_stderrorError;
	
}


STD_error_t RCC_DisablePeripheralClk
(
	RCC_Bus_t 			ARG_udtBus,
	RCC_PeripheraName_t ARG_udtPeripheraName
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	switch(ARG_udtBus)
	{
		case AHB1:
		{
			RCC_AHB1ENR	&=~(1U<<ARG_udtPeripheraName);
			L_stderrorError=E_OK;
			break;
		}
		case AHB2:
		{
			RCC_AHB2ENR	&=~(1U<<ARG_udtPeripheraName);
			L_stderrorError=E_OK;
			break;
		}
		case APB1:
		{
			RCC_APB1ENR	&=~(1U<<ARG_udtPeripheraName);
			L_stderrorError=E_OK;
			break;
		}
		case APB2:
		{
			RCC_APB2ENR	&=~(1U<<ARG_udtPeripheraName);
			L_stderrorError=E_OK;
			break;
		}
		
		default:
		{
			L_stderrorError=E_NOK;
			break;
		}
			
	}
	return L_stderrorError;
	
}
