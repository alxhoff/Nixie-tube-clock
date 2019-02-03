/*
 * draw.h
 *
 *  Created on: Aug 8, 2017
 *      Author: alxhoff
 */

#ifndef DRAW_H_
#define DRAW_H_

#include "render.h"

typedef enum {
	BLINK_HOUR,
	BLINK_MINUTE,
	BLINK_SEC,
	BLINK_PM
} BLINK_TIME_t;



//STATES
//TIME
unsigned char draw_time_init(void);

void draw_time_enter(void);

void draw_time_run(void);

void draw_time_exit(void);

//SET TIME
unsigned char draw_set_time_init(void);

void draw_set_time_enter(void);

void draw_set_time_run(void);

void draw_set_time_exit(void);

//SET ALARM 1
unsigned char draw_alarm1_init(void);

void draw_alarm1_enter(void);

void draw_alarm1_run(void);

void draw_alarm1_exit(void);

//SET ALARM 2
unsigned char draw_alarm2_init(void);

void draw_alarm2_enter(void);

void draw_alarm2_run(void);

void draw_alarm2_exit(void);

#endif /* DRAW_H_ */
