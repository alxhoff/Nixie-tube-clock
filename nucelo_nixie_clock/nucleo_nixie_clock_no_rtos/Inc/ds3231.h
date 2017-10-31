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

#define STM_I2C_PORT	hi2c2

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

typedef enum {ALARM_EVERY_SECOND, ALARM_MATCH_SECONDS,
		ALARM_MATCH_MINUTES, ALARM_MATCH_HOURS,
		ALARM_MATCH_DATE_OR_DAY} ALARM_TYPE_t;

typedef enum {
	ALARM_ONE,
	ALARM_TWO,
	BOTH,
	TIME
} TYPE_TIME_t;

typedef enum {DAY_OF_MONTH, DAY_OF_WEEK} DY_DT_t;

typedef enum {ONE_K, ONE_POINT_K, FOUR_K, EIGHT_K} WAVE_FREQ_t;

typedef enum {EMPTY_MONTH, JANUARY, FEBUARY, MARCH, APRIL, MAY, JUNE,
	JULY, AUGUST, SEPTERMBER, OCTOBER, NOVEMBER, DECEMBER}
months;

typedef enum{EMPTY_DAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY,
	FRIDAY, SATURDAY, SUNDAY} DAYS_t;

typedef enum{AM, PM} TIME_OF_DAY_12HR_t;

typedef enum{
	DS3231_OK 			= 0,
	DS3231_MEM 			= 1,
	DS3231_I2C			= 2,
	DS3231_MISSING_ARG	= 3
} DS3231_ERR_t;

typedef struct ds3231_registers{
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
    } ds3231_registers_t;

//TODO handle dirty flags

typedef struct ds3231_time{
	uint8_t twelve_hour;
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	TIME_OF_DAY_12HR_t pm;
	uint8_t week_day;
	uint8_t date;
	uint8_t month;
	uint16_t year;

	uint8_t dirty;
} ds3231_time_t;

typedef struct ds3231_alarm{
	uint8_t twelve_hour;
	uint8_t	sec;
	uint8_t min;
	uint8_t hour;
	TIME_OF_DAY_12HR_t pm;
	uint8_t week_day;
	uint8_t date;
	DY_DT_t date_or_day;
	ALARM_TYPE_t alarm_type;

	uint8_t dirty;
} ds3231_alarm_t;

typedef struct ds3231_alarm_short{
	uint8_t twelve_hour;
	uint8_t min;
	uint8_t hour;
	TIME_OF_DAY_12HR_t pm;
	uint8_t week_day;
	uint8_t date;
	DY_DT_t date_or_day;
	ALARM_TYPE_t alarm_type;

	uint8_t dirty;
} ds3231_alarm_short_t;

union ds3231_alarm_unknown{
	ds3231_alarm_t long_alarm;
	ds3231_alarm_short_t short_alarm;
};

typedef struct ds3231_device_init{
	ds3231_time_t initial_time;

	I2C_HandleTypeDef* i2c_handle;

} ds3231_device_init_t;

typedef struct ds3231_device DS3231_device_t;

struct ds3231_device{
	ds3231_time_t* time_1;
	ds3231_alarm_t* alarm_1;
	ds3231_alarm_short_t* alarm_2;

	I2C_HandleTypeDef* i2c_handle;

	float temp;

	ds3231_registers_t* registers;

	DS3231_ERR_t (*get_time)(DS3231_device_t*);
	DS3231_ERR_t (*set_time)(DS3231_device_t*);
	DS3231_ERR_t (*get_date)(DS3231_device_t*);
	DS3231_ERR_t (*set_date)(DS3231_device_t*);
	DS3231_ERR_t (*get_alarm)(DS3231_device_t*, TYPE_TIME_t);
	DS3231_ERR_t (*set_alarm)(DS3231_device_t*, TYPE_TIME_t);
	DS3231_ERR_t (*get_temp)(DS3231_device_t*);
	DS3231_ERR_t (*dump_register)(DS3231_device_t*);
};

//self
DS3231_device_t* DS3231_init(ds3231_device_init_t* init_struct);
DS3231_ERR_t self_DS3231_set_time(DS3231_device_t* self);
DS3231_ERR_t self_DS3231_get_time(DS3231_device_t* self);
DS3231_ERR_t self_DS3231_set_date(DS3231_device_t* self);
DS3231_ERR_t self_DS3231_get_date(DS3231_device_t* self);
DS3231_ERR_t self_DS3231_set_alarm(DS3231_device_t* self,
			TYPE_TIME_t alarm_number);
DS3231_ERR_t self_DS3231_get_alarm(DS3231_device_t* self,
		TYPE_TIME_t alarm_number);
DS3231_ERR_t self_DS3231_get_temp(DS3231_device_t* self);
DS3231_ERR_t self_DS3231_register_dump(DS3231_device_t* self);

uint8_t dec2bcd(uint8_t d);
uint8_t bcd2dec(uint8_t b);
void DS3231_set_time_short(I2C_HandleTypeDef *hi2c, uint8_t twelve_hour,
		uint8_t hour, uint8_t min, uint8_t sec);
void DS3231_get_time_short(I2C_HandleTypeDef *hi2c, uint8_t* pm,
		uint8_t* twelve_hour, uint8_t* hour, uint8_t*min, uint8_t* sec);
void DS3231_set_date_short(I2C_HandleTypeDef *hi2c, uint16_t year,
		uint8_t month, uint8_t date, uint8_t day);
void DS3231_get_date_short(I2C_HandleTypeDef *hi2c, uint16_t* year,
		uint8_t* month, uint8_t* date, uint8_t* day);
void DS3231_set_time(I2C_HandleTypeDef *hi2c, ds3231_time_t* time);
void DS3231_get_time(I2C_HandleTypeDef *hi2c, ds3231_time_t* return_struct);
float DS3231_get_temp(I2C_HandleTypeDef *hi2c);
void DS3231_set_alarm(I2C_HandleTypeDef *hi2c, ds3231_alarm_t* alarm_time,
			TYPE_TIME_t alarm_number);
void DS3231_register_dump(I2C_HandleTypeDef *hi2c, ds3231_registers_t* return_struct);

#endif /* DS3231_STM32_ALEX_H_ */
