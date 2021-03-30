/*
 * LED.h
 *
 * Created: 19/03/2021 11:59:31 AM
 *  Author: Mark Fayez
 */ 


#ifndef LED_H_
#define LED_H_

#define LED0 0
#define LED1 1
#define LED2 2

#include "DIO.h"

#define LED0_PORT DIO_PORTC
#define LED0_PIN DIO_PIN_2

#define LED1_PORT DIO_PORTC
#define LED1_PIN DIO_PIN_7

#define LED2_PORT DIO_PORTD
#define LED2_PIN DIO_PIN_3

void LED_Init(uint8 LED);
void LED_ON(uint8 LED);
void LED_OFF(uint8 LED);
void LED_Toggle(uint8 LED);

#endif /* LED_H_ */