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

volatile unsigned int buttonValue;

void initInterrupts(void);

#endif /* !BUTTONS_H */
