/*
 * draw.c
 *
 *  Created on: Aug 8, 2017
 *      Author: alxhoff
 */

#include <string.h>

#include "screen.h"
#include "draw.h"
#include "RTC_dev.h"
#include "stm32f1xx_hal.h"
//#include "SN54HC595.h"
#include "nixie.h"
#include "config.h"

unsigned char blink_flag = 0;

static char weekday[12] = { 0 };
static char date[12] = { 0 };
static char time[12] = { 0 };

const char *weekday_strings[8] = {
	"XXX", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN",
};
const char *month_strings[13] = { "XXX", "JAN", "FEB", "MAR", "APR",
				  "MAY", "JUN", "JUL", "AUG", "SEP",
				  "OCT", "NOV", "DEC" };

static void get_weekday_string(WEEKDAYS_e weekday, char *buf)
{
	switch (weekday) {
	case MONDAY:
	case TUESDAY:
	case WEDNESDAY:
	case THURSDAY:
	case FRIDAY:
	case SATURDAY:
	case SUNDAY:
		strcpy(buf, weekday_strings[weekday]);
		break;
	default:
		strcpy(buf, weekday_strings[0]);
		break;
	}
}

static void get_month_string(MONTHS_e month, char *buf)
{
	switch (month) {
	case JANUARY:
	case FEBUARY:
	case MARCH:
	case APRIL:
	case MAY:
	case JUNE:
	case JULY:
	case AUGUST:
	case SEPTERMBER:
	case OCTOBER:
	case NOVEMBER:
	case DECEMBER:
		strcpy(buf, month_strings[month]);
		break;
	default:
		strcpy(buf, month_strings[0]);
		break;
	}
}

static void get_alarm_date_string(char *buf, TIME_TYPE_e type)
{
	unsigned char date;
	WEEKDAYS_e weekday;
	DAY_OR_DATE_e date_or_day;

	switch (type) {
	case ALARM_ONE:
		date_or_day = RTC_dev_alarm1_get_day_or_date();
		if (date_or_day == DAY_OF_WEEK) {
			weekday = RTC_dev_alarm1_get_weekday();
			get_weekday_string(weekday, buf);
		} else {
			date = RTC_dev_alarm1_get_date();
			sprintf(buf, "%d", date);
		}

		break;
	case ALARM_TWO:
		date_or_day = RTC_dev_alarm2_get_day_or_date();
		if (date_or_day == DAY_OF_WEEK) {
			weekday = RTC_dev_alarm2_get_weekday();
			get_weekday_string(weekday, buf);
		} else {
			date = RTC_dev_alarm2_get_date();
			sprintf(buf, "%d", date);
		}
		break;
	default:
		break;
	}
}

static void get_alarm_time_string(char *buf, TIME_TYPE_e type)
{
	unsigned char hour;
	unsigned char min;

	switch (type) {
	case ALARM_ONE:
		hour = RTC_dev_alarm1_get_hour();
		min = RTC_dev_alarm1_get_min();

		if (RTC_dev_alarm1_get_format() == HOUR_24)
			sprintf(buf, "%02d:%02d", hour, min);
		else if (RTC_dev_alarm1_get_am_pm() == AM)
			sprintf(buf, "%02d:%02d%s", hour, min, "AM");
		else
			sprintf(buf, "%02d:%02d%s", hour, min, "PM");
		break;
	case ALARM_TWO:
		hour = RTC_dev_alarm2_get_hour();
		min = RTC_dev_alarm2_get_min();

		if (RTC_dev_alarm2_get_format() == HOUR_24)
			sprintf(buf, "%02d:%02d", hour, min);
		else if (RTC_dev_alarm2_get_am_pm() == AM)
			sprintf(buf, "%02d:%02d%s", hour, min, "AM");
		else
			sprintf(buf, "%02d:%02d%s", hour, min, "PM");
		break;
	default:
		break;
	}
}

static void get_date_string(char *buf, signed char manual_date,
			    signed char manual_month, signed short manual_year)
{
	unsigned char date;
	MONTHS_e month;
	unsigned short year;
	static char month_str[4] = { 0 };

	if (manual_date == -1)
		date = RTC_dev_time_get_date();
	else
		date = manual_date;

	if (manual_month == -1)
		month = RTC_dev_time_get_month();
	else
		month = manual_month;

	if (manual_year == -1)
		year = RTC_dev_time_get_year();
	else
		year = (unsigned short)manual_year;

	get_month_string(month, month_str);

	sprintf(buf, "%02d %s %04hu", date, month_str, year);

	if ((manual_date != -1) && blink_flag)
		strncpy(buf, "--", 2);
	else if ((manual_month != -1) && blink_flag)
		strncpy(buf + 3, "---", 3);
	else if ((manual_year != -1) && blink_flag)
		strncpy(buf + 7, "----", 4);

	return;
}

static void get_time_weekday_string(char *buf, signed char manual_weekday)
{
	WEEKDAYS_e weekday;

	if (manual_weekday == -1)
		weekday = RTC_dev_time_get_weekday();
	else
		weekday = manual_weekday;

	if ((manual_weekday != -1) && blink_flag)
		strcpy(buf, "---");
	else
		get_weekday_string(weekday, buf);
}

static void get_time_string(char *buf, signed char manual_hour,
			    signed char manual_min, signed char manual_sec)
{
	unsigned char hour;
	unsigned char min;
	unsigned char sec;

	if (manual_hour == -1)
		hour = RTC_dev_time_get_hour();
	else
		hour = manual_hour;

	if (manual_min == -1)
		min = RTC_dev_time_get_min();
	else
		min = manual_min;

	if (manual_sec == -1)
		sec = RTC_dev_time_get_sec();
	else
		sec = manual_sec;

	if (RTC_dev_time_get_format() == HOUR_24)
		sprintf(buf, "%02d:%02d:%02d", hour, min, sec);
	else {
		if (RTC_dev_time_get_AM_or_PM() == AM)
			sprintf(buf, "%02d:%02d:%02d%s", hour, min, sec, "AM");
		else
			/* PM */
			sprintf(buf, "%02d:%02d:%02d%s", hour, min, sec, "PM");
	}

	// XOR one digit blinking
	if ((manual_hour != -1) && blink_flag)
		strncpy(buf, "--", 2);
	else if ((manual_min != -1) && blink_flag)
		strncpy(buf + 3, "--", 2);
	else if ((manual_sec != -1) && blink_flag)
		strncpy(buf + 6, "--", 2);
}

//TIME
void draw_get_and_draw_time(signed char m_hour, signed char m_min,
			    signed char m_sec, signed char m_weekday,
			    signed char m_date, signed char m_month,
			    signed short m_year)
{
	unsigned char nixie_changed = 0;
	static uint32_t nixie_output;
	static unsigned char minutes;
	static unsigned char hours;

	RTC_dev_get_time();
	get_time_weekday_string(weekday, m_weekday);
	get_date_string(date, m_date, m_month, m_year);
	get_time_string(time, m_hour, m_min, m_sec);

	screen_add_line_at_index(0, weekday);
	screen_add_line_at_index(1, date);
	screen_add_line_at_index(2, time);

	// Set nixie
	nixie_enable_all();

	if (m_hour == -1)
		hours = RTC_dev_time_get_hour();
	else{
		hours = m_hour;
		nixie_disable_tube(NIXIE_HOUR_INDEX_LSB);
		nixie_disable_tube(NIXIE_HOUR_INDEX_LSB + 1);
	}

	if (m_min == -1)
		minutes = RTC_dev_time_get_min();
	else{
		minutes = m_min;
		nixie_disable_tube(NIXIE_MIN_INDEX_LSB);
		nixie_disable_tube(NIXIE_MIN_INDEX_LSB + 1);
	}

	nixie_split_set_digit(minutes, NIXIE_MIN_INDEX_LSB);
	nixie_split_set_digit(hours, NIXIE_HOUR_INDEX_LSB);

	nixie_output = nixie_compile_output();
	SN54HC595_out_int(nixie_output);
}
