/*
 * states.c
 *
 *  Created on: 21 Jan 2019
 *      Author: alxhoff
 */

#include "states.h"
#include "config.h"

//states
#include "draw.h"

#include <string.h>
#include <stdlib.h>

typedef struct state state_t;
struct state {
	unsigned char id;
	unsigned char initd;

	struct state_ops *ops;
};

typedef struct state_machine {
	state_t *current_state;
	state_t *next_state;

	unsigned char input;

	state_t **states;
	unsigned char state_count;
} state_machine_t;

state_machine_t sm = { 0 };

void states_set_input(unsigned char input)
{
	sm.input = input;
}

unsigned char states_get_input(void)
{
	return sm.input;
}

void states_clear_input(void)
{
	sm.input = 0;
}

static state_t *states_get_state(unsigned char id)
{
	static unsigned int i;

	for (i = 0; i < sm.state_count; i++)
		if (sm.states[i]->id == id)
			return sm.states[i];

	return NULL;
}

void *states_get_data(void)
{
	if (sm.current_state->ops)
		return sm.current_state->ops->data;

	return NULL;
}

void states_set_state(unsigned char state_id)
{
	state_t *next_state = states_get_state(state_id);

	if (next_state)
		sm.next_state = next_state;
}

unsigned char states_run(void)
{
	// Handle input
	if (sm.input) {
		//only handle one input ever, keep it simple
		if (((sm.input >> 0) & 0x01) &&
		    sm.current_state->ops->left_button)
			(sm.current_state->ops->left_button)();
		else if (((sm.input >> 1) & 0x01) &&
			 sm.current_state->ops->center_button)
			(sm.current_state->ops->center_button)();
		else if (((sm.input >> 2) & 0x01) &&
			 sm.current_state->ops->right_button)
			(sm.current_state->ops->right_button)();

		states_clear_input();
	}

	// Handle state change
	if (sm.next_state != sm.current_state) {
		if (sm.current_state->ops->exit) /* Exit current state*/
			(sm.current_state->ops->exit)();

		sm.current_state = sm.next_state; /* Change states*/

		if (sm.current_state->ops->enter) /* Enter next state*/
			(sm.current_state->ops->enter)();
	}

	// Run current state
	if (sm.current_state->ops->run) /* Run current state*/
		(sm.current_state->ops->run)();

	return 0;
}

static unsigned char states_add(unsigned char id, struct state_ops *ops)
{
	if (ops == NULL)
		return -1;

	state_t *ret = calloc(1, sizeof(state_t));
	if (!ret)
		return -1;

	ret->ops = ops;
	ret->id = id;

	sm.states =
		realloc(sm.states, sizeof(state_t *) * (sm.state_count + 1));
	sm.states[sm.state_count] = ret;
	sm.state_count++;

	if (ret->ops->probe)
		ret->ops->probe();

	ret->initd = 1;

	return 0;
}

// Static state structures
#include "user_states.h"

#define SET_INITIAL_STATE(STATE)                                               \
	sm.current_state = states_get_state(STATE);                            \
	sm.next_state = states_get_state(STATE);

void states_init(void)
{
	//send state
	states_add(state_time, &state_show_time);
	states_add(state_time_set_hour, &state_set_time_hour);
	states_add(state_time_set_min, &state_set_time_mins);
#ifdef SCREEN_ON
	states_add(state_time_set_sec, &state_set_time_secs);
	states_add(state_time_set_date, &state_set_time_date);
	states_add(state_time_set_month, &state_set_time_month);
	states_add(state_time_set_year, &state_set_time_year);
	states_add(state_time_set_day, &state_set_time_day);
	states_add(state_alarm_1_set, &state_show_alarm_1_set);
	states_add(state_alarm_1_set_min, &state_show_alarm_1_set_hour);
	states_add(state_alarm_1_set_hour, &state_show_alarm_1_set_min);
	states_add(state_alarm_1_set_day, &state_show_alarm_1_set_day);
#endif

	//set initial state
	SET_INITIAL_STATE(state_time);
}
