/**
 * @file scheduler_sim.cpp
 * @brief Simulates a Preemptive Scheduler's decision logic.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

enum class TaskState { RUNNING, READY, BLOCKED };

struct TCB {
    std::string name;
    int priority;
    TaskState state;
};

class MockScheduler {
    std::vector<TCB> tasks;

public:
    void add_task(std::string name, int priority, TaskState initial_state) {
        tasks.push_back({name, priority, initial_state});
    }

    void run_systick_interrupt() {
        std::cout << "\n[SysTick Interrupt] Scheduler evaluating tasks...\n";
        
        TCB* highest_ready = nullptr;

        // The Scheduler scans all tasks
        for (auto& task : tasks) {
            // If the task is blocked, ignore it
            if (task.state == TaskState::BLOCKED) continue;
            
            // If it was running, it is now competing as a READY task
            if (task.state == TaskState::RUNNING) {
                task.state = TaskState::READY;
            }

            // Find the highest priority task that is READY
            if (highest_ready == nullptr || task.priority > highest_ready->priority) {
                highest_ready = &task;
            }
        }

        if (highest_ready) {
            highest_ready->state = TaskState::RUNNING;
            std::cout << "  -> Switching CPU to: " << highest_ready->name << " (Priority " << highest_ready->priority << ")\n";
        } else {
            std::cout << "  -> System Idle.\n";
        }
    }
    
    void print_states() {
        std::cout << "  States: ";
        for (const auto& task : tasks) {
            std::string state_str = (task.state == TaskState::RUNNING) ? "RUNNING" : 
                                    (task.state == TaskState::READY) ? "READY" : "BLOCKED";
            std::cout << "[" << task.name << ":" << state_str << "] ";
        }
        std::cout << "\n";
    }
    
    void wake_task(const std::string& name) {
        for (auto& task : tasks) {
            if (task.name == name) task.state = TaskState::READY;
        }
    }
};

int main() {
    std::cout << "--- Preemptive Scheduler Logic ---\n";

    MockScheduler scheduler;
    scheduler.add_task("Motor", 5, TaskState::BLOCKED); // High priority, but sleeping
    scheduler.add_task("WiFi", 2, TaskState::READY);
    scheduler.add_task("Idle", 0, TaskState::READY);

    scheduler.print_states();
    scheduler.run_systick_interrupt(); // WiFi should win
    scheduler.print_states();

    std::cout << "\n[Hardware] An interrupt occurs, waking the Motor task!\n";
    scheduler.wake_task("Motor");
    scheduler.print_states();
    
    scheduler.run_systick_interrupt(); // Motor should instantly preempt WiFi
    scheduler.print_states();

    return 0;
}
