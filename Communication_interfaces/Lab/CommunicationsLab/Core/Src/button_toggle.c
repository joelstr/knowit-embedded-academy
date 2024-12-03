#include "button_toggle.h"
#include "stm32f3xx_hal.h"
#include "cmsis_os.h"
#include "uart_com.h"
#include <stdio.h>
#include <string.h>

#include "blink.h"


void ButtonToggle()
{
	if (1)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
	}
}

