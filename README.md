# STM32

# STM32 re-usable code snippet


## Description

Re-usable codes:


### Function: Create Random Value:
`// Function to generate a random value between 50 and 700
int getRandomValue(int low = 50, int high = 700) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(low, high);
    return dis(gen);
}`

