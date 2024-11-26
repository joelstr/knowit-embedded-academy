#include "button_toggle.h"
#include "stm32f3xx_hal.h"
#include "cmsis_os.h"
#include <stdio.h>
#include <string.h>

#include "blink.h"
#include "uart_print.h"

static int16_t AdcHigh();

#define ON_THRESHOLD 2000 // [mV]
#define HIGH_ERROR_LIMIT 3000 // [mV]
#define ADREF 3300 // [mV]

void ButtonToggle()
{
	if (AdcHigh())
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
	}
}

static int16_t AdcHigh()
{
	char msg[10];
	int16_t rawValue = 0;
	int16_t mV = 0;

	// Read the ADC and convert the value to mV

	// Convert to string and print
	sprintf(msg, "%d\r\n", mV);
	UartPrint(msg, strlen(msg));

	return ((mV > ON_THRESHOLD) && (mV < HIGH_ERROR_LIMIT));
}

void AdcInit()
{
	// Enable the ADC clock
	__HAL_RCC_ADC1_CLK_ENABLE();

	// Initialize the ADC peripheral

}
