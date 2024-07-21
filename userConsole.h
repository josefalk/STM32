#ifndef USER_CONSOLE_H
#define USER_CONSOLE_H

#ifdef __cplusplus
#endif

#ifdef STM32L4xx
#include "stm32l4xx_hal.h"
#elif defined(STM32H7xx)
#include "stm32h7xx_hal.h"
#endif


#include <stdarg.h> // Required for variadic functions

void userConsole(const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Print formatted output to standard output; replace as needed
    vprintf(format, args);

    va_end(args);
}


/* If you are using C, you neeed to remove the below
 * function decleration. It work only on C++
 * this in case you want to use it for numbers.
 */

void userConsole(int *format, ...);



int getRandomValue(int low = 50, int high = 700);


#ifdef __cplusplus

#endif

#endif // USER_CONSOLE_H
