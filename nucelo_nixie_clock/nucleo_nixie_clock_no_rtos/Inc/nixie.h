/*
 * nixie.h
 *
 *  Created on: Oct 6, 2017
 *      Author: alxhoff
 */

#ifndef NIXIE_H_
#define NIXIE_H_

#ifndef bool
#define bool uint8_t
#endif
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif

#define NIXIE_TUBE_ARRAY_SIZE	2

typedef struct nixie_tube nixie_tube_t;

struct nixie_tube{
	uint8_t value;

	bool enabled;
};

typedef struct nixie_tube_array{
	uint8_t count;

	uint8_t* data_temp;

	nixie_tube_t** tubes;

	uint16_t mask;

	uint8_t* output;
}nixie_tube_array_t;

int8_t nixie_init_array(nixie_tube_array_t* array, uint8_t device_count);
int8_t nixie_set_tube(nixie_tube_array_t* array, uint8_t index, uint8_t value);
int8_t nixie_set_tubes(nixie_tube_array_t* array, uint8_t* data);
void nixie_split_digit(uint8_t input, uint8_t* output);
int8_t nixie_enable_mask(nixie_tube_array_t* array, uint32_t mask);
int8_t nixie_enable_tube(nixie_tube_array_t* array, uint8_t index);
int8_t nixie_disable_tube(nixie_tube_array_t* array, uint8_t index);
int8_t nixie_enable_all(nixie_tube_array_t* array);
int8_t nixie_disable_all(nixie_tube_array_t* array);
int8_t nixie_compile_output(nixie_tube_array_t* array);


#endif /* NIXIE_H_ */
