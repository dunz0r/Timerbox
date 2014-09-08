/*
 * File Name : main.c
 * Purpose : Blink an LED
 * Creation Date : 01-05-2013
 * Last Modified : sön  7 sep 2014 20:47:09
 * Created By : Gabriel Fornaeus, <gf@hax0r.se>
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "hd44780.h"

// Encoder value, updated via ISR
unsigned int encoderValue = 0;

int main (void) {
	cli();
	lcd_init();
	lcd_clrscr();
	lcd_gotoxy(0,1);
	lcd_puts("http://hax0r.se");
	// Set up as output
	DDRD |= (1 << PD5) | (1 << PD6);

	// Set up inputs
	DDRD &= ~(1 << PD2);
	DDRD &= ~(1 << PD3);
	// Enable pullups
	PORTD |= (1 << PD2);
	PORTD |= (1 << PD3);

	// Interrupt on change 
	PCMSK &= ~(1 << PIND2);
	PCMSK &= ~(1 << PIND1);
	MCUCR &= ~(1 << ISC00);
	MCUCR |= (1 << ISC01);
	MCUCR &= ~(1 << ISC10);
	MCUCR |= (1 << ISC11);
	GIMSK |= (1 << INT0);
	//GIMSK |= (1 << INT1);
	sei();
	char string[16];
	// Go to zero position
	lcd_gotoxy(0,0);
	_delay_ms(100);
	for(;;) {
		sprintf(string, ":%d", encoderValue);
		//PORTD ^= (1 << PD5);
		lcd_clrscr();
		lcd_gotoxy(0,0);
		lcd_puts(string);
		_delay_ms(200);
	}
}

ISR(INT0_vect) {
	if(PIND & (1 <<PD3)){
		encoderValue--;
		PORTD |= (1 << PD5);
	} else
	{
		encoderValue++;
		PORTD &= ~(1 << PD5);
	}}
/*
ISR(INT1_vect) {
	if(PIND & (1 <<PD3)){
		encoderValue--;
		PORTD |= (1 << PD5);
	} else
	{
		encoderValue++;
		PORTD &= ~(1 << PD5);
	}
}
*/
