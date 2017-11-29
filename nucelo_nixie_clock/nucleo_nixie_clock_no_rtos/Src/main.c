/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"

/* USER CODE BEGIN Includes */
#include "externs.h"
#include "ds3231.h"
#include "ssd1306.h"
#include "render.h"
#include "buttons.h"
#include "nixie.h"
#include "SN54HC595.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c2;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
SSD1306_device_t* LCD_dev;

//RTC
DS3231_device_t* RTC_dev;

//NIXIE
nixie_tube_array_t NIXIE_dev;

shift_array_t SHIFT_dev = {
		.dev_count 		= 2,
	.ser_in_pin 	= SHIFT_SER_DAT_Pin,
	.ser_in_port 	= SHIFT_SER_DAT_GPIO_Port,
	.ser_clk_pin 	= SHIFT_SER_CLK_Pin,
	.ser_clk_port 	= SHIFT_SER_CLK_GPIO_Port,
	.latch_pin 		= SHIFT_LATCH_Pin,
	.latch_port 	= SHIFT_LATCH_GPIO_Port,
	.out_ena_pin 	= SHIFT_ENA_Pin,
	.out_ena_port 	= SHIFT_ENA_GPIO_Port,
	.sr_clr_pin 	= SHIFT_CLR_Pin,
	.sr_clr_port 	= SHIFT_CLR_GPIO_Port,
};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C2_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
void convert_time_to_shift(void)
{
	RTC_dev->get_time(RTC_dev);

	nixie_split_digit(RTC_dev->time_1->hour, &NIXIE_dev.data_temp[0]);
	nixie_split_digit(RTC_dev->time_1->min, &NIXIE_dev.data_temp[2]);

	nixie_set_tubes(&NIXIE_dev, NIXIE_dev.data_temp);

	nixie_compile_output(&NIXIE_dev);


  	SHIFT_dev.set_data(&SHIFT_dev, NIXIE_dev.output);

  	SHIFT_dev.output(&SHIFT_dev, 2);
}
/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C2_Init();

  /* USER CODE BEGIN 2 */
//INIT
  //LCD
  	SSD1306_device_init_t LCD_init_dev =
  	{
  		.background = White,
  		.width = 128,
  		.height = 64,
  		.port = &hi2c2,
  		.font = &Font_11x18,
  	};

  	LCD_dev = ssd1306_init(&LCD_init_dev);

  	LCD_dev->clear_wo_update(LCD_dev);
  	LCD_dev->cursor(LCD_dev, 23, 23);
  	LCD_dev->string(LCD_dev, "LCD Init'd");
  	LCD_dev->update(LCD_dev);

  	//SHIFT
    	SN54HC595_init_obj(&SHIFT_dev);

    	//RTC
  	ds3231_device_init_t RTC_init_dev =
  	{
  		.initial_time = {
  			.twelve_hour = TRUE,

  			.sec = 45,
  			.min = 59,
  			.hour = 12,
  			.pm = PM,

  			.week_day = 1,
  			.date = 05,
  			.month = 06,
  			.year = 2017,

  			.dirty = 0
  		},
  		.i2c_handle = &hi2c2,
  	};

  	RTC_dev = DS3231_init(&RTC_init_dev);

  	//NIXIE ARRAY
    	nixie_init_array(&NIXIE_dev, NIXIE_TUBE_ARRAY_SIZE);

    	nixie_enable_all(&NIXIE_dev);
//INIT END

	ds3231_time_t test_return_time;

//	ds3231_time_t testTime = {
//	  		.twelve_hour = TRUE,
//	  		.sec = 55,
//	  		.min = 59,
//	  		.hour = 11,
//	  		.pm = PM,
//	  		.week_day = 5,
//	  		.date = 31,
//	  		.month = 12,
//	  		.year = 2017
//	  	};
//	DS3231_set_time(&hi2c2, &testTime);

	RTC_dev->get_time(RTC_dev);

	DS3231_get_time(&hi2c2, &test_return_time);

	//test alarm
	RTC_dev->alarm_1->sec = 45;
	RTC_dev->alarm_1->min = 8;
	RTC_dev->alarm_1->hour = 7;
	RTC_dev->alarm_1->date = 1;
	RTC_dev->alarm_1->week_day = 2;
	RTC_dev->alarm_1->alarm_type = ALARM_MATCH_MINUTES;

	RTC_dev->set_alarm(RTC_dev, ALARM_ONE);

	RTC_dev->alarm_1->min = 6;
	RTC_dev->alarm_1->hour = 6;
	RTC_dev->alarm_1->sec = 6;
	RTC_dev->alarm_1->alarm_type = ALARM_MATCH_MINUTES;

	//test alarm2
	RTC_dev->alarm_2->min = 7;
	RTC_dev->alarm_2->hour = 6;
	RTC_dev->alarm_2->date = 20;
	RTC_dev->alarm_2->week_day = 5;
	RTC_dev->alarm_2->alarm_type = ALARM_MATCH_MINUTES;

	RTC_dev->set_alarm(RTC_dev, ALARM_TWO);

	RTC_dev->alarm_2->min = 6;
	RTC_dev->alarm_2->hour = 6;
	RTC_dev->alarm_2->alarm_type = ALARM_MATCH_MINUTES;

	//blink flag
	uint32_t ticks = HAL_GetTick();
	uint32_t time_ticks = HAL_GetTick();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
	  if(HAL_GetTick() > time_ticks + GET_TIME_SPEED){

			  time_ticks = HAL_GetTick();

			  convert_time_to_shift();
	  }

	  if(HAL_GetTick() > ticks + BLINK_SPEED){
	 		  blink_flag ^= 1<<0;

	 		  ticks = HAL_GetTick();

	 		  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);

	 		  if(blink_flag)
	 			  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
	 		  else
	 			  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
	  }

	  buttons_listener_callback();
	  render_task_callback();
  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* I2C2 init function */
static void MX_I2C2_Init(void)
{

  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
     PA2   ------> USART2_TX
     PA3   ------> USART2_RX
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, SHIFT_SER_CLK_Pin|SHIFT_SER_DAT_Pin|SHIFT_ENA_Pin|SHIFT_CLR_Pin 
                          |LD3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LD2_Pin|LD1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SHIFT_LATCH_GPIO_Port, SHIFT_LATCH_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : SHIFT_SER_CLK_Pin SHIFT_SER_DAT_Pin SHIFT_ENA_Pin SHIFT_CLR_Pin 
                           LD3_Pin */
  GPIO_InitStruct.Pin = SHIFT_SER_CLK_Pin|SHIFT_SER_DAT_Pin|SHIFT_ENA_Pin|SHIFT_CLR_Pin 
                          |LD3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : BUT0_Pin BUT1_Pin BUT2_Pin */
  GPIO_InitStruct.Pin = BUT0_Pin|BUT1_Pin|BUT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : USART_TX_Pin USART_RX_Pin */
  GPIO_InitStruct.Pin = USART_TX_Pin|USART_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LD2_Pin LD1_Pin */
  GPIO_InitStruct.Pin = LD2_Pin|LD1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : SHIFT_LATCH_Pin */
  GPIO_InitStruct.Pin = SHIFT_LATCH_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SHIFT_LATCH_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : DHT_Pin */
  GPIO_InitStruct.Pin = DHT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(DHT_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
