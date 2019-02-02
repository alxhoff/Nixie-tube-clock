/*
 * render.c
 *
 *  Created on: Aug 6, 2017
 *      Author: alxhoff
 */


#include "render.h"
#include "externs.h"

SCREEN_RENDER_STATE_t render_state = DISP_TIME;
SET_TARGET_t set_target = SET_HOUR;
SET_STATE_t set_state = NOT_SETTING;

void render_task_callback(void)
{
	LCD_dev->clear_wo_update(LCD_dev);

//	switch(render_state)
//	{
//	case DISP_TIME:
//		RTC_dev->get_time(RTC_dev);
//		draw_time( 10, 5);
//		break;
//	case DISP_ALARM1:
//		RTC_dev->get_alarm(RTC_dev, ALARM_ONE);
//		draw_alarm(10, 5, ALARM_ONE);
//		break;
//	case DISP_ALARM2:
//		RTC_dev->get_alarm(RTC_dev, ALARM_ONE);
//		draw_alarm(10, 5, ALARM_TWO);
//		break;
//	case SET_TIME:
//		draw_set_states( 0, 0);
//		break;
//	case SET_ALARM1:
//		draw_set_states( 0, 0);
//		break;
//	case SET_ALARM2:
//		draw_set_states( 0, 0);
//		break;
//	default:
//		break;
//	}

	LCD_dev->update(LCD_dev);
}
