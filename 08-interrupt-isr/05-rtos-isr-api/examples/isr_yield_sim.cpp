/**
 * @file isr_yield_sim.cpp
 * @brief Simulates the logic of pxHigherPriorityTaskWoken and portYIELD_FROM_ISR.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <string>

// Mock RTOS Constants
#define pdFALSE 0
#define pdTRUE 1
typedef int BaseType_t;

// Mock System State
int running_task_priority = 1; // "Idle Task" is currently running
int waiting_task_priority = 5; // "Processing Task" is sleeping, waiting for Queue

// Mock RTOS API
void xQueueSendFromISR(const std::string& data, BaseType_t* pxHigherPriorityTaskWoken) {
    std::cout << "    [RTOS API] Data '" << data << "' added to queue.\n";
    std::cout << "    [RTOS API] Waking up 'Processing Task' (Pri " << waiting_task_priority << ")...\n";
    
    // The RTOS checks if the newly awoken task is more important than the currently interrupted task!
    if (waiting_task_priority > running_task_priority) {
        std::cout << "    [RTOS API] Woken task is HIGHER priority than current! Setting flag to TRUE.\n";
        *pxHigherPriorityTaskWoken = pdTRUE;
    } else {
        *pxHigherPriorityTaskWoken = pdFALSE;
    }
}

// Mock Yield Macro
void portYIELD_FROM_ISR(BaseType_t xHigherPriorityTaskWoken) {
    if (xHigherPriorityTaskWoken == pdTRUE) {
        std::cout << "  >> [PORT YIELD] FORCING INSTANT CONTEXT SWITCH TO HIGH PRIORITY TASK! <<\n";
    } else {
        std::cout << "  >> [PORT YIELD] No yield needed. Resuming previously interrupted task. <<\n";
    }
}

// The ISR
void Hardware_ISR() {
    std::cout << "  [ISR] Hardware Interrupt Entered!\n";
    
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    
    xQueueSendFromISR("SENSOR_DATA", &xHigherPriorityTaskWoken);
    
    std::cout << "  [ISR] Work finished. Evaluating Yield...\n";
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    
    std::cout << "  [ISR] Exiting.\n";
}

int main() {
    std::cout << "--- portYIELD_FROM_ISR Simulation ---\n\n";

    std::cout << "SCENARIO 1: Interrupting a Low Priority Task (Priority 1)\n";
    running_task_priority = 1;
    Hardware_ISR();

    std::cout << "\n------------------------------------------------\n\n";

    std::cout << "SCENARIO 2: Interrupting a Max Priority Task (Priority 10)\n";
    // Imagine the ISR fired while a massive Priority 10 task was doing math.
    running_task_priority = 10; 
    Hardware_ISR();

    return 0;
}
