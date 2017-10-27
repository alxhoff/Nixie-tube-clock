/*
 * nixie.c
 *
 *  Created on: Oct 6, 2017
 *      Author: alxhoff
 */

#include <stdlib.h>
#include <stdio.h>

#include "nixie.h"

uint8_t nixie_bcd_to_nixie(uint8_t bcd)
{
	return (1 <<  ((bcd/16 * 10) + (bcd % 16)));
}

int8_t nixie_init_array(nixie_tube_array_t* array, uint8_t device_count)
{
	if(device_count <= 0) return -1;

	array->output = (uint8_t*)calloc(device_count, sizeof(uint8_t));

	if(array->output == NULL) return -2;

	array->tubes = (nixie_tube_t**)calloc(device_count, sizeof(nixie_tube_t*));

	for(uint8_t i = 0; i < device_count; i++)
		array->tubes[i] = (nixie_tube_t*)calloc(1, sizeof(nixie_tube_t));

	array->mask = 0;
	array->count = device_count;

	return 0;
}

int8_t nixie_set_tube(nixie_tube_array_t* array, uint8_t index, uint8_t value)
{
	if(value < 0 || value  > 9) return -1;

	array->tubes[index]->value= value;

	return 0;
}

int8_t nixie_compile_output(nixie_tube_array_t* array)
{
	uint8_t output[array->count];

	for(uint8_t i = 0; i < array->count; i++){
		if(array->mask & (1 << (array->count - i)))
			output[i] = nixie_bcd_to_nixie(array->tubes[i]->value);
	}

	memcpy(array->output, output, sizeof(uint8_t) * array->count);

	return 0;
}
