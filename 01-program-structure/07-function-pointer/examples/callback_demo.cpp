/**
 * @file callback_demo.cpp
 * @brief Demonstrates Function Pointers used as Callbacks and Dispatch Tables.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

// --- 1. CALLBACK DEMO ---
using timer_callback_t = void (*)();

void timer_isr(timer_callback_t cb) {
    std::cout << "[Hardware] Timer ticked!\n";
    if (cb) {
        cb(); // Execute the callback
    }
}

void blink_led() {
    std::cout << "[App] LED Toggled.\n";
}


// --- 2. DISPATCH TABLE DEMO ---
using command_handler_t = void (*)(const uint8_t*);

struct Command {
    uint8_t id;
    command_handler_t handler;
};

void handle_read(const uint8_t* data)  { std::cout << "Handling Read Command.\n"; }
void handle_write(const uint8_t* data) { std::cout << "Handling Write Command.\n"; }

constexpr Command cmd_table[] = {
    {0x01, handle_read},
    {0x02, handle_write},
};

void parse_packet(uint8_t id, const uint8_t* payload) {
    for (const auto& cmd : cmd_table) {
        if (cmd.id == id) {
            cmd.handler(payload); // Call via pointer
            return;
        }
    }
    std::cout << "Unknown command ID: " << (int)id << "\n";
}

int main() {
    std::cout << "--- Callback Demo ---\n";
    // Pass the function pointer to the hardware simulator
    timer_isr(blink_led);
    
    // C++11 Lambdas that capture NOTHING can decay to function pointers!
    timer_isr([]() { std::cout << "[App] Lambda Callback executed.\n"; });

    std::cout << "\n--- Dispatch Table Demo ---\n";
    parse_packet(0x02, nullptr);
    parse_packet(0x99, nullptr);

    return 0;
}
