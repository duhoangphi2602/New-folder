# Atomic Operations (<atomic>)

## 1. Concept
"Atomic" comes from the Greek word *atomos*, meaning "indivisible". 
If an operation is Atomic, it is mathematically impossible for the OS Scheduler or a Hardware Interrupt to pause the CPU in the middle of the operation. It either executes completely (100%), or it hasn't executed at all (0%). There is no 50%.

Because the operation cannot be split, a Race Condition is physically impossible.

## 2. The Hardware Reality
In Topic 06, we saw that `counter++` takes 3 assembly instructions (Load, Add, Store). It is highly divisible, and therefore not atomic.
To make it atomic, modern CPU architectures (like ARM Cortex-M3/M4/M7) include special hardware instructions.
- ARM provides `LDREX` (Load Register Exclusive) and `STREX` (Store Register Exclusive).
- These instructions lock the memory bus at the silicon level. If a Context Switch happens between them, the CPU hardware detects it and automatically retries the operation until it succeeds uninterrupted.

## 3. Syntax (C++11)
Instead of writing Assembly, C++11 provides `std::atomic`. The compiler automatically generates the complex `LDREX/STREX` assembly code for you.

```cpp
#include <atomic>

// 1. Declare the shared variable as atomic
std::atomic<int> sensor_count = 0;

void SensorISR() {
    // 2. Safely increment. 
    // No Mutex needed! No Critical Section needed! 100% ISR Safe!
    sensor_count++; 
}

void PrintTask() {
    // 3. Safely read.
    int current = sensor_count.load(); 
    printf("Count: %d\n", current);
}
```

## 4. Why Not Use Atomic for Everything?
If Atomics are so fast and safe, why do we still use Mutexes?
Because Atomics only work on **primitive hardware types** (integers, booleans, pointers). 
- You *can* use `std::atomic<uint32_t>`.
- You *cannot* use `std::atomic<SensorStruct>` if the struct is 100 bytes large. The CPU memory bus is only 32 bits wide; it physically cannot load 100 bytes in a single, indivisible clock cycle. To protect large structs or arrays, you MUST use a Mutex.

## 5. Example
*(See `examples/` for a demonstration of a lock-free atomic flag).*

## 6. Cortex-M0 Limitation
Beware: The ultra-cheap ARM Cortex-M0 architecture (unlike the M3/M4) *does not* possess `LDREX/STREX` hardware instructions. If you compile `std::atomic` for a Cortex-M0, the GCC compiler will secretly wrap your variable in a global Critical Section (disabling hardware interrupts) to simulate atomicity. This can silently destroy your system's latency.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
