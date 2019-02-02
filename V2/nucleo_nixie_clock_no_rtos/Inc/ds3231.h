/*
 * ds3231_stm32_alex.h
 *
 *  Created on: Aug 6, 2017
 *      Author: alxhoff
 */

#ifndef DS3231_STM32_ALEX_H_
#define DS3231_STM32_ALEX_H_

#include "externs.h"
#include "stm32f1xx_hal.h"

#ifndef TRUE
#define TRUE	1
#endif

#ifndef	 FALSE
#define FALSE	0
#endif

#define DS3231_ADDR8	0xD0

#define PM_AM_FLAG		5
#define TWELVE_FLAG		6
#define DY_DT_FLAG		6
#define ALARM_MASK_BITS	7

#define ALARM_INTERRUPT_ENABLE		2
#define ALARM2_CRTL_ENABLE			1
#define ALARM1_CRTL_ENABLE			0

#define ALARM2_STATUS				1
#define ALARM1_STATUS				0

#define RS1							3
#define RS2							4

#ifndef uint8_t
#define uint8_t uint8_t
#endif

#ifndef uint16_t
#define uint16_t uint16_t
#endif

typedef enum {
	ALARM_EVERY_SECOND,
	ALARM_MATCH_SECONDS,
	ALARM_MATCH_MINUTES,
	ALARM_MATCH_HOURS,
	ALARM_MATCH_DATE_OR_DAY
} ALARM_TYPE_t;

typedef enum {
	ALARM_ONE, ALARM_TWO, BOTH, TIME,
} TYPE_TIME_t;

typedef enum {
	DAY_OF_MONTH, DAY_OF_WEEK
} DY_DT_t;

typedef enum {
	ONE_K, ONE_POINT_K, FOUR_K, EIGHT_K
} WAVE_FREQ_t;

typedef enum {
	EMPTY_MONTH,
	JANUARY,
	FEBUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTERMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
} MONTHS_e;

typedef enum {
	EMPTY_DAY = 0,
	SUNDAY = 1,
	MONDAY = 2,
	TUESDAY = 3,
	WEDNESDAY = 4,
	THURSDAY = 5,
	FRIDAY = 6,
	SATURDAY = 7,
} WEEKDAYS_e;

typedef enum {
	AM = 0, PM = 1,
} AM_OR_PM_e;

typedef enum {
	HOUR_24 = 0, HOUR_12 = 1,
} HOUR_12_OR_24_e;

typedef struct ds3231_time {
	HOUR_12_OR_24_e twelve_hour;
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	AM_OR_PM_e am_or_pm;
	WEEKDAYS_e weekday;
	uint8_t date;
	MONTHS_e month;
	uint16_t year;
} ds3231_time_t;

typedef struct ds3231_alarm {
	HOUR_12_OR_24_e twelve_hour;
	uint8_t min;
	uint8_t hour;
	AM_OR_PM_e pm;
	WEEKDAYS_e week_day;
	uint8_t date;
	DY_DT_t date_or_day;
	ALARM_TYPE_t alarm_type;
	uint8_t sec;
} ds3231_alarm_t;

typedef struct ds3231_alarm_short {
	HOUR_12_OR_24_e twelve_hour;
	uint8_t min;
	uint8_t hour;
	AM_OR_PM_e pm;
	WEEKDAYS_e week_day;
	uint8_t date;
	DY_DT_t date_or_day;
	ALARM_TYPE_t alarm_type;
} ds3231_alarm_short_t;

typedef union ds3231_alarm_u {
	ds3231_alarm_t long_alarm;
	ds3231_alarm_short_t short_alarm;
} ds3231_alarm_ut;

signed char DS3231_write_time(I2C_HandleTypeDef *hi2c, ds3231_time_t* time);
signed char DS3231_read_time(I2C_HandleTypeDef *hi2c,
		ds3231_time_t* return_struct);
signed char DS3231_write_date(I2C_HandleTypeDef *hi2c, uint16_t year,
uint8_t month, uint8_t date, uint8_t weekday);
signed char DS3231_read_date(I2C_HandleTypeDef *hi2c, uint16_t* year,
uint8_t* month, uint8_t* date, uint8_t* day);
signed char DS3231_read_temp(I2C_HandleTypeDef *hi2c, float *temp);
signed char DS3231_set_alarm(I2C_HandleTypeDef *hi2c,
		ds3231_alarm_t* alarm_time, TYPE_TIME_t alarm_number);
signed char DS3231_get_alarm(I2C_HandleTypeDef *hi2c,
		ds3231_alarm_t* return_struct, TYPE_TIME_t alarm_number);

#endif /* DS3231_STM32_ALEX_H_ */
