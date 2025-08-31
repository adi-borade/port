#include "py32f0xx.h"   // Device header (adjust according to your IDE/CMSIS pack)

void GPIO_Config(void)
{
    // 1. Enable clock for GPIOA
    RCC->IOPENR |= RCC_IOPENR_GPIOAEN;

    // 2. Configure PA1, PA2, PA3 as output
    // First clear the bits (set to 00)
    GPIOA->MODER &= ~((3UL << (1 * 2)) | (3UL << (2 * 2)) | (3UL << (3 * 2)));

    // Now set to 01 (output mode)
    GPIOA->MODER |=  ((1UL << (1 * 2)) | (1UL << (2 * 2)) | (1UL << (3 * 2)));


}

int main(void)
{
    GPIO_Config();

    while(1)
    {
        // Toggle PA1, PA2, PA3 for testing
        GPIOA->ODR ^= (1UL << 1) | (1UL << 2) | (1UL << 3);
        for(volatile int i=0; i<500000; i++); // crude delay
    }
}
