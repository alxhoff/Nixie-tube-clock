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
	state_time,
	state_time_set,
	state_time_set_sec,
	state_time_set_min,
	state_time_set_hour,
	state_time_set_date,
	state_time_set_month,
	state_time_set_year,
	state_time_set_day,
	state_alarm_1_set,
} state_e;

unsigned char states_init(void);
unsigned char states_run(void);
void *get_state_data(void);
void set_state_data(void *data);

#endif /* STATES_H_ */
