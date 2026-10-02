# Mutexes (Mutual Exclusion)

## 1. The Race Condition
Imagine two RTOS tasks share a global variable: `int tickets = 100;`
Task A wants to buy a ticket: `tickets = tickets - 1;`
In assembly, this is 3 steps: 1) Read variable to Register. 2) Subtract 1. 3) Write back to RAM.
**The Collision:**
1. Task A (Prio 1) reads `tickets` (sees 100). Subtracts 1 (now 99 in CPU register).
2. *SYS-TICK PREEMPTION!* Task B (Prio 2) wakes up.
3. Task B reads `tickets` (it is still 100 in RAM!). Subtracts 1 (99). Writes 99 to RAM. Task B finishes.
4. Task A resumes. It writes its register (99) to RAM.
Two tickets were sold, but the variable only decreased by 1! This is a **Race Condition**. 

## 2. The Critical Section
Any piece of code that modifies a shared resource (a global variable, the I2C bus, the UART peripheral) is called a **Critical Section**. You must guarantee that once a task enters a critical section, no other task can enter that same section until the first task is finished.

## 3. Enter the Mutex (The Bathroom Key)
A Mutex is a software lock managed by the RTOS. Think of it as a physical key to a single-occupancy bathroom (the UART).
- Task A wants to use the UART. It asks the OS: `xSemaphoreTake(uart_mutex)`. The OS gives Task A the key.
- Task A starts transmitting data.
- Task B wakes up and wants to use the UART. It asks the OS for the key: `xSemaphoreTake(uart_mutex)`.
- The OS says: *"No, Task A has the key. Go to sleep."* The OS moves Task B into the **Blocked List**.
- Task A finishes and returns the key: `xSemaphoreGive(uart_mutex)`.
- The OS instantly wakes up Task B, gives it the key, and lets it use the UART safely.

## 4. Why not just use a `bool` flag?
Why use a heavy RTOS Mutex when you could just do this?
```cpp
bool uart_in_use = false;
void TaskB() {
    while(uart_in_use == true) { } // Wait for it to be false
    uart_in_use = true;
    use_uart();
}
```
If Task B (High Priority) gets trapped in that `while` loop, it never Blocks. The RTOS gives it 100% of the CPU. Task A (Low Priority, who currently holds the UART) never gets the CPU time required to finish its job and set the boolean back to `false`. The system permanently deadlocks. 
A Mutex puts the waiting task to sleep, solving this perfectly.

## 5. Example
*(See `examples/` for FreeRTOS Mutex syntax).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
