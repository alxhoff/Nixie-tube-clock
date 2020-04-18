/*
 * user_states.h
 *
 *  Created on: 17 Apr 2020
 *      Author: alxhoff
 */

#ifndef USER_STATES_H_
#define USER_STATES_H_

#include "RTC_dev.h"
// Button config
// Left button: changes big state: show time -> set time -> set alarm
// Center button: changes state inside the the big state, ie. set time will start blinking the hours
// and the next press will move to the minutes
// Right button: Increases the value of an item if in a set state

//STATES
typedef enum{
	state_time,
	state_time_set_hour,
	state_time_set_min,
#ifdef NIXIE_SET
	state_time_set_sec,
	state_time_set_date,
	state_time_set_month,
	state_time_set_year,
	state_time_set_day,
	state_alarm_1_set,
	state_alarm_1_set_min,
	state_alarm_1_set_hour,
	state_alarm_1_set_day,
#endif
} state_e;

#define DRAW_DEFAULT_TIME draw_get_and_draw_time(-1, -1, -1, -1, -1, -1, -1)
#define DRAW_TIME_W_HOUR(hour) draw_get_and_draw_time(hour, -1, -1, -1, -1, -1, -1)
#define DRAW_TIME_W_MIN(min) draw_get_and_draw_time(-1, min, -1, -1, -1, -1, -1)
#define DRAW_TIME_W_SEC(sec) draw_get_and_draw_time(-1, -1, sec, -1, -1, -1, -1)
#define DRAW_TIME_W_WEEKDAY(weekday) draw_get_and_draw_time(-1, -1, -1, weekday, -1, -1, -1)
#define DRAW_TIME_W_DATE(date) draw_get_and_draw_time(-1, -1, -1, -1, date, -1, -1)
#define DRAW_TIME_W_MONTH(month) draw_get_and_draw_time(-1, -1, -1, -1, -1, month, -1)
#define DRAW_TIME_W_YEAR(year) draw_get_and_draw_time(-1, -1, -1, -1, -1, -1, year)
/* ================================ SHOW TIME ============================== */
/*
 * Main time screen, during run the state should retrieve the time with each
 * TIM3 interrupt and update the value on the screen
 */
void state_show_time_lb(void){
	states_set_state(state_time_set_hour);
}

void state_show_time_run(void){
	DRAW_DEFAULT_TIME;
}
struct state_ops state_show_time = {
	.data = NULL,

	.left_button = state_show_time_lb,
	.center_button = NULL,
	.right_button = NULL,

	.probe = NULL,
	.enter = NULL,
	.run = state_show_time_run,
	.exit = NULL,
};
/* ================================ SET TIME HOUR ============================== */
/*
 * Upon entering an hour value should be taken which is stored as an int in the states data.
 * This value is incremented and displayed during the state and then saved when leaving the state.
 * This is applied to all members of set time.
 */
static unsigned int state_set_time_hour_data = 0;

void state_set_time_hour_lb(void){
#ifdef NIXIE_SET
	states_set_state(state_alarm_1_set);
#else
	states_set_state(state_time);
#endif // NIXIE_SET
}

void state_set_time_hour_cb(void){
	states_set_state(state_time_set_min);
}

void state_set_time_hour_rb(void){
	unsigned int *hour = (unsigned int *)states_get_data();
	(*hour) %= 12;
	(*hour) += 1;
}

void state_set_time_hour_enter(void){
	unsigned int *hour = (unsigned int *)states_get_data();
	*hour = RTC_dev_time_get_hour();
}

void state_set_time_hour_run(void){
	unsigned int *hour = (unsigned int *)states_get_data();
	DRAW_TIME_W_HOUR(*hour);
}

void state_set_time_hour_exit(void){
	unsigned int *hour = (unsigned int *)states_get_data();
	RTC_dev_time_set_hour(*hour);
}

struct state_ops state_set_time_hour = {
	.data = &state_set_time_hour_data,

	.left_button = state_set_time_hour_lb,
	.center_button = state_set_time_hour_cb,
	.right_button = state_set_time_hour_rb,

	.probe = NULL,
	.enter = state_set_time_hour_enter,
	.run = state_set_time_hour_run,
	.exit = state_set_time_hour_exit,
};
/* ================================ SET TIME MIN ============================== */
static unsigned int state_set_time_mins_data = 0;

void state_set_time_mins_lb(void){
#ifdef NIXIE_SET
	states_set_state(state_alarm_1_set);
#else
	states_set_state(state_time);
#endif // NIXIE_SET
}

void state_set_time_mins_cb(void){
#ifdef NIXIE_SET
	states_set_state(state_time_set_sec);
#else
	states_set_state(state_time_set_hour);
#endif // NIXIE_SET
}

void state_set_time_mins_rb(void){
	unsigned int *mins = (unsigned int *)states_get_data();
	(*mins) %= 60;
	(*mins) += 1;
}

void state_set_time_mins_enter(void){
	unsigned int *mins = (unsigned int *)states_get_data();
	*mins = RTC_dev_time_get_min();
}

void state_set_time_mins_run(void){
	unsigned int *mins = (unsigned int *)states_get_data();
	DRAW_TIME_W_MIN(*mins);
}

void state_set_time_mins_exit(void){
	unsigned int *mins = (unsigned int *)states_get_data();
	RTC_dev_time_set_min(*mins);
}

struct state_ops state_set_time_mins = {
	.data = &state_set_time_mins_data,

	.left_button = state_set_time_mins_lb,
	.center_button = state_set_time_mins_cb,
	.right_button = state_set_time_mins_rb,

	.probe = NULL,
	.enter = state_set_time_mins_enter,
	.run = state_set_time_mins_run,
	.exit = state_set_time_mins_exit,
};
#ifdef NIXIE_SET
/* ================================ SET TIME SEC============================== */
static unsigned int state_set_time_secs_data = 0;

void state_set_time_secs_lb(void){
#ifdef NIXIE_SET
	states_set_state(state_alarm_1_set);
#else
	states_set_state(state_time);
#endif // NIXIE_SET
}

void state_set_time_secs_cb(void){
	states_set_state(state_time_set_date);
}

void state_set_time_secs_rb(void){
	unsigned int *secs = (unsigned int *)states_get_data();
	(*secs) %= 60;
	(*secs) += 1;
}

void state_set_time_secs_enter(void){
	unsigned int *secs = (unsigned int *)states_get_data();
	*secs = RTC_dev_time_get_sec();
}

void state_set_time_secs_run(void){
	unsigned int *secs = (unsigned int *)states_get_data();
	DRAW_TIME_W_SEC(*secs);
}

void state_set_time_secs_exit(void){
	unsigned int *secs = (unsigned int *)states_get_data();
	RTC_dev_time_set_sec(*secs);
}

struct state_ops state_set_time_secs = {
	.data = &state_set_time_secs_data,

	.left_button = state_set_time_secs_lb,
	.center_button = state_set_time_secs_cb,
	.right_button = state_set_time_secs_rb,

	.probe = NULL,
	.enter = state_set_time_secs_enter,
	.run = state_set_time_secs_run,
	.exit = state_set_time_secs_exit,
};
/* ================================ SET TIME DATE============================== */
static unsigned int state_set_time_date_data = 0;

void state_set_time_date_lb(void){
#ifdef NIXIE_SET
	states_set_state(state_alarm_1_set);
#else
	states_set_state(state_time);
#endif // NIXIE_SET
}

void state_set_time_date_cb(void){
	states_set_state(state_time_set_month);
}

void state_set_time_date_rb(void){
	unsigned int *date = (unsigned int *)states_get_data();
	(*date) %= 31;
	(*date) += 1;
}

void state_set_time_date_enter(void){
	unsigned int *date = (unsigned int *)states_get_data();
	*date = RTC_dev_time_get_date();
}

void state_set_time_date_run(void){
	unsigned int *date = (unsigned int *)states_get_data();
	DRAW_TIME_W_DATE(*date);
}

void state_set_time_date_exit(void){
	unsigned int *date = (unsigned int *)states_get_data();
	RTC_dev_time_set_date(*date);
}

struct state_ops state_set_time_date = {
	.data = &state_set_time_date_data,

	.left_button = state_set_time_date_lb,
	.center_button = state_set_time_date_cb,
	.right_button = state_set_time_date_rb,

	.probe = NULL,
	.enter = state_set_time_date_enter,
	.run = state_set_time_date_run,
	.exit = state_set_time_date_exit,
};
/* ================================ SET TIME MONTH============================== */
static unsigned int state_set_time_month_data = 0;

void state_set_time_month_lb(void){
#ifdef NIXIE_SET
	states_set_state(state_alarm_1_set);
#else
	states_set_state(state_time);
#endif // NIXIE_SET
}

void state_set_time_month_cb(void){
	states_set_state(state_time_set_year);
}

void state_set_time_month_rb(void){
	unsigned int *month =(unsigned int *)states_get_data();
	(*month) %= 12;
	(*month) += 1;
}

void state_set_time_month_enter(void){
	unsigned int *month =(unsigned int *)states_get_data();
	*month = RTC_dev_time_get_month();
}

void state_set_time_month_run(void){
	unsigned int *month =(unsigned int *)states_get_data();
	DRAW_TIME_W_MONTH(*month);
}

void state_set_time_month_exit(void){
	unsigned int *month =(unsigned int *)states_get_data();
	RTC_dev_time_set_month(*month);
}

struct state_ops state_set_time_month = {
	.data = &state_set_time_month_data,

	.left_button = state_set_time_month_lb,
	.center_button = state_set_time_month_cb,
	.right_button = state_set_time_month_rb,

	.probe = NULL,
	.enter = state_set_time_month_enter,
	.run = state_set_time_month_run,
	.exit = state_set_time_month_exit,
};
/* ================================ SET TIME YEAR============================== */
static unsigned int state_set_time_year_data = 0;

void state_set_time_year_lb(void){
#ifdef NIXIE_SET
	states_set_state(state_alarm_1_set);
#else
	states_set_state(state_time);
#endif // NIXIE_SET
}

void state_set_time_year_cb(void){
	states_set_state(state_time_set_day);
}

void state_set_time_year_rb(void){
	unsigned int *year = (unsigned int *)states_get_data();
	(*year)++;
}

void state_set_time_year_enter(void){
	unsigned int *year = (unsigned int *)states_get_data();
	*year = RTC_dev_time_get_year();
}

void state_set_time_year_run(void){
	unsigned int *year = (unsigned int *)states_get_data();
	DRAW_TIME_W_YEAR(*year);
}

void state_set_time_year_exit(void){
	unsigned int *year = (unsigned int *)states_get_data();
	RTC_dev_time_set_year(*year);
}

struct state_ops state_set_time_year = {
	.data = &state_set_time_year_data,

	.left_button = state_set_time_year_lb,
	.center_button = state_set_time_year_cb,
	.right_button = state_set_time_year_rb,

	.probe = NULL,
	.enter = state_set_time_year_enter,
	.run = state_set_time_year_run,
	.exit = state_set_time_year_exit,
};
/* ================================ SET TIME DAY============================== */
static unsigned int state_set_time_day_data = 0;

void state_set_time_day_lb(void){
#ifdef NIXIE_SET
	states_set_state(state_alarm_1_set);
#else
	states_set_state(state_time);
#endif // NIXIE_SET
}

void state_set_time_day_cb(void){
	states_set_state(state_time_set_hour);
}

void state_set_time_day_rb(void){
	unsigned int *day = (unsigned int *)states_get_data();
	(*day) %= 7;
	(*day) += 1;
}

void state_set_time_day_enter(void){
	unsigned int *day = (unsigned int *)states_get_data();
	*day = RTC_dev_time_get_weekday();
}

void state_set_time_day_run(void){
	unsigned int *day = (unsigned int *)states_get_data();
	DRAW_TIME_W_WEEKDAY(*day);
}

void state_set_time_day_exit(void){
	unsigned int *day = (unsigned int *)states_get_data();
	RTC_dev_time_set_day(*day);
}

struct state_ops state_set_time_day = {
	.data = &state_set_time_day_data,

	.left_button = state_set_time_day_lb,
	.center_button = state_set_time_day_cb,
	.right_button = state_set_time_day_rb,

	.probe = NULL,
	.enter = state_set_time_day_enter,
	.run = state_set_time_day_run,
	.exit = state_set_time_day_exit,
};
/* ================================ ALARM 1 SET============================== */
struct state_ops state_show_alarm_1_set = {
	.data = NULL,

	.left_button = NULL,
	.center_button = NULL,
	.right_button = NULL,

	.probe = NULL,
	.enter = NULL,
	.run = NULL,
	.exit = NULL,
};
/* ================================ ALARM 1 SET HOUR============================== */
struct state_ops state_show_alarm_1_set_hour = {
		.data = NULL,

	.left_button = NULL,
	.center_button = NULL,
	.right_button = NULL,

	.probe = NULL,
	.enter = NULL,
	.run = NULL,
	.exit = NULL,
};
/* ================================ ALARM 1 SET MIN ============================== */
struct state_ops state_show_alarm_1_set_min = {
		.data = NULL,

	.left_button = NULL,
	.center_button = NULL,
	.right_button = NULL,

	.probe = NULL,
	.enter = NULL,
	.run = NULL,
	.exit = NULL,
};
/* ================================ ALARM 1 SET DAY ============================== */
struct state_ops state_show_alarm_1_set_day = {
		.data = NULL,

	.left_button = NULL,
	.center_button = NULL,
	.right_button = NULL,

	.probe = NULL,
	.enter = NULL,
	.run = NULL,
	.exit = NULL,
};
#endif // NIXIE_SET
#endif /* USER_STATES_H_ */
