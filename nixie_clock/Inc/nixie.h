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

typedef struct nixie_tube nixie_tube_t;

struct nixie_tube{
	uint8_t value;

	bool enabled;
};

typedef struct nixie_tube_array{
	uint8_t count;

	nixie_tube_t** tubes;

	uint16_t mask;

	uint8_t* output;
}nixie_tube_array_t;

#endif /* NIXIE_H_ */
