/*
 * my_timers.c
 *
 *  Created on: Aug 9, 2017
 *      Author: alxhoff
 */

#include "my_timers.h"

/* set_blink_timer_callback function */
void set_blink_timer_callback()
{
  /* USER CODE BEGIN set_blink_timer_callback */
	xSemaphoreGive(set_blink_semaphoreHandle);
//	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
  /* USER CODE END set_blink_timer_callback */
}
