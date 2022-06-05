/*
 * nixie.h
 *
 *  Created on: Oct 6, 2017
 *      Author: alxhoff
 */

#ifndef NIXIE_H_
#define NIXIE_H_

//supports up to 8 devices, ie. 32 bit output

void nixieEnableAll(void);
void nixieDisableAll(void);
void nixieEnableTube(unsigned char index);
void nixieDisableTube(unsigned char index);
void nixieSetTube(unsigned char index, unsigned char value);
unsigned char nixieSetDoubleDigits(volatile unsigned char input,
		unsigned char index);
uint32_t nixieCompileOutput(void);

#endif /* NIXIE_H_ */
