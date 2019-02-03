/*
 * screen.h
 *
 *  Created on: Sep 16, 2017
 *      Author: alxhoff
 */

#ifndef SCREEN_H_
#define SCREEN_H_

unsigned char screen_init(void);
void screen_add_line(char *line);
signed char screen_add_line_at_index(unsigned char i, char *line);
void screen_refresh(void const *args);
void screen_clear(void);

#endif /* SCREEN_H_ */
