/*
 * buttons.h
 * Copyright (C) 2014 Gabriel Fornaeus <gf@hax0r.se>
 *
 * Distributed under terms of the GPLv3 license.
 */

#ifndef BUTTONS_H
#define BUTTONS_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "hd44780.h"

volatile unsigned int buttonValue;
char string[16];

void initInterrupts(void);

#endif /* !BUTTONS_H */
