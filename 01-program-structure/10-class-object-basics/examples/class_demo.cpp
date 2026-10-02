/**
 * @file class_demo.cpp
 * @brief Demonstrates C++ classes, constructors, and encapsulation.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

class GpioPin {
public:
    // Constructor uses an initialization list
    explicit GpioPin(int pin_number) 
        : pin_number_(pin_number), is_high_(false) {
        std::cout << "Hardware Pin " << pin_number_ << " initialized.\n";
    }

    // Destructor
    ~GpioPin() {
        std::cout << "Hardware Pin " << pin_number_ << " safely disabled.\n";
    }

    void set_high() {
        is_high_ = true;
        std::cout << "Pin " << pin_number_ << " -> HIGH\n";
    }

    void set_low() {
        is_high_ = false;
        std::cout << "Pin " << pin_number_ << " -> LOW\n";
    }

    // const member function promises not to modify class variables
    bool is_high() const {
        return is_high_;
    }

private:
    int pin_number_;
    bool is_high_;
};

int main() {
    std::cout << "--- Starting Main ---\n";
    {
        // Object created on the stack. Constructor is called automatically.
        GpioPin led(13);
        
        led.set_high();
        
        // led.pin_number_ = 14; // ERROR: private member!
    } // Object goes out of scope here. Destructor is called automatically.
    
    std::cout << "--- Ending Main ---\n";
    return 0;
}
