/*
 * config.h
 *
 *  Created on: 2 Feb 2019
 *      Author: alxhoff
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include "main.h"
#include "stm32f1xx_hal.h"

//SCREEN
#define SCREEN_CURSOR_PERIOD 750
#define SSD1306_I2C_PORT hi2c2
#define SCREEN_USER_CURSOR 0
#define SCREEN_FRAMEBUFFER_LENGTH 20

//RTC
#define RTC_DEF_TWELVE_HR 1
#define RTC_DEF_HOUR 11
#define RTC_DEF_MIN 59
#define RTC_DEF_SEC 58
#define RTC_DEF_AM_PM PM
#define RTC_DEF_WEEKDAY 1
#define RTC_DEF_DATE 05
#define RTC_DEF_MONTH 06
#define RTC_DEF_YEAR 2017
#define RTC_I2C_PORT hi2c2

#define RTC_DEF_ALM1_TWELVE_HR HOUR_12
#define RTC_DEF_ALM1_HOUR 1
#define RTC_DEF_ALM1_MIN 2
#define RTC_DEF_ALM1_AM_PM PM
#define RTC_DEF_ALM1_WEEKDAY TUESDAY
#define RTC_DEF_ALM1_DATE 3
#define RTC_DEF_ALM1_DAY_OR_DATE DAY_OF_WEEK
#define RTC_DEF_ALM1_TYPE ALARM_MATCH_MINUTES
#define RTC_DEV_ALM1_SEC 0

#define RTC_DEF_ALM2_TWELVE_HR HOUR_12
#define RTC_DEF_ALM2_HOUR 14
#define RTC_DEF_ALM2_MIN 5
#define RTC_DEF_ALM2_AM_PM PM
#define RTC_DEF_ALM2_WEEKDAY MONDAY
#define RTC_DEF_ALM2_DATE 14
#define RTC_DEF_ALM2_DAY_OR_DATE DAY_OF_WEEK
#define RTC_DEF_ALM2_TYPE ALARM_MATCH_MINUTES

//SHIFT
#define SHIFT_DEVICES 2
#define SHIFT_SER_IN_PORT SHIFT_SER_IN_GPIO_Port
#define SHIFT_SER_IN_PIN SHIFT_SER_IN_Pin
#define SHIFT_SER_CLK_PORT SHIFT_SER_CLK_GPIO_Port
#define SHIFT_SER_CLK_PIN SHIFT_SER_CLK_Pin
#define SHIFT_LATCH_PORT SHIFT_LATCH_GPIO_Port
#define SHIFT_LATCH_PIN SHIFT_LATCH_Pin
#define SHIFT_OUT_ENA_PORT SHIFT_ENA_GPIO_Port
#define SHIFT_OUT_ENA_PIN SHIFT_ENA_Pin
#define SHIFT_SER_CLR_PORT SHIFT_CLR_GPIO_Port
#define SHIFT_SER_CLR_PIN SHIFT_CLR_Pin

//NIXIES
// If NIXIE_SET is set then setting time will adhere to nixie capabilities, ie. skip seconds and date
#define NIXIE_SET 1
#define NIXIE_DEVICES 4
#define NIXIE_MIN_INDEX_LSB 0
#define NIXIE_HOUR_INDEX_LSB 2
// Digits are displayed in reverse order for each shift register
// So to show 12 on the nixies you need to send it 21
#define NIXIE_FLIPPED 1

//BUTTONS
#define BUTTON_COUNT 3
#define DEBOUNCE_DELAY 50

#define LEFT_BUTTON_PORT BUT0_GPIO_Port
#define LEFT_BUTTON_PIN BUT0_Pin
#define CENTER_BUTTON_PORT BUT1_GPIO_Port
#define CENTER_BUTTON_PIN BUT1_Pin
#define RIGHT_BUTTON_PORT BUT2_GPIO_Port
#define RIGHT_BUTTON_PIN BUT2_Pin

#define NUM_OF_BUTTONS 3

extern I2C_HandleTypeDef hi2c2;

#endif /* CONFIG_H_ */
