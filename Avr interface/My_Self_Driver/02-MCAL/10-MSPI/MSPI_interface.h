/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MSPI				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 28, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/



#ifndef _MSPI_INTERFACE_H_
#define _MSPI_INTERFACE_H_

/*SPI CONTROL*/
#define SPI_DISABLE 				0
#define SPI_ENABLE 					1

/*SPI INTERRUPTSTATE*/
#define SPI_INTERRUPTDISABLE		0
#define SPI_INTERRUPTENABLE			1

/*SPI DATA ORDER*/
#define MSPI_MSB 					0
#define MSPI_LSB 					1


/*SPI MODE*/
#define MSPI_SLAVE 					0
#define MSPI_MASTER 				1

/*SPI INTERRUPT STATE*/
#define MSPI_MODE0 					0
#define MSPI_MODE1 					1
#define MSPI_MODE2 					2
#define MSPI_MODE3 					3

/*OSCILLATOR FREQUENCY*/
#define MSPI_FCPU_BY_4 				0
#define MSPI_FCPU_BY_16 			1
#define MSPI_FCPU_BY_64 			2
#define MSPI_FCPU_BY_128 			3
#define MSPI_FCPU_BY_2 				4
#define MSPI_FCPU_BY_8 				5
#define MSPI_FCPU_BY_32 			6


STD_error_t MUSART_stderrorInit
(
	u8 ARG_u8MEnableControl,
	u8 ARG_u8Mode,
	u8 ARG_u8ClockMode,
	u8 ARG_u8DataOrder,
	u8 ARG_u8InterruptState,
	u8 ARG_u8Freq
);

u8 MSPI_ReadWrite_Sync
(
	u8  ARG_u8Data
);

STD_error_t MSPI_ReadWrite_ASync
(
	u8 * ARG_pu8Data,
	void (*ARG_pvoidfNotificationFunction)(void)
);

void MUSART_voidSendString
(
	const char* ARG_ccharpString
);



#endif