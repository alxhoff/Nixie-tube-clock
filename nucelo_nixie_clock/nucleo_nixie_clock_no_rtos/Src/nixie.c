/*
 * nixie.c
 *
 *  Created on: Oct 6, 2017
 *      Author: alxhoff
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "nixie.h"

uint8_t nixie_bcd_to_dec(uint8_t bcd)
{
	return (1 <<  ((bcd/16 * 10) + (bcd % 16)));
}



int8_t nixie_init_array(nixie_tube_array_t* array, uint8_t device_count)
{
	if(device_count <= 0) return -1;

	uint8_t output_size = 0;

	(device_count % 2 == 0) ? (output_size = device_count / 2) : (output_size = device_count / 2 + 1);

	array->output = (uint8_t*)calloc(output_size, sizeof(uint8_t));

	if(array->output == NULL) return -2;

	array->tubes = (nixie_tube_t**)calloc(device_count, sizeof(nixie_tube_t*));

	for(uint8_t i = 0; i < device_count; i++)
		array->tubes[i] = (nixie_tube_t*)calloc(1, sizeof(nixie_tube_t));

	array->data_temp = (uint8_t*)calloc(device_count, sizeof(uint8_t));

	array->mask = 0xFFFF;
	array->count = device_count;

	return 0;
}

int8_t nixie_enable_mask(nixie_tube_array_t* array, uint32_t mask)
{
	uint32_t temp = mask;
	for(uint8_t i = 0; i < array->count; i++){
		array->tubes[i]->enabled = temp & 1;
		temp  = temp >> 1;
	}
	return 0;
}

int8_t nixie_enable_tube(nixie_tube_array_t* array, uint8_t index)
{
	array->tubes[index]->enabled = 1;
	return 0;
}

int8_t nixie_disable_tube(nixie_tube_array_t* array, uint8_t index)
{
	array->tubes[index]->enabled = 0;
	return 0;
}

int8_t nixie_enable_all(nixie_tube_array_t* array)
{
	for(uint8_t i = 0; i < array->count; i++)
		array->tubes[i]->enabled = 1;

	return 0;
}

int8_t nixie_disable_all(nixie_tube_array_t* array)
{
	for(uint8_t i = 0; i < array->count; i++)
			array->tubes[i]->enabled = 0;

	return 0;
}

int8_t nixie_set_tube(nixie_tube_array_t* array, uint8_t index, uint8_t value)
{
	if(value < 0 || value  > 9) return -1;

	array->tubes[index]->value= value;

	return 0;
}

int8_t nixie_set_tubes(nixie_tube_array_t* array, uint8_t* data)
{
	for(uint8_t i = 0; i < array->count; i++)
		array->tubes[i]->value = data[i];

	return 0;
}

void nixie_split_digit(uint8_t input, uint8_t* output)
{
	output[0] = input / 10;
	output[1] = input % 10;
}

int8_t nixie_compile_output(nixie_tube_array_t* array)
{
	if(array->count){
		for(uint8_t i = 0; i < array->count; i++){
			if(array->mask & (1 << (array->count - i))){
				if(i%2 == 0)
					array->output[i/2] = (array->tubes[i]->value << 4);
				else
					array->output[i/2] |= array->tubes[i]->value;
			}
		}

	}else
		return -1;
	return 0;
}
