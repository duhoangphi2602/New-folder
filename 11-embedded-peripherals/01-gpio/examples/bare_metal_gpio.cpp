/**
 * @file bare_metal_gpio.cpp
 * @brief Conceptual bare-metal C++ code for GPIO (based on STM32 architecture).
 */

#include <cstdint>

// 1. Define Memory-Mapped Register Addresses (Usually found in vendor headers)
#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*(volatile uint32_t*)(GPIOA_BASE + 0x00)) // Mode Register
#define GPIOA_PUPDR (*(volatile uint32_t*)(GPIOA_BASE + 0x0C)) // Pull-up/Pull-down
#define GPIOA_IDR   (*(volatile uint32_t*)(GPIOA_BASE + 0x10)) // Input Data
#define GPIOA_ODR   (*(volatile uint32_t*)(GPIOA_BASE + 0x14)) // Output Data

int main() {
    // SCENARIO: 
    // Pin PA5 is an LED (Output)
    // Pin PA0 is a Button (Input, needs Pull-Up)

    // 2. Configure Pin Modes
    // Clear the 2 bits for PA5, then set them to '01' (Output Mode)
    GPIOA_MODER &= ~(0b11 << (5 * 2)); 
    GPIOA_MODER |=  (0b01 << (5 * 2));

    // Clear the 2 bits for PA0, leave as '00' (Input Mode)
    GPIOA_MODER &= ~(0b11 << (0 * 2));

    // 3. Configure Pull-Up for the Button (PA0)
    // Set the 2 bits for PA0 to '01' (Pull-Up enabled)
    GPIOA_PUPDR &= ~(0b11 << (0 * 2));
    GPIOA_PUPDR |=  (0b01 << (0 * 2));

    // 4. The Super Loop
    while (1) {
        // Read the button (Bit 0 of the IDR)
        // Since it's pulled UP, it reads 1 when unpressed, 0 when pressed to GND.
        bool is_pressed = ((GPIOA_IDR & (1 << 0)) == 0);

        if (is_pressed) {
            // Turn LED ON (Set bit 5 of ODR to 1)
            GPIOA_ODR |= (1 << 5);
        } else {
            // Turn LED OFF (Clear bit 5 of ODR to 0)
            GPIOA_ODR &= ~(1 << 5);
        }
    }
}
