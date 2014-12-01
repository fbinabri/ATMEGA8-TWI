/*
* TWI_ATMEGA8.c
*
* Created: 26-Oct-14 2:41:00 PM
*  Author: Shekhar
*/

#define F_CPU	1000000UL  //Clock running at 1 MHz

#include <avr/io.h>
#include <util/delay.h>
#include "i2c.h"
#include "rtc.h"

#define LED_SET		PORTB |= (1 << PINB0)
#define LED_CLR		PORTB &= ~(1 << PINB0)

int main(void)
{
	char data;
	DDRB |= 1 << PINB0;
	LED_CLR;
	
	rtc_write(0x03,0x01);	// Day 
	
	rtc_write(0x04,0x26);	// Date
	rtc_write(0x05,0x10);	// Month
	rtc_write(0x06,0x14);	// Year
	
	rtc_write(0x00,0x00);
	rtc_write(0x01,0x59);
	rtc_write(0x02,0x71);	
	
	while(1)
	{
		
		//TODO:: Please write your application code
	}
}