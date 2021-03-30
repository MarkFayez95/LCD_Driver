/*
 * LCD_CFG.h
 *
 * Created: 26/03/2021 1:14:13 PM
 *  Author: Mark Fayez
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "DIO.h"

#define	LCD_Mode	4

#if LCD_Mode == 4

	#define		LCD_4BIT_MODE_CMD_PORT		DIO_PORTB
	#define		LCD_4BIT_MODE_DATA_PORT		DIO_PORTA

	#define		LCD_RS_PIN		DIO_PIN_1
	#define		LCD_RW_PIN		DIO_PIN_2
	#define		LCD_E_PIN		DIO_PIN_3

#elif LCD_Mode == 8

	#define		LCD_8BIT_MODE_CMD_PORT		DIO_PORTA
	#define		LCD_8BIT_MODE_DATA_PORT		DIO_PORTB

	#define		LCD_RS_PIN		DIO_PIN_1
	#define		LCD_RW_PIN		DIO_PIN_2
	#define		LCD_E_PIN		DIO_PIN_3

#endif

#define		LCD_D0		DIO_PIN_0
#define		LCD_D1		DIO_PIN_1
#define		LCD_D2		DIO_PIN_2
#define		LCD_D3		DIO_PIN_3
#define		LCD_D4		DIO_PIN_4
#define		LCD_D5		DIO_PIN_5
#define		LCD_D6		DIO_PIN_6
#define		LCD_D7		DIO_PIN_7

#endif /* LCD_CFG_H_ */