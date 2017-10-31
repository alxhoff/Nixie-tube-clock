/*
 * buttons.h
 *
 *  Created on: Aug 4, 2017
 *      Author: alxhoff
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

/*
 * BUTTON DEFINES
 */

#define DEBOUNCE_DELAY 		20

#define LEFT_BUTTON1_PORT 	GPIOD
#define LEFT_BUTTON1_PIN	GPIO_PIN_7
#define CENTER_BUTTON1_PORT GPIOC
#define CENTER_BUTTON1_PIN	GPIO_PIN_0
#define RIGHT_BUTTON1_PORT	GPIOA
#define RIGHT_BUTTON1_PIN	GPIO_PIN_3

#define LEFT_BUTTON2_PORT 	GPIOE
#define LEFT_BUTTON2_PIN	GPIO_PIN_0
#define CENTER_BUTTON2_PORT GPIOB
#define CENTER_BUTTON2_PIN	GPIO_PIN_11
#define RIGHT_BUTTON2_PORT	GPIOB
#define RIGHT_BUTTON2_PIN	GPIO_PIN_10

#define NUM_OF_BUTTONS		6

#ifndef TRUE
#define TRUE	1
#endif

#ifndef FALSE
#define FALSE	0
#endif

typedef enum {LEFT1, CENTER1, RIGHT1, LEFT2, CENTER2, RIGHT2, MAX_VALUE} BUTTON_POSITIONS_t;

void ButtonsInit();
void ButtonListenerTask(void const * argument);

#endif /* BUTTONS_H_ */
