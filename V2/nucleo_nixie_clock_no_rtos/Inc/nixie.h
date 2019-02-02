/*
 * nixie.h
 *
 *  Created on: Oct 6, 2017
 *      Author: alxhoff
 */

#ifndef NIXIE_H_
#define NIXIE_H_

signed char nixie_init(void);
void nixie_set_tubes(unsigned char* data);
void nixie_set_tube(unsigned char index, unsigned char value);
void nixie_enable_all(void);
void nixie_disable_all(void);

#endif /* NIXIE_H_ */
