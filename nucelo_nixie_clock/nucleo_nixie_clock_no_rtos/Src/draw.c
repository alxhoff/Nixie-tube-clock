/*
 * draw.c
 *
 *  Created on: Aug 8, 2017
 *      Author: alxhoff
 */

#include "draw.h"
#include "externs.h"

//STATES
void draw_disp_time_state(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y,
		ds3231_time_t* time)
{
	DS3231_get_time(&hi2c2, time);
	draw_time(&hi2c2, x + 10, y + 5, time);
	if(time->twelve_hour){
		draw_am_pm(&hi2c2, x + 100, y + 5, time->pm);
	}
	draw_day(&hi2c2, x + 4, y + 25, time->week_day);
	draw_date(&hi2c2, x + 35, y + 25, time->date);
	draw_month(&hi2c2, x + 65, y + 25, time->month);
	draw_year(&hi2c2, x + 45, y + 45, time->year);
}

void draw_disp_alarm1_state(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y,
		ds3231_alarm_t* alarm)
{
	DS3231_get_alarm(&hi2c2, alarm, ALARM_ONE);
	draw_alarm(&hi2c2, x+10, y+5, alarm);
	if(alarm->twelve_hour){
		draw_am_pm(&hi2c2, x + 100, y + 5, alarm->pm);
	}
	draw_day(&hi2c2, x + 4, y + 25, alarm->week_day);
	draw_date(&hi2c2, x + 35, y + 25, alarm->date);

}

//void draw_set_states(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y,
//		void* timeStruct)
//{
//	ssd1306_SetCursor(23,5);
//	switch(render_state){
//	case SET_TIME:{
//		ds3231_time_t* time = (ds3231_time_t*)timeStruct;
//		if(xSemaphoreTake(set_blink_semaphoreHandle, 10)){
//			draw_time(hi2c, x + 10, y + 5, timeStruct);
//		}else{
//			draw_time_blink(hi2c, x + 10, y + 5, timeStruct, set_state);
//		}
//		break;
//	}
//	case SET_ALARM1:{
//		ds3231_alarm_t* time = (ds3231_alarm_t*)timeStruct;
//		if(xSemaphoreTake(set_blink_semaphoreHandle, 10)){
//			draw_alarm(hi2c, x + 10, y + 5, timeStruct);
//		}else{
//			draw_alarm_blink(hi2c, x + 10, y + 5, timeStruct, set_state);
//		}
//		break;
//	}
//	case SET_ALARM2:{
//		ds3231_alarm_t* time = (ds3231_alarm_t*)timeStruct;
//		if(xSemaphoreTake(set_blink_semaphoreHandle, 10)){
//			draw_alarm(hi2c, x + 10, y + 5, timeStruct);
//		}else{
//			draw_alarm_blink(hi2c, x + 10, y + 5, timeStruct, set_state);
//		}
//		break;
//	}
//	default:
//		break;
//	}
//
//	ssd1306_SetCursor(23,35);
//
//	switch(set_state){
//	case SET_HOUR:
//		ssd1306_WriteString("hour",Font_11x18,Black);
//		break;
//	case SET_MIN:
//		ssd1306_WriteString("min",Font_11x18,Black);
//		break;
//	case SET_SEC:
//		ssd1306_WriteString("sec",Font_11x18,Black);
//		break;
//	case SET_PM:
//		ssd1306_WriteString("pm",Font_11x18,Black);
//		break;
//	case SET_DAY:
//		ssd1306_WriteString("day",Font_11x18,Black);
//		break;
//	case SET_DATE:
//		ssd1306_WriteString("date",Font_11x18,Black);
//		break;
//	case SET_MONTH:
//		ssd1306_WriteString("month",Font_11x18,Black);
//		break;
//	case SET_YEAR:
//		ssd1306_WriteString("year",Font_11x18,Black);
//		break;
//	case SET_DATE_OR_DAY:
//		ssd1306_WriteString("date/day",Font_11x18,Black);
//		break;
//	case SET_ALARM_TYPE:
//		ssd1306_WriteString("al type",Font_11x18,Black);
//		break;
//	case SET_TWELVE_HOUR:
//		ssd1306_WriteString("twelv",Font_11x18,Black);
//		break;
//	default:
//		break;
//	}
//}

void draw_alarm_blink(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, ds3231_alarm_t* alarm, BLINK_TIME blink){
	char time_str[] = "12:59:59";
	ssd1306_SetCursor(x, y);
	switch(blink){
	case BLINK_HOUR:
		sprintf(time_str, "--:%d:%d", alarm->min, alarm->sec);
		break;
	case BLINK_MINUTE:
		sprintf(time_str, "%d:--:%d", alarm->hour, alarm->sec);
		break;
	case BLINK_SEC:
		sprintf(time_str, "%d:%d:--", alarm->hour, alarm->min);
		break;
	case BLINK_PM:
		break;
	default:
		break;
	}
	ssd1306_WriteString(time_str,Font_11x18,Black);
}

void draw_alarm(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, ds3231_alarm_t* alarm){
	char time_str[] = "12:59:59";
	ssd1306_SetCursor(x, y);
	sprintf(time_str, "%d:%d:%d", alarm->hour, alarm->min, alarm->sec);
	ssd1306_WriteString(time_str,Font_11x18,Black);
}

void draw_time_blink(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, ds3231_time_t* time, BLINK_TIME blink){
	char time_str[9];
	ssd1306_SetCursor(x, y);
	switch(blink){
	case BLINK_HOUR:
		sprintf(time_str, "--:%d:%d", time->min, time->sec);
		break;
	case BLINK_MINUTE:
		sprintf(time_str, "%d:--:%d", time->hour, time->sec);
		break;
	case BLINK_SEC:
		sprintf(time_str, "%d:%d:--", time->hour, time->min);
		break;
	case BLINK_PM:
		break;
	default:
		break;
	}
	ssd1306_WriteString(time_str,Font_11x18,Black);
}

void draw_time(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, ds3231_time_t* time)
{
	char time_str[] = "12:59:59";
	ssd1306_SetCursor(x, y);
	sprintf(time_str, "%d:%d:%d", time->hour, time->min, time->sec);
	ssd1306_WriteString(time_str,Font_11x18,Black);
}

char* get_time_string(ds3231_time_t* time){
	static char time_str[9];

	sprintf(time_str, "%d:%d:%d", time->hour, time->min, time->sec);

	return time_str;
}


void draw_am_pm(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, TIME_OF_DAY_12HR_t pm)
{
	ssd1306_SetCursor(x, y);
	if(pm == PM){
		ssd1306_WriteString("PM",Font_11x18,Black);
	}else{
		ssd1306_WriteString("AM",Font_11x18,Black);
	}
}

void draw_date(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, uint8_t date)
{
	char date_str[2];
	sprintf(date_str, "%2d", date);
	ssd1306_SetCursor(x, y);
	ssd1306_WriteString(date_str,Font_11x18,Black);
}

void draw_year(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, uint16_t year)
{
	char year_str[4];
	sprintf(year_str, "%4d", year);
	ssd1306_SetCursor(x, y);
	ssd1306_WriteString(year_str,Font_11x18,Black);
}

void draw_month(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, months month)
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
		}

	ssd1306_SetCursor(x, y);
	ssd1306_WriteString(month_str,Font_11x18,Black);
}

void draw_day(I2C_HandleTypeDef *hi2c, uint8_t x, uint8_t y, DAYS_t day){
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
			break;
		}

	ssd1306_SetCursor(x, y);
	ssd1306_WriteString(day_str,Font_11x18,Black);
}

