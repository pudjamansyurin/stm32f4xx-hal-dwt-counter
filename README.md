# STM32F4xx HAL DWT Counter Module

## How to use the module

#### **`main.c`**

```c
#include "stm32f4xx-hal-dwt-counter/dwt-counter.h"

int main(void)
{
  uint32_t cycles;
  float s, ms, us, ns;

  /* Super loop */
  while(1) {
		/* Start the counter */
		DWT_Start();

		/* Do some operations here */

		/* Get CPU cycles count */
		cycles = DWT_GetCycle();

		/* Get elapsed time in seconds */
		s = DWT_GetTime_s();

		/* Get elapsed time in mili seconds */
		ms = DWT_GetTime_us();

		/* Get elapsed time in micro seconds */
		us = DWT_GetTime_us();

		/* Get elapsed time in nano seconds */
		ns = DWT_GetTime_ns();

		/* Stop the counter */
		DWT_Stop();
  }
}
```
