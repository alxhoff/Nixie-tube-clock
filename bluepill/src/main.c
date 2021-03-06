
#include "main.h"
#include "cmsis_os.h"
#include "screen.h"
#include "ssd1306.h"
#include "RTC_dev.h"
#include "nixie.h"
#include "states.h"
#include "SN54HC595.h"
#include "draw.h"
#include "config.h"

I2C_HandleTypeDef PROJECT_I2C_PORT;
TIM_HandleTypeDef htim3;

osThreadId defaultTaskHandle;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);
static int MX_I2C2_Init(void);
void StartDefaultTask(void const *argument);

void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htim3);
	HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
	blink_flag = !blink_flag;
}

void ButtonTestTask(void const *argument)
{
	while (1) {
		HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
		if (!HAL_GPIO_ReadPin(BUT0_GPIO_Port, BUT0_Pin)) {
			HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
			osDelay(200);
		}

		if (!HAL_GPIO_ReadPin(BUT1_GPIO_Port, BUT1_Pin)) {
			HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
			osDelay(200);
		}

		if (!HAL_GPIO_ReadPin(BUT2_GPIO_Port, BUT2_Pin)) {
			HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
			osDelay(200);
		}
		osDelay(500);
	}
}

int main(void)
{
	volatile int ret;
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	MX_TIM3_Init();
	if (MX_I2C2_Init())
		goto err_hold;

	SN54HC595_init();
	if (ssd1306_init())
		goto err_hold;
	screen_init();
	RTC_dev_init(1);
	states_init();

	/** osThreadDef(defaultTask, ButtonTestTask, osPriorityNormal, 0, 128); */
	osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 256);
	defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

	osKernelStart();

err_hold:
	while (1) {
	}
}

static void MX_TIM3_Init(void)
{
	TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };

	htim3.Instance = TIM3;
	htim3.Init.Prescaler = 64000;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = 1000;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
	if (HAL_TIM_Base_Init(&htim3) != HAL_OK) {
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) !=
	    HAL_OK) {
		Error_Handler();
	}
}

void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Initializes the CPU, AHB and APB busses clocks 
  */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}
	/**Initializes the CPU, AHB and APB busses clocks 
  */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK |
				      RCC_CLOCKTYPE_SYSCLK |
				      RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) !=
	    HAL_OK) {
		Error_Handler();
	}
}

static int MX_I2C2_Init(void)
{
	PROJECT_I2C_PORT.Instance = I2C1;
	PROJECT_I2C_PORT.Init.ClockSpeed = 100000;
	PROJECT_I2C_PORT.Init.DutyCycle = I2C_DUTYCYCLE_2;
	PROJECT_I2C_PORT.Init.OwnAddress1 = 0;
	PROJECT_I2C_PORT.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	PROJECT_I2C_PORT.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	PROJECT_I2C_PORT.Init.OwnAddress2 = 0;
	PROJECT_I2C_PORT.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	PROJECT_I2C_PORT.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&PROJECT_I2C_PORT) != HAL_OK) {
		Error_Handler();
		return -1;
	}
	return 0;
}

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SCREEN_RESET_Pin|SHIFT_SER_IN_Pin|SHIFT_SER_CLK_Pin|SHIFT_LATCH_Pin 
                          |SHIFT_ENA_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SHIFT_CLR_GPIO_Port, SHIFT_CLR_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LD1_Pin */
  GPIO_InitStruct.Pin = LD1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : BUT0_Pin BUT1_Pin */
  GPIO_InitStruct.Pin = BUT0_Pin|BUT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : BUT2_Pin */
  GPIO_InitStruct.Pin = BUT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(BUT2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : SCREEN_RESET_Pin SHIFT_SER_IN_Pin SHIFT_SER_CLK_Pin SHIFT_LATCH_Pin 
                           SHIFT_ENA_Pin */
  GPIO_InitStruct.Pin = SCREEN_RESET_Pin|SHIFT_SER_IN_Pin|SHIFT_SER_CLK_Pin|SHIFT_LATCH_Pin 
                          |SHIFT_ENA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : SHIFT_CLR_Pin */
  GPIO_InitStruct.Pin = SHIFT_CLR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SHIFT_CLR_GPIO_Port, &GPIO_InitStruct);
}

void StartDefaultTask(void const *argument)
{
	for (;;) {
		screen_clear();
		states_run();
		screen_refresh(NULL);
		HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);

		osDelay(500);
	}
}

void Error_Handler(void)
{
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif
