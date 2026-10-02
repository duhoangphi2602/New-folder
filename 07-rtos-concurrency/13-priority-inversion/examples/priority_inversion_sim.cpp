/**
 * @file priority_inversion_sim.cpp
 * @brief Simulates the logic of Priority Inheritance.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <string>

struct Task {
    std::string name;
    int base_priority;
    int current_priority;
};

class Mutex {
    Task* owner = nullptr;
public:
    void take(Task& requestor) {
        if (owner == nullptr) {
            owner = &requestor;
            std::cout << "  [Mutex] " << requestor.name << " acquired the Mutex.\n";
        } else {
            std::cout << "  [Mutex] " << requestor.name << " (Pri: " << requestor.current_priority 
                      << ") is BLOCKED by " << owner->name << " (Pri: " << owner->current_priority << ").\n";
            
            // THE MAGIC: Priority Inheritance!
            if (requestor.current_priority > owner->current_priority) {
                std::cout << "  [RTOS] PRIORITY INHERITANCE TRIGGERED!\n";
                std::cout << "  [RTOS] Boosting " << owner->name << "'s priority to " << requestor.current_priority << "!\n";
                owner->current_priority = requestor.current_priority;
            }
        }
    }

    void give(Task& releaser) {
        if (owner == &releaser) {
            std::cout << "  [Mutex] " << releaser.name << " released the Mutex.\n";
            
            // Remove the boost!
            if (releaser.current_priority > releaser.base_priority) {
                std::cout << "  [RTOS] Restoring " << releaser.name << "'s priority back to " << releaser.base_priority << ".\n";
                releaser.current_priority = releaser.base_priority;
            }
            owner = nullptr;
        }
    }
};

int main() {
    std::cout << "--- Priority Inversion / Inheritance Simulation ---\n\n";

    Task low = {"LowTask", 1, 1};
    Task med = {"MedTask", 5, 5};
    Task high = {"HighTask", 10, 10};

    Mutex data_bus;

    std::cout << "1. LowTask starts and takes the bus.\n";
    data_bus.take(low);

    std::cout << "\n2. HighTask wakes up and wants the bus.\n";
    data_bus.take(high); // This will trigger the inheritance!

    std::cout << "\n3. MedTask wakes up! (Priority 5)\n";
    std::cout << "   Scheduler Check: MedTask (5) vs LowTask (" << low.current_priority << ")\n";
    std::cout << "   Result: LowTask wins! MedTask is forced to wait.\n";

    std::cout << "\n4. LowTask finishes and releases the bus.\n";
    data_bus.give(low);

    return 0;
}
