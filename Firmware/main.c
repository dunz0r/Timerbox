/*
 * File Name : main.c
 * Purpose : Blink an LED
 * Creation Date : 01-05-2013
 * Last Modified : mån 15 sep 2014 23:47:50
 * Created By : Gabriel Fornaeus, <gf@hax0r.se>
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "lib/encoders.h"
#include "lib/hd44780.h"

int main (void) {
	// Clear interrupts during setup phase
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

	// initialize and enale interrupts
	initInterrupts();
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


