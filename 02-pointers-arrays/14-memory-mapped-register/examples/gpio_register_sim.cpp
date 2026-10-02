/*
 * Language: C++17
 * Target: PC (Simulation)
 * Build: g++ -std=c++17 gpio_register_sim.cpp -o gpio_sim
 * Run: ./gpio_sim
 * Expected output:
 *   [GPIO] Initial register value: 0x00000000
 *   [GPIO] After SET pin 5:        0x00000020
 *   [GPIO] After SET pin 13:       0x00002020
 *   [GPIO] After CLEAR pin 5:      0x00002000
 *   [GPIO] After TOGGLE pin 13:    0x00000000
 *   [GPIO] After TOGGLE pin 13:    0x00002000
 * What to learn: How pointers + bit manipulation access hardware registers
 */

#include <cstdint>
#include <cstdio>

// --- Simulated hardware register ---
// On real hardware, this would be at a fixed address like 0x40020014
static std::uint32_t simulated_gpio_odr = 0x00000000;

void print_register(const char* label, std::uint32_t value) {
    std::printf("[GPIO] %-30s 0x%08X\n", label, value);
}

// --- GPIO abstraction class ---
class Gpio {
public:
    explicit Gpio(volatile std::uint32_t* output_reg, std::uint8_t pin)
        : reg_(output_reg), mask_(1u << pin) {}

    void set()    { *reg_ |=  mask_; }
    void clear()  { *reg_ &= ~mask_; }
    void toggle() { *reg_ ^=  mask_; }
    bool read() const { return (*reg_ & mask_) != 0; }

private:
    volatile std::uint32_t* reg_;
    std::uint32_t mask_;
};

int main() {
    // In real embedded code:
    // volatile uint32_t* GPIO_ODR = reinterpret_cast<volatile uint32_t*>(0x40020014);

    // For simulation, we use a local variable:
    volatile std::uint32_t* gpio_reg = &simulated_gpio_odr;

    print_register("Initial register value:", *gpio_reg);

    // Create GPIO objects for different pins
    Gpio led(gpio_reg, 5);
    Gpio buzzer(gpio_reg, 13);

    led.set();
    print_register("After SET pin 5:", *gpio_reg);

    buzzer.set();
    print_register("After SET pin 13:", *gpio_reg);

    led.clear();
    print_register("After CLEAR pin 5:", *gpio_reg);

    buzzer.toggle();
    print_register("After TOGGLE pin 13:", *gpio_reg);

    buzzer.toggle();
    print_register("After TOGGLE pin 13:", *gpio_reg);

    return 0;
}
