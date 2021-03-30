/*
 * MCU.h
 *
 * Created: 18/03/2021 10:05:01 PM
 *  Author: Mark Fayez
 */ 


#ifndef MCU_H_
#define MCU_H_

#include "STD_DTypes.h"

#define PINA (*(volatile uint8*)0x39)
#define DDRA (*(volatile uint8*)0x3A)
#define PORTA (*(volatile uint8*)0x3B)

#define PINB (*(volatile uint8*)0x36)
#define DDRB (*(volatile uint8*)0x37)
#define PORTB (*(volatile uint8*)0x38)

#define PINC (*(volatile uint8*)0x33)
#define DDRC (*(volatile uint8*)0x34)
#define PORTC (*(volatile uint8*)0x35)

#define PIND (*(volatile uint8*)0x30)
#define DDRD (*(volatile uint8*)0x31)
#define PORTD (*(volatile uint8*)0x32)

#endif /* MCU_H_ */