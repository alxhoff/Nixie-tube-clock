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
	GPIO_InitStruct.Pin = LEFT_BUTTON1_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(LEFT_BUTTON1_PORT, &GPIO_InitStruct);
}

void buttons_handle_center_not_setting(void)
{
	switch(render_state){
	case DISP_TIME:
		break;
	case DISP_ALARM1:
		break;
	case DISP_ALARM2:
		break;
	case SET_TIME:
		break;
	case SET_ALARM1:
		break;
	case SET_ALARM2:
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

void buttons_handle_left_not_setting(void)
{
	switch(render_state){
	case DISP_TIME:
		RTC_dev->get_alarm(RTC_dev, ALARM_TWO);
		render_state = SET_ALARM2;
		break;
	case DISP_ALARM1:
		RTC_dev->get_time(RTC_dev);
		render_state = DISP_TIME;
		break;
	case DISP_ALARM2:
		RTC_dev->get_alarm(RTC_dev, ALARM_ONE);
		render_state = DISP_ALARM1;
		break;
	case SET_TIME:
		RTC_dev->get_alarm(RTC_dev, ALARM_TWO);
		render_state = DISP_ALARM2;
		break;
	case SET_ALARM1:
		RTC_dev->get_time(RTC_dev);
		render_state = SET_TIME;
		break;
	case SET_ALARM2:
		RTC_dev->get_alarm(RTC_dev, ALARM_ONE);
		render_state = SET_ALARM1;
		break;
	default:
		break;
	}
}


void buttons_handle_left_setting_digit(void)
{
//	switch(render_state){
//		case DISP_TIME:
//			break;
//		case DISP_ALARM1:
//			break;
//		case DISP_ALARM2:
//			break;
//		case SET_TIME:
//			switch(set_state){
//			case SET_HOUR:
//				if(set_time.twelve_hour){
//					if(set_time.hour == 12){
//						set_time.hour = 1;
//					}else{
//						set_time.hour++;
//					}
//				}else{
//					if(set_time.hour == 23){
//						set_time.hour = 0;
//					}else{
//						set_time.hour++;
//					}
//				}
//				break;
//			case SET_MIN:
//				if(set_time.min == 59){
//					set_time.min = 0;
//				}else{
//					set_time.min++;
//				}
//				break;
//			case SET_SEC:
//				set_time.sec = 0;
//				break;
//			case SET_DAY:
//				if(set_time.week_day == 7){
//					set_time.week_day = 1;
//				}else{
//					set_time.week_day++;
//				}
//				break;
//			case SET_DATE:
//				if(set_time.date == 31){
//					set_time.date = 1;
//				}else{
//					set_time.date++;
//				}
//				break;
//			case SET_MONTH:
//				if(set_time.month == 12){
//					set_time.month = 1;
//				}else{
//					set_time.month++;
//				}
//				break;
//			case SET_YEAR:
//				set_time.year++;
//				break;
//			case SET_PM:
//				if(set_time.pm == PM){
//					set_time.pm = AM;
//				}else{
//					set_time.pm = PM;
//				}
//				break;
//			case SET_TWELVE_HOUR:
//				if(set_time.twelve_hour == TRUE){
//					set_time.twelve_hour = FALSE;
//				}else{
//					set_time.twelve_hour = TRUE;
//				}
//				break;
//			default:
//				break;
//			}
//			break;
//		case SET_ALARM1:
//			break;
//		case SET_ALARM2:
//			break;
//		default:
//			break;
//		}
}

void buttons_handle_left_setting_move(void)
{

}

void buttons_handle_left(void)
{
	switch(set_state){
	case NOT_SETTING:
		buttons_handle_left_not_setting();
		break;
	case SETTING_DIGIT:
		buttons_handle_left_setting_digit();
		break;
	case SETTING_MOVE:
		buttons_handle_left_setting_move();
		break;
	default:
		break;
	}
}

void buttons_handle_right_set_time(void)
{

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
		render_state = SET_TIME;
		break;
	case SET_TIME:
		RTC_dev->get_alarm(RTC_dev, ALARM_ONE);
		render_state = SET_ALARM1;
		break;
	case SET_ALARM1:
		RTC_dev->get_alarm(RTC_dev, ALARM_TWO);
		render_state = SET_ALARM2;
		break;
	case SET_ALARM2:
		RTC_dev->get_time(RTC_dev);
		render_state = DISP_TIME;
		break;
	default:
		break;
	}
}

void buttons_handle_right_setting_digit(void)
{

}

void buttons_handle_right_setting_move(void)
{

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

		for(BUTTON_POSITIONS_t i=LEFT1;i<MAX_VALUE;i++){
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
							case LEFT1:
								buttons_handle_left();
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




//							case LEFT2:
//								switch(render_state){
//								case DISP_TIME:
//									break;
//								case DISP_ALARM1:
//									break;
//								case DISP_ALARM2:
//									break;
//								case SET_TIME:
//									switch(set_state){
//									case SET_HOUR:
//										if(set_time.twelve_hour){
//											if(set_time.hour == 12){
//												set_time.hour = 1;
//											}else{
//												set_time.hour++;
//											}
//										}else{
//											if(set_time.hour == 23){
//												set_time.hour = 0;
//											}else{
//												set_time.hour++;
//											}
//										}
//										break;
//									case SET_MIN:
//										if(set_time.min == 59){
//											set_time.min = 0;
//										}else{
//											set_time.min++;
//										}
//										break;
//									case SET_SEC:
//										set_time.sec = 0;
//										break;
//									case SET_DAY:
//										if(set_time.week_day == 7){
//											set_time.week_day = 1;
//										}else{
//											set_time.week_day++;
//										}
//										break;
//									case SET_DATE:
//										if(set_time.date == 31){
//											set_time.date = 1;
//										}else{
//											set_time.date++;
//									gl	}
//										break;
//									case SET_MONTH:
//										if(set_time.month == 12){
//											set_time.month = 1;
//										}else{
//											set_time.month++;
//										}
//										break;
//									case SET_YEAR:
//										set_time.year++;
//										break;
//									case SET_PM:
//										if(set_time.pm == PM){
//											set_time.pm = AM;
//										}else{
//											set_time.pm = PM;
//										}
//										break;
//									case SET_TWELVE_HOUR:
//										if(set_time.twelve_hour == TRUE){
//											set_time.twelve_hour = FALSE;
//										}else{
//											set_time.twelve_hour = TRUE;
//										}
//										break;
//									default:
//										break;
//									}
//									break;
//								case SET_ALARM1:
//									break;
//								case SET_ALARM2:
//									break;
//								default:
//									break;
//								}
//								break;
//							case CENTER2:
//								HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
//								break;
//							case RIGHT2:
//								switch(render_state){
//								case DISP_TIME:
//									break;
//								case DISP_ALARM1:
//									break;
//								case DISP_ALARM2:
//									break;
//								case SET_TIME:
//									switch(set_state){
//									case SET_HOUR:
//										if(set_time.twelve_hour){
//											if(set_time.hour == 1){
//												set_time.hour = 12;
//											}else{
//												set_time.hour--;
//											}
//										}else{
//											if(set_time.hour == 0){
//												set_time.hour = 23;
//											}else{
//												set_time.hour--;
//											}
//										}
//										break;
//									case SET_MIN:
//										if(set_time.min == 0){
//											set_time.min = 59;
//										}else{
//											set_time.min--;
//										}
//										break;
//									case SET_SEC:
//										set_time.sec = 0;
//										break;
//									case SET_DAY:
//										if(set_time.week_day == 1){
//											set_time.week_day = 7;
//										}else{
//											set_time.week_day--;
//										}
//										break;
//									case SET_DATE:
//										if(set_time.date == 1){
//											set_time.date = 31;
//										}else{
//											set_time.date--;
//										}
//										break;
//									case SET_MONTH:
//										if(set_time.month == 1){
//											set_time.month = 12;
//										}else{
//											set_time.month--;
//										}
//										break;
//									case SET_YEAR:
//										set_time.year--;
//										break;
//									case SET_PM:
//										if(set_time.pm == AM){
//											set_time.pm = PM;
//										}else{
//											set_time.pm = AM;
//										}
//										break;
//									case SET_TWELVE_HOUR:
//										if(set_time.twelve_hour == FALSE){
//											set_time.twelve_hour = TRUE;
//										}else{
//											set_time.twelve_hour = FALSE;
//										}
//										break;
//									default:
//										break;
//									}
//									break;
//								case SET_ALARM1:
//									switch(render_state){
//								case DISP_TIME:
//									break;
//								case DISP_ALARM1:
//									break;
//								case DISP_ALARM2:
//									break;
//								case SET_TIME:
//									switch(set_state){
//									case SET_HOUR:
//										if(set_alarm.twelve_hour){
//											if(set_alarm.hour == 1){
//												set_alarm.hour = 12;
//											}else{
//												set_alarm.hour--;
//											}
//										}else{
//											if(set_alarm.hour == 0){
//												set_alarm.hour = 23;
//											}else{
//												set_alarm.hour--;
//											}
//										}
//										break;
//									case SET_MIN:
//										if(set_alarm.min == 0){
//											set_alarm.min = 59;
//										}else{
//											set_alarm.min--;
//										}
//										break;
//									case SET_SEC:
//										set_alarm.sec = 0;
//										break;
//									case SET_DAY:
//										if(set_alarm.week_day == 1){
//											set_alarm.week_day = 7;
//										}else{
//											set_alarm.week_day--;
//										}
//										break;
//									case SET_DATE:
//										if(set_alarm.date == 1){
//											set_alarm.date = 31;
//										}else{
//											set_alarm.date--;
//										}
//										break;
//									case SET_PM:
//										if(set_alarm.pm == AM){
//											set_alarm.pm = PM;
//										}else{
//											set_alarm.pm = AM;
//										}
//										break;
//									case SET_TWELVE_HOUR:
//										if(set_alarm.twelve_hour == FALSE){
//											set_alarm.twelve_hour = TRUE;
//										}else{
//											set_alarm.twelve_hour = FALSE;
//										}
//										break;
//									case SET_DATE_OR_DAY:
//										if(set_alarm.date_or_day == DAY_OF_MONTH){
//											set_alarm.date_or_day = DAY_OF_WEEK;
//										}else{
//											set_alarm.date_or_day = DAY_OF_MONTH;
//										}
//										break;
//									case SET_ALARM_TYPE:
//										if(set_alarm.alarm_type == ALARM_EVERY_SECOND){
//											set_alarm.alarm_type = ALARM_MATCH_DATE_OR_DAY;
//										}else{
//											set_alarm.alarm_type--;
//										}
//										break;
//									default:
//										break;
//									}
//									break;
//								case SET_ALARM1:
//									break;
//								case SET_ALARM2:
//									break;
//								default:
//									break;
//								}
//								break;
//									break;
//								case SET_ALARM2:
//									break;
//								default:
//									break;
//								}
//								break;
//							default:
//								break;
