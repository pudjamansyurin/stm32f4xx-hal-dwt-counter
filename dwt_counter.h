/*
 * dwt_counter.h
 *
 *  Created on: Feb 19, 2022
 *      Author: pujak
 */

#ifndef STM32F4XX_DWT_COUNTER_DWT_COUNTER_H_
#define STM32F4XX_DWT_COUNTER_DWT_COUNTER_H_

#include "stm32f4xx_hal.h"

/* Public macros */
#define CYC_TO_TIME(__X__) ((float) __X__ / HAL_RCC_GetHCLKFreq())

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

__STATIC_INLINE uint32_t DWT_GetCycle(void)
{
  return (DWT->CYCCNT);
}

__STATIC_INLINE float DWT_GetTime_s(void)
{
  return (CYC_TO_TIME(DWT->CYCCNT));
}

__STATIC_INLINE float DWT_GetTime_ms(void)
{
  return (DWT_GetTime_s() * 1000);
}

__STATIC_INLINE float DWT_GetTime_us(void)
{
  return (DWT_GetTime_ms() * 1000);
}

__STATIC_INLINE float DWT_GetTime_ns(void)
{
  return (DWT_GetTime_us() * 1000);
}

#endif /* STM32F4XX_DWT_COUNTER_DWT_COUNTER_H_ */
