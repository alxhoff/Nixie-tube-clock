/*
 * states.h
 *
 *  Created on: Jun 2, 2022
 *      Author: alxhoff
 */

#ifndef INC_STATES_H_
#define INC_STATES_H_

// States
#define STATE_INIT				0 //Default
#define STATE_HOURS_BLINKING	1
#define STATE_MINUTES_BLINKING	2
#define STATE_SHOWING_TIME		3

unsigned int statesInit(void);

#endif /* INC_STATES_H_ */
