/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: SPI					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: August 27,2023 		*/
/*  Last Edit	: N/A					*/
/****************************************/

#ifndef  _MSPI_INTERFACE_H_
#define  _MSPI_INTERFACE_H_

#define   MSPI_MODE_MASTER                              16
#define   MSPI_MODE_SLAVE                               0

#define   MSPI_CLOCK_POLPHA_NONINVERTING_LEADING        0
#define   MSPI_CLOCK_POLPHA_NONINVERTING_TRAILING       4
#define   MSPI_CLOCK_POLPHA_INVERTING_LEADING           8
#define   MSPI_CLOCK_POLPHA_INVERTING_TRAILING          12

#define   MSPI_DATAORDER_MSB                            0
#define   MSPI_DATAORDER_LSB                            32

#define   MSPI_PRESCALAR_4                              0
#define   MSPI_PRESCALAR_16                             1
#define   MSPI_PRESCALAR_64                             2
#define   MSPI_PRESCALAR_128                            3
#define   MSPI_PRESCALAR_2                              4
#define   MSPI_PRESCALAR_8                              5
#define   MSPI_PRESCALAR_32                             6

STD_error_t MSPI_stderrorInti(u8 ARG_u8Mode, u8 ARG_u8ClockPolPha, u8 ARG_u8DataOrder, u8 ARG_u8PreScalar);

void MSPI_voidEnable(void);

void MSPI_voidDisable(void);

void MSPI_voidEnableInterrupt(void);

void MSPI_voidDisableInterrupt(void);

STD_error_t MSPI_stderrorSetCallback(void (*ARG_pvoidfUserFunction)(void));

char MSPI_charTranceive(char ARG_charData);

void MSPI_voidFlagPolling(void);

#endif
