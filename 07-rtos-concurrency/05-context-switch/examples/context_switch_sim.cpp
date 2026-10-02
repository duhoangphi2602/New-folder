/**
 * @file context_switch_sim.cpp
 * @brief Conceptually simulates the register PUSH/POP mechanism of a Context Switch.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <vector>

// Simulated CPU Registers
struct CPURegisters {
    int R0 = 0, R1 = 0;
    int ProgramCounter = 0;
    int StackPointer = 0;
};

// Simulated Task Control Block
struct TCB {
    std::string name;
    std::vector<int> stack_memory;
    int saved_stack_pointer;
};

class SimulatedCore {
public:
    CPURegisters cpu;
    
    // Simulates the RTOS saving context
    void save_context(TCB& current_task) {
        std::cout << "  [RTOS] Saving Context for " << current_task.name << "...\n";
        
        // Push registers onto the task's stack
        current_task.stack_memory.push_back(cpu.R0);
        current_task.stack_memory.push_back(cpu.R1);
        current_task.stack_memory.push_back(cpu.ProgramCounter);
        
        // Save the stack pointer to the TCB
        current_task.saved_stack_pointer = current_task.stack_memory.size();
    }

    // Simulates the RTOS restoring context
    void restore_context(TCB& next_task) {
        std::cout << "  [RTOS] Restoring Context for " << next_task.name << "...\n";
        
        // Read stack pointer from TCB
        cpu.StackPointer = next_task.saved_stack_pointer;
        
        // Pop registers from the task's stack
        cpu.ProgramCounter = next_task.stack_memory.back(); next_task.stack_memory.pop_back();
        cpu.R1             = next_task.stack_memory.back(); next_task.stack_memory.pop_back();
        cpu.R0             = next_task.stack_memory.back(); next_task.stack_memory.pop_back();
    }
};

int main() {
    std::cout << "--- Context Switch Mechanics ---\n\n";

    SimulatedCore core;
    TCB taskA = {"Task A", {}, 0};
    TCB taskB = {"Task B", {99, 88, 1004}, 3}; // Task B was previously paused at PC=1004, R1=88, R0=99

    std::cout << "1. Task A is running. (R0=10, PC=555)\n";
    core.cpu.R0 = 10;
    core.cpu.R1 = 20;
    core.cpu.ProgramCounter = 555;

    std::cout << "\n2. SysTick Interrupt fires! Context Switch begins.\n";
    core.save_context(taskA);
    
    std::cout << "   (Scheduler Algorithm picks Task B...)\n";
    
    core.restore_context(taskB);

    std::cout << "\n3. Task B resumes execution!\n";
    std::cout << "   CPU State -> R0: " << core.cpu.R0 
              << ", R1: " << core.cpu.R1 
              << ", PC: " << core.cpu.ProgramCounter << "\n";

    return 0;
}
