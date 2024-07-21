#include "main.h"
#include <cstring>  // Include for strlen in C++
#include <cstdio>
#include <random>

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

// Function to generate a random value between 50 and 700
int getRandomValue(int low = 50, int high = 700) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(low, high);
    return dis(gen);
}
