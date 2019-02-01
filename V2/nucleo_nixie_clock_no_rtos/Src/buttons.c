/*
 * buttons.c
 *
 *  Created on: Aug 4, 2017
 *      Author: alxhoff
 */

#include "buttons.h"
#include "render.h"

#include "main.h"

//BUTTONS
uint8_t button_input[NUM_OF_BUTTONS] = {0};
uint8_t button_last_state[NUM_OF_BUTTONS] = {0};
uint8_t button_current_state[NUM_OF_BUTTONS] = {0};
uint32_t button_last_time[NUM_OF_BUTTONS] = {0};
uint32_t debounce_delay = DEBOUNCE_DELAY;

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
	GPIO_InitStruct.Pin = BACK_BUTTON1_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(BACK_BUTTON1_PORT, &GPIO_InitStruct);
}

void buttons_handle_center_not_setting(void)
{
	switch(render_state){
	case DISP_TIME:
		render_state = SET_TIME;
		set_state = SETTING_MOVE;
		break;
	case DISP_ALARM1:
		render_state = SET_ALARM1;
		set_state = SETTING_MOVE;
		break;
	case DISP_ALARM2:
		render_state = SET_ALARM2;
		set_state = SETTING_MOVE;
		break;
	default:
		break;
	}
}

void buttons_handle_center_setting_digit(void)
{
}

void buttons_handle_center_setting_move(void)
{
	set_state = SETTING_DIGIT;
}

void buttons_handle_center(void)
{
	switch(set_state){
	case NOT_SETTING:
		buttons_handle_center_not_setting();
		break;
	case SETTING_DIGIT:
		buttons_handle_center_setting_digit();
		break;
	case SETTING_MOVE:
		buttons_handle_center_setting_move();
		break;
	default:
		break;
	}
}

void buttons_handle_back_not_setting(void)
{
	render_state = DISP_TIME;
}


void buttons_handle_back_setting_digit(void)
{
	set_state = SETTING_MOVE;
	switch(render_state){
	case SET_TIME:
		RTC_dev->set_time(RTC_dev);
		break;
	case SET_ALARM1:
		RTC_dev->set_alarm(RTC_dev, ALARM_ONE);
		break;
	case SET_ALARM2:
		RTC_dev->set_alarm(RTC_dev, ALARM_TWO);
		break;
	default:
		break;
	}
}

void buttons_handle_back_setting_move(void)
{
	set_state = NOT_SETTING;
	switch(render_state){
	case SET_TIME:
		render_state = DISP_TIME;
		break;
	case SET_ALARM1:
		render_state = DISP_ALARM1;
		break;
	case SET_ALARM2:
		render_state = DISP_ALARM2;
		break;
	default:
		break;
	}
}

void buttons_handle_back(void)
{
	switch(set_state){
	case NOT_SETTING:
		buttons_handle_back_not_setting();
		break;
	case SETTING_DIGIT:
		buttons_handle_back_setting_digit();
		break;
	case SETTING_MOVE:
		buttons_handle_back_setting_move();
		break;
	default:
		break;
	}
}

void buttons_handle_right_setting_digit(void)
{
	switch(render_state){
		case DISP_TIME:
		case DISP_ALARM1:
		case DISP_ALARM2:
			break;
		case SET_TIME:
			switch(set_target){
			case SET_HOUR:
				if(RTC_dev->time_1->twelve_hour){
					if(RTC_dev->time_1->hour == 12){
						RTC_dev->time_1->hour = 1;
					}else{
						RTC_dev->time_1->hour++;
					}
				}else{
					if(RTC_dev->time_1->hour == 23){
						RTC_dev->time_1->hour = 0;
					}else{
						RTC_dev->time_1->hour++;
					}
				}
				break;
			case SET_MIN:
				if(RTC_dev->time_1->min == 59){
					RTC_dev->time_1->min = 0;
				}else{
					RTC_dev->time_1->min++;
				}
				break;
			case SET_SEC:
				RTC_dev->time_1->sec = 0;
				break;
			case SET_DAY:
				if(RTC_dev->time_1->week_day == 7){
					RTC_dev->time_1->week_day = 1;
				}else{
					RTC_dev->time_1->week_day++;
				}
				break;
			case SET_DATE:
				if(RTC_dev->time_1->date == 31){
					RTC_dev->time_1->date = 1;
				}else{
					RTC_dev->time_1->date++;
				}
				break;
			case SET_MONTH:
				if(RTC_dev->time_1->month == 12){
					RTC_dev->time_1->month = 1;
				}else{
					RTC_dev->time_1->month++;
				}
				break;
			case SET_YEAR:
				RTC_dev->time_1->year++;
				break;
			case SET_PM:
				if(RTC_dev->time_1->pm == PM){
					RTC_dev->time_1->pm = AM;
				}else{
					RTC_dev->time_1->pm = PM;
				}
				break;
			case SET_TWELVE_HOUR:
				if(RTC_dev->time_1->twelve_hour == TRUE){
					RTC_dev->time_1->twelve_hour = FALSE;
				}else{
					RTC_dev->time_1->twelve_hour = TRUE;
				}
				break;
			default:
				break;
			}
			break;
		case SET_ALARM1:
			switch(set_target){
			case SET_HOUR:
				if(RTC_dev->alarm_1->twelve_hour){
					if(RTC_dev->alarm_1->hour == 12){
						RTC_dev->alarm_1->hour = 1;
					}else{
						RTC_dev->alarm_1->hour++;
					}
				}else{
					if(RTC_dev->alarm_1->hour == 23){
						RTC_dev->alarm_1->hour = 0;
					}else{
						RTC_dev->alarm_1->hour++;
					}
				}
				break;
			case SET_MIN:
				if(RTC_dev->alarm_1->min == 59){
					RTC_dev->alarm_1->min = 0;
				}else{
					RTC_dev->alarm_1->min++;
				}
				break;
			case SET_SEC:
				RTC_dev->alarm_1->sec = 0;
				break;
			case SET_DAY:
				if(RTC_dev->alarm_1->week_day == 7){
					RTC_dev->alarm_1->week_day = 1;
				}else{
					RTC_dev->alarm_1->week_day++;
				}
				break;
			case SET_DATE:
				if(RTC_dev->alarm_1->date == 31){
					RTC_dev->alarm_1->date = 1;
				}else{
					RTC_dev->alarm_1->date++;
				}
				break;
			case SET_PM:
				if(RTC_dev->alarm_1->pm == PM){
					RTC_dev->alarm_1->pm = AM;
				}else{
					RTC_dev->alarm_1->pm = PM;
				}
				break;
			case SET_TWELVE_HOUR:
				if(RTC_dev->alarm_1->twelve_hour == TRUE){
					RTC_dev->alarm_1->twelve_hour = FALSE;
				}else{
					RTC_dev->alarm_1->twelve_hour = TRUE;
				}
				break;
			default:
				break;
			}
			break;
		case SET_ALARM2:
			switch(set_target){
			case SET_HOUR:
				if(RTC_dev->alarm_2->twelve_hour){
					if(RTC_dev->alarm_2->hour == 12){
						RTC_dev->alarm_2->hour = 1;
					}else{
						RTC_dev->alarm_2->hour++;
					}
				}else{
					if(RTC_dev->alarm_2->hour == 23){
						RTC_dev->alarm_2->hour = 0;
					}else{
						RTC_dev->alarm_2->hour++;
					}
				}
				break;
			case SET_MIN:
				if(RTC_dev->alarm_2->min == 59){
					RTC_dev->alarm_2->min = 0;
				}else{
					RTC_dev->alarm_2->min++;
				}
				break;
			case SET_DAY:
				if(RTC_dev->alarm_2->week_day == 7){
					RTC_dev->alarm_2->week_day = 1;
				}else{
					RTC_dev->alarm_2->week_day++;
				}
				break;
			case SET_DATE:
				if(RTC_dev->alarm_2->date == 31){
					RTC_dev->alarm_2->date = 1;
				}else{
					RTC_dev->alarm_2->date++;
				}
				break;
			case SET_PM:
				if(RTC_dev->alarm_2->pm == PM){
					RTC_dev->alarm_2->pm = AM;
				}else{
					RTC_dev->alarm_2->pm = PM;
				}
				break;
			case SET_TWELVE_HOUR:
				if(RTC_dev->alarm_2->twelve_hour == TRUE){
					RTC_dev->alarm_2->twelve_hour = FALSE;
				}else{
					RTC_dev->alarm_2->twelve_hour = TRUE;
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
	}
}

void buttons_handle_right_not_setting(void)
{
	switch(render_state){
	case DISP_TIME:
		RTC_dev->get_alarm(RTC_dev, ALARM_ONE);
		render_state = DISP_ALARM1;
		break;
	case DISP_ALARM1:
		RTC_dev->get_alarm(RTC_dev, ALARM_TWO);
		render_state = DISP_ALARM2;
		break;
	case DISP_ALARM2:
		RTC_dev->get_time(RTC_dev);
		render_state = DISP_TIME;
		break;
	default:
		break;
	}
}

void buttons_handle_right_setting_move(void)
{
	switch(set_target){
		case SET_HOUR:
			set_target = SET_MIN;
			break;
		case SET_MIN:
			set_target = SET_SEC;
			break;
		case SET_SEC:
			set_target = SET_PM;
			break;
		case SET_PM:
			set_target = SET_DAY;
			break;
		case SET_DAY:
			set_target = SET_DATE;
			break;
		case SET_DATE:
			if((render_state == SET_ALARM1) || (render_state == SET_ALARM2))
				set_target = SET_HOUR;
			else
				set_target = SET_MONTH;
			break;
		case SET_MONTH:
			set_target = SET_YEAR;;
			break;
		case SET_YEAR:
			set_target = SET_HOUR;
			break;
		default:
			break;
	}
}

void buttons_handle_right(void)
{
	switch(set_state){
	case NOT_SETTING:
		buttons_handle_right_not_setting();
		break;
	case SETTING_DIGIT:
		buttons_handle_right_setting_digit();
		break;
	case SETTING_MOVE:
		buttons_handle_right_setting_move();
		break;
	default:
		break;
	}
}

void buttons_listener_callback(void)
{

	for(BUTTON_POSITIONS_t i=BACK1;i<MAX_VALUE;i++){
		switch(i){
		case BACK1:
			button_input[i] = HAL_GPIO_ReadPin(BACK_BUTTON1_PORT, BACK_BUTTON1_PIN);
			break;
		case CENTER1:
			button_input[i] = HAL_GPIO_ReadPin(CENTER_BUTTON1_PORT, CENTER_BUTTON1_PIN);
			break;
		case RIGHT1:
			button_input[i] = HAL_GPIO_ReadPin(RIGHT_BUTTON1_PORT, RIGHT_BUTTON1_PIN);
			break;
		default:
			break;
		}
		if(button_input[i] != button_last_state[i]){
			button_last_time[i] = HAL_GetTick();
		}
		if((HAL_GetTick() - button_last_time[i]) > debounce_delay){
			if(button_input[i] != button_current_state[i]){
				button_current_state[i] = button_input[i];
				//press
				if(!button_input[i]){
					switch(i){
						case BACK1:
							buttons_handle_back();
							break;
						case CENTER1:
							buttons_handle_center();
							break;
						case RIGHT1:
							buttons_handle_right();
							break;
						default:
							break;
					}
				//release
				}else{
				}
			}
		}
		button_last_state[i]=button_input[i];
	}
}
