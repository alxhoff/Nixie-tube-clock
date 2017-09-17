/*
 * render.h
 *
 *  Created on: Aug 6, 2017
 *      Author: alxhoff
 */

#ifndef RENDER_H_
#define RENDER_H_

#include "ssd1306.h"
#include "ds3231_stm32_alex.h"

typedef enum {DISP_TIME, SET_TIME, DISP_ALARM1, DISP_ALARM2,
	SET_ALARM1, SET_ALARM2} SCREEN_RENDER_STATE;

typedef enum {SET_HOUR, SET_MIN, SET_SEC, SET_DAY, SET_DATE,
	SET_MONTH, SET_YEAR, SET_PM, SET_TWELVE_HOUR, SET_DATE_OR_DAY, SET_ALARM_TYPE} SET_STATE;

extern ds3231Time testStruct;
extern SCREEN_RENDER_STATE render_state;
extern SET_STATE set_state;

void ScreenRenderTask();

#endif /* RENDER_H_ */
