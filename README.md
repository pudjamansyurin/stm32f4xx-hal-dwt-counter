# STM32F4xx HAL DWT Counter Module

## How to use the module

#### **`main.c`**

```c
#include "stm32f4xx-hal-dwt-counter/dwt-counter.h"

int main(void)
{
  uint32_t cycles;
  float second, us;

  /* Super loop */
  while(1) {
		/* Start the counter */
		DWT_Start();

		/* Do some operations here */

		/* Get CPU cycles count */
		cycles = DWT_GetCounter();

		/* Get elapsed time */
		second = DWT_GetTime();

		/* Get elapsed time in us */
		us = DWT_GetTime_us();

		/* Stop the counter */
		DWT_Stop();
  }
}
```
