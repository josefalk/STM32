#include "userGY25.h"
#include "userConsole.h"


// External peripherals
extern I2C_HandleTypeDef hi2c4;
extern UART_HandleTypeDef huart3;


void userGY25()
{
    uint8_t buf[12];
    uint8_t buf2[12];

    HAL_I2C_Master_Receive(&hi2c4, 0x68 << 1, buf, 12, HAL_MAX_DELAY);
    // Process the received data
    float yaw = (float)((buf[1] << 8) | buf[0]) / 100.0;
    float pitch = (float)((buf[3] << 8) | buf[2]) / 100.0;
    float roll = (float)((buf[5] << 8) | buf[4]) / 100.0;
    // Use yaw, pitch, and roll as needed

    HAL_UART_Transmit(&huart3, (uint8_t*)buf, sizeof(buf), HAL_MAX_DELAY);
    userConsole(yaw);
    userConsole(pitch);
    userConsole(roll);

    HAL_I2C_Master_Receive(&hi2c4, 0x60 << 1, buf2, 12, HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart3, (uint8_t*)buf2, sizeof(buf2), HAL_MAX_DELAY);
    userConsole("temp :");
    userConsole(buf2[0]);
    userConsole(buf2[1]);
    userConsole(buf2[2]);
    userConsole(buf2[3]);
    userConsole(buf2[4]);
    userConsole(buf2[5]);
    userConsole(buf2[6]);
    userConsole(buf2[7]);
    userConsole(buf2[8]);
    userConsole(buf2[9]);
}
