/*
 * dwt_counter.h
 *
 *  Created on: Feb 19, 2022
 *      Author: pujak
 */

#ifndef STM32F4XX_DWT_COUNTER_DWT_COUNTER_H_
#define STM32F4XX_DWT_COUNTER_DWT_COUNTER_H_

#include "stm32f4xx_hal.h"

/* Public function declarations & definitions */
__STATIC_INLINE void DWT_Start(void)
{
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
  DWT->CYCCNT = 0;
  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

__STATIC_INLINE void DWT_Stop(void)
{
  DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;
  DWT->CYCCNT = 0;
  CoreDebug->DEMCR &= ~CoreDebug_DEMCR_TRCENA_Msk;
}

__STATIC_INLINE void DWT_Restart(void)
{
  DWT_Stop();
  DWT_Start();
}

__STATIC_INLINE uint32_t DWT_GetCounter(void)
{
  return (DWT->CYCCNT);
}

__STATIC_INLINE float DWT_GetTime(void)
{
  return ((float) DWT->CYCCNT / HAL_RCC_GetHCLKFreq());
}

__STATIC_INLINE float DWT_GetTime_ms(void)
{
  return (DWT_GetTime() * 1000);
}

__STATIC_INLINE float DWT_GetTime_us(void)
{
  return (DWT_GetTime() * 1000000);
}

__STATIC_INLINE float DWT_GetTime_ns(void)
{
  return (DWT_GetTime() * 1000000000);
}

#endif /* STM32F4XX_DWT_COUNTER_DWT_COUNTER_H_ */
