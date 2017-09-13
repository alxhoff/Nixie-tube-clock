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
#include "lwip.h"


#define u08 uint8_t
#define u16 uint16_t

extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
extern osSemaphoreId set_blink_semaphoreHandle;
extern TimerHandle_t rtos_blink_timer;
extern ds3231Time set_time;
extern ds3231Alarm set_alarm;
extern ADC_HandleTypeDef hadc1;

extern struct netif gnetif;
extern ip4_addr_t ipaddr;
extern ip4_addr_t netmask;
extern ip4_addr_t gw;
extern uint8_t IP_ADDRESS[4];
extern uint8_t NETMASK_ADDRESS[4];
extern uint8_t GATEWAY_ADDRESS[4];



#endif /* EXTERNS_H_ */
