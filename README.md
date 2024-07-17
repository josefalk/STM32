# STM32

# STM32 re-usable code snippet


## Description

Re-usable codes:


### Function: Create Random Value:

```
#include <cstring>
#include <random>


// Function to generate a random value between 50 and 700
int getRandomValue(int low = 50, int high = 700) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(low, high);
    return dis(gen);
}
```

### Function: Non-blocking delay function using SysTick:

```
// Non-blocking delay function using SysTick
void user_delay(uint32_t milliseconds)
{
    uint32_t start = HAL_GetTick();  // Get current tick count

    // Wait until specified milliseconds elapse
    while ((HAL_GetTick() - start) < milliseconds) {
        // Waiting loop
    }
}
```


### Funcition to Enable virtual console:

userConsole.h
```
#ifndef USER_CONSOLE_H
#define USER_CONSOLE_H

#ifdef __cplusplus
#endif

#include "stm32l4xx_hal.h"

/* In C and C++, default argument values
 * are not part of the C standard
 * but are part of the C++ standard.
 * Therefore, if you want to provide
 * a default value for an argument
 * in a header file, you should use
 * C++ and ensure the compiler treats
 * your source files as C++ code.
 * If you use C language, remove the default assignment.
 *
 */

// Declaration of userConsole with default argument value

void userConsole(const char *msg);



#ifdef __cplusplus

#endif

#endif // USER_CONSOLE_H
```

UserConsole.cpp

```
#include "main.h"
#include "stm32l4xx_hal.h"
#include <cstring>  // Include for strlen in C++



// huart2 is declared as an external variable
extern UART_HandleTypeDef huart2;


// If it is a text.
void userConsole(const char *msg = "Hello, World!\r\n")
{
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

}

// If it is a number.
void userConsole(int value) {
    char buffer[20];  // Adjust size based on your needs
    sprintf(buffer, "%d\r\n", value);
    HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
}

```
Use the function in main.c
```
  /* USER CODE BEGIN WHILE */
  while (1)
  {
      userConsole("Hello World! \r\n");
       HAL_Delay(1000);
    /* USER CODE END WHILE */
```

Verify the below uart confiugation in main.c (it should be there by default)

```
#include "userConsole.h"

static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}
```

Turn on/off LED 
```
 while (1)
  {
      HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
      HAL_Delay(500);
      HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
      HAL_Delay(500);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
```

## I2C Scanner

```
 	printf("Scanning I2C bus:\r\n");
	HAL_StatusTypeDef result;
 	uint8_t i;
 	for (i=1; i<128; i++)
 	{
 	  /*
 	   * the HAL wants a left aligned i2c address
 	   * &hi2c1 is the handle
 	   * (uint16_t)(i<<1) is the i2c address left aligned
 	   * retries 2
 	   * timeout 2
 	   */
 	  result = HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t)(i<<1), 2, 2);
 	  if (result != HAL_OK) // HAL_ERROR or HAL_BUSY or HAL_TIMEOUT
 	  {
 		  printf("."); // No ACK received at that address
 	  }
 	  if (result == HAL_OK)
 	  {
 		  printf("0x%X", i); // Received an ACK at that address
 	  }
 	}
 	printf("\r\n");
}
```
