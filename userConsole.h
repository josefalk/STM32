#ifndef USER_CONSOLE_H
#define USER_CONSOLE_H

#ifdef __cplusplus
#endif

#ifdef STM32L4xx
#include "stm32l4xx_hal.h"
#elif defined(STM32H7xx)
#include "stm32h7xx_hal.h"
#endif



void userConsole(const char *msg);

/* If you are using C, you neeed to remove the below
 * function decleration. It work only on C++
 * this in case you want to use it for numbers.
 */

void userConsole(int);



int getRandomValue(int low = 50, int high = 700);


#ifdef __cplusplus

#endif

#endif // USER_CONSOLE_H
