/*
 * draw.h
 *
 *  Created on: Aug 8, 2017
 *      Author: alxhoff
 */

#ifndef DRAW_H_
#define DRAW_H_

extern unsigned char blink_flag;

void draw_get_and_draw_time(signed char m_hour, signed char m_min, signed char m_sec,
		signed char m_weekday, signed char m_date, signed char m_month, signed short m_year);

//SET ALARM 1
void draw_alarm1_run(void);
void draw_alarm1_min_run(void);
void draw_alarm1_hour_run(void);
void draw_alarm1_day_run(void);

#endif /* DRAW_H_ */
