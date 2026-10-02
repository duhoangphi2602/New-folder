# Memory Ordering

## 1. The Reordering Problem
Look at this code, where Task 1 prepares some data and then sets a flag for Task 2.
```cpp
int sensor_data = 0;
std::atomic<bool> data_ready = false;

// TASK 1 (Producer)
sensor_data = 42;         // Line A
data_ready = true;        // Line B

// TASK 2 (Consumer)
if (data_ready == true) { // Line C
    print(sensor_data);   // Line D
}
```
**The Nightmare:** Task 2 prints `0`. How?
Because the Compiler or the CPU hardware looked at Task 1 and said: *"Line A and Line B have no mathematical dependency on each other. I can run Line B before Line A to save 1 nanosecond of pipeline stalling."*
So, the CPU physically executes `data_ready = true` FIRST. Then Task 2 wakes up, sees the flag is true, and reads `sensor_data` (which is still 0!). Finally, Task 1 executes `sensor_data = 42`. 

## 2. Memory Barriers (Fences)
To prevent this, you must build invisible "Fences" in your code, telling the Compiler and CPU: *"You may reorder things, but you are legally forbidden from moving code across this fence."*
C++ provides different strengths of fences via the `std::memory_order` enum passed into atomic operations.

## 3. The 3 Main Orderings

### A. `std::memory_order_seq_cst` (Sequential Consistency)
This is the default if you just write `data_ready = true`. It is the strictest, safest, and slowest ordering. It builds a massive, impenetrable wall. It guarantees that all threads see all operations in the exact same order. Use this 99% of the time.

### B. `std::memory_order_relaxed`
This is the fastest. It builds NO fence whatsoever. The compiler and CPU can reorder wildly.
*When to use:* Simple counters where you only care about the final number, not the timeline.
```cpp
counter.fetch_add(1, std::memory_order_relaxed); // Super fast
```

### C. The `Release` - `Acquire` Pair
This is the professional standard for Producer-Consumer data passing (like the buggy code in Section 1).
- **Release (Producer):** `data_ready.store(true, std::memory_order_release);`
  *Rule:* No memory writes that happened *before* this line can be moved *after* this line. (Guarantees `sensor_data = 42` is fully finished and pushed to RAM before the flag is set).
- **Acquire (Consumer):** `data_ready.load(std::memory_order_acquire);`
  *Rule:* No memory reads that happen *after* this line can be moved *before* this line. (Guarantees Task 2 doesn't pre-fetch `sensor_data` before checking the flag).

## 4. Why Bother?
If `seq_cst` is safe, why use `Release/Acquire`? Because on ARM processors, `seq_cst` forces the CPU to issue expensive `DMB` (Data Memory Barrier) hardware instructions that stall the CPU pipeline and destroy performance. `Release/Acquire` is often free or much cheaper, while providing exactly enough safety.

## 5. Example
*(See `examples/` for the correct implementation of the Producer-Consumer pattern).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
