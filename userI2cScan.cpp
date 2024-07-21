#include "userI2cScan.h"
#include <cstdio>
#include <cstring>  // Include for strlen

// External declaration of the UART handle
extern UART_HandleTypeDef huart3;

// Custom function to send a string via UART
void uartSendString(const char *str) {
    HAL_UART_Transmit(&huart3, (uint8_t*)str, strlen(str), HAL_MAX_DELAY);
}

// Custom function to send a character via UART
void uartSendChar(char ch) {
    HAL_UART_Transmit(&huart3, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
}

void scanI2cBus(I2C_HandleTypeDef *hi2c) {
    uartSendString("Scanning I2C bus:\r\n");
    HAL_StatusTypeDef result;
    char buffer[10];  // Buffer to hold the address in hex format
    for (uint8_t i = 1; i < 128; i++) {
        /*
         * the HAL wants a left aligned i2c address
         * &hi2c is the handle
         * (uint16_t)(i << 1) is the i2c address left aligned
         * retries 2
         * timeout 2
         */
        result = HAL_I2C_IsDeviceReady(hi2c, (uint16_t)(i << 1), 2, 2);
        if (result != HAL_OK) { // HAL_ERROR or HAL_BUSY or HAL_TIMEOUT
            uartSendChar('.'); // No ACK received at that address
        }
        if (result == HAL_OK) {
            sprintf(buffer, "0x%X ", i); // Received an ACK at that address
            uartSendString(buffer);
        }
    }
    uartSendString("\r\n");
}
