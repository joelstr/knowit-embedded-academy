#include "blink.h"
#include "stm32f3xx_hal.h"
#include "cmsis_os.h"

const int32_t TOGGLE_TIME = 10000; // [ms]

static uint32_t ticks = 0;
static int32_t ToggleLed();

void BlinkLed()
{
	if(ToggleLed())
	{
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
	}
}


static int32_t ToggleLed()
{
    int32_t toggle = 0; // Set to non-zero if we should toggle the led

    ticks++;
    if (ticks > TOGGLE_TIME)
    {
    	ticks = 0;
    	toggle = 1;
    }

    return toggle;
}


void ResetTimer()
{
	ticks = 0;
}

