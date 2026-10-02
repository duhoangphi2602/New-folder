/**
 * @file lambda_demo.cpp
 * @brief Demonstrates C++11 lambdas and captures.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

// A dummy C-style driver that takes a raw function pointer
void hardware_register_callback(void (*cb)(int)) {
    // Simulate hardware event
    cb(42);
}

int main() {
    std::cout << "--- Basic Lambda ---\n";
    auto square = [](int x) { return x * x; };
    std::cout << "Square of 5 is: " << square(5) << "\n";

    std::cout << "\n--- Captures ---\n";
    int counter = 0;

    // Capture by reference
    auto inc_ref = [&counter]() { counter++; };
    inc_ref();
    std::cout << "Counter (ref): " << counter << "\n";

    // Capture by value
    // Note: To modify a copy captured by value, we must mark the lambda 'mutable'
    auto inc_val = [counter]() mutable {
        counter++;
        std::cout << "Counter (inside by-value lambda): " << counter << "\n";
    };
    inc_val();
    std::cout << "Counter (original in main): " << counter << "\n";

    std::cout << "\n--- Embedded Callback Demo ---\n";
    // This works! The lambda is stateless (empty capture list)
    hardware_register_callback([](int status) {
        std::cout << "Hardware triggered with status: " << status << "\n";
    });

    // UNCOMMENT TO SEE COMPILE ERROR:
    // int my_id = 100;
    // hardware_register_callback([my_id](int status) {
    //     std::cout << "Hardware triggered for ID " << my_id << "\n";
    // });

    return 0;
}
