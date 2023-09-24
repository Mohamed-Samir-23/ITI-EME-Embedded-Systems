/************************************/
/*	Author	  :	Mostafa Tawfik		*/
/*	SWC		  : TWI					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	August 29, 2023		*/
/*	Last Edit :	N/A					*/
/************************************/


#ifndef	_MTWI_PRIVATE_H_
#define _MTWI_PRIVATE_H_



/*TWI Bit Rate Register*/
#define TWBR *((volatile u8*)0x20)
/*TWI Control Register*/ 
#define TWCR *((volatile u8*)0x56)

/* TWI Interrupt flag it is raised for 7 more than a reason*/
#define TWINT			7
/* TWI Enable Acknowledge bit*/
#define TWEA			6
/* TWI Start Condition Bit*/		
#define TWSTA			5
/* TWI Stop Condition Bit*/
#define TWSTO			4
/* TWI Write Collison flag*/
#define TWWC			3
/* TWI Enable bit*/
#define TWEN			2
/*TWI PIE*/
#define TWIE			0


/*TWI Status Regiseter*/
#define TWSR *((volatile u8*)0x21)

/*5-Bit indiciates the status of the communication*/
#define TWST7			7
#define TWST6			6
#define TWST5			5
#define TWST4			4
#define TWST3			3
/*2-Bit to control the prescalers*/
#define TWPS1			1
#define TWPS0			0

/*TWD Data Regiseter*/
#define TWDR *((volatile u8*)0x23)
#define TWD7			7
#define TWD6			6
#define TWD5			5
#define TWD4			4
#define TWD3			3
#define TWD2			2
#define TWD1			1
#define TWD0			0





/*TWI Slave address register`*/
#define TWAR *((volatile u8*)0x22)


#define TWA6			7
#define TWA5   			6
#define TWA4   			5
#define TWA3   			4
#define TWA2   			3
#define TWA1   			2
#define TWA0   			1
#define TWGCE			0


#define TWS_MASK		0xF8

#endif
