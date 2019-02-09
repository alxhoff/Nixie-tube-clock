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
void draw_time_run(void);

//SET TIME
void draw_set_time_run(void);
void draw_set_time_sec_run(void);
void draw_set_time_min_run(void);
void draw_set_time_hour_run(void);
void draw_set_time_date_run(void);
void draw_set_time_month_run(void);
void draw_set_time_year_run(void);
void draw_set_time_day_run(void);
//SET ALARM 1
void draw_alarm1_run(void);
void draw_alarm1_min_run(void);
void draw_alarm1_hour_run(void);
void draw_alarm1_day_run(void);

#endif /* DRAW_H_ */
