/**
 * @file lifetime_demo.cpp
 * @brief Demonstrates Object Lifetime and the danger of dangling references.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

class Configuration {
public:
    int baud_rate = 115200;
    Configuration() { std::cout << "  [Config Created]\n"; }
    ~Configuration() { std::cout << "  [Config Destroyed]\n"; }
};

// Returns a pointer to a LOCAL variable. This is a catastrophic bug.
Configuration* get_bad_config() {
    std::cout << "Entering get_bad_config()...\n";
    Configuration local_config;
    local_config.baud_rate = 9600;
    
    std::cout << "Leaving get_bad_config()...\n";
    return &local_config; // WARNING: Returning address of local variable!
} // local_config is destroyed right here!

int main() {
    std::cout << "--- Lifetime & Ownership Demo ---\n\n";

    std::cout << "1. Requesting Configuration...\n";
    Configuration* ptr = get_bad_config();
    
    std::cout << "\n2. Reading Configuration...\n";
    // At this exact moment, 'ptr' is pointing to a dead Stack Frame!
    // The memory might have been overwritten by other functions.
    // Reading it is Undefined Behavior. It might print 9600, or it might crash.
    std::cout << "Baud rate is: " << ptr->baud_rate << " (DANGEROUS!)\n";

    return 0;
}
