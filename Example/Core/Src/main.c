/**
  ******************************************************************************
  * @file           : 	main.c
  * @author			: 	Luke Emery
  * @brief          : 	Simple blinky basic program for testing
  * 					the hardware during provisioning. Pins are defined
  * 					with names given on the discovery board. Requires
  * 					include of the stm32f4xx_hal header to use the
  * 					abstraction functions to control the hardware features.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 Staffordshire University.
  * All rights reserved.
  *
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */


/* Definitions ---------------------------------------------------------------*/
#define DELAYMS 	250
#define B1_Pin 		GPIO_PIN_0
#define LD3_Pin 	GPIO_PIN_13
#define LD4_Pin 	GPIO_PIN_12
#define LD5_Pin 	GPIO_PIN_14
#define LD6_Pin 	GPIO_PIN_15


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"


/* Function prototypes -----------------------------------------------*/
static void init_board_GPIO(void);


/**
  * @brief	The application entry point.
  * 		After initialising the HAL and board GPIO
  * 		enters the program loop, an infinite loop.
  * @param	None
  * @retval int	: return status
  */
int main(void)
{
	/* Reset of all peripherals, Initialise the Flash interface and the Systick. */
	HAL_Init();

	/* Initialise all configured peripherals */
	init_board_GPIO();

  	/* Program Loop */
  	for(;;)
  	{
		HAL_GPIO_WritePin(GPIOD, LD3_Pin|LD4_Pin|LD5_Pin|LD6_Pin, GPIO_PIN_RESET);
		HAL_Delay(DELAYMS);		HAL_GPIO_WritePin(GPIOD, LD3_Pin|LD4_Pin|LD5_Pin|LD6_Pin, GPIO_PIN_SET);
		HAL_Delay(DELAYMS);
  	}

	return 0;
}


/**
  * @brief	GPIO Initialization Function
  * 		Initialises the clock for PORT D,
  * 		configures the user button and
  * 		user LEDs for use in the program.
  * @param	None
  * @retval	None
  */
static void init_board_GPIO(void)
{
	/* Local Variables */
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Port Clock Enable */
	__HAL_RCC_GPIOD_CLK_ENABLE();

	/* Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOD, LD3_Pin|LD4_Pin|LD5_Pin|LD6_Pin, GPIO_PIN_RESET);

	/* Configure GPIO pin : B1_Pin (Blue Push Button) */
	GPIO_InitStruct.Pin = B1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/* Configure GPIO pins : LD3_Pin LD4_Pin LD5_Pin LD6_Pin */
	GPIO_InitStruct.Pin = LD3_Pin|LD4_Pin|LD5_Pin|LD6_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}
