# STM32

# STM32 re-usable code snippet


## Description

Re-usable codes:


### Function: Create Random Value:
```
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
