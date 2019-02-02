/*
 * RTC_dev.c
 *
 *  Created on: 2 Feb 2019
 *      Author: alxhoff
 */

#include <stdlib.h>

#include "RTC_dev.h"
#include "stm32f1xx_hal.h"
#include "RTC_config.h"

typedef struct ds3231_device ds3231_device_t;

struct ds3231_device {
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

DS3231_device_t ds3231_dev = { 0 };

signed char DS3231_dev_write_time(DS3231_device_t* self) {
	if(DS3231_write_time(self->i2c_handle, &self->time_1))
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
	uint8_t alarm_register_addr = 0x07;
	uint8_t write_buffer[4];
	uint8_t day_date_byte = 0x00;

	//TODO last case
	switch (alarm_number) {
	case ALARM_ONE: //long
		alarm_register_addr = 0x07;

		write_buffer[0] = dec2bcd(self->alarm_1.sec) & 0x7F;
		write_buffer[1] = dec2bcd(self->alarm_1.min) & 0x7F;

		write_buffer[2] = 0x00;

		if (self->alarm_1.twelve_hour) {
			//12 hour
			if (self->alarm_1.pm == PM) {
				//PM
				write_buffer[2] = bcd2dec(self->alarm_1.hour & 0x1F);
				write_buffer[2] |= (1 << PM_AM_FLAG) | (1 << TWELVE_FLAG);
			} else {
				//AM
				write_buffer[2] = dec2bcd(self->alarm_1.hour & 0x1F);
				//set flags
				write_buffer[2] |= (1 << TWELVE_FLAG);
				write_buffer[2] &= ~(1 << PM_AM_FLAG);
			}
		} else {
			//24 hours
			write_buffer[2] = dec2bcd(self->alarm_1.hour & 0x3F);
			//set flags
			write_buffer[2] &= ~(1 << TWELVE_FLAG);
		}

		if (self->alarm_1.date_or_day == DAY_OF_MONTH) {
			//Day of month
			day_date_byte |= (1 << DY_DT_FLAG);
			day_date_byte |= dec2bcd(self->alarm_1.date & 0x3F);
		} else {
			//Day of week
			day_date_byte &= ~(1 << DY_DT_FLAG);
			day_date_byte |= dec2bcd(self->alarm_1.week_day & 0x0F);
		}

		write_buffer[3] = day_date_byte;

		switch (self->alarm_1.alarm_type) {
		case ALARM_EVERY_SECOND:
			write_buffer[0] |= (1 << ALARM_MASK_BITS);
			write_buffer[1] |= (1 << ALARM_MASK_BITS);
			write_buffer[2] |= (1 << ALARM_MASK_BITS);
			write_buffer[3] |= (1 << ALARM_MASK_BITS);
			break;
		case ALARM_MATCH_SECONDS:
			write_buffer[0] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[1] |= (1 << ALARM_MASK_BITS);
			write_buffer[2] |= (1 << ALARM_MASK_BITS);
			write_buffer[3] |= (1 << ALARM_MASK_BITS);
			break;
		case ALARM_MATCH_MINUTES:
			write_buffer[0] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[1] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[2] |= (1 << ALARM_MASK_BITS);
			write_buffer[3] |= (1 << ALARM_MASK_BITS);
			break;
		case ALARM_MATCH_HOURS:
			write_buffer[0] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[1] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[2] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[3] |= (1 << ALARM_MASK_BITS);
			break;
		case ALARM_MATCH_DATE_OR_DAY:
			write_buffer[0] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[1] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[2] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[3] &= ~(1 << ALARM_MASK_BITS);
			break;
		default:
			break;
		}

		if (HAL_I2C_Mem_Write(self->i2c_handle, DS3231_ADDR8,
				alarm_register_addr, 1, write_buffer, 4, 10) != HAL_OK)
			return -1;

		break;
	case ALARM_TWO: //short
		alarm_register_addr = 0x0B;

		write_buffer[0] = dec2bcd(self->alarm_2.min) & 0x7F;

		write_buffer[1] = 0x00;

		if (self->alarm_2.twelve_hour) {
			//12 hour
			if (self->alarm_2.pm == PM) {
				//PM
				write_buffer[1] = bcd2dec(self->alarm_2.hour & 0x1F);
				write_buffer[1] |= (1 << PM_AM_FLAG) | (1 << TWELVE_FLAG);
			} else {
				//AM
				write_buffer[1] = dec2bcd(self->alarm_2.hour & 0x1F);
				//set flags
				write_buffer[1] |= (1 << TWELVE_FLAG);
				write_buffer[1] &= ~(1 << PM_AM_FLAG);
			}
		} else {
			//24 hours
			write_buffer[1] = dec2bcd(self->alarm_2.hour & 0x3F);
			//set flags
			write_buffer[1] &= ~(1 << TWELVE_FLAG);
		}

		if (self->alarm_2.date_or_day == DAY_OF_MONTH) {
			//Day of month
			day_date_byte |= (1 << DY_DT_FLAG);
			day_date_byte |= dec2bcd(self->alarm_2.date & 0x3F);
		} else {
			//Day of week
			day_date_byte &= ~(1 << DY_DT_FLAG);
			day_date_byte |= dec2bcd(self->alarm_2.week_day & 0x0F);
		}

		write_buffer[2] = day_date_byte;

		//TODO CHECK THIS
		switch (self->alarm_2.alarm_type) {
		case ALARM_MATCH_MINUTES:
			write_buffer[0] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[1] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[2] |= (1 << ALARM_MASK_BITS);
			break;
		case ALARM_MATCH_HOURS:
			write_buffer[0] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[1] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[2] &= ~(1 << ALARM_MASK_BITS);
			break;
		case ALARM_MATCH_DATE_OR_DAY:
			write_buffer[0] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[1] &= ~(1 << ALARM_MASK_BITS);
			write_buffer[2] &= ~(1 << ALARM_MASK_BITS);
			break;
		default:
			break;
		}

		if (HAL_I2C_Mem_Write(self->i2c_handle, DS3231_ADDR8,
				alarm_register_addr, 1, write_buffer, 3, 10) != HAL_OK)
			return -1;

		break;
	default:
		break;
	}
	return 0;
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
		self->alarm_1.sec = bcd2dec(read_buffer[0] & 0x7F);
		self->alarm_1.min = bcd2dec(read_buffer[1] & 0x7F);

		if (read_buffer[2] & (1 << TWELVE_FLAG)) {
			//12 hour
			self->alarm_1.twelve_hour = TRUE;
			if (read_buffer[2] & (1 << PM_AM_FLAG)) {
				//PM
				self->alarm_1.pm = PM;
			} else {
				//AM
				self->alarm_1.pm = AM;
			}
			self->alarm_1.hour = bcd2dec(read_buffer[2] & 0x1F);
		} else {
			//24 hour
			self->alarm_1.twelve_hour = FALSE;
			self->alarm_1.pm = AM;
			self->alarm_1.hour = bcd2dec(read_buffer[2] & 0x3F);
		}

		if (read_buffer[3] & (1 << DY_DT_FLAG)) {
			//day of month
			self->alarm_1.date_or_day = DAY_OF_MONTH;
			self->alarm_1.date = bcd2dec(read_buffer[3] & 0x3F);
		} else {
			//day of week
			self->alarm_1.date_or_day = DAY_OF_WEEK;
			self->alarm_1.week_day = bcd2dec(read_buffer[3] & 0x0F);
		}
		break;
	case ALARM_TWO: //short
		self->alarm_2.min = bcd2dec(read_buffer[0] & 0x7F);

		if (read_buffer[1] & (1 << TWELVE_FLAG)) {
			//12 hour
			self->alarm_2.twelve_hour = TRUE;
			if (read_buffer[1] & (1 << PM_AM_FLAG)) {
				//PM
				self->alarm_2.pm = PM;
			} else {
				//AM
				self->alarm_2.pm = AM;
			}
			self->alarm_2.hour = bcd2dec(read_buffer[3] & 0x1F);
		} else {
			//24 hour
			self->alarm_2.twelve_hour = FALSE;
			self->alarm_2.pm = AM;
			self->alarm_2.hour = bcd2dec(read_buffer[3] & 0x3F);
		}

		if (read_buffer[4] & (1 << DY_DT_FLAG)) {
			//day of month
			self->alarm_2.date_or_day = DAY_OF_MONTH;
			self->alarm_2.date = bcd2dec(read_buffer[4] & 0x3F);
		} else {
			//day of week
			self->alarm_2.date_or_day = DAY_OF_WEEK;
			self->alarm_2.week_day = bcd2dec(read_buffer[4] & 0x0F);
		}
		break;
	default:
		return -1;
		break;
	}

	return 0;
}

//untested
signed char DS3231_dev_get_temp(DS3231_device_t* self) {
	return DS3231_read_temp(self->i2c_handle, &self->temp);
}

DS3231_device_t* DS3231_dev_create(uint8_t twelve_hour, uint8_t hour,
		uint8_t min, uint8_t sec, AM_OR_PM_e am_pm, uint8_t week_day,
		uint8_t date, uint8_t month, uint16_t year,
		I2C_HandleTypeDef* i2c_handle) {
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
		uint8_t date, uint8_t month, uint16_t year,
		I2C_HandleTypeDef* i2c_handle) {
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
	DS3231_dev_init(&ds3231_dev, RTC_DEF_TWELVE_HR, RTC_DEF_HOUR, RTC_DEF_MIN,
			RTC_DEF_SEC,
			RTC_DEF_AM_PM, RTC_DEF_WEEKDAY, RTC_DEF_DATE, RTC_DEF_MONTH,
			RTC_DEF_YEAR, RTC_DEF_I2C);
}
