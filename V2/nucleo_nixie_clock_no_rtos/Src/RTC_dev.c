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
	signed char (*set_time)(DS3231_device_t*, uint8_t, uint8_t, uint8_t);
	signed char (*get_date)(DS3231_device_t*);
	signed char (*set_date)(DS3231_device_t*, WEEKDAYS_e, uint8_t, MONTHS_e,
			uint16_t);
	signed char (*get_alarm)(DS3231_device_t*, TYPE_TIME_t);
	signed char (*set_alarm)(DS3231_device_t*, TYPE_TIME_t);
	signed char (*get_temp)(DS3231_device_t*);
	signed char (*dump_register)(DS3231_device_t*);
};

DS3231_device_t RTC_dev = { 0 };

HOUR_12_OR_24_e RTC_dev_time_get_twelve_hour(void){
	return RTC_dev.time_1.twelve_hour;
}

uint8_t RTC_dev_time_get_hour(void){
	return RTC_dev.time_1.hour;
}

uint8_t RTC_dev_time_get_min(void){
	return RTC_dev.time_1.min;
}

uint8_t RTC_dev_time_get_sec(void){
	return RTC_dev.time_1.sec;
}

AM_OR_PM_e RTC_dev_time_get_AM_or_PM(void){
	return RTC_dev.time_1.am_or_pm;
}

WEEKDAYS_e RTC_dev_time_get_weekday(void){
	return RTC_dev.time_1.weekday;
}

uint8_t RTC_dev_time_get_date(void){
	return RTC_dev.time_1.date;
}

MONTHS_e RTC_dev_time_get_month(void){
	return RTC_dev.time_1.month;
}

uint16_t RTC_dev_time_get_year(void){
	return RTC_dev.time_1.year;
}

signed char self_RTC_dev_write_time(DS3231_device_t* dev, uint8_t hour,
		uint8_t min,
		uint8_t sec) {
	dev->time_1.hour = hour;
	dev->time_1.min = min;
	dev->time_1.sec = sec;

	if (DS3231_write_time(dev->i2c_handle, &dev->time_1))
		return -1;

	return 0;
}

signed char RTC_dev_write_time(uint8_t hour, uint8_t min, uint8_t sec) {
	return RTC_dev.set_time(&RTC_dev, hour, min, sec);
}

signed char RTC_dev_actualize(DS3231_device_t *dev) {

	if (RTC_dev.set_time(dev, dev->time_1.hour, dev->time_1.min,
			dev->time_1.sec))
		return -1;
	//TODO complete this
	return 0;
}

signed char self_RTC_dev_read_time(DS3231_device_t* dev) {
	return DS3231_read_time(dev->i2c_handle, &dev->time_1);
}

signed char RTC_dev_read_time(void) {
	return RTC_dev.get_time(&RTC_dev);
}

signed char self_RTC_dev_write_date(DS3231_device_t* dev, WEEKDAYS_e weekday,
		uint8_t date, MONTHS_e month, uint16_t year) {
	dev->time_1.weekday = weekday;
	dev->time_1.date = date;
	dev->time_1.month = month;
	dev->time_1.year = year;

	return DS3231_write_date(dev->i2c_handle, dev->time_1.year,
			dev->time_1.month, dev->time_1.date, dev->time_1.weekday);
}

signed char RTC_dev_write_date(WEEKDAYS_e weekday, uint8_t date, MONTHS_e month,
		uint16_t year) {
	return RTC_dev.set_date(&RTC_dev, weekday, date, month, year);
}

signed char self_RTC_dev_read_date(DS3231_device_t* dev) {
	return DS3231_read_date(dev->i2c_handle, &dev->time_1.year,
			&dev->time_1.month, &dev->time_1.date, &dev->time_1.weekday);
}

//untested
//TODO alarm stuff
signed char self_RTC_dev_write_alarm(DS3231_device_t* dev,
		TYPE_TIME_t alarm_number) {
	//TODO last case
	switch (alarm_number) {
	case ALARM_ONE: //long
		return DS3231_set_alarm(dev->i2c_handle, &dev->alarm_1, alarm_number);
	case ALARM_TWO: //short
		return DS3231_set_alarm(dev->i2c_handle,
				(ds3231_alarm_t *) &dev->alarm_2, alarm_number);
	default:
		break;
	}
	return -1;
}

signed char RTC_dev_write_alarm(TYPE_TIME_t alarm_number) {
	return RTC_dev.set_alarm(&RTC_dev, alarm_number);
}

//TODO check second alarm
//untested
signed char self_RTC_dev_get_alarm(DS3231_device_t* dev,
		TYPE_TIME_t alarm_number) {
	uint8_t read_buffer[4];
	volatile uint8_t alarm_register_addr = 0x00;

	//TODO last case
	switch (alarm_number) {
	case ALARM_ONE:
		alarm_register_addr = 0x07;
		break;
	case ALARM_TWO:
		alarm_register_addr = 0x0B;
		break;
	default:
		return -1;
		break;
	}

	if (HAL_I2C_Mem_Read(dev->i2c_handle, DS3231_ADDR8, alarm_register_addr, 1,
			read_buffer, 4, 10) != HAL_OK)
		return -1;

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

signed char RTC_dev_get_alarm(TYPE_TIME_t alarm_number) {
	return RTC_dev.get_alarm(&RTC_dev, alarm_number);
}

//untested
signed char self_RTC_dev_get_temp(DS3231_device_t* dev) {
	return DS3231_read_temp(dev->i2c_handle, &dev->temp);
}

signed char RTC_dev_get_temp(void) {
	return RTC_dev.get_temp(&RTC_dev);
}

DS3231_device_t* RTC_dev_create(uint8_t twelve_hour, uint8_t hour,
uint8_t min, uint8_t sec, AM_OR_PM_e am_pm, uint8_t week_day,
uint8_t date, uint8_t month, uint16_t year, I2C_HandleTypeDef* i2c_handle) {
	DS3231_device_t* device = (DS3231_device_t*) calloc(1,
			sizeof(DS3231_device_t));

	device->time_1.twelve_hour = twelve_hour;
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
	device->set_time = &self_RTC_dev_write_time;
	device->get_time = &self_RTC_dev_read_time;
	device->set_date = &self_RTC_dev_write_date;
	device->get_date = &self_RTC_dev_read_date;
	device->set_alarm = &self_RTC_dev_write_alarm;
	device->get_alarm = &self_RTC_dev_get_alarm;
	device->get_temp = &self_RTC_dev_get_temp;

	RTC_dev_actualize(device);

	return device;
}

signed char RTC_dev_init(void) {
	RTC_dev.time_1.twelve_hour = RTC_DEF_TWELVE_HR;
	RTC_dev.time_1.hour = RTC_DEF_HOUR;
	RTC_dev.time_1.min = RTC_DEF_MIN;
	RTC_dev.time_1.sec = RTC_DEF_SEC;
	RTC_dev.time_1.am_or_pm = RTC_DEF_AM_PM;
	RTC_dev.time_1.weekday = RTC_DEF_WEEKDAY;
	RTC_dev.time_1.date = RTC_DEF_DATE;
	RTC_dev.time_1.month = RTC_DEF_MONTH;
	RTC_dev.time_1.year = RTC_DEF_YEAR;

	RTC_dev.i2c_handle = RTC_DEF_I2C;

	//functions
	RTC_dev.set_time = &self_RTC_dev_write_time;
	RTC_dev.get_time = &self_RTC_dev_read_time;
	RTC_dev.set_date = &self_RTC_dev_write_date;
	RTC_dev.get_date = &self_RTC_dev_read_date;
	RTC_dev.set_alarm = &self_RTC_dev_write_alarm;
	RTC_dev.get_alarm = &self_RTC_dev_get_alarm;
	RTC_dev.get_temp = &self_RTC_dev_get_temp;

	return RTC_dev_actualize(&RTC_dev);
}
