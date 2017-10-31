/*
 * render.c
 *
 *  Created on: Aug 6, 2017
 *      Author: alxhoff
 */


#include "render.h"
//#include "draw.h"
#include "externs.h"

SCREEN_RENDER_STATE_t render_state = DISP_TIME;
SET_TARGET_t set_type = SET_HOUR;
SET_STATE_t set_state = NOT_SETTING;

void render_task_callback(void)
{
	LCD_dev->clear_wo_update(LCD_dev);

	switch(render_state)
	{
	case DISP_TIME:
		draw_disp_time_state( 0, 0);
		break;
	case DISP_ALARM1:
		draw_disp_alarm1_state( 0, 0);
		break;
	case DISP_ALARM2:
		draw_disp_alarm2_state( 0, 0);
		break;
	case SET_TIME:
		draw_set_states( 0, 0);
		break;
	case SET_ALARM1:
		draw_set_states( 0, 0);
		break;
	case SET_ALARM2:
		draw_set_states( 0, 0);
		break;
	default:
		break;
	}

	LCD_dev->update(LCD_dev);
}
