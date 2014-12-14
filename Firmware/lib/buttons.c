/*
 * buttons.c
 * Copyright (C) 2014 Gabriel Fornaeus <gf@hax0r.se>
 *
 * Distributed under terms of the GPLv3 license.
 */

#include "buttons.h"

volatile unsigned int buttonValue = 0;

void initInterrupts(void) {
	// Turn on pullups
	PCMSK |= (1 << PIND2);
	PCMSK |= (1 << PIND1);
	// Interrupt on low
	MCUCR &= ~(1 << ISC00);
	MCUCR &= ~(1 << ISC01);
	MCUCR &= ~(1 << ISC10);
	MCUCR &= ~(1 << ISC11);

	GIMSK |= (1 << INT0);
	GIMSK |= (1 << INT1);
}

ISR(INT0_vect) {
	if(buttonValue > 0)
		buttonValue--;
}
ISR(INT1_vect) {
	buttonValue++;
}
