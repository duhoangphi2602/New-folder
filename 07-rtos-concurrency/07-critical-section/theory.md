# Critical Section

## 1. Concept
A **Critical Section** is a block of code that must execute completely, from start to finish, without *any* possibility of being interrupted or preempted. 
To achieve this, the RTOS literally writes to a hardware CPU register to globally disable all hardware interrupts. 
Because interrupts are disabled, the SysTick timer cannot fire. Because SysTick cannot fire, the Scheduler cannot run. Therefore, Preemption is mathematically impossible.

## 2. Syntax (FreeRTOS)
```cpp
void modify_shared_data() {
    // 1. Disable all interrupts! The CPU is now deaf to the outside world.
    taskENTER_CRITICAL(); 
    
    // 2. Modify the shared variable (Safe from all Tasks and ISRs)
    global_counter++; 
    
    // 3. Re-enable interrupts! The CPU can hear again.
    taskEXIT_CRITICAL(); 
}
```

## 3. The ISR Problem
Why use this brutal method instead of a standard Mutex?
Imagine a Task is reading `global_counter`. It locks a Mutex.
Suddenly, a hardware UART interrupt fires (an ISR). The CPU pauses the Task and jumps to the ISR. The ISR wants to write to `global_counter`, so it tries to lock the Mutex.
**DEADLOCK!** The ISR is waiting for the Mutex, but the Mutex is held by the paused Task. The Task can't run until the ISR finishes. The system freezes forever.
**Rule:** You cannot use Mutexes inside ISRs. If a Task shares data with an ISR, the Task MUST use a Critical Section to protect it.

## 4. Example
*(See `examples/` for how Critical Sections are mapped to RAII in modern C++).*

## 5. The Devastating Trade-off: Latency
A Critical Section turns off interrupts. 
Suppose you write a Critical Section that takes 5 milliseconds to execute (e.g., parsing a string). 
During those 5ms, the user presses the Emergency Stop button on the machine. The hardware sends an interrupt to the CPU. **The CPU ignores it.** 
The Emergency Stop ISR will not run until `taskEXIT_CRITICAL()` is finally called 5ms later. In a high-speed robotic system, 5 milliseconds of delay can result in physical destruction.
**Rule:** A Critical Section must be as short as physically possible (a few nanoseconds). Only use it to copy or increment a variable, never to process data.

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
