/*
 * file:    timer.c
 * 
 */
#include "platform.h"

#include "timer.h"
#include "led.h"

static void timer_gpio_init(void);

static void timer_gpio_init(void)
{

}

void timer_init(void)
{
    timer_gpio_init();

    NVIC_SetPriority(TIM6_DAC_IRQn, 0);
    NVIC_EnableIRQ(TIM6_DAC_IRQn);

    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM6);

    LL_TIM_SetPrescaler(TIM6, 108 - 1);

    LL_TIM_EnableARRPreload(TIM6);

    LL_TIM_EnableIT_UPDATE(TIM6);

    LL_TIM_SetAutoReload(TIM6, 100);

    LL_TIM_EnableCounter(TIM6);
}

void TIM6_DAC_IRQHandler(void)
{
	if(TIM6->SR & TIM_SR_UIF)
	{
		//TIM6->CR1&=~(TIM_CR1_CEN);

        
    leds_blueLedSetState(LEDS_STATE_TOGGLE);
    leds_redLedSetState(LEDS_STATE_TOGGLE);

	}
	TIM6->SR&=~(TIM_SR_UIF);
}