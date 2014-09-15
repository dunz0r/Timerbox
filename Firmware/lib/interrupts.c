/*
 * File Name : interrupts.c
 * Purpose :
 * Creation Date : 15-09-2014
 * Last Modified : mån 15 sep 2014 23:00:17
 * Created By : Gabriel Fornaeus, <gf@hax0r.se>
 *
 */

#include "interrupts.h"

void initInterrupts(void) {
	// Interrupt on change 
	PCMSK &= ~(1 << PIND2);
	PCMSK &= ~(1 << PIND1);
	MCUCR &= ~(1 << ISC00);
	MCUCR |= (1 << ISC01);
	MCUCR &= ~(1 << ISC10);
	MCUCR |= (1 << ISC11);
	GIMSK |= (1 << INT0);
	//GIMSK |= (1 << INT1);
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
