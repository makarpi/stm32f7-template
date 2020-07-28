#include "platform.h"

#include "console.h"
#include "led.h"

static void SystemClock_Config(void);

int main(void)
{
    /* Microcontroller system and clock init */
    SystemInit();
    SystemClock_Config();

    /* Console init */
    console_init();
    leds_init();
    leds_blueLedSetState(1);
    leds_redLedSetState(1);

    while (1)
    {

    }
}

static void SystemClock_Config(void)
{
    LL_FLASH_SetLatency(LL_FLASH_LATENCY_7);

    if (LL_FLASH_GetLatency() != LL_FLASH_LATENCY_7)
    {
        //   Error_Handler();
    }
    LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
    LL_PWR_EnableOverDriveMode();
    LL_RCC_HSE_Enable();

    /* Wait till HSE is ready */
    while (LL_RCC_HSE_IsReady() != 1)
    {
    }
    LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_4, 216, LL_RCC_PLLP_DIV_2);
    LL_RCC_PLL_Enable();

    /* Wait till PLL is ready */
    while (LL_RCC_PLL_IsReady() != 1)
    {
    }
    LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
    LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_4);
    LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_2);
    LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

    /* Wait till System clock is ready */
    while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
    {
    }
    LL_Init1msTick(216000000);
    LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
    LL_SetSystemCoreClock(216000000);
}