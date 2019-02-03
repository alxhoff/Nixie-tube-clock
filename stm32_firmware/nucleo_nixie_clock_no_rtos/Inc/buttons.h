/*
 * buttons.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alxhoff
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

typedef enum {
	BACK1,
	CENTER1,
	RIGHT1,
	MAX_VALUE
} BUTTON_POSITIONS_t;

typedef enum{
	NOT_SETTING,
	SETTING_DIGIT,
	SETTING_MOVE,
} SET_STATE_t;

void ButtonsInit();
void buttons_listener_callback(void);

#endif /* BUTTONS_H_ */
