/*
 * File Name : main.c
 * Purpose : Blink an LED
 * Creation Date : 01-05-2013
 * Last Modified : mån 15 sep 2014 23:01:57
 * Created By : Gabriel Fornaeus, <gf@hax0r.se>
 *
 */

#include <avr/io.h>
#include <avr/interrupt.h>

// Encoder value, updated via ISR
volatile unsigned int encoderValue;

void initInterrupts(void);
