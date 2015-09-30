///
/// \file	stm32f4xx_hal_hook.c
///	\brief	
///	\date	29 sept. 2015
/// \author	nb_work
///

#include "stm32f4xx_hal.h"

static int inHandlerMode(void)
{
	return __get_IPSR() != 0;
}

/**
 * @brief Provides a tick value in millisecond.
 * @note This function is declared as __weak to be overwritten in case of other
 *       implementations in user file.
 * @retval tick value
 */
uint32_t HAL_GetTick(void)
{
	if (inHandlerMode())
	{
		return xTaskGetTickCountFromISR();
	}
	else
	{
		return xTaskGetTickCount();
	}
}

/**
 * @brief This function provides accurate delay (in milliseconds) based
 *        on variable incremented.
 * @note In the default implementation , SysTick timer is the source of time base.
 *       It is used to generate interrupts at regular time intervals where uwTick
 *       is incremented.
 * @note This function is declared as __weak to be overwritten in case of other
 *       implementations in user file.
 * @param Delay: specifies the delay time length, in milliseconds.
 * @retval None
 */
void HAL_Delay(__IO uint32_t Delay)
{
	/// TODO : use vtaskDelay

	uint32_t tickstart = 0;
	tickstart = HAL_GetTick();
	while((HAL_GetTick() - tickstart) < Delay)
	{
	}
}
