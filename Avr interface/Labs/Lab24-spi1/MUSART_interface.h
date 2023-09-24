/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MUSART			*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 27, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/


#ifndef _MUSART_INTERFACE_H_
#define _MUSART_INTERFACE_H_

/*CommunicationTerminal*/
#define MUSART_SINGLE_PROCESSOR 									0
#define MUSART_MULTI_PROCESSOR 										1

/*CommunicationMode*/
#define MUSART_ASYNC_NORMAL_SPEED									0
#define MUSART_ASYNC_DOUBLE_SPEED									1
#define MUSART_SYNC													2


/*EnableMode*/
#define MUSART_DISABLE_MODE											0
#define MUSART_TX_MODE												1
#define MUSART_RX_MODE												2
#define MUSART_TX_RX_MODE											3

/*InterruptSource*/
#define MUSART_INTERRUPT_DISABLE									0
#define MUSART_INTERRUPT_UDREMPTY_ENABLE							1
#define MUSART_INTERRUPT_TXCOMPLETE_ENABLE							2
#define MUSART_INTERRUPT_TXCOMPLETE_UDREMPTY_ENABLE					3
#define MUSART_INTERRUPT_RXCOMPLETE_ENABLE							4
#define MUSART_INTERRUPT_RXCOMPLETE_UDREMPTY_ENABLE					5
#define MUSART_INTERRUPT_RXCOMPLETE_TXCOMPLETE_ENABLE				6
#define MUSART_INTERRUPT_RXCOMPLETE_TXCOMPLETE_UDREMPTY_ENABLE		7

/*DataFrame*/
#define MUSART_5BIT_DATA											0
#define MUSART_6BIT_DATA											1
#define MUSART_7BIT_DATA											2
#define MUSART_8BIT_DATA											3
#define MUSART_9BIT_DATA											7

/*ParityFrame*/
#define MUSART_PARITY_DISABLE										0
#define MUSART_PARITY_EVEN											1
#define MUSART_PARITY_ODD											2

/*StopFrame*/
#define MUSART_STOP_1BIT											0
#define MUSART_STOP_2BIT											1

/*ClockPolarity*/
#define MUSART_SAMPLE_ON_FALLING									0
#define MUSART_SAMPLE_ON_RISING										1
#define MUSART_SAMPLE_DISABLE										0
 

#ifndef F_CPU
#define F_CPU 1000000UL
#warning F_CPU is not define. Assuming 8MHz clock.
#endif


STD_error_t MUSART_stderrorInit
(
	u8 ARG_u8USARTEnableMode,
	u8 ARG_u8CommunicationTerminal,
	u8 ARG_u8CommunicationMode,
	u8 ARG_u8InterruptSource,
	u8 ARG_u8DataFrame,
	u8 ARG_u8ParityFrame,
	u8 ARG_u8StopFrame,
	u8 ARG_ClockPolarity,
	u16 ARG_u16BaudRate
);

STD_error_t	MUSART_stderrorSendDataSync
(
	u16 ARG_u16Data
);

STD_error_t	MUSART_stderrorSendDataASync
(
	u16 ARG_u16Data,
	void (*ARG_pvoidfNotificationFunction)(void)
);


STD_error_t	MUSART_stderrorReadDataSync
(
	u16* ARG_u16Data
);

STD_error_t	MUSART_stderrorReadDataASync
(
	u16* ARG_u16Data,
	void (*ARG_pvoidfNotificationFunction)(void)
);


void MUSART_voidSendString
(
	const char* ARG_ccharpString
);


#endif
