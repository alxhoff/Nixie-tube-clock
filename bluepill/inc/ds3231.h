/*
 * ds3231_stm32_alex.h
 *
 *  Created on: Aug 6, 2017
 *      Author: alxhoff
 */

#ifndef DS3231_STM32_ALEX_H_
#define DS3231_STM32_ALEX_H_

#include "stm32f1xx_hal.h"

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define DS3231_ADDR8 0xD0

#define PM_AM_FLAG 5
#define TWELVE_FLAG 6
#define DAY_OR_DATE_FLAG 6
#define ALARM_MASK_BITS 7

#define ALARM_INTERRUPT_ENABLE 2
#define ALARM2_CRTL_ENABLE 1
#define ALARM1_CRTL_ENABLE 0

#define ALARM2_STATUS 1
#define ALARM1_STATUS 0

#define RS1 3
#define RS2 4

typedef enum {
	ALARM_EVERY_SECOND = 1,
	ALARM_MATCH_SECONDS = 2,
	ALARM_MATCH_MINUTES = 3,
	ALARM_MATCH_HOURS = 4,
	ALARM_MATCH_DATE_OR_DAY = 5
} ALARM_TYPE_e;

typedef enum {
	ALARM_ONE = 1,
	ALARM_TWO = 2,
	BOTH = 3,
	TIME = 4,
} TIME_TYPE_e;

typedef enum { DAY_OF_MONTH = 0, DAY_OF_WEEK = 1 } DAY_OR_DATE_e;

typedef enum { ONE_K, ONE_POINT_K, FOUR_K, EIGHT_K } WAVE_FREQ_e;

typedef enum {
	EMPTY_MONTH,
	JANUARY = 1,
	FEBUARY = 2,
	MARCH = 3,
	APRIL = 4,
	MAY = 5,
	JUNE = 6,
	JULY = 7,
	AUGUST = 8,
	SEPTERMBER = 9,
	OCTOBER = 10,
	NOVEMBER = 11,
	DECEMBER = 12
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
	AM = 0,
	PM = 1,
	AM_PM_IGNORE,
} AM_OR_PM_e;

typedef enum {
	HOUR_24 = 0,
	HOUR_12 = 1,
	HOUR_IGNORE,
} TIME_FORMAT_e;

typedef struct ds3231_time {
	TIME_FORMAT_e format;
	unsigned char min;
	unsigned char hour;
	AM_OR_PM_e am_or_pm;
	WEEKDAYS_e weekday;
	unsigned char date;
	MONTHS_e month;
	uint16_t year;

	unsigned char sec;
} ds3231_time_t;

typedef struct ds3231_alarm {
	TIME_FORMAT_e format;
	unsigned char min;
	unsigned char hour;
	AM_OR_PM_e am_or_pm;
	WEEKDAYS_e weekday;
	unsigned char date;
	DAY_OR_DATE_e day_or_date;
	ALARM_TYPE_e type;
	unsigned char sec;
} ds3231_alarm_t;

typedef struct ds3231_alarm_short {
	TIME_FORMAT_e format;
	unsigned char min;
	unsigned char hour;
	AM_OR_PM_e am_or_pm;
	WEEKDAYS_e weekday;
	unsigned char date;
	DAY_OR_DATE_e day_or_date;
	ALARM_TYPE_e type;
} ds3231_alarm_short_t;

typedef union ds3231_alarm_u {
	ds3231_alarm_t long_alarm;
	ds3231_alarm_short_t short_alarm;
} ds3231_alarm_ut;

signed char DS3231_set_time_sec(I2C_HandleTypeDef *hi2c, unsigned char sec);
signed char DS3231_set_time_min(I2C_HandleTypeDef *hi2c, unsigned char min);
signed char DS3231_set_time_hour(I2C_HandleTypeDef *hi2c, unsigned char hour,
				 TIME_FORMAT_e format, AM_OR_PM_e am_pm);
signed char DS3231_set_time_day(I2C_HandleTypeDef *hi2c, unsigned char day);
signed char DS3231_set_time_date(I2C_HandleTypeDef *hi2c, unsigned char date);
signed char DS3231_set_time_month(I2C_HandleTypeDef *hi2c, unsigned char month);
signed char DS3231_set_time_year(I2C_HandleTypeDef *hi2c, unsigned short year);

signed char DS3231_set_time(I2C_HandleTypeDef *hi2c, ds3231_time_t *time);
signed char DS3231_get_time(I2C_HandleTypeDef *hi2c,
			    ds3231_time_t *return_struct);
signed char DS3231_set_date(I2C_HandleTypeDef *hi2c, uint16_t year,
			    unsigned char month, unsigned char date,
			    unsigned char weekday);
signed char DS3231_get_date(I2C_HandleTypeDef *hi2c, uint16_t *year,
			    unsigned char *month, unsigned char *date,
			    unsigned char *day);
signed char DS3231_get_temp(I2C_HandleTypeDef *hi2c, float *temp);
signed char DS3231_set_alarm(I2C_HandleTypeDef *hi2c,
			     ds3231_alarm_t *alarm_time,
			     TIME_TYPE_e alarm_number);
signed char DS3231_get_alarm(I2C_HandleTypeDef *hi2c,
			     ds3231_alarm_t *return_struct,
			     TIME_TYPE_e alarm_number);

#endif /* DS3231_STM32_ALEX_H_ */
