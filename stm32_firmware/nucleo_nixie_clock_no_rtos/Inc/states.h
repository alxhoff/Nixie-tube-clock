/*
 * states.h
 *
 *  Created on: Sep 13, 2017
 *      Author: alxhoff
 */

#ifndef STATES_H_
#define STATES_H_

//STATES
typedef enum{
	state_time = 0,
	state_time_set = 1,
	state_time_set_min = 2,
	state_time_set_hour = 3,
#ifdef SCREEN_ON
	state_time_set_sec = 4,
	state_time_set_date = 5,
	state_time_set_month = 6,
	state_time_set_year = 7,
	state_time_set_day = 8,
	state_alarm_1_set = 9,
	state_alarm_1_set_min = 10,
	state_alarm_1_set_hour = 11,
	state_alarm_1_set_day = 12,
#endif
} state_e;

unsigned char states_init(void);
unsigned char states_run(void);
void *get_state_data(void);
void set_state_data(void *data);
void states_set_input(unsigned char input);
unsigned char states_get_state(void);
void states_set_state(unsigned char state);
unsigned char states_get_input(void);
void states_clear_input(void);

#endif /* STATES_H_ */
