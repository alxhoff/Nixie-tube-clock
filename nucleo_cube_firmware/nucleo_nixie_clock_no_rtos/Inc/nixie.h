/*
 * nixie.h
 *
 *  Created on: Oct 6, 2017
 *      Author: alxhoff
 */

#ifndef NIXIE_H_
#define NIXIE_H_

//supports up to 8 devices, ie. 32 bit output

void nixie_enable_all(void);
void nixie_disable_all(void);
void nixie_enable_tube(unsigned char index);
void nixie_disable_tube(unsigned char index);
void nixie_set_tube(unsigned char index, unsigned char value);
unsigned char nixie_split_set_digit(volatile unsigned char input,
				    unsigned char index);
uint32_t nixie_compile_output(void);

#endif /* NIXIE_H_ */
