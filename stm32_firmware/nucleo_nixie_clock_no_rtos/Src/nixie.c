/*
 * nixie.c
 *
 *  Created on: Oct 6, 2017
 *      Author: alxhoff
 */

#include <stdlib.h>
#include <string.h>

#include "nixie.h"
#include "config.h"

typedef struct nixie_tube nixie_tube_t;

struct nixie_tube {
	unsigned char value;

	unsigned char enabled;
};

typedef struct nixie_tube_array {
	unsigned char count;

	nixie_tube_t tubes[NIXIE_DEVICES];

	unsigned short mask;
	unsigned char uncompiled_output[NIXIE_DEVICES];
	unsigned char output[CHECK_ODD(NIXIE_DEVICES)];
} nixie_tube_array_t;

nixie_tube_array_t nixie_dev = { 0 };

unsigned char nixie_bcd_to_dec(unsigned char bcd) {
	return (1 << ((bcd / 16 * 10) + (bcd % 16)));
}

void nixie_enable_mask(unsigned long mask) {
	unsigned long temp = mask;
	for (unsigned char i = 0; i < NIXIE_DEVICES; i++) {
		nixie_dev.tubes[i].enabled = temp & 1;
		temp = temp >> 1;
	}
}

void nixie_enable_tube(unsigned char index) {
	nixie_dev.tubes[index].enabled = 1;
}

void nixie_disable_tube(unsigned char index) {
	nixie_dev.tubes[index].enabled = 0;
}

void nixie_enable_all(void) {
	for (unsigned char i = 0; i < NIXIE_DEVICES; i++)
		nixie_enable_tube(i);
}

void nixie_disable_all(void) {
	for (unsigned char i = 0; i < NIXIE_DEVICES; i++)
		nixie_disable_tube(i);
}

void nixie_set_tube(unsigned char index, unsigned char value) {
	if (value >= 0 && value <= 9)
		nixie_dev.tubes[index].value = value;
}

void nixie_set_tubes(unsigned char* data) {
	for (unsigned char i = 0; i < NIXIE_DEVICES; i++) {
		memcpy(&(nixie_dev.tubes[i].value), &data[i], sizeof(unsigned char));
	}
}

unsigned char nixie_split_set_digit(volatile unsigned char input, unsigned char index) {
	if(index + 1 >= NIXIE_DEVICES)
		return -1;

	nixie_set_tube(index + 1, input / 10);
	nixie_set_tube(index, input % 10);

	return 0;
}

unsigned char *nixie_compile_output(void) {
	for (unsigned char i = 0; i < NIXIE_DEVICES; i++) {
		if (i % 2 == 0)
			nixie_dev.output[i / 2] = nixie_dev.tubes[i].value;
		else
			nixie_dev.output[i / 2] |= (nixie_dev.tubes[i].value << 4);
	}
	return &nixie_dev.output[0];
}

signed char nixie_init(void) {

	nixie_dev.mask = 0xFF *  NIXIE_DEVICES;

	return 0;
}
