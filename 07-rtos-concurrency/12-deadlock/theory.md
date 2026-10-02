# Deadlock

## 1. Concept (The Deadly Embrace)
Imagine two resources: The UART (Mutex A) and the SD Card (Mutex B).
Task 1 wants to read from UART and write to the SD card.
Task 2 wants to read from the SD card and write to UART.

**The Sequence:**
1. Task 1 starts. It takes Mutex A (UART). 
2. *[Context Switch!]*
3. Task 2 starts. It takes Mutex B (SD Card).
4. Task 2 now needs Mutex A to finish its work. But Mutex A is locked by Task 1! Task 2 goes to sleep (Blocked).
5. *[Context Switch!]*
6. Task 1 resumes. It now needs Mutex B to finish its work. But Mutex B is locked by Task 2! Task 1 goes to sleep (Blocked).

**Result:** Task 1 is waiting for Task 2. Task 2 is waiting for Task 1. Neither can wake up. The system is permanently frozen.

## 2. The 4 Coffman Conditions
For a deadlock to occur, these 4 conditions must **all** be true simultaneously:
1. **Mutual Exclusion:** Resources cannot be shared; only one task can hold a Mutex at a time.
2. **Hold and Wait:** A task holds one Mutex while waiting to acquire another.
3. **No Preemption:** The OS cannot forcibly rip a Mutex out of a task's hands.
4. **Circular Wait:** Task A waits for B, B waits for C, C waits for A.

If you break *even one* of these conditions, deadlocks are mathematically impossible.

## 3. How to Prevent Deadlocks

### Strategy 1: Strict Lock Ordering (Breaks Circular Wait)
This is the most common and robust solution. You create a company-wide rule: **Mutexes must always be acquired in alphabetical (or numerical) order.**
If both Task 1 and Task 2 are forced to acquire Mutex A *before* Mutex B, the Deadly Embrace cannot happen. Task 2 will simply block at Mutex A, allowing Task 1 to acquire B, finish its work, and release both.

### Strategy 2: Timeout Limits (Breaks Hold and Wait)
Never wait for a Mutex infinitely. 
```cpp
// Bad: Wait forever
xSemaphoreTake(mutex, portMAX_DELAY); 

// Good: Wait max 100ms. If failed, release everything and try again later.
if (xSemaphoreTake(mutex, pdMS_TO_TICKS(100)) == pdFALSE) {
    // Timeout! Abort mission, release other mutexes, return error.
}
```

## 4. Example
*(See `examples/` for a C++ thread simulation demonstrating Lock Ordering prevention).*

## 5. Modern C++ Solutions
C++11 provides `std::lock(m1, m2, ...)`. This is a magic function that takes multiple Mutexes at exactly the same time, using a deadlock-avoidance algorithm under the hood. If your RTOS environment supports C++11 threading, this is the safest way to acquire multiple locks.

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
