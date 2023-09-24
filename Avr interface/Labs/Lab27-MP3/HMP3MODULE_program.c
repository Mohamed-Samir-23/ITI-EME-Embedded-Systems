/**************************************/
/*  Author		: Mohamed Samir		  */
/*  SWC			: MP3MODULE		 	  */
/*  Layer		: HAL				  */
/*  Version		: 1.0				  */
/*  Date		: September 03, 2023  */
/*  Last Edit	: N/V 				  */
/**************************************/

/* Library Include */
#include "LBIT_math.h"
#include "LSTD_types.h"

/* SWC Include */
#include "HMP3MODULE_private.h"
#include "HMP3MODULE_config.h"
#include "HMP3MODULE_interface.h"
#include "MUSART_interface.h"
#include <util/delay.h>


#define MP3_CMD_PLAYBACK 0x03

#define MP3_CMD_SETVOLUME 0x06

#define MP3_CMD_RESET 0x0C

#define MP3_CMD_PLAY 0x0D

#define MP3_CMD_PAUSE 0x0E






u8 HMP3MODULE_u8DefualtCommand[MP3_CMD_SIZE] = 
{
MP3_START_INITI_BYTE,
MP3_VERSION_BYTE,
MP3_LENGTH_INITI_BYTE,
MP3_CMD_INITI_BYTE,
MP3_NOFEEDBACK_BYTE,
MP3_HPARAMETER_INITI_BYTE,
MP3_LPARAMETER_INITI_BYTE,
MP3_HCHECKSUM_INITI_BYTE,
MP3_LCHECKSUM_INITI_BYTE,
MP3_END_INITI_BYTE
};


void HMP3MODULE_voidInit(void)
{
	MUSART_stderrorInit
	(
		MUSART_TX_MODE,
		MUSART_SINGLE_PROCESSOR ,
		MUSART_ASYNC_NORMAL_SPEED,
		MUSART_INTERRUPT_DISABLE,
		MUSART_8BIT_DATA,
		MUSART_PARITY_DISABLE,
		MUSART_STOP_1BIT,
		MUSART_SAMPLE_DISABLE,
		9600
	);
	
	HMP3MODULE_u8DefualtCommand[CMD_BYTE]=MP3_CMD_RESET;
	
	HMP3MODULE_voidSendCommandFrame();
	
	HMP3MODULE_u8DefualtCommand[CMD_BYTE]=MP3_CMD_INITI_BYTE;

	_delay_ms(1000);
}

void HMP3MODULE_voidPlayTrack(u16 ARG_u16TrackNumber)
{
	
	HMP3MODULE_u8DefualtCommand[CMD_BYTE]=MP3_CMD_PLAYBACK;
	
	HMP3MODULE_u8DefualtCommand[MSBPARAMETER_BYTE]=ARG_u16TrackNumber>>8;
	
	HMP3MODULE_u8DefualtCommand[LSBPARAMETER_BYTE]=(u8)ARG_u16TrackNumber;
	
	HMP3MODULE_voidSendCommandFrame();
	
	HMP3MODULE_u8DefualtCommand[CMD_BYTE]=MP3_CMD_INITI_BYTE;
	
	HMP3MODULE_u8DefualtCommand[MSBPARAMETER_BYTE]=MP3_HPARAMETER_INITI_BYTE;
	
	HMP3MODULE_u8DefualtCommand[LSBPARAMETER_BYTE]=MP3_LPARAMETER_INITI_BYTE;
}

void HMP3MODULE_voidSelectVolume(u16 ARG_VolumeLevel)
{
	
	HMP3MODULE_u8DefualtCommand[CMD_BYTE]=MP3_CMD_SETVOLUME;
	
	HMP3MODULE_u8DefualtCommand[MSBPARAMETER_BYTE]=ARG_VolumeLevel>>8;
	
	HMP3MODULE_u8DefualtCommand[LSBPARAMETER_BYTE]=(u8)ARG_VolumeLevel;
	
	HMP3MODULE_voidSendCommandFrame();
	
	HMP3MODULE_u8DefualtCommand[CMD_BYTE]=MP3_CMD_INITI_BYTE;
	
	HMP3MODULE_u8DefualtCommand[MSBPARAMETER_BYTE]=MP3_HPARAMETER_INITI_BYTE;
	
	HMP3MODULE_u8DefualtCommand[LSBPARAMETER_BYTE]=MP3_LPARAMETER_INITI_BYTE;
	
}



static  void HMP3MODULE_voidSendCommandFrame(void)
{
	
	u8 L_u8i;
	u16 L_u8CheckSum=0;
	u16 L_u8AddFrame=0;
	for(L_u8i=0;L_u8i<10;L_u8i++)
	{
		
		if(L_u8i>0&&L_u8i<7)
		{
			
			L_u8AddFrame+=HMP3MODULE_u8DefualtCommand[L_u8i];
			
		}
		else if(L_u8i==7)
		{
			
			L_u8CheckSum=0xFFFF-L_u8AddFrame+1;
			
			HMP3MODULE_u8DefualtCommand[MSBCHECKSUM_BYTE]= L_u8CheckSum>>8;
			
			HMP3MODULE_u8DefualtCommand[LSBCHECKSUM_BYTE]= (u8) L_u8CheckSum;
		}
		MUSART_stderrorSendDataSync(HMP3MODULE_u8DefualtCommand[L_u8i]);
	}
}
