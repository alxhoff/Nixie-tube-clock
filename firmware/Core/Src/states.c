/*
 * states.c
 *
 *  Created on: Jun 2, 2022
 *      Author: alxhoff
 */
#include <stdlib.h>

#include "sm.h"
#include "states.h"
#include "rtc_dev.h"
#include "sn54hc595.h"
#include "nixie.h"
#include "buttons.h"

/*
 * If the seconds of the RTC are even Nixies should be disabled
 */
void statesBlinkNixies(void) {
	// Read seconds from RTC
	RTC_dev_get_time();
	// Read RTC seconds
	unsigned int seconds = RTC_dev_time_get_sec();

	// Set Nixie enable accordingly
	if (seconds % 2)
		nixieEnableAll();
	else
		nixieDisableAll();
}

/*
 * Allocate a temporary variable to store hours/mins when setting time
 */
void* statesBlinkingInit(void *data) {
	return calloc(1, sizeof(unsigned char));
}

/*
 * Free data
 */
void statesExitFreeData(void *data) {
	free(data);
}

void statesSettingDigit(unsigned char nixie_index, void *data,
		unsigned char mod, unsigned char next_state) {
	// Blink Nixies
	statesBlinkNixies();

	// Buttons pushes
	unsigned int buttons = buttonsGet();
	if (buttons & BUTTON_MASK_LEFT) {
		(*(unsigned char*) data)++;
	} else if (buttons & BUTTON_MASK_CENTER) {
		if (*(unsigned char*) data > 1)
			(*(unsigned char*) data)--;
	} else if (buttons & BUTTON_MASK_RIGHT) {
		smSetStates(next_state);
	}

	// Wrap numbers if needed
	*(unsigned char*) data %= mod;

	// Set value to Nixies
	nixieSetDoubleDigits(*(unsigned char*) data, nixie_index);
}

/*
 * State should blink hours while showing tmp value stored in data
 */
void statesHoursBlinkingRun(void *data) {
	statesSettingDigit(2, data, 24, STATE_MINUTES_BLINKING);
}

/*
 * State should save new hours value to RTC
 */
void statesHoursBlinkingExit(void *data) {
	// Store hours to RTC
	RTC_dev_time_set_hour(*(unsigned char*) data);

	// Switch to setting minutes state
	statesExitFreeData(data);
	smSetStates(STATE_MINUTES_BLINKING);
}

/*
 * State should blink minutes while showing tmp value stored in data
 */
void statesMinutesBlinkingRun(void *data) {
	statesSettingDigit(0, data, 60, STATE_SHOWING_TIME);
}

/*
 * State should save new minutes value to RTC
 */
void statesMinutesBlinkingExit(void *data) {
	// Store minutes to RTC
	RTC_dev_time_set_min(*(unsigned char*) data);

	// Set RTC seconds to zero
	RTC_dev_set_time_sec_zero();

	// Switch to showing time state
	statesExitFreeData(data);
	smSetStates(STATE_SHOWING_TIME);
}

struct time {
	unsigned char hours;
	unsigned char mins;
};

/*
 * Create required data
 */
void* statesShowTimeInit(void *data) {
	return calloc(1, sizeof(struct time));
}

void statesShowTimeEnter(void *data) {
	nixieEnableAll();
}

/*
 * Read time from RTC and show on Nixies
 */
void statesShowTimeRun(void *data) {
	// Read time from RTC
	RTC_dev_get_time();

	// Show time on Nixies
	nixieSetDoubleDigits(RTC_dev_time_get_hour(), 2);
	nixieSetDoubleDigits(RTC_dev_time_get_min(), 0);

	//Output to Nixies through shift registers
	SN54HC595_out_int(nixieCompileOutput());
}

unsigned int statesInit(void) {
	smAddState(STATE_HOURS_BLINKING, "Hours blinking", statesBlinkingInit,
	NULL, statesHoursBlinkingRun, statesExitFreeData, NULL);
	smAddState(STATE_MINUTES_BLINKING, "Minutes blinking", statesBlinkingInit,
	NULL, statesMinutesBlinkingRun, statesExitFreeData, NULL);
	smAddState(STATE_SHOWING_TIME, "Showing time", statesShowTimeInit,
			statesShowTimeEnter, statesShowTimeRun, NULL, NULL);

	return 0;
}

