#ifndef USER_I2C_SCAN_H
#define USER_I2C_SCAN_H

#include "stm32h7xx_hal.h"  // Include the HAL library for the HAL_StatusTypeDef and I2C functions

void scanI2cBus(I2C_HandleTypeDef *hi2c);

#endif // USER_I2C_SCAN_H
