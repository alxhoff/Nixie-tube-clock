/*
 * draw.c
 *
 *  Created on: Aug 8, 2017
 *      Author: alxhoff
 */

#include <string.h>

#include "draw.h"
#include "externs.h"

uint8_t blink_flag = 0;

//STATES


void draw_am_pm( uint8_t x, uint8_t y, AM_OR_PM_e pm)
{
//	LCD_dev->cursor(LCD_dev, x, y);
//	if(pm == PM){
//		LCD_dev->string(LCD_dev, "PM");
//	}else{
//		LCD_dev->string(LCD_dev, "AM");
//	}
}

void draw_day( uint8_t x, uint8_t y, WEEKDAYS_e day)
{
	char day_str[3];

	switch(day){
		case MONDAY:
			strcpy(day_str, "MON");
			break;
		case TUESDAY:
			strcpy(day_str, "TUE");
			break;
		case WEDNESDAY:
			strcpy(day_str, "WED");
			break;
		case THURSDAY:
			strcpy(day_str, "THU");
			break;
		case FRIDAY:
			strcpy(day_str, "FRI");
			break;
		case SATURDAY:
			strcpy(day_str, "SAT");
			break;
		case SUNDAY:
			strcpy(day_str, "SUN");
			break;
		default:
			strcpy(day_str, "XXX");
			break;
		}
//	LCD_dev->cursor(LCD_dev, x, y);
//	LCD_dev->string(LCD_dev, day_str);
}

void draw_date( uint8_t x, uint8_t y, uint8_t date)
{
	char date_str[2];
//	sprintf(date_str, "%2d", date);
//	LCD_dev->cursor(LCD_dev, x, y);
//	LCD_dev->string(LCD_dev, date_str);
}

void draw_month( uint8_t x, uint8_t y, MONTHS_e month)
{
	char month_str[3];

	switch(month){
		case JANUARY:
			strcpy(month_str, "JAN");
			break;
		case FEBUARY:
			strcpy(month_str, "FEB");
			break;
		case MARCH:
			strcpy(month_str, "MAR");
			break;
		case APRIL:
			strcpy(month_str, "APR");
			break;
		case MAY:
			strcpy(month_str, "MAY");
			break;
		case JUNE:
			strcpy(month_str, "JUN");
			break;
		case JULY:
			strcpy(month_str, "JUL");
			break;
		case AUGUST:
			strcpy(month_str, "AUG");
			break;
		case SEPTERMBER:
			strcpy(month_str, "SEP");
			break;
		case OCTOBER:
			strcpy(month_str, "OCT");
			break;
		case NOVEMBER:
			strcpy(month_str, "NOV");
			break;
		case DECEMBER:
			strcpy(month_str, "DEC");
			break;
		default:
			break;
		}

//	LCD_dev->cursor(LCD_dev, x, y);
//	LCD_dev->string(LCD_dev, month_str);
}

void draw_year( uint8_t x, uint8_t y, uint16_t year)
{
//	char year_str[4];
//	sprintf(year_str, "%4d", year);
//	LCD_dev->cursor(LCD_dev, x, y);
//	LCD_dev->string(LCD_dev, year_str);
}

void draw_time(uint8_t x, uint8_t y)
{
//	char time_str[] = "12:59:59";
//	LCD_dev->cursor(LCD_dev, x, y);
//	sprintf(time_str, "%02d:%02d:%02d", RTC_dev->time_1->hour,
//			RTC_dev->time_1->min, RTC_dev->time_1->sec);
//	LCD_dev->string(LCD_dev, time_str);
//
//	if(RTC_dev->time_1->twelve_hour)
//			draw_am_pm( x + 90, y , RTC_dev->time_1->pm);
//
//	draw_day( x , y + 20, RTC_dev->time_1->week_day);
//	draw_date( x + 35, y + 20, RTC_dev->time_1->date);
//	draw_month( x + 65, y + 20, RTC_dev->time_1->month);
//	draw_year( x, y + 40, RTC_dev->time_1->year);
}

void draw_alarm( uint8_t x, uint8_t y, TYPE_TIME_t alarm)
{

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


void draw_disp_alarm2_state(uint8_t x, uint8_t y)
{
//	RTC_dev->get_alarm(RTC_dev, ALARM_TWO);
//	draw_alarm(x+10, y+5, ALARM_TWO);
//	if(RTC_dev->alarm_2->twelve_hour)
//		draw_am_pm(x + 100, y + 5, RTC_dev->alarm_2->pm);
//
//	draw_day( x + 10, y + 25, RTC_dev->alarm_2->week_day);
//	draw_date( x + 50, y + 25, RTC_dev->alarm_2->date);
}

//TODO remove dependency on retrieving time a second time
void draw_set_states( uint8_t x, uint8_t y)
{
//	LCD_dev->cursor(LCD_dev, x + 25, y + 5);
//	switch(render_state){
//	case SET_TIME:{
//
//		char* disp_str = "SET";
//		LCD_dev->cursor(LCD_dev, x + 90, y + 45);
//		LCD_dev->string(LCD_dev, disp_str);
//
//		if(blink_flag && (set_state == SETTING_DIGIT)){
//			draw_time_blink(x + 10, y + 5, TIME, set_target);
//		}else if(set_state == SETTING_MOVE){
//			draw_time_blink(x + 10, y + 5, TIME, set_target);
//		}else{
//			draw_time( x + 10, y + 5);
//		}
//		break;
//	}
//	case SET_ALARM1:{
//
//		char* disp_str = "SET 1";
//		LCD_dev->cursor(LCD_dev, x + 70, y + 45);
//		LCD_dev->string(LCD_dev, disp_str);
//
//		if(blink_flag && (set_state == SETTING_DIGIT)){
//			draw_time_blink( x + 10, y + 5, ALARM_ONE, set_target);
//		}else if(set_state == NOT_SETTING){
//			draw_time_blink( x + 10, y + 5, ALARM_ONE, set_target);
//		}else{
//			draw_alarm( x + 10, y + 5, ALARM_ONE);
//		}
//		break;
//	}
//	case SET_ALARM2:{
//		char* disp_str = "SET 2";
//		LCD_dev->cursor(LCD_dev, x + 70, y + 45);
//		LCD_dev->string(LCD_dev, disp_str);
//
//		if(blink_flag && (set_state == SETTING_DIGIT)){
//			draw_time_blink( x + 10, y + 5, ALARM_TWO, set_target);
//		}else if(set_state == NOT_SETTING){
//			draw_time_blink( x + 10, y + 5, ALARM_TWO, set_target);
//		}else{
//			draw_alarm( x + 10, y + 5, ALARM_TWO);
//		}
//		break;
//	}
//	default:
//		break;
//	}

//	LCD_dev->cursor(LCD_dev, x + 65, y + 45);
//
//	switch(set_target){
//	case SET_HOUR:
//		LCD_dev->string(LCD_dev, "hour");
//		break;
//	case SET_MIN:
//		LCD_dev->string(LCD_dev, "min");
//		break;
//	case SET_SEC:
//		LCD_dev->string(LCD_dev, "sec");
//		break;
//	case SET_PM:
//		LCD_dev->string(LCD_dev, "pm");
//		break;
//	case SET_DAY:
//		LCD_dev->string(LCD_dev, "day");
//		break;
//	case SET_DATE:
//		LCD_dev->string(LCD_dev, "date");
//		break;
//	case SET_MONTH:
//		LCD_dev->string(LCD_dev, "month");
//		break;
//	case SET_YEAR:
//		LCD_dev->string(LCD_dev, "year");
//		break;
//	case SET_DATE_OR_DAY:
//		LCD_dev->string(LCD_dev, "date/day");
//		break;
//	case SET_ALARM_TYPE:
//		LCD_dev->string(LCD_dev, "al type");
//		break;
//	case SET_TWELVE_HOUR:
//		LCD_dev->string(LCD_dev, "twelve");
//		break;
//	default:
//		break;
//	}
}

void draw_time_blink( uint8_t x, uint8_t y,TYPE_TIME_t type,
		SET_TARGET_t blink_target)
{
	char time_str[] = "12:59:59";
	uint8_t sec = 0, min = 0, hour = 0;

	sprintf(time_str, "%02d:%02d:%02d", hour, min, sec);

//	if(type == ALARM_ONE){
//		draw_alarm(x,y, ALARM_ONE);
//		sec = RTC_dev->alarm_1->sec;
//		min = RTC_dev->alarm_1->min;
//		hour = RTC_dev->alarm_1->hour;
//	}else if(type == ALARM_TWO){
//		draw_alarm(x,y, ALARM_TWO);
//		sec = 0;
//		min = RTC_dev->alarm_2->min;
//		hour = RTC_dev->alarm_2->hour;
//	}else if(type == TIME){
//		draw_time(x, y);
//		sec = RTC_dev->time_1->sec;
//		min = RTC_dev->time_1->min;
//		hour = RTC_dev->time_1->hour;
//	}

//	switch(blink_target){
//	case SET_HOUR:
//		sprintf(time_str, "--:%02d:%02d", min, sec);
//		LCD_dev->cursor(LCD_dev, x, y);
//		LCD_dev->string(LCD_dev, time_str);
//		break;
//	case SET_MIN:
//		sprintf(time_str, "%02d:--:%02d", hour, sec);
//		LCD_dev->cursor(LCD_dev, x, y);
//		LCD_dev->string(LCD_dev, time_str);
//		break;
//	case SET_SEC:
//		sprintf(time_str, "%02d:%02d:--", hour, min);
//		LCD_dev->cursor(LCD_dev, x, y);
//		LCD_dev->string(LCD_dev, time_str);
//		break;
//	case SET_DAY:{
//		char* day_str = "---";
//		LCD_dev->cursor(LCD_dev, x, y + 20);
//		LCD_dev->string(LCD_dev, day_str);
//		}
//		break;
//	case SET_DATE:{
//		char* date_str = "--";
//		LCD_dev->cursor(LCD_dev, x + 35, y + 20);
//		LCD_dev->string(LCD_dev, date_str);
//		}
//		break;
//	case SET_MONTH:{
//		char* month_str = "---";
//		LCD_dev->cursor(LCD_dev, x + 65, y + 20);
//		LCD_dev->string(LCD_dev, month_str);
//		}
//		break;
//	case SET_YEAR:{
//		char* year_str = "----";
//		LCD_dev->cursor(LCD_dev, x, y + 40);
//		LCD_dev->string(LCD_dev, year_str);
//		}
//		break;
//	case SET_PM:{
//		char* pm_str = "--";
//		LCD_dev->cursor(LCD_dev, x + 90, y);
//		LCD_dev->string(LCD_dev, pm_str);
//		}
//		break;
//	default:
//		break;
//	}
}

//char* get_time_string(ds3231_time_t* time){
//	static char time_str[9];
//
//	sprintf(time_str, "%d:%d:%d", time->hour, time->min, time->sec);
//
//	return time_str;
//}


//STATES
//TIME
unsigned char draw_time_init(void){

	return 0;
}

void draw_time_enter(void){

}

void draw_time_run(void){

}

void draw_time_exit(void){

}

//SET TIME
unsigned char draw_set_time_init(void){

	return 0;
}

void draw_set_time_enter(void){

}

void draw_set_time_run(void){

}

void draw_set_time_exit(void){

}

//SET ALARM 1
unsigned char draw_alarm1_init(void){

	return 0;
}

void draw_alarm1_enter(void){

}

void draw_alarm1_run(void){

}

void draw_alarm1_exit(void){

}

//SET ALARM 2
unsigned char draw_alarm2_init(void){

	return 0;
}

void draw_alarm2_enter(void){

}

void draw_alarm2_run(void){

}

void draw_alarm2_exit(void){

}



