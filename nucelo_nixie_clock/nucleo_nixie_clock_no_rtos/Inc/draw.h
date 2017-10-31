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


void draw_disp_time_state(uint8_t x, uint8_t y);
void draw_disp_alarm1_state(uint8_t x, uint8_t y);
void draw_disp_alarm2_state(uint8_t x, uint8_t y);
void draw_set_states( uint8_t x, uint8_t y);
void draw_alarm_blink(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, ds3231_alarm_t* alarm, BLINK_TIME_t blink);
void draw_alarm( uint8_t x, uint8_t y, TYPE_TIME_t alarm);
void draw_time_blink( uint8_t x, uint8_t y,TYPE_TIME_t type ,
		BLINK_TIME_t blink);
void draw_time(uint8_t x, uint8_t y);
void draw_am_pm( uint8_t x, uint8_t y, TIME_OF_DAY_12HR_t pm);
void draw_date( uint8_t x, uint8_t y, uint8_t date);
void draw_year( uint8_t x, uint8_t y, uint16_t year);
void draw_month( uint8_t x, uint8_t y, months month);
void draw_day( uint8_t x, uint8_t y, DAYS_t day);

#endif /* DRAW_H_ */
