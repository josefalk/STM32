#ifndef USER_DRV8833_H
#define USER_DRV8833_H

#include "main.h"  // Include your main header where HAL and other definitions are available
#include <stdbool.h>  // For boolean types

// Function to initialize and start the DRV8833 motor driver
bool DRV8833_StartDriver();

// Function to run the motor forward with a specified duty cycle
void DRV8833_RunForward(TIM_HandleTypeDef* htim2, uint32_t dutyCycle);

// Function to run the motor reverse with a specified duty cycle
void DRV8833_RunReverse(TIM_HandleTypeDef* htim2, uint32_t dutyCycle);

// Function to stop the motor
void DRV8833_StopMotor(TIM_HandleTypeDef* htim2);

// Function to run the motor forward with 100% duty cycle
void DRV8833_RunForward100(TIM_HandleTypeDef* htim2);

// Function to run the motor reverse with 100% duty cycle
void DRV8833_RunReverse100(TIM_HandleTypeDef* htim2);

// Function to gradually escalate duty cycle from 0% to 100%
void DRV8833_EscalateRunForward(TIM_HandleTypeDef* htim2, uint32_t channel, uint32_t stepDelay);


#endif // USER_DRV8833_H
