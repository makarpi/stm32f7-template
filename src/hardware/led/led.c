#include "stm32f7xx_ll_gpio.h"
#include "stm32f7xx_ll_rcc.h"
#include "stm32f7xx.h"
#include "stm32f7xx_ll_bus.h"

#include "led.h"


void led_init(void)
{
    LL_GPIO_InitTypeDef LED2_GPIO_User = {0};

    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);

    LED2_GPIO_User.Pin = LL_GPIO_PIN_7;
    LED2_GPIO_User.Mode = LL_GPIO_MODE_OUTPUT;
    LED2_GPIO_User.Pull = LL_GPIO_PULL_NO;

    LL_GPIO_Init(GPIOB, &LED2_GPIO_User);

    LED2_GPIO_User.Pin = LL_GPIO_PIN_14;
    LED2_GPIO_User.Mode = LL_GPIO_MODE_OUTPUT;
    LED2_GPIO_User.Pull = LL_GPIO_PULL_NO;

    LL_GPIO_Init(GPIOB, &LED2_GPIO_User);

    LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_7);
    LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_14);
    // LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_7);
}