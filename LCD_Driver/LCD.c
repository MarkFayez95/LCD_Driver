/*
 * LCD.c
 *
 * Created: 26/03/2021 1:13:42 PM
 *  Author: Mark Fayez
 */ 
#include "LCD.h"

void LCD_Init (void)
{
	#if LCD_MODE == 4
	
	DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT, LCD_RS_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT, LCD_RW_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN , DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT, LCD_D4_PIN , DIO_PORT_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT, LCD_D5_PIN , DIO_PORT_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT, LCD_D6_PIN , DIO_PORT_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT, LCD_D7_PIN , DIO_PORT_OUTPUT);
	
	_delay_ms(100);
	
	LCD_WriteCommand(0x33);
	LCD_WriteCommand(0x32);
	LCD_WriteCommand(0x28);
	
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x01);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x02);
	
	#elif LCD_MODE == 8
	
	DIO_SetPinDir(LCD_8BIT_MODE_CMD_PORT, LCD_RS_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_MODE_CMD_PORT, LCD_RW_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_MODE_CMD_PORT, LCD_E_PIN , DIO_PIN_OUTPUT);
	
	DIO_SetPortDir(LCD_8BIT_MODE_DATA_PORT, DIO_PORT_OUTPUT);
	
	_delay_ms(100);
	
	LCD_WriteCommand(0x38);
	
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x01);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x02);
	
	#endif
}

void LCD_WriteCommand (uint8 cmd)
{
	
	#if LCD_MODE == 4
	
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT. LCD_RS_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT. LCD_RW_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_LOW);
	
	LCD_4BIT_MODE_DATA_PORT |= (cmd & 0xF0);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_LOW);
	
	LCD_4BIT_MODE_DATA_PORT |= (cmd << 4);
	
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_LOW);
	
	_delay_ms(5);
	
	#elif LCD_MODE == 8
	
	DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT. LCD_RS_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT. LCD_RW_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_LOW);
	
	LCD_8BIT_MODE_DATA_PORT = cmd;
	DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_LOW);
	
	_delay_ms(5);
	
	#endif
}

void LCD_WriteChar (uint8 data)
{
	#if LCD_MODE == 4
	
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT. LCD_RS_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT. LCD_RW_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_LOW);
	
	LCD_4BIT_MODE_DATA_PORT |= (data & 0xF0);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_LOW);
	
	LCD_4BIT_MODE_DATA_PORT |= (data << 4);
	
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_LOW);
	
	_delay_ms(5);
	
	#elif LCD_MODE == 8
	
	DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT. LCD_RS_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT. LCD_RW_PIN, DIO_PIN_LOW);
	DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_LOW);
	
	LCD_8BIT_MODE_DATA_PORT = data;
	DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT. LCD_E_PIN, DIO_PIN_LOW);
	
	_delay_ms(5);
	
	#endif
	
	LCD_WriteCommand (0x06);
	
}


/*  Assignment  */
void LCD_WriteInteger (sint32 num)
{
	
}
/******************/

void LCD_WriteString(uint8* str)
{
	uint8 Str_count = 0;
	while (str[Str_count] != '\0')
	{
		LCD_WriteChar (str[Str_count]);
		Str_count++;
	}
}

void LCD_GoToLocation(uint8 row, uint8 col)
{
	
}

void LCD_Clear (void)
{
	LCD_WriteCommand(0x01);
}

