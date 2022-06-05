/*
 * buttons.c
 *
 *  Created on: Aug 4, 2017
 *      Author: alxhoff
 */

#include "states.h"
#include "config.h"
#include "buttons.h"

typedef struct button {
	GPIO_PinState state;
	uint32_t prev_press;
} button_t;

//typedef struct buttons {
//	char button_input[NUM_OF_BUTTONS];
//	char button_last_state[NUM_OF_BUTTONS];
//	char button_current_state[NUM_OF_BUTTONS];
//	unsigned long button_last_time[NUM_OF_BUTTONS];
//} buttons_t;

//buttons_t buttons_dev = { 0 };
button_t buttons[BUTTON_COUNT] = { 0 };
QueueHandle_t button_queue = NULL;

void buttonsInit() {
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

	button_queue = xQueueCreate(1, sizeof(unsigned char));
}

unsigned char buttonsGet(void) {
	unsigned char b = 0;

	if (button_queue)
		xQueueReceive(button_queue, &b, 0);

	return b;
}

unsigned char buttonsCheck(GPIO_TypeDef *port, uint16_t pin, button_t *button) {
	if (HAL_GetTick() - button->prev_press > DEBOUNCE_DELAY) {
		GPIO_PinState but = !HAL_GPIO_ReadPin(port, pin);
		if (but != button->state) {
			if (button->state)
				button->state = 0;
			else
				button->state = 1;

			return button->state;
		}
	}
	return 0;
}

void HAL_GPIO_EXTI_Callback(volatile uint16_t GPIO_Pin) {
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_Pin);
	unsigned char ret = 0;
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;

	if (GPIO_Pin == LEFT_BUTTON_PIN) {
		if (buttonsCheck(LEFT_BUTTON_PORT, LEFT_BUTTON_PIN, &buttons[0])) {
			ret |= BUTTON_MASK_LEFT;
			HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
		}
	} else if (GPIO_Pin == CENTER_BUTTON_PIN) {
		if (buttonsCheck(CENTER_BUTTON_PORT, CENTER_BUTTON_PIN, &buttons[1])) {
			ret |= BUTTON_MASK_CENTER;
			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		}
	} else if (GPIO_Pin == RIGHT_BUTTON_PIN) {
		if (buttonsCheck(RIGHT_BUTTON_PORT, RIGHT_BUTTON_PIN, &buttons[2])) {
			ret |= BUTTON_MASK_RIGHT;
			HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
		}
	}
	if (button_queue != NULL)
		xQueueSendToFrontFromISR(button_queue, &ret, &xHigherPriorityTaskWoken);

	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
