/*
 * RTC_dev.h
 *
 *  Created on: 2 Feb 2019
 *      Author: alxhoff
 */

#ifndef RTC_DEV_H_
#define RTC_DEV_H_

#include "ds3231.h"

signed char RTC_dev_init(unsigned char def_vals);
signed char RTC_dev_actualize(void);
signed char RTC_dev_set_time(unsigned char hour, unsigned char min,
			     unsigned char sec, TIME_FORMAT_e format,
			     AM_OR_PM_e am_pm);
signed char RTC_dev_get_time(void);
signed char RTC_dev_set_alarm(TIME_TYPE_e alarm_number, unsigned char hour,
			      unsigned char min, TIME_FORMAT_e format,
			      AM_OR_PM_e am_pm, WEEKDAYS_e weekday,
			      unsigned char date, DAY_OR_DATE_e date_or_day,
			      ALARM_TYPE_e type);
signed char RTC_dev_get_alarm(TIME_TYPE_e alarm_number);
signed char RTC_dev_set_date(WEEKDAYS_e, unsigned char date, MONTHS_e month,
			     unsigned short year);
signed char RTC_dev_read_date(void);

//INCREMENTS
void RTC_dev_set_time_sec_zero(void);
void RTC_dev_set_time_min_increment(void);
void RTC_dev_set_time_hour_increment(void);
void RTC_dev_set_time_day_increment(void);
void RTC_dev_set_time_date_increment(void);
void RTC_dev_set_time_month_increment(void);
void RTC_dev_set_time_year_increment(void);

//SETS
signed char RTC_dev_time_set_hour(unsigned char hour);
signed char RTC_dev_time_set_min(unsigned char min);
signed char RTC_dev_time_set_sec(unsigned char sec);
signed char RTC_dev_time_set_day(unsigned char day);
signed char RTC_dev_time_set_date(unsigned char date);
signed char RTC_dev_time_set_month(unsigned char month);
signed char RTC_dev_time_set_year(unsigned short year);

//GETS
TIME_FORMAT_e RTC_dev_time_get_format(void);
unsigned char RTC_dev_time_get_hour(void);
unsigned char RTC_dev_time_get_min(void);
unsigned char RTC_dev_time_get_sec(void);
AM_OR_PM_e RTC_dev_time_get_AM_or_PM(void);
WEEKDAYS_e RTC_dev_time_get_weekday(void);
unsigned char RTC_dev_time_get_date(void);
MONTHS_e RTC_dev_time_get_month(void);
unsigned short RTC_dev_time_get_year(void);
TIME_FORMAT_e RTC_dev_alarm1_get_format(void);
unsigned char RTC_dev_alarm1_get_min(void);
unsigned char RTC_dev_alarm1_get_hour(void);
AM_OR_PM_e RTC_dev_alarm1_get_am_pm(void);
WEEKDAYS_e RTC_dev_alarm1_get_weekday(void);
unsigned char RTC_dev_alarm1_get_date(void);
DAY_OR_DATE_e RTC_dev_alarm1_get_day_or_date(void);
ALARM_TYPE_e RTC_dev_alarm1_get_type(void);
unsigned char RTC_dev_alarm1_get_sec(void);
TIME_FORMAT_e RTC_dev_alarm2_get_format(void);
unsigned char RTC_dev_alarm2_get_min(void);
unsigned char RTC_dev_alarm2_get_hour(void);
AM_OR_PM_e RTC_dev_alarm2_get_am_pm(void);
WEEKDAYS_e RTC_dev_alarm2_get_weekday(void);
unsigned char RTC_dev_alarm2_get_date(void);
DAY_OR_DATE_e RTC_dev_alarm2_get_day_or_date(void);
ALARM_TYPE_e RTC_dev_alarm2_get_type(void);

#endif /* RTC_DEV_H_ */
