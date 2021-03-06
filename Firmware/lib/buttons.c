/*
 * buttons.c
 * Copyright (C) 2014 Gabriel Fornaeus <gf@hax0r.se>
 *
 * Distributed under terms of the GPLv3 license.
 */

#include "buttons.h"

volatile unsigned int buttonValue = 0;
char string[16];

void initInterrupts(void) {
	// Interrupt on low
	PCMSK &= ~(1 << PIND2);
	PCMSK &= ~(1 << PIND1);
	MCUCR &= ~(1 << ISC00);
	MCUCR &= ~(1 << ISC01);
	MCUCR &= ~(1 << ISC10);
	MCUCR &= ~(1 << ISC11);

	GIMSK |= (1 << INT0);
	GIMSK |= (1 << INT1);
}

ISR(INT0_vect) {
	if(buttonValue > 0) {
		_delay_ms(200);
		lcd_clrscr();
		buttonValue--;
		sprintf(string, ":%d", buttonValue);
		lcd_gotoxy(0,0);
		lcd_puts(string);
	}
}
ISR(INT1_vect) {
	_delay_ms(200);
	lcd_clrscr();
	buttonValue++;
	sprintf(string, ":%d", buttonValue);
	lcd_gotoxy(0,0);
	lcd_puts(string);
}
