/*
 * i2c.h
 *
 *  Created on: Aug 6, 2017
 *      Author: alxhoff
 */

#ifndef EXTERNS_H_
#define EXTERNS_H_

#include "cmsis_os.h"
#include "ds3231_stm32_alex.h"

extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
extern osSemaphoreId set_blink_semaphoreHandle;
extern TimerHandle_t rtos_blink_timer;
extern ds3231Time set_time;
extern ds3231Alarm set_alarm;

#endif /* EXTERNS_H_ */
