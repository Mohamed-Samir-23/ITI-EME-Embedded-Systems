/**************************************/
/*  Author		: Mohamed Samir		  */
/*  SWC			: MP3MODULE		 	  */
/*  Layer		: HAL				  */
/*  Version		: 1.0				  */
/*  Date		: September 03, 2023  */
/*  Last Edit	: N/V 				  */
/**************************************/

#ifndef _HMP3MODULE_INTERFACE_H_
#define _HMP3MODULE_INTERFACE_H_

void HMP3MODULE_voidInit(void);

void HMP3MODULE_voidPlayTrack(u16 ARG_u16TrackNumber);

void HMP3MODULE_voidSelectVolume(u16 ARG_VolumeLevel);



#endif