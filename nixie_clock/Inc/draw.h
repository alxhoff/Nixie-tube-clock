/*
 * draw.h
 *
 *  Created on: Aug 8, 2017
 *      Author: alxhoff
 */

#ifndef DRAW_H_
#define DRAW_H_

#include "render.h"

typedef enum {BLINK_HOUR, BLINK_MINUTE, BLINK_SEC, BLINK_PM} BLINK_TIME_t;

void draw_disp_time_state(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, ds3231_time_t* time);
void draw_disp_alarm1_state(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, ds3231_alarm_t* alarm);
void draw_set_states(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, void* timeStruct);
void draw_alarm_blink(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, ds3231_alarm_t* alarm, BLINK_TIME_t blink);
void draw_alarm(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, ds3231_alarm_t* alarm);
void draw_time_blink(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, ds3231_time_t* time, BLINK_TIME_t blink);
void draw_time(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, ds3231_time_t* time);
void draw_am_pm(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, TIME_OF_DAY_12HR_t pm);
void draw_date(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, uint8_t date);
void draw_year(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, uint16_t year);
void draw_month(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, months month);
void draw_day(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, DAYS_t day);

//const char* get_time_string(ds3231Time* time)

#endif /* DRAW_H_ */
