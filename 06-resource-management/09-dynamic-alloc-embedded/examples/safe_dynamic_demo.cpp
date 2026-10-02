/**
 * @file safe_dynamic_demo.cpp
 * @brief Demonstrates Pattern 1: Allocate Once, Run Forever
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <vector>
#include <memory>

class Sensor {
    int id;
public:
    Sensor(int id) : id(id) { std::cout << "  [Init] Sensor " << id << " allocated on Heap.\n"; }
    void read() { std::cout << "  [Run] Reading Sensor " << id << "...\n"; }
};

// We don't know how many sensors we have until we read the config file!
// So we MUST use dynamic allocation. But we use it safely.
std::vector<std::unique_ptr<Sensor>> active_sensors;

void boot_sequence(int config_sensor_count) {
    std::cout << "--- BOOT SEQUENCE (Heap allowed) ---\n";
    for (int i = 0; i < config_sensor_count; ++i) {
        // Pattern 1: Allocate dynamically during boot
        active_sensors.push_back(std::make_unique<Sensor>(i));
    }
    std::cout << "Boot complete. System locked. No more allocations allowed.\n\n";
}

void mission_loop() {
    std::cout << "--- MISSION LOOP (Strictly NO Heap allocations) ---\n";
    // We just iterate over the pre-allocated objects.
    // Zero latency, zero fragmentation.
    for (const auto& sensor : active_sensors) {
        sensor->read();
    }
}

int main() {
    // 1. Read hardware config (simulated: 3 sensors)
    int hardware_detected_sensors = 3;
    
    // 2. Boot
    boot_sequence(hardware_detected_sensors);
    
    // 3. Run Forever
    mission_loop();
    mission_loop();

    return 0;
}
