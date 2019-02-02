/*
 * nixie.c
 *
 *  Created on: Oct 6, 2017
 *      Author: alxhoff
 */

#include <stdlib.h>
#include <string.h>

#include "config.h"

typedef struct nixie_tube nixie_tube_t;

struct nixie_tube {
	unsigned char value;

	unsigned char enabled;
};

typedef struct nixie_tube_array {
	unsigned char count;

	unsigned char* data_temp;

	nixie_tube_t** tubes;

	unsigned short mask;

	unsigned char* output;
} nixie_tube_array_t;

nixie_tube_array_t nixie_dev = { 0 };

unsigned char nixie_bcd_to_dec(unsigned char bcd) {
	return (1 << ((bcd / 16 * 10) + (bcd % 16)));
}

void nixie_enable_mask(unsigned long mask) {
	unsigned long temp = mask;
	for (unsigned char i = 0; i < nixie_dev.count; i++) {
		nixie_dev.tubes[i]->enabled = temp & 1;
		temp = temp >> 1;
	}
}

void nixie_enable_tube(unsigned char index) {
	nixie_dev.tubes[index]->enabled = 1;
}

void nixie_disable_tube(unsigned char index) {
	nixie_dev.tubes[index]->enabled = 0;
}

void nixie_enable_all(void) {
	for (unsigned char i = 0; i < nixie_dev.count; i++)
		nixie_enable_tube(i);
}

void nixie_disable_all(void) {
	for (unsigned char i = 0; i < nixie_dev.count; i++)
		nixie_disable_tube(i);
}

void nixie_set_tube(unsigned char index, unsigned char value) {
	if (value < 0 || value > 9)

	nixie_dev.tubes[index]->value = value;
}

void nixie_set_tubes(unsigned char* data) {
	for (unsigned char i = 0; i < (nixie_dev.count); i++) {
		memcpy(&(nixie_dev.tubes[i]->value), &data[i], sizeof(unsigned char));
	}
}

void nixie_split_digit(unsigned char input, unsigned char* output) {
	output[0] = input / 10;
	output[1] = input % 10;
}

signed char nixie_compile_output(nixie_tube_array_t* array) {
	if (nixie_dev.count) {
//		for(unsigned char i = 0; i < nixie_dev.count; i++){
//			if(nixie_dev.mask & (1 << (nixie_dev.count - i))){
//				if(i%2 == 0)
//					nixie_dev.output[i/2] = (nixie_dev.tubes[i]->value << 4);
//				else
//					nixie_dev.output[i/2] |= nixie_dev.tubes[i]->value;
//			}
//		}
		for (unsigned char i = 0; i < nixie_dev.count; i++) {
			if (i % 2 == 0)
				nixie_dev.output[i / 2] = (nixie_dev.tubes[i]->value << 4);
			else
				nixie_dev.output[i / 2] |= nixie_dev.tubes[i]->value;
		}
		return 0;
	} else
		return -1;
	return 0;
}

signed char nixie_init(void) {
	if (NIXIE_DEVICES <= 0)
		return -1;

	/* 1 controller controlls 2 devs */
	nixie_dev.output = (unsigned char*) calloc(
			(NIXIE_DEVICES % 2 == 0) ?
					NIXIE_DEVICES / 2 : NIXIE_DEVICES / 2 + 1,
			sizeof(unsigned char));

	if (nixie_dev.output == NULL)
		return -2;

	nixie_dev.tubes = (nixie_tube_t**) calloc(NIXIE_DEVICES,
			sizeof(nixie_tube_t*));

	for (unsigned char i = 0; i < NIXIE_DEVICES; i++)
		nixie_dev.tubes[i] = (nixie_tube_t*) calloc(1, sizeof(nixie_tube_t));

	nixie_dev.data_temp = (unsigned char*) calloc(NIXIE_DEVICES,
			sizeof(unsigned char));

	nixie_dev.mask = 0xFFFF;
	nixie_dev.count = NIXIE_DEVICES;

	return 0;
}
