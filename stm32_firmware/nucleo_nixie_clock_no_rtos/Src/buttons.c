/*
 * buttons.c
 *
 *  Created on: Aug 4, 2017
 *      Author: alxhoff
 */

#include "stm32f1xx_hal.h"
#include "config.h"
#include "main.h"

typedef struct button {
	unsigned char state;
	unsigned long prev_press;
} button_t;

typedef enum button_masks {
	no_press = 0, left = 0b1, center = 0b10, right = 0b1000
} button_mask_e;

typedef struct buttons {
	char button_input[NUM_OF_BUTTONS];
	char button_last_state[NUM_OF_BUTTONS];
	char button_current_state[NUM_OF_BUTTONS];
	unsigned long button_last_time[NUM_OF_BUTTONS];
} buttons_t;

buttons_t buttons_dev = { 0 };
button_t button_dev[BUTTON_COUNT] = { 0 };

void ButtonsInit() {

	GPIO_InitTypeDef GPIO_InitStruct;

	/*Configure GPIO pin : PF3 */
	GPIO_InitStruct.Pin = RIGHT_BUTTON_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(RIGHT_BUTTON_PORT, &GPIO_InitStruct);

	/*Configure GPIO pin : PC0 */
	GPIO_InitStruct.Pin = CENTER_BUTTON_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(CENTER_BUTTON_PORT, &GPIO_InitStruct);

	/*Configure GPIO pin : PA3 */
	GPIO_InitStruct.Pin = LEFT_BUTTON_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(LEFT_BUTTON_PORT, &GPIO_InitStruct);
}

unsigned char check_button(GPIO_TypeDef *port, uint16_t pin, button_t *button) {
	if(HAL_GetTick() - button->prev_press > DEBOUNCE_DELAY){
		if(HAL_GPIO_ReadPin(port, pin) != button->state){
			if(button->state){
				button->state = 0;
				return 0;
			}else{
				button->state = 1;
				return 1;
			}
		}
	}
	return 0;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_Pin);
	button_mask_e ret = no_press;

	if (GPIO_Pin == LEFT_BUTTON_PIN) {
		ret = check_button(LEFT_BUTTON_PORT, LEFT_BUTTON_PIN, &button_dev[0]);
		if(ret)
			HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
	} else if (GPIO_Pin == CENTER_BUTTON_PIN) {
		ret = check_button(CENTER_BUTTON_PORT, CENTER_BUTTON_PIN, &button_dev[1]);
		if(ret)
			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	} else if (GPIO_Pin == RIGHT_BUTTON_PIN) {
		ret = check_button(RIGHT_BUTTON_PORT, RIGHT_BUTTON_PIN, &button_dev[2]);
		if(ret)
			HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
	}
}
