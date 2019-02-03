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

uint8_t blink_flag = 0;

void draw_alarm(uint8_t x, uint8_t y, TIME_TYPE_e alarm) {

//	char time_str[] = "12:59:59";
//	LCD_dev->cursor(LCD_dev, x, y);
//	switch(alarm){
//	case ALARM_ONE:
//		sprintf(time_str, "%02d:%02d:%02d", RTC_dev->alarm_1->hour,
//				RTC_dev->alarm_1->min, RTC_dev->alarm_1->sec);
//		LCD_dev->string(LCD_dev, time_str);
//		break;
//	case ALARM_TWO:
//		sprintf(time_str, "%02d:%02d:%02d", RTC_dev->alarm_2->hour,
//				RTC_dev->alarm_2->min, 0);
//		LCD_dev->string(LCD_dev, time_str);
//		break;
//	default:
//		break;
//	}
//
//	if(RTC_dev->alarm_1->twelve_hour)
//		draw_am_pm(x + 100, y + 5, RTC_dev->alarm_1->pm);
//
//	draw_day( x , y + 20, RTC_dev->alarm_1->week_day);
//	draw_date( x + 35, y + 20, RTC_dev->alarm_1->date);
}

void draw_disp_alarm2_state(uint8_t x, uint8_t y) {
//	RTC_dev->get_alarm(RTC_dev, ALARM_TWO);
//	draw_alarm(x+10, y+5, ALARM_TWO);
//	if(RTC_dev->alarm_2->twelve_hour)
//		draw_am_pm(x + 100, y + 5, RTC_dev->alarm_2->pm);
//
//	draw_day( x + 10, y + 25, RTC_dev->alarm_2->week_day);
//	draw_date( x + 50, y + 25, RTC_dev->alarm_2->date);
}

void get_weekday_string(WEEKDAYS_e weekday, char *buf) {
	switch (weekday) {
	case MONDAY:
		strcpy(buf, "MON");
		break;
	case TUESDAY:
		strcpy(buf, "TUE");
		break;
	case WEDNESDAY:
		strcpy(buf, "WED");
		break;
	case THURSDAY:
		strcpy(buf, "THU");
		break;
	case FRIDAY:
		strcpy(buf, "FRI");
		break;
	case SATURDAY:
		strcpy(buf, "SAT");
		break;
	case SUNDAY:
		strcpy(buf, "SUN");
		break;
	default:
		strcpy(buf, "XXX");
		break;
	}
}

void get_month_string(MONTHS_e month, char *buf) {
	switch (month) {
	case JANUARY:
		strcpy(buf, "JAN");
		break;
	case FEBUARY:
		strcpy(buf, "FEB");
		break;
	case MARCH:
		strcpy(buf, "MAR");
		break;
	case APRIL:
		strcpy(buf, "APR");
		break;
	case MAY:
		strcpy(buf, "MAY");
		break;
	case JUNE:
		strcpy(buf, "JUN");
		break;
	case JULY:
		strcpy(buf, "JUL");
		break;
	case AUGUST:
		strcpy(buf, "AUG");
		break;
	case SEPTERMBER:
		strcpy(buf, "SEP");
		break;
	case OCTOBER:
		strcpy(buf, "OCT");
		break;
	case NOVEMBER:
		strcpy(buf, "NOV");
		break;
	case DECEMBER:
		strcpy(buf, "DEC");
		break;
	default:
		break;
	}
}

void get_alarm_date_string(char *buf, TIME_TYPE_e type) {
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

void get_alarm_time_string(char *buf, TIME_TYPE_e type){
	unsigned char hour;
	unsigned char min;

	switch(type){
	case ALARM_ONE:
		hour = RTC_dev_alarm1_get_hour();
		min = RTC_dev_alarm1_get_min();

		if(RTC_dev_alarm1_get_format() == HOUR_24)
			sprintf(buf, "%02d:%02d", hour, min);
		else
			if(RTC_dev_alarm1_get_am_pm() == AM)
				sprintf(buf, "%02d:%02d%s", hour, min, "AM");
			else
				sprintf(buf, "%02d:%02d%s", hour, min, "PM");
		break;
	case ALARM_TWO:
		hour = RTC_dev_alarm2_get_hour();
		min = RTC_dev_alarm2_get_min();

		if(RTC_dev_alarm2_get_format() == HOUR_24)
			sprintf(buf, "%02d:%02d", hour, min);
		else
			if(RTC_dev_alarm2_get_am_pm() == AM)
				sprintf(buf, "%02d:%02d%s", hour, min, "AM");
			else
				sprintf(buf, "%02d:%02d%s", hour, min, "PM");
		break;
	default:
		break;
	}
}

void get_date_string(char *buf) {
	unsigned char date = RTC_dev_time_get_date();
	MONTHS_e month = RTC_dev_time_get_month();
	unsigned short year = RTC_dev_time_get_year();

	char month_str[4] = { 0 };
	get_month_string(month, month_str);

	sprintf(buf, "%02d %s %02hu", date, month_str, year);
}

void get_time_weekday_string(char *buf) {
	WEEKDAYS_e weekday = RTC_dev_time_get_weekday();

	get_weekday_string(weekday, buf);
}

void get_time_string(char *buf) {
	unsigned char hour = RTC_dev_time_get_hour();
	unsigned char min = RTC_dev_time_get_min();
	unsigned char sec = RTC_dev_time_get_sec();

	if (RTC_dev_time_get_format() == HOUR_24)
		sprintf(buf, "%02d:%02d:%02d", hour, min, sec);
	else {
		if (RTC_dev_time_get_AM_or_PM() == AM)
			sprintf(buf, "%02d:%02d:%02d%s", hour, min, sec, "AM");
		else
			/* PM */
			sprintf(buf, "%02d:%02d:%02d%s", hour, min, sec, "PM");
	}
}

//STATES
//TIME
unsigned char draw_time_init(void) {

	return 0;
}

void draw_time_enter(void) {

}

void draw_time_run(void) {
	static char weekday[12];
	static char date[12];
	static char time[12];

	RTC_dev_get_time();

	get_time_weekday_string(weekday);
	get_date_string(date);
	get_time_string(time);

	screen_add_line_at_index(0, weekday);
	screen_add_line_at_index(1, date);
	screen_add_line_at_index(2, time);
}

void draw_time_exit(void) {

}

//SET TIME
unsigned char draw_set_time_init(void) {

	return 0;
}

void draw_set_time_enter(void) {

}

void draw_set_time_run(void) {

}

void draw_set_time_exit(void) {

}

//SET ALARM 1
unsigned char draw_alarm1_init(void) {

	return 0;
}

void draw_alarm1_enter(void) {

}

void draw_alarm1_run(void) {
	static char date[12];
	static char time[12];

	RTC_dev_get_alarm(ALARM_ONE);

	get_alarm_date_string(date, ALARM_ONE);
	get_alarm_time_string(time, ALARM_ONE);

	screen_add_line_at_index(1, date);
	screen_add_line_at_index(2, time);
}

void draw_alarm1_exit(void) {

}

//SET ALARM 2
unsigned char draw_alarm2_init(void) {

	return 0;
}

void draw_alarm2_enter(void) {

}

void draw_alarm2_run(void) {
	static char date[12];
	static char time[12];

	RTC_dev_get_alarm(ALARM_TWO);

	get_alarm_date_string(date, ALARM_TWO);
	get_alarm_time_string(time, ALARM_TWO);

	screen_add_line_at_index(1, date);
	screen_add_line_at_index(2, time);
}

void draw_alarm2_exit(void) {

}

