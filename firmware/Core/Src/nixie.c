/*
 * nixie.c
 *
 *  Created on: Oct 6, 2017
 *      Author: alxhoff
 */

#include <stdlib.h>
#include <stdint.h>

#include "sn54hc595.h"
#include "nixie.h"
#include "config.h"

#define CHECK_ODD(N) ((N % 2 == 0) ? N / 2 : (N + 1) / 2)

typedef struct nixie_tube nixie_tube_t;

struct nixie_tube {
	unsigned char value;
	unsigned char enabled;
};

typedef struct nixie_tube_array {
	nixie_tube_t tubes[NIXIE_DEVICES];
} nixie_tube_array_t;

nixie_tube_array_t nixie_dev = { 0 };

void nixieEnableTube(unsigned char index) {
	nixie_dev.tubes[index].enabled = 1;
}

void nixieDisableTube(unsigned char index) {
	nixie_dev.tubes[index].enabled = 0;
}

void nixieEnableAll(void) {
	for (unsigned char i = 0; i < NIXIE_DEVICES; i++)
		nixieEnableTube(i);
}

void nixieDisableAll(void) {
	for (unsigned char i = 0; i < NIXIE_DEVICES; i++)
		nixieDisableTube(i);
}

void nixieSetTube(unsigned char index, unsigned char value) {
	if (value >= 0 && value <= 9)
		nixie_dev.tubes[index].value = value;
}

unsigned char nixieSetDoubleDigits(volatile unsigned char input,
		unsigned char index) {
	if (index + 1 >= NIXIE_DEVICES)
		return -1;

	nixieSetTube(index + 1, input / 10);
	nixieSetTube(index, input % 10);

	return 0;
}

uint32_t nixieCompileOutput(void) {
	uint32_t ret = 0;

	for (unsigned char i = 0; i < NIXIE_DEVICES; i++)
		if (nixie_dev.tubes[i].enabled)
			ret |= ((nixie_dev.tubes[i].value & 0x0F) << (4 * i));
		else
			ret &= ~(0x0F << (i * 4));
#if NIXIE_FLIPPED == 1
	ret = ((ret & 0xF0F0F0F0) >> 4) | ((ret & 0x0F0F0F0F) << 4);
#endif // NIXIE_FLIPPED

	return ret;
}
