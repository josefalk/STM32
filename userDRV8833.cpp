#include "main.h"  // Include your main header where HAL and other definitions are available

// Function to initialize and start the DRV8833 motor driver
bool DRV8833_StartDriver()
{
    // Set PA4 high to start the driver
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

    // Check if PA4 is high
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_SET)
    {
        return true;  // Successfully started the driver
    }
    else
    {
        return false; // Failed to start the driver
    }
}

// Function to run the motor forward with a specified duty cycle
void DRV8833_RunForward(TIM_HandleTypeDef* htim2, uint32_t dutyCycle)
{
    __HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_2, dutyCycle);
    __HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_1, 0);
    HAL_Delay(1000);  // Run forward for 1 second
}

// Function to run the motor reverse with a specified duty cycle
void DRV8833_RunReverse(TIM_HandleTypeDef* htim2, uint32_t dutyCycle)
{
    __HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_1, dutyCycle);
    __HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_2, 0);
    HAL_Delay(1000);  // Run reverse for 1 second
}

// Function to stop the motor
void DRV8833_StopMotor(TIM_HandleTypeDef* htim2)
{
    __HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_1, 0);
    __HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_2, 0);
    HAL_Delay(1000);  // Stop for 1 second
}

// Function to run the motor forward with 100% duty cycle
void DRV8833_RunForward100(TIM_HandleTypeDef* htim2)
{
    __HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_2, htim2->Init.Period);
    __HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_1, 0);
    HAL_Delay(1000);  // Run forward for 1 second
}

// Function to run the motor reverse with 100% duty cycle
void DRV8833_RunReverse100(TIM_HandleTypeDef* htim2)
{
    __HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_1, htim2->Init.Period);
    __HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_2, 0);
    HAL_Delay(1000);  // Run reverse for 1 second
}

// Function to gradually escalate duty cycle from 0% to 100%
void DRV8833_EscalateRunForward(TIM_HandleTypeDef* htim2, uint32_t channel, uint32_t stepDelay)
{
    uint32_t period = htim2->Init.Period;

    for (uint32_t dutyCycle = 0; dutyCycle <= period; dutyCycle += (period / 10))  // Increment by 10% of period
    {
        if (channel == TIM_CHANNEL_1)
        {
            __HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_1, dutyCycle);
        }
        else if (channel == TIM_CHANNEL_2)
        {
            __HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_2, dutyCycle);
        }

        HAL_Delay(stepDelay);  // Delay to allow visible effect of the change
    }
}
