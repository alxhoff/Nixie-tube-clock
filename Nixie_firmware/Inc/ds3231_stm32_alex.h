/*
 * ds3231_stm32_alex.h
 *
 *  Created on: Aug 6, 2017
 *      Author: alxhoff
 */

#include "externs.h"
#include "stm32f4xx_hal.h"


#ifndef DS3231_STM32_ALEX_H_
#define DS3231_STM32_ALEX_H_

#define DS3231_ADDR8	0xD0

#define STM_I2C_PORT	hi2c2

typedef enum {ALARM_EVERY_SECOND, ALARM_MATCH_SECONDS,
		ALARM_MATCH_MINUTES, ALARM_MATCH_HOURS,
		ALARM_MATCH_DATE_OR_DAY} ALARM_TYPE;

typedef enum {ALARM_ONE, ALARM_TWO, BOTH} ALARM_NUMBER;

typedef enum {DAY_OF_MONTH, DAY_OF_WEEK} DY_DT;

typedef enum {ONE_K, ONE_POINT_K, FOUR_K, EIGHT_K} WAVE_FREQ;

typedef enum {EMPTY_MONTH, JANUARY, FEBUARY, MARCH, APRIL, MAY, JUNE,
	JULY, AUGUST, SEPTERMBER, OCTOBER, NOVEMBER, DECEMBER}
months;

typedef enum{EMPTY_DAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY,
	FRIDAY, SATURDAY, SUNDAY} days;

typedef enum{AM, PM} time_of_day;

typedef struct {
        uint8_t sec;
        uint8_t min;
        uint8_t hour;
		uint8_t week_day;
        uint8_t date;
        uint8_t month;
        uint16_t year;
        uint8_t	alarm1_sec;
        uint8_t alarm1_min;
        uint8_t alarm1_hour;
        uint8_t alarm1_date;
        uint8_t alarm2_min;
        uint8_t alarm2_hour;
        uint8_t alarm2_date;
        uint8_t control;
        uint8_t status;
        uint8_t offset;
        uint8_t MSB_temp;
        uint8_t LSB_temp;
    } ds3231Registers;

typedef struct {
	uint8_t twelve_hour;
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	time_of_day pm;
	uint8_t week_day;
	uint8_t date;
	uint8_t month;
	uint16_t year;
} ds3231Time;

typedef struct {
	uint8_t twelve_hour;
	uint8_t	sec;
	uint8_t min;
	uint8_t hour;
	time_of_day pm;
	uint8_t week_day;
	uint8_t date;
	DY_DT date_or_day;
	ALARM_TYPE alarm_type;
} ds3231Alarm;

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

uint8_t dec2bcd(uint8_t d);
uint8_t bcd2dec(uint8_t b);
void DS3231_set_time_short(I2C_HandleTypeDef *hi2c, uint8_t twelve_hour, uint8_t hour, uint8_t min, uint8_t sec);
void DS3231_get_time_short(I2C_HandleTypeDef *hi2c, uint8_t* pm, uint8_t* twelve_hour, uint8_t* hour, uint8_t*min, uint8_t* sec);
void DS3231_set_date_short(I2C_HandleTypeDef *hi2c, uint16_t year, uint8_t month, uint8_t date, uint8_t day);
void DS3231_get_date_short(I2C_HandleTypeDef *hi2c, uint16_t* year, uint8_t* month, uint8_t* date, uint8_t* day);
void DS3231_set_time(I2C_HandleTypeDef *hi2c, ds3231Time* time);
void DS3231_get_time(I2C_HandleTypeDef *hi2c, ds3231Time* return_struct);
float DS3231_get_temp(I2C_HandleTypeDef *hi2c);
void DS3231_register_dump(I2C_HandleTypeDef *hi2c, ds3231Registers* return_struct);

#endif /* DS3231_STM32_ALEX_H_ */
