# STM32F4xx DWT Counter Module

## How to use the module

#### **`main.c`**

```c
#include "stm32f4xx-dwt-counter-module/dwt-counter.h"

int main(void)
{
  uint32_t start, cycles;

  /* Initialize the counter */
  DWT_Init();

  /* Super loop */
  while(1) {
		/* Record start of operations */
		start = DWT_GetCounter();

		/* Do some operations here */

		/* Record end of operations */
		cycles = DWT_GetCounter() - start;
  }

  /* DeInit the counter */
  DWT_DeInit();
}
```
