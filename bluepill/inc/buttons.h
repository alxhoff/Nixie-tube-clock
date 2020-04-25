/*
 * buttons.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alxhoff
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

typedef enum button_masks {
	no_press = 0,
	left = 0b1,
	center = 0b10,
	right = 0b100
} button_mask_e;

void ButtonsInit();

#endif /* BUTTONS_H_ */
