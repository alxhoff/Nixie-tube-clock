/*
 * states.h
 *
 *  Created on: Sep 13, 2017
 *      Author: alxhoff
 */

#ifndef STATES_H_
#define STATES_H_

#include "config.h"

struct state_ops {
	void *data; // data used with state ops

	void (*left_button)(void);
	void (*center_button)(void);
	void (*right_button)(void);

	void (*probe)(void);
	void (*enter)(void);
	void (*run)(void);
	void (*exit)(void);
};

void states_init(void);
unsigned char states_run(void);
void *get_state_data(void);
void states_set_input(unsigned char input);
void states_set_state(unsigned char state);
unsigned char states_get_input(void);
void states_clear_input(void);

#endif /* STATES_H_ */
