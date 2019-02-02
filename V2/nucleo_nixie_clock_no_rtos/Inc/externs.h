/*
 * i2c.h
 *
 *  Created on: Aug 6, 2017
 *      Author: alxhoff
 */

#ifndef EXTERNS_H_
#define EXTERNS_H_

#include "ssd1306.h"
#include "ds3231.h"
#include "buttons.h"

extern I2C_HandleTypeDef hi2c2;

extern uint8_t blink_flag;

//BUTTONS
uint8_t button_input[NUM_OF_BUTTONS];
uint8_t button_last_state[NUM_OF_BUTTONS];
uint8_t button_current_state[NUM_OF_BUTTONS];
uint32_t button_last_time[NUM_OF_BUTTONS];
uint32_t debounce_delay;

#endif /* EXTERNS_H_ */
