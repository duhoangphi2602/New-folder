/**
 * @file static_alloc_demo.cpp
 * @brief Demonstrates C++ std::array and template-based static allocation.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <array>

// A statically allocated Ring Buffer
template <typename T, size_t Capacity>
class StaticRingBuffer {
private:
    std::array<T, Capacity> buffer;
    size_t head = 0;
    size_t count = 0;

public:
    bool push(const T& item) {
        if (count >= Capacity) {
            std::cout << "  [!] Error: Buffer Full! (Capacity = " << Capacity << ")\n";
            return false; 
        }
        buffer[(head + count) % Capacity] = item;
        count++;
        return true;
    }

    void print_status() const {
        std::cout << "  Status: " << count << "/" << Capacity << " slots used.\n";
    }
};

// Global static allocation (Lives in .bss)
StaticRingBuffer<int, 3> sensor_history;

int main() {
    std::cout << "--- Static Allocation Demo ---\n\n";

    std::cout << "Pushing data...\n";
    sensor_history.push(10);
    sensor_history.push(20);
    sensor_history.print_status();

    std::cout << "Pushing more data...\n";
    sensor_history.push(30);
    sensor_history.print_status();

    std::cout << "Trying to exceed static capacity...\n";
    sensor_history.push(40); // This will safely fail without corrupting memory

    return 0;
}
