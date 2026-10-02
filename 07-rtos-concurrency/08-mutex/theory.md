# Mutex (Mutual Exclusion)

## 1. Concept
A Mutex is a software "Token" or "Key" managed by the RTOS. 
If a resource (like an I2C bus or a global variable) is protected by a Mutex, a Task must successfully "take" the Mutex before it is allowed to touch the resource. When it is finished, it must "give" the Mutex back.

## 2. The Magic of the Blocked State
What happens if Task A has the Mutex, and Task B tries to take it?
Does Task B spin in a `while` loop, wasting 100% of the CPU while it waits? 
**No.** The RTOS intervenes. If the Mutex is unavailable, the RTOS instantly removes Task B from the CPU, changes its state to **BLOCKED**, and runs another task. 
When Task A finally gives the Mutex back, the RTOS automatically wakes Task B up, hands it the Mutex, and lets it run. 
*A Mutex wastes zero CPU cycles while waiting!*

## 3. Syntax (FreeRTOS)
```cpp
SemaphoreHandle_t my_mutex = xSemaphoreCreateMutex();

void modify_data() {
    // 1. Take the Mutex. Wait infinitely if someone else has it.
    if (xSemaphoreTake(my_mutex, portMAX_DELAY) == pdTRUE) {
        
        // 2. We now own the Mutex. Safely modify data.
        global_counter++; 
        
        // 3. Give the Mutex back!
        xSemaphoreGive(my_mutex);
    }
}
```

## 4. Modern C++ (RAII)
Just like memory leaks, if you `take` a Mutex but forget to `give` it back (due to an early `return` or exception), the entire system will eventually deadlock. In Modern C++, we use RAII to guarantee the Mutex is released.

```cpp
#include <mutex>
std::mutex my_mutex;

void modify_data() {
    // Locks on creation. Unlocks automatically when function ends!
    std::lock_guard<std::mutex> guard(my_mutex);
    
    global_counter++;
    if (error) return; // Completely safe! Mutex is automatically unlocked.
}
```

## 5. Mutex vs Critical Section
- **Critical Section:** Turns off hardware interrupts. The CPU is deaf. *Nobody* can preempt you.
- **Mutex:** Interrupts stay on! If Task A locks a Mutex, a high-priority Task C (which doesn't need that Mutex) can still preempt Task A. This preserves system latency and responsiveness. 

## 6. Example
*(See `examples/` for a C++ implementation of a Mutex-protected hardware bus).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
