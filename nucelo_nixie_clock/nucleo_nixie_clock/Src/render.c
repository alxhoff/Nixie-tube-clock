/*
 * render.c
 *
 *  Created on: Aug 6, 2017
 *      Author: alxhoff
 */


#include "render.h"
//#include "draw.h"
#include "externs.h"

SCREEN_RENDER_STATE render_state = DISP_TIME;
SET_STATE set_state = SET_HOUR;


void ScreenRenderTask(void)
{

	while(1){
		LCD->clear(LCD);

//		switch(render_state){
//		case DISP_TIME:
////			draw_disp_time_state(&hi2c2, 0, 0, &testStruct);
//			break;
//		case DISP_ALARM1:
////			draw_disp_alarm1_state(&hi2c2, 0, 0, &testAlarm1);
//			break;
//		case DISP_ALARM2:{
////			float temp_tmp;
////			volatile u16 temp_16;
////			char temp_str[7];
////
////			temp_tmp = ADC_get_MCU_temp();
////			temp_16 = (u16)(temp_tmp * 100.0);
////
//////			sprintf(temp_str, "%0.2f", temp_tmp);
////
//////			int i = 0;
//////			while(temp_str[i]!='\0'){
//////				if(temp_str[i]=='.'){
//////					temp_str[i]=':';
//////				}
//////				i++;
//////			}
////
////
//////			ssd1306_SetCursor(10, 10);
//////			ssd1306_WriteString(&temp_str,Font_11x18,Black);
////			ssd1306_SetCursor(10, 35);
////			ssd1306_WriteString("temp",Font_11x18,Black);
//
//
////			ds3231Time get_time = {0};
////			DS3231_get_time(&hi2c2, &get_time);
////			char *time_str = get_time_string(&get_time);
////			ssd1306_SetCursor(10, 35);
////			ssd1306_WriteString(time_str,Font_11x18,Black);
//			break;
//		}
//		case SET_TIME:
////			draw_set_states(&hi2c2, 0, 0, &set_time);
//			break;
//		case SET_ALARM1:
////			draw_set_states(&hi2c2, 0, 0, &set_alarm);
//			break;
//		case SET_ALARM2:
////			draw_set_states(&hi2c2, 0, 0, &set_alarm);
//			break;
//		default:
//			break;
//		}

		LCD->cursor(LCD, 23, 23);
		LCD->string(LCD, "in render");

		LCD->update(LCD);
		vTaskDelay(20);
	}
}
