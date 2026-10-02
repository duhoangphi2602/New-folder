/**
 * @file raii_lock_guard.cpp
 * @brief Demonstrates std::lock_guard style Mutex RAII.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

class Mutex {
public:
    void lock() { std::cout << "[MUTEX] Locked!\n"; }
    void unlock() { std::cout << "[MUTEX] Unlocked!\n"; }
};

// Generic RAII wrapper that takes any object with lock()/unlock()
template <typename T>
class LockGuard {
    T& mtx;
public:
    // Constructor locks the mutex
    LockGuard(T& m) : mtx(m) { mtx.lock(); }
    
    // Destructor unlocks the mutex
    ~LockGuard() { mtx.unlock(); }
    
    LockGuard(const LockGuard&) = delete;
    LockGuard& operator=(const LockGuard&) = delete;
};

// Global shared resource
Mutex shared_i2c_bus;

void read_sensor(bool sensor_offline) {
    // Acquire the lock via RAII
    LockGuard<Mutex> guard(shared_i2c_bus);
    
    if (sensor_offline) {
        std::cout << "Sensor is offline. Aborting.\n";
        return; // Mutex safely unlocked here!
    }
    
    std::cout << "Reading sensor data over I2C...\n";
} // Mutex safely unlocked here!

int main() {
    std::cout << "--- RAII Mutex Lock Guard ---\n\n";
    read_sensor(false);
    std::cout << "\n";
    read_sensor(true);
    return 0;
}
