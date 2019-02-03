/*
 * RTC_dev.h
 *
 *  Created on: 2 Feb 2019
 *      Author: alxhoff
 */

#ifndef RTC_DEV_H_
#define RTC_DEV_H_

#include "ds3231.h"

signed char RTC_dev_init(void);
signed char RTC_dev_write_time(unsigned char hour, unsigned char min,
		unsigned char sec);
signed char RTC_dev_read_time(void);
signed char RTC_dev_write_date(WEEKDAYS_e, unsigned char date, MONTHS_e month,
unsigned short year);
signed char RTC_dev_read_date(void);

//GETS
HOUR_12_OR_24_e RTC_dev_time_get_twelve_hour(void);
unsigned char RTC_dev_time_get_hour(void);
unsigned char RTC_dev_time_get_min(void);
unsigned char RTC_dev_time_get_sec(void);
AM_OR_PM_e RTC_dev_time_get_AM_or_PM(void);
WEEKDAYS_e RTC_dev_time_get_weekday(void);
unsigned char RTC_dev_time_get_date(void);
MONTHS_e RTC_dev_time_get_month(void);
unsigned short RTC_dev_time_get_year(void);

#endif /* RTC_DEV_H_ */
