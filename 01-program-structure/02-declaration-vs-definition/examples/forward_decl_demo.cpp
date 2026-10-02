/**
 * @file forward_decl_demo.cpp
 * @brief Demonstrates forward declarations.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <memory>

// 1. Forward Declaration
class HeavyDriver;

class Application {
public:
    Application();
    ~Application();
    
    // We can use pointers and references to an incomplete type
    void set_driver(HeavyDriver* driver);

private:
    HeavyDriver* driver_ptr_ = nullptr;
    // HeavyDriver driver_val_; // ERROR: Incomplete type cannot be used by value
};

// 2. Full Definition
class HeavyDriver {
public:
    void do_work() {
        std::cout << "Heavy Driver working...\n";
    }
};

// 3. Implementation of Application methods
// Now the full definition is available, so we can dereference the pointer.
Application::Application() = default;
Application::~Application() = default;

void Application::set_driver(HeavyDriver* driver) {
    driver_ptr_ = driver;
    if (driver_ptr_) {
        driver_ptr_->do_work(); // Needs full definition here!
    }
}

int main() {
    HeavyDriver hw;
    Application app;
    app.set_driver(&hw);
    return 0;
}
