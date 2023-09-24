/**************************************/
/*  Author		: Mohamed Samir		  */
/*  SWC			: MP3MODULE		 	  */
/*  Layer		: HAL				  */
/*  Version		: 1.0				  */
/*  Date		: September 03, 2023  */
/*  Last Edit	: N/V 				  */
/**************************************/


#ifndef _HMP3MODULE_PRIVATE_H_
#define _HMP3MODULE_PRIVATE_H_

#define MP3_CMD_SIZE						10

#define MP3_START_INITI_BYTE 				0x7E

#define MP3_VERSION_BYTE					0xFF

#define MP3_LENGTH_INITI_BYTE 				0x06

#define MP3_CMD_INITI_BYTE 					0x00

#define MP3_NOFEEDBACK_BYTE 				0x00

#define MP3_RQTFEEDBACK_BYTE 				0x01

#define MP3_HPARAMETER_INITI_BYTE 			0x00

#define MP3_LPARAMETER_INITI_BYTE 			0x00

#define MP3_HCHECKSUM_INITI_BYTE 			0x00

#define MP3_LCHECKSUM_INITI_BYTE 			0x00

#define MP3_END_INITI_BYTE 					0xEF


#define START_BYTE 							0

#define VERSION_BYTE 						1

#define LENGTH_BYTE 						2

#define CMD_BYTE 							3

#define FEEDBACK_BYTE 						4

#define MSBPARAMETER_BYTE 					5

#define LSBPARAMETER_BYTE 					6

#define MSBCHECKSUM_BYTE 					7

#define LSBCHECKSUM_BYTE 					8

#define END_BYTE 							9


static  void HMP3MODULE_voidSendCommandFrame(void);

#endif