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
	signed char (*set_time)(DS3231_device_t*);
	signed char (*get_date)(DS3231_device_t*);
	signed char (*set_date)(DS3231_device_t*);
	signed char (*get_alarm)(DS3231_device_t*, TYPE_TIME_t);
	signed char (*set_alarm)(DS3231_device_t*, TYPE_TIME_t);
	signed char (*get_temp)(DS3231_device_t*);
	signed char (*dump_register)(DS3231_device_t*);
};

DS3231_device_t DS3231_dev = { 0 };

signed char DS3231_dev_write_time(DS3231_device_t* self) {
	if (DS3231_write_time(self->i2c_handle, &self->time_1))
		return -1;

	self->time_1.dirty = 0;

	return 0;
}

signed char DS3231_dev_read_time(DS3231_device_t* self) {
	return DS3231_read_time(self->i2c_handle, &self->time_1);
}

signed char DS3231_dev_write_date(DS3231_device_t* self) {
	return DS3231_write_date(self->i2c_handle, self->time_1.year,
			self->time_1.month, self->time_1.date, self->time_1.week_day);
}

signed char DS3231_dev_read_date(DS3231_device_t* self) {
	return DS3231_read_date(self->i2c_handle, &self->time_1.year,
			&self->time_1.month, &self->time_1.date, &self->time_1.week_day);
}

//untested
signed char DS3231_dev_write_alarm(DS3231_device_t* self,
		TYPE_TIME_t alarm_number) {
	//TODO last case
	switch (alarm_number) {
	case ALARM_ONE: //long
		return DS3231_set_alarm(self->i2c_handle, &self->alarm_1, alarm_number);
	case ALARM_TWO: //short
		return DS3231_set_alarm(self->i2c_handle,
				(ds3231_alarm_t *) &self->alarm_2, alarm_number);
	default:
		break;
	}
	return -1;
}

//TODO check second alarm
//untested
signed char DS3231_dev_get_alarm(DS3231_device_t* self,
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

	if (HAL_I2C_Mem_Read(self->i2c_handle, DS3231_ADDR8, alarm_register_addr, 1,
			read_buffer, 4, 10) != HAL_OK)
		return -1;

	//TODO last case
	switch (alarm_number) {
	case ALARM_ONE: //long
		return DS3231_get_alarm(self->i2c_handle, &self->alarm_1, alarm_number);
	case ALARM_TWO: //short
		return DS3231_get_alarm(self->i2c_handle,
				(ds3231_alarm_t *) &self->alarm_2, alarm_number);
	default:
		break;
	}

	return -1;
}

//untested
signed char DS3231_dev_get_temp(DS3231_device_t* self) {
	return DS3231_read_temp(self->i2c_handle, &self->temp);
}

DS3231_device_t* DS3231_dev_create(uint8_t twelve_hour, uint8_t hour,
uint8_t min, uint8_t sec, AM_OR_PM_e am_pm, uint8_t week_day,
uint8_t date, uint8_t month, uint16_t year, I2C_HandleTypeDef* i2c_handle) {
	DS3231_device_t* device = (DS3231_device_t*) calloc(1,
			sizeof(DS3231_device_t));

	device->time_1.twelve_hour = twelve_hour;
	device->time_1.hour = hour;
	device->time_1.min = min;
	device->time_1.sec = sec;
	device->time_1.pm = am_pm;
	device->time_1.week_day = week_day;
	device->time_1.date = date;
	device->time_1.month = month;
	device->time_1.year = year;

	device->i2c_handle = i2c_handle;

	//functions
	device->set_time = &DS3231_dev_write_time;
	device->get_time = &DS3231_dev_read_time;
	device->set_date = &DS3231_dev_write_date;
	device->get_date = &DS3231_dev_read_date;
	device->set_alarm = &DS3231_dev_write_alarm;
	device->get_alarm = &DS3231_dev_get_alarm;
	device->get_temp = &DS3231_dev_get_temp;

	device->set_time(device);

	return device;
}

void DS3231_dev_init(DS3231_device_t *device, uint8_t twelve_hour, uint8_t hour,
uint8_t min, uint8_t sec, AM_OR_PM_e am_pm, uint8_t week_day,
uint8_t date, uint8_t month, uint16_t year, I2C_HandleTypeDef* i2c_handle) {
	device->time_1.twelve_hour = twelve_hour;
	device->time_1.hour = hour;
	device->time_1.min = min;
	device->time_1.sec = sec;
	device->time_1.pm = am_pm;
	device->time_1.week_day = week_day;
	device->time_1.date = date;
	device->time_1.month = month;
	device->time_1.year = year;

	device->i2c_handle = i2c_handle;

	//functions
	device->set_time = &DS3231_dev_write_time;
	device->get_time = &DS3231_dev_read_time;
	device->set_date = &DS3231_dev_write_date;
	device->get_date = &DS3231_dev_read_date;
	device->set_alarm = &DS3231_dev_write_alarm;
	device->get_alarm = &DS3231_dev_get_alarm;
	device->get_temp = &DS3231_dev_get_temp;

	device->set_time(device);
}

void RTC_dev_init(void) {
	DS3231_dev_init(&DS3231_dev, RTC_DEF_TWELVE_HR, RTC_DEF_HOUR, RTC_DEF_MIN,
	RTC_DEF_SEC,
	RTC_DEF_AM_PM, RTC_DEF_WEEKDAY, RTC_DEF_DATE, RTC_DEF_MONTH,
	RTC_DEF_YEAR, RTC_DEF_I2C);
}
