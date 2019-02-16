/*
 * RTC_dev.c
 *
 *  Created on: 2 Feb 2019
 *      Author: alxhoff
 */

#include <stdlib.h>

#include "RTC_dev.h"
#include "stm32f1xx_hal.h"
#include "config.h"

typedef struct DS3231_device DS3231_device_t;

struct DS3231_device {
	ds3231_time_t time_1;
	ds3231_alarm_t alarm_1;
	ds3231_alarm_short_t alarm_2;

	I2C_HandleTypeDef* i2c_handle;

	float temp;

	signed char (*get_time)(DS3231_device_t*);
	signed char (*set_time)(DS3231_device_t*, unsigned char, unsigned char,
			unsigned char, TIME_FORMAT_e, AM_OR_PM_e);
	signed char (*get_date)(DS3231_device_t*);
	signed char (*set_date)(DS3231_device_t*, WEEKDAYS_e, unsigned char,
			MONTHS_e, unsigned short);
	signed char (*get_alarm)(DS3231_device_t*, TIME_TYPE_e);
	signed char (*set_alarm)(DS3231_device_t*, TIME_TYPE_e, unsigned char,
			unsigned char, TIME_FORMAT_e, AM_OR_PM_e, WEEKDAYS_e, unsigned char,
			DAY_OR_DATE_e, ALARM_TYPE_e);
	signed char (*get_temp)(DS3231_device_t*);
	signed char (*dump_register)(DS3231_device_t*);
};

DS3231_device_t RTC_dev = { 0 };

//GETS
TIME_FORMAT_e RTC_dev_time_get_format(void) {
	return RTC_dev.time_1.format;
}

unsigned char RTC_dev_time_get_hour(void) {
	return RTC_dev.time_1.hour;
}

unsigned char RTC_dev_time_get_min(void) {
	return RTC_dev.time_1.min;
}

unsigned char RTC_dev_time_get_sec(void) {
	return RTC_dev.time_1.sec;
}

AM_OR_PM_e RTC_dev_time_get_AM_or_PM(void) {
	return RTC_dev.time_1.am_or_pm;
}

WEEKDAYS_e RTC_dev_time_get_weekday(void) {
	return RTC_dev.time_1.weekday;
}

unsigned char RTC_dev_time_get_date(void) {
	return RTC_dev.time_1.date;
}

MONTHS_e RTC_dev_time_get_month(void) {
	return RTC_dev.time_1.month;
}

unsigned short RTC_dev_time_get_year(void) {
	return RTC_dev.time_1.year;
}

TIME_FORMAT_e RTC_dev_alarm1_get_format(void) {
	return RTC_dev.alarm_1.format;
}

unsigned char RTC_dev_alarm1_get_min(void) {
	return RTC_dev.alarm_1.min;
}

unsigned char RTC_dev_alarm1_get_hour(void) {
	return RTC_dev.alarm_1.hour;
}

AM_OR_PM_e RTC_dev_alarm1_get_am_pm(void) {
	return RTC_dev.alarm_1.am_or_pm;
}

WEEKDAYS_e RTC_dev_alarm1_get_weekday(void) {
	return RTC_dev.alarm_1.weekday;
}

unsigned char RTC_dev_alarm1_get_date(void) {
	return RTC_dev.alarm_1.date;
}

DAY_OR_DATE_e RTC_dev_alarm1_get_day_or_date(void) {
	return RTC_dev.alarm_1.day_or_date;
}

ALARM_TYPE_e RTC_dev_alarm1_get_type(void) {
	return RTC_dev.alarm_1.type;
}

unsigned char RTC_dev_alarm1_get_sec(void) {
	return RTC_dev.alarm_1.sec;
}

TIME_FORMAT_e RTC_dev_alarm2_get_format(void) {
	return RTC_dev.alarm_2.format;
}

unsigned char RTC_dev_alarm2_get_min(void) {
	return RTC_dev.alarm_2.min;
}

unsigned char RTC_dev_alarm2_get_hour(void) {
	return RTC_dev.alarm_2.hour;
}

AM_OR_PM_e RTC_dev_alarm2_get_am_pm(void) {
	return RTC_dev.alarm_2.am_or_pm;
}

WEEKDAYS_e RTC_dev_alarm2_get_weekday(void) {
	return RTC_dev.alarm_2.weekday;
}

unsigned char RTC_dev_alarm2_get_date(void) {
	return RTC_dev.alarm_2.date;
}

DAY_OR_DATE_e RTC_dev_alarm2_get_day_or_date(void) {
	return RTC_dev.alarm_2.day_or_date;
}

ALARM_TYPE_e RTC_dev_alarm2_get_type(void) {
	return RTC_dev.alarm_2.type;
}

void RTC_dev_set_time_sec_zero(void) {
	RTC_dev.time_1.sec = 0;
}

signed char RTC_dev_set_time_sec(unsigned char sec) {
	return DS3231_set_time_sec(RTC_dev.i2c_handle, sec);
}

void RTC_dev_set_time_min_increment(void) {
	if (RTC_dev.time_1.min == 59)
		RTC_dev.time_1.min = 0;
	else
		RTC_dev.time_1.min++;
}

signed char RTC_dev_set_time_min(unsigned char min) {
	return DS3231_set_time_min(RTC_dev.i2c_handle, min);
}

void RTC_dev_set_time_hour_increment(void) {
	if (RTC_dev.time_1.format == HOUR_24)
		if (RTC_dev.time_1.hour == 23)
			RTC_dev.time_1.hour = 0;
		else
			RTC_dev.time_1.hour++;
	else if (RTC_dev.time_1.hour == 12)
		RTC_dev.time_1.hour = 1;
	else
		RTC_dev.time_1.hour++;
}

signed char RTC_dev_set_time_hour(unsigned char hour, TIME_FORMAT_e format,
		AM_OR_PM_e am_pm) {
	return DS3231_set_time_hour(RTC_dev.i2c_handle, hour, format, am_pm);
}

void RTC_dev_set_time_day_increment(void) {
	if (RTC_dev.time_1.weekday == SATURDAY)
		RTC_dev.time_1.weekday = SUNDAY;
	else
		RTC_dev.time_1.weekday++;
}

signed char RTC_dev_set_time_day(unsigned char day) {
	return DS3231_set_time_day(RTC_dev.i2c_handle, day);
}

#define CHECK_MONTH_INCREMENT(DAYS)	\
				if(RTC_dev.time_1.date == DAYS)	\
					RTC_dev.time_1.date = 1;	\
				else	\
					RTC_dev.time_1.date++;

void RTC_dev_set_time_date_increment(void) {
	switch (RTC_dev.time_1.month) {
	case JANUARY:
	case MARCH:
	case MAY:
	case JULY:
	case AUGUST:
	case OCTOBER:
	case DECEMBER:
		CHECK_MONTH_INCREMENT(31)
		break;
	case FEBUARY:
		if ((RTC_dev.time_1.year % 4) == 0) //leap year
			CHECK_MONTH_INCREMENT(29)
		else
		CHECK_MONTH_INCREMENT(28)
		break;
		CHECK_MONTH_INCREMENT(31)
		break;
	case APRIL:
	case JUNE:
	case SEPTERMBER:
	case NOVEMBER:
		CHECK_MONTH_INCREMENT(30)
		break;
	default:
		break;
	}
}

signed char RTC_dev_set_time_date(unsigned char date) {
	return DS3231_set_time_date(RTC_dev.i2c_handle, date);
}

void RTC_dev_set_time_month_increment(void) {
	if (RTC_dev.time_1.month == DECEMBER)
		RTC_dev.time_1.month = JANUARY;
	else
		RTC_dev.time_1.month++;
}

signed char RTC_dev_set_time_month(unsigned char month) {
	return DS3231_set_time_month(RTC_dev.i2c_handle, month);
}

void RTC_dev_set_time_year_increment(void) {
	RTC_dev.time_1.year++;
}

signed char RTC_dev_set_time_year(unsigned char year) {
	return DS3231_set_time_year(RTC_dev.i2c_handle, year);
}

signed char self_RTC_dev_set_time(DS3231_device_t* dev, unsigned char hour,
		unsigned char min, unsigned char sec, TIME_FORMAT_e format,
		AM_OR_PM_e am_pm) {
	dev->time_1.hour = (format == HOUR_12 && hour > 12) ? hour - 12 : hour;
	dev->time_1.min = min;
	dev->time_1.sec = sec;
	dev->time_1.format = format;
	dev->time_1.am_or_pm = am_pm;

	if (DS3231_set_time(dev->i2c_handle, &dev->time_1))
		return -1;

	return 0;
}

signed char RTC_dev_set_time(unsigned char hour, unsigned char min,
		unsigned char sec, TIME_FORMAT_e format, AM_OR_PM_e am_pm) {
	return RTC_dev.set_time(&RTC_dev, hour, min, sec, format, am_pm);
}

signed char self_RTC_dev_get_time(DS3231_device_t* dev) {
	return DS3231_get_time(dev->i2c_handle, &dev->time_1);
}

signed char RTC_dev_get_time(void) {
	return RTC_dev.get_time(&RTC_dev);
}

signed char self_RTC_dev_set_date(DS3231_device_t* dev, WEEKDAYS_e weekday,
		unsigned char date, MONTHS_e month, unsigned short year) {
	dev->time_1.weekday = weekday;
	dev->time_1.date = date;
	dev->time_1.month = month;
	dev->time_1.year = year;

	return DS3231_set_date(dev->i2c_handle, dev->time_1.year, dev->time_1.month,
			dev->time_1.date, dev->time_1.weekday);
}

signed char RTC_dev_set_date(WEEKDAYS_e weekday, unsigned char date,
		MONTHS_e month, unsigned short year) {
	return RTC_dev.set_date(&RTC_dev, weekday, date, month, year);
}

signed char self_RTC_dev_get_date(DS3231_device_t* dev) {
	return DS3231_get_date(dev->i2c_handle, &dev->time_1.year,
			&dev->time_1.month, &dev->time_1.date, &dev->time_1.weekday);
}

//untested
//TODO alarm stuff
signed char self_RTC_dev_set_alarm(DS3231_device_t* dev,
		TIME_TYPE_e alarm_number, unsigned char hour, unsigned char min,
		TIME_FORMAT_e format, AM_OR_PM_e am_pm, WEEKDAYS_e weekday,
		unsigned char date, DAY_OR_DATE_e date_or_day, ALARM_TYPE_e type) {
	//TODO last case
	switch (alarm_number) {
	case ALARM_ONE: //long
		dev->alarm_1.hour = (format == HOUR_12 && hour > 12) ? hour - 12 : hour;
		dev->alarm_1.min = min;
		dev->alarm_1.sec = 0;
		dev->alarm_1.format = format;
		dev->alarm_1.am_or_pm = am_pm;
		dev->alarm_1.weekday = weekday;
		dev->alarm_1.date = date;
		dev->alarm_1.day_or_date = date_or_day;
		dev->alarm_1.type = type;
		return DS3231_set_alarm(dev->i2c_handle, &dev->alarm_1, alarm_number);
	case ALARM_TWO: //short
		dev->alarm_2.hour = (format == HOUR_12 && hour > 12) ? hour - 12 : hour;
		dev->alarm_2.min = min;
		dev->alarm_2.format = format;
		dev->alarm_2.am_or_pm = am_pm;
		dev->alarm_2.weekday = weekday;
		dev->alarm_2.date = date;
		dev->alarm_2.day_or_date = date_or_day;
		dev->alarm_2.type = type;
		return DS3231_set_alarm(dev->i2c_handle,
				(ds3231_alarm_t *) &dev->alarm_2, alarm_number);
	default:
		break;
	}
	return -1;
}

signed char RTC_dev_set_alarm(TIME_TYPE_e alarm_number, unsigned char hour,
		unsigned char min, TIME_FORMAT_e format, AM_OR_PM_e am_pm,
		WEEKDAYS_e weekday, unsigned char date, DAY_OR_DATE_e date_or_day,
		ALARM_TYPE_e type) {
	return RTC_dev.set_alarm(&RTC_dev, alarm_number, hour, min, format, am_pm,
			weekday, date, date_or_day, type);
}

//TODO check second alarm
//untested
signed char self_RTC_dev_get_alarm(DS3231_device_t* dev,
		TIME_TYPE_e alarm_number) {

	//TODO last case
	switch (alarm_number) {
	case ALARM_ONE: //long
		return DS3231_get_alarm(dev->i2c_handle, &dev->alarm_1, alarm_number);
	case ALARM_TWO: //short
		return DS3231_get_alarm(dev->i2c_handle,
				(ds3231_alarm_t *) &dev->alarm_2, alarm_number);
	default:
		break;
	}

	return -1;
}

signed char RTC_dev_get_alarm(TIME_TYPE_e alarm_number) {
	return RTC_dev.get_alarm(&RTC_dev, alarm_number);
}

//untested
signed char self_RTC_dev_get_temp(DS3231_device_t* dev) {
	return DS3231_get_temp(dev->i2c_handle, &dev->temp);
}

signed char RTC_dev_get_temp(void) {
	return RTC_dev.get_temp(&RTC_dev);
}

signed char self_RTC_dev_actualize(DS3231_device_t *dev) {

	if (RTC_dev.set_time(dev, dev->time_1.hour, dev->time_1.min,
			dev->time_1.sec, dev->time_1.format, dev->time_1.am_or_pm))
		return -1;
	if (RTC_dev.set_alarm(dev, ALARM_ONE, dev->alarm_1.hour, dev->alarm_1.min,
			dev->alarm_1.format, dev->alarm_1.am_or_pm, dev->alarm_1.weekday,
			dev->alarm_1.date, dev->alarm_1.day_or_date, dev->alarm_1.type))
		return -1;
	if (RTC_dev.set_alarm(dev, ALARM_TWO, dev->alarm_2.hour, dev->alarm_2.min,
			dev->alarm_2.format, dev->alarm_2.am_or_pm, dev->alarm_2.weekday,
			dev->alarm_2.date, dev->alarm_2.day_or_date, dev->alarm_2.type))
		return -1;
	return 0;
}

signed char RTC_dev_actualize(void){
	return self_RTC_dev_actualize(&RTC_dev);
}

DS3231_device_t* RTC_dev_create(unsigned char twelve_hour, unsigned char hour,
		unsigned char min, unsigned char sec, AM_OR_PM_e am_pm,
		unsigned char week_day, unsigned char date, unsigned char month,
		unsigned short year, I2C_HandleTypeDef* i2c_handle) {
	DS3231_device_t* device = (DS3231_device_t*) calloc(1,
			sizeof(DS3231_device_t));

	device->time_1.format = twelve_hour;
	device->time_1.hour = hour;
	device->time_1.min = min;
	device->time_1.sec = sec;
	device->time_1.am_or_pm = am_pm;
	device->time_1.weekday = week_day;
	device->time_1.date = date;
	device->time_1.month = month;
	device->time_1.year = year;

	device->i2c_handle = i2c_handle;

	//functions
	device->set_time = &self_RTC_dev_set_time;
	device->get_time = &self_RTC_dev_get_time;
	device->set_date = &self_RTC_dev_set_date;
	device->get_date = &self_RTC_dev_get_date;
	device->set_alarm = &self_RTC_dev_set_alarm;
	device->get_alarm = &self_RTC_dev_get_alarm;
	device->get_temp = &self_RTC_dev_get_temp;

	self_RTC_dev_actualize(device);

	return device;
}

signed char RTC_dev_init(unsigned char def_vals) {
	//time
	if (def_vals) {
		RTC_dev.time_1.format = RTC_DEF_TWELVE_HR;
		RTC_dev.time_1.hour = RTC_DEF_HOUR;
		RTC_dev.time_1.min = RTC_DEF_MIN;
		RTC_dev.time_1.sec = RTC_DEF_SEC;
		RTC_dev.time_1.am_or_pm = RTC_DEF_AM_PM;
		RTC_dev.time_1.weekday = RTC_DEF_WEEKDAY;
		RTC_dev.time_1.date = RTC_DEF_DATE;
		RTC_dev.time_1.month = RTC_DEF_MONTH;
		RTC_dev.time_1.year = RTC_DEF_YEAR;

		//alarm 1
		RTC_dev.alarm_1.format = RTC_DEF_ALM1_TWELVE_HR;
		RTC_dev.alarm_1.min = RTC_DEF_ALM1_MIN;
		RTC_dev.alarm_1.hour = RTC_DEF_ALM1_HOUR;
		RTC_dev.alarm_1.am_or_pm = RTC_DEF_ALM1_AM_PM;
		RTC_dev.alarm_1.weekday = RTC_DEF_ALM1_WEEKDAY;
		RTC_dev.alarm_1.date = RTC_DEF_ALM1_DATE;
		RTC_dev.alarm_1.day_or_date = RTC_DEF_ALM1_DAY_OR_DATE;
		RTC_dev.alarm_1.type = RTC_DEF_ALM1_TYPE;
		RTC_dev.alarm_1.sec = RTC_DEV_ALM1_SEC;

		//alarm 1
		RTC_dev.alarm_2.format = RTC_DEF_ALM2_TWELVE_HR;
		RTC_dev.alarm_2.min = RTC_DEF_ALM2_MIN;
		RTC_dev.alarm_2.hour = RTC_DEF_ALM2_HOUR;
		RTC_dev.alarm_2.am_or_pm = RTC_DEF_ALM2_AM_PM;
		RTC_dev.alarm_2.weekday = RTC_DEF_ALM2_WEEKDAY;
		RTC_dev.alarm_2.date = RTC_DEF_ALM2_DATE;
		RTC_dev.alarm_2.day_or_date = RTC_DEF_ALM2_DAY_OR_DATE;
		RTC_dev.alarm_2.type = RTC_DEF_ALM2_TYPE;
	}

	RTC_dev.i2c_handle = RTC_DEF_I2C;

	//functions
	RTC_dev.set_time = &self_RTC_dev_set_time;
	RTC_dev.get_time = &self_RTC_dev_get_time;
	RTC_dev.set_date = &self_RTC_dev_set_date;
	RTC_dev.get_date = &self_RTC_dev_get_date;
	RTC_dev.set_alarm = &self_RTC_dev_set_alarm;
	RTC_dev.get_alarm = &self_RTC_dev_get_alarm;
	RTC_dev.get_temp = &self_RTC_dev_get_temp;

	return self_RTC_dev_actualize(&RTC_dev);
}
