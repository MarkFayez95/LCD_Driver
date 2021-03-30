/*
 * LCD_Driver.c
 *
 * Created: 26/03/2021 1:09:38 PM
 * Author : Mark Fayez
 */ 


#define F_CPU 16000000UL

#include "LED.h"
#include "Button.h"
#include "LCD.h"
#include <Util/delay.h>


int main(void)
{
	sint32 Clicks_Counter = 0;
	uint8 Clicks_increment = 0;
	
	LED_Init(LED0);
	LED_Init(LED1);
	LED_Init(LED2);
	
	Button_Init(BUTTON0);
	Button_Init(BUTTON1);
	Button_Init(BUTTON2);
	
	LCD_Init();
	LCD_GoToLocation(0,3);
	LCD_WriteString("WELCOME!");
	
	LED_Toggle(LED0);
	LED_Toggle(LED1);
	LED_Toggle(LED2);
	_delay_ms(250);
	LED_Toggle(LED0);
	LED_Toggle(LED1);
	LED_Toggle(LED2);
	_delay_ms(300);
	LED_Toggle(LED0);
	LED_Toggle(LED1);
	LED_Toggle(LED2);
	_delay_ms(250);
	LED_Toggle(LED0);
	LED_Toggle(LED1);
	LED_Toggle(LED2);
	_delay_ms(300);
	LED_Toggle(LED0);
	LED_Toggle(LED1);
	LED_Toggle(LED2);
	_delay_ms(250);
	LED_Toggle(LED0);
	LED_Toggle(LED1);
	LED_Toggle(LED2);
	
	LCD_Clear();
	LCD_WriteString("Press any Button!");
	
	LED_Toggle(LED0);
	_delay_ms(250);
	LED_Toggle(LED1);
	_delay_ms(250);
	LED_Toggle(LED2);
	_delay_ms(300);
	LED_Toggle(LED0);
	_delay_ms(250);
	LED_Toggle(LED1);
	_delay_ms(250);
	LED_Toggle(LED2);
	
	
	LCD_Clear();
	
	while (1)
	{
		if(Button_GetValue(BUTTON0) == 1)
		{
			LED_Toggle(LED0);
			LCD_Clear();
			LCD_WriteString("Button 0, Clicks +1");
			_delay_ms(500);
			LED_Toggle(LED0);
			LCD_Clear();
			Clicks_Counter += 1;
			Clicks_increment = 1;
		}
		else if(Button_GetValue(BUTTON1) == 1)
		{
			LED_Toggle(LED1);
			LCD_Clear();
			LCD_WriteString("Button 1, Clicks +2");
			_delay_ms(500);
			LED_Toggle(LED1);
			LCD_Clear();
			Clicks_Counter += 2;
			Clicks_increment = 1;
		}
		else if(Button_GetValue(BUTTON2) == 1)
		{
			LED_Toggle(LED2);
			LCD_Clear();
			LCD_WriteString("Button 2, Clicks +3");
			_delay_ms(500);
			LED_Toggle(LED2);
			LCD_Clear();
			Clicks_Counter += 3;
			Clicks_increment = 1;
		}
		else if(Clicks_increment > 0)
		{
			LCD_Clear();
			LCD_WriteString("Clicks= ");
			LCD_WriteInteger(Clicks_Counter);
			Clicks_increment = 0;
		}
		
	}
}

