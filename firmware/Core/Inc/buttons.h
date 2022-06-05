/*
 * buttons.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alxhoff
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "FreeRTOS.h"
#include "queue.h"

#define BUTTON_MASK_LEFT 0b1
#define BUTTON_MASK_CENTER 0b10
#define BUTTON_MASK_RIGHT 0b100

void buttonsInit();
unsigned char buttonsGet(void);

#endif /* BUTTONS_H_ */
