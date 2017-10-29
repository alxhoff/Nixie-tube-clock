
#include "stm32f1xx_hal.h"

#ifndef __FONTS_H__
#define __FONTS_H__

typedef struct font_def{
	const uint8_t FontWidth;
	uint8_t FontHeight;
	const uint16_t *data;
} font_def_t;

extern font_def_t Font_7x10;
extern font_def_t Font_11x18;
extern font_def_t Font_16x26;

#endif

