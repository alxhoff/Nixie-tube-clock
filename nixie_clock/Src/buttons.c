/*
 * buttons.c
 *
 *  Created on: Aug 4, 2017
 *      Author: alxhoff
 */

#include "buttons.h"
#include "render.h"

ds3231Time set_time = {0};
ds3231Alarm set_alarm = {0};

void ButtonsInit(){

	GPIO_InitTypeDef GPIO_InitStruct;

	/*Configure GPIO pin : PF3 */
	GPIO_InitStruct.Pin = RIGHT_BUTTON1_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(RIGHT_BUTTON1_PORT, &GPIO_InitStruct);

	/*Configure GPIO pin : PC0 */
	GPIO_InitStruct.Pin = CENTER_BUTTON1_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(CENTER_BUTTON1_PORT, &GPIO_InitStruct);

	/*Configure GPIO pin : PA3 */
	GPIO_InitStruct.Pin = LEFT_BUTTON1_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(LEFT_BUTTON1_PORT, &GPIO_InitStruct);

	/*Configure GPIO pin : PB10 */
	GPIO_InitStruct.Pin = RIGHT_BUTTON2_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(RIGHT_BUTTON2_PORT, &GPIO_InitStruct);

	/*Configure GPIO pin : PB11 */
	GPIO_InitStruct.Pin = CENTER_BUTTON2_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(CENTER_BUTTON2_PORT, &GPIO_InitStruct);

	/*Configure GPIO pin : PE0 */
	GPIO_InitStruct.Pin = LEFT_BUTTON2_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(LEFT_BUTTON2_PORT, &GPIO_InitStruct);

}

void ButtonListenerTask(void const * argument)
{

	uint8_t button_input[NUM_OF_BUTTONS] = {0};
	uint8_t button_last_state[NUM_OF_BUTTONS] = {0};
	uint8_t button_current_state[NUM_OF_BUTTONS] = {0};
	TickType_t button_last_time[NUM_OF_BUTTONS] = {0};
	TickType_t debounce_delay = pdMS_TO_TICKS(DEBOUNCE_DELAY);

  /* Infinite loop */
	for(;;)
	{

		for(button_positions i=LEFT1;i<MAX_VALUE+1;i++){
			switch(i){
			case LEFT1:
				button_input[i] = HAL_GPIO_ReadPin(LEFT_BUTTON1_PORT, LEFT_BUTTON1_PIN);
				break;
			case CENTER1:
				button_input[i] = HAL_GPIO_ReadPin(CENTER_BUTTON1_PORT, CENTER_BUTTON1_PIN);
				break;
			case RIGHT1:
				button_input[i] = HAL_GPIO_ReadPin(RIGHT_BUTTON1_PORT, RIGHT_BUTTON1_PIN);
				break;
			case LEFT2:
				button_input[i] = HAL_GPIO_ReadPin(LEFT_BUTTON2_PORT, LEFT_BUTTON2_PIN);
				break;
			case CENTER2:
				button_input[i] = HAL_GPIO_ReadPin(CENTER_BUTTON2_PORT, CENTER_BUTTON2_PIN);
				break;
			case RIGHT2:
				button_input[i] = HAL_GPIO_ReadPin(RIGHT_BUTTON2_PORT, RIGHT_BUTTON2_PIN);
				break;
			default:
				break;
			}
			if(button_input[i] != button_last_state[i]){
				button_last_time[i] = xTaskGetTickCount();
			}
			if((xTaskGetTickCount() - button_last_time[i]) > debounce_delay){
				if(button_input[i] != button_current_state[i]){
					button_current_state[i] = button_input[i];
					//press
					if(!button_input[i]){
						switch(i){
							case LEFT1:
								switch(render_state){
								case DISP_TIME:
									render_state = DISP_ALARM2;
									break;
								case DISP_ALARM1:
									render_state = DISP_TIME;
									break;
								case DISP_ALARM2:
									render_state = DISP_ALARM1;
									break;

								case SET_TIME:
									if(set_state == SET_HOUR){
										set_state = SET_TWELVE_HOUR;
									}else{
										set_state--;
									}
									break;
								case SET_ALARM1:
								case SET_ALARM2:
									if(set_state == SET_HOUR){
										set_state = SET_ALARM_TYPE;
									}else{
										set_state--;
									}
									break;

								default:
									break;
								}

								break;
							case CENTER1:
								switch(render_state){
								case DISP_TIME:
									render_state = SET_TIME;
//									xTimerStart(rtos_blink_timer,0);
									//get current time
									DS3231_get_time(&hi2c2, &set_time);
									break;
								case DISP_ALARM1:
//									xTimerStart(rtos_blink_timer,0);
									render_state = SET_ALARM1;
									//get current alarm
									DS3231_get_alarm(&hi2c2, &set_alarm, ALARM_ONE);
									break;
								case DISP_ALARM2:
//									xTimerStart(rtos_blink_timer,0);
									render_state = SET_ALARM2;
									//get current alarm
									DS3231_get_alarm(&hi2c2, &set_alarm, ALARM_TWO);
									break;

								case SET_TIME:
									render_state = DISP_TIME;
									set_state = SET_HOUR;
//									xTimerStop(rtos_blink_timer, 0);
									//get current time
									DS3231_set_time(&hi2c2, &set_time);
									break;
								case SET_ALARM1:
									render_state = DISP_ALARM1;
									set_state = SET_HOUR;
//									xTimerStop(rtos_blink_timer, 0);
									//get current alarm
									DS3231_set_alarm(&hi2c2, &set_alarm, ALARM_ONE);
									break;
								case SET_ALARM2:
									render_state = DISP_ALARM2;
									set_state = SET_HOUR;
//									xTimerStop(rtos_blink_timer, 0);
									//get current alarm
									DS3231_get_alarm(&hi2c2, &set_alarm, ALARM_TWO);
									break;

								default:
									break;
								}
								break;
							case RIGHT1:
								switch(render_state){
								case DISP_TIME:
									render_state = DISP_ALARM1;
									break;
								case DISP_ALARM1:
									render_state = DISP_ALARM2;
									break;
								case DISP_ALARM2:
									render_state = DISP_TIME;
									break;
								case SET_TIME:
									if(set_state == SET_TWELVE_HOUR){
										set_state = SET_HOUR;
									}else{
										set_state++;
									}
									break;
								case SET_ALARM1:
								case SET_ALARM2:
									if(set_state == SET_ALARM_TYPE){
										set_state = SET_HOUR;
									}else{
										set_state++;
									}
									break;

								default:
									break;
								}
								break;
							case LEFT2:
								switch(render_state){
								case DISP_TIME:
									break;
								case DISP_ALARM1:
									break;
								case DISP_ALARM2:
									break;
								case SET_TIME:
									switch(set_state){
									case SET_HOUR:
										if(set_time.twelve_hour){
											if(set_time.hour == 12){
												set_time.hour = 1;
											}else{
												set_time.hour++;
											}
										}else{
											if(set_time.hour == 23){
												set_time.hour = 0;
											}else{
												set_time.hour++;
											}
										}
										break;
									case SET_MIN:
										if(set_time.min == 59){
											set_time.min = 0;
										}else{
											set_time.min++;
										}
										break;
									case SET_SEC:
										set_time.sec = 0;
										break;
									case SET_DAY:
										if(set_time.week_day == 7){
											set_time.week_day = 1;
										}else{
											set_time.week_day++;
										}
										break;
									case SET_DATE:
										if(set_time.date == 31){
											set_time.date = 1;
										}else{
											set_time.date++;
										}
										break;
									case SET_MONTH:
										if(set_time.month == 12){
											set_time.month = 1;
										}else{
											set_time.month++;
										}
										break;
									case SET_YEAR:
										set_time.year++;
										break;
									case SET_PM:
										if(set_time.pm == PM){
											set_time.pm = AM;
										}else{
											set_time.pm = PM;
										}
										break;
									case SET_TWELVE_HOUR:
										if(set_time.twelve_hour == TRUE){
											set_time.twelve_hour = FALSE;
										}else{
											set_time.twelve_hour = TRUE;
										}
										break;
									default:
										break;
									}
									break;
								case SET_ALARM1:
									break;
								case SET_ALARM2:
									break;
								default:
									break;
								}
								break;
							case CENTER2:
								HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
								break;
							case RIGHT2:
								switch(render_state){
								case DISP_TIME:
									break;
								case DISP_ALARM1:
									break;
								case DISP_ALARM2:
									break;
								case SET_TIME:
									switch(set_state){
									case SET_HOUR:
										if(set_time.twelve_hour){
											if(set_time.hour == 1){
												set_time.hour = 12;
											}else{
												set_time.hour--;
											}
										}else{
											if(set_time.hour == 0){
												set_time.hour = 23;
											}else{
												set_time.hour--;
											}
										}
										break;
									case SET_MIN:
										if(set_time.min == 0){
											set_time.min = 59;
										}else{
											set_time.min--;
										}
										break;
									case SET_SEC:
										set_time.sec = 0;
										break;
									case SET_DAY:
										if(set_time.week_day == 1){
											set_time.week_day = 7;
										}else{
											set_time.week_day--;
										}
										break;
									case SET_DATE:
										if(set_time.date == 1){
											set_time.date = 31;
										}else{
											set_time.date--;
										}
										break;
									case SET_MONTH:
										if(set_time.month == 1){
											set_time.month = 12;
										}else{
											set_time.month--;
										}
										break;
									case SET_YEAR:
										set_time.year--;
										break;
									case SET_PM:
										if(set_time.pm == AM){
											set_time.pm = PM;
										}else{
											set_time.pm = AM;
										}
										break;
									case SET_TWELVE_HOUR:
										if(set_time.twelve_hour == FALSE){
											set_time.twelve_hour = TRUE;
										}else{
											set_time.twelve_hour = FALSE;
										}
										break;
									default:
										break;
									}
									break;
								case SET_ALARM1:
									switch(render_state){
								case DISP_TIME:
									break;
								case DISP_ALARM1:
									break;
								case DISP_ALARM2:
									break;
								case SET_TIME:
									switch(set_state){
									case SET_HOUR:
										if(set_alarm.twelve_hour){
											if(set_alarm.hour == 1){
												set_alarm.hour = 12;
											}else{
												set_alarm.hour--;
											}
										}else{
											if(set_alarm.hour == 0){
												set_alarm.hour = 23;
											}else{
												set_alarm.hour--;
											}
										}
										break;
									case SET_MIN:
										if(set_alarm.min == 0){
											set_alarm.min = 59;
										}else{
											set_alarm.min--;
										}
										break;
									case SET_SEC:
										set_alarm.sec = 0;
										break;
									case SET_DAY:
										if(set_alarm.week_day == 1){
											set_alarm.week_day = 7;
										}else{
											set_alarm.week_day--;
										}
										break;
									case SET_DATE:
										if(set_alarm.date == 1){
											set_alarm.date = 31;
										}else{
											set_alarm.date--;
										}
										break;
									case SET_PM:
										if(set_alarm.pm == AM){
											set_alarm.pm = PM;
										}else{
											set_alarm.pm = AM;
										}
										break;
									case SET_TWELVE_HOUR:
										if(set_alarm.twelve_hour == FALSE){
											set_alarm.twelve_hour = TRUE;
										}else{
											set_alarm.twelve_hour = FALSE;
										}
										break;
									case SET_DATE_OR_DAY:
										if(set_alarm.date_or_day == DAY_OF_MONTH){
											set_alarm.date_or_day = DAY_OF_WEEK;
										}else{
											set_alarm.date_or_day = DAY_OF_MONTH;
										}
										break;
									case SET_ALARM_TYPE:
										if(set_alarm.alarm_type == ALARM_EVERY_SECOND){
											set_alarm.alarm_type = ALARM_MATCH_DATE_OR_DAY;
										}else{
											set_alarm.alarm_type--;
										}
										break;
									default:
										break;
									}
									break;
								case SET_ALARM1:
									break;
								case SET_ALARM2:
									break;
								default:
									break;
								}
								break;
									break;
								case SET_ALARM2:
									break;
								default:
									break;
								}
								break;
							default:
								break;
						}
					//release
					}else{
						switch(i){
							case LEFT1:
								HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
								break;
							case CENTER1:
								HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
								break;
							case RIGHT1:
								HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
								break;
							case LEFT2:
								HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
								break;
							case CENTER2:
								HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
								break;
							case RIGHT2:
								HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
								break;
							default:
								break;
							}
					}
				}
			}
			button_last_state[i]=button_input[i];
		}
	}
}
