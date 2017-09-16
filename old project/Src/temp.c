#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef hadc1;

float getMCUTemperature() {
	float temp;

	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 0xFFFFFFFFU);
	HAL_ADC_Stop(&hadc1);

	temp = (float)HAL_ADC_GetValue(&hadc1);
	temp = (temp/4095.0)*3300.0;
	temp = (temp - 760.0)/2.5;
	temp += 25.0;

	return temp;
}
