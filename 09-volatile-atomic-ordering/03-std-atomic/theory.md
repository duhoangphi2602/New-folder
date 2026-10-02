# std::atomic

## 1. The Mutex Overhead
Consider two RTOS tasks incrementing a shared counter. 
Using a Mutex looks like this:
```cpp
int counter = 0;
Mutex my_mutex;

void task() {
    my_mutex.lock();     // Takes hundreds of CPU cycles. May block the task.
    counter++;           // Takes 3 CPU cycles.
    my_mutex.unlock();   // Takes hundreds of CPU cycles. May wake up tasks.
}
```
You are spending 1000 CPU cycles to protect an operation that takes 3 cycles. This is terrible for performance and RTOS latency.

## 2. The `std::atomic` Solution
By changing the variable type, C++ handles the thread-safety invisibly, without an OS Mutex.
```cpp
#include <atomic>

std::atomic<int> counter = 0;

void task() {
    counter++; // Thread-safe! Takes ~10 CPU cycles. NEVER blocks.
}
```

## 3. How does it work? (Hardware Magic)
`std::atomic` does not use software locks. It compiles down to specialized hardware instructions provided by the CPU silicon. 
On ARM Cortex-M processors, it uses `LDREX` (Load Exclusive) and `STREX` (Store Exclusive).
- **LDREX:** Reads the variable from RAM and tells the memory bus to "Monitor" this specific address.
- **ADD:** Modifies the value in the CPU register.
- **STREX:** Attempts to write the new value to RAM. 
  - If no other task/ISR touched the memory address while we were doing the ADD, the write succeeds.
  - If another task *did* touch the memory, the hardware bus detects it, the `STREX` physically fails, and the CPU instantly loops back to retry the `LDREX` automatically.

## 4. When to use `std::atomic`
- **Counters:** `std::atomic<int> dropped_packets;`
- **State Flags:** `std::atomic<bool> is_calibrated;`
- **Pointers:** `std::atomic<uint8_t*> buffer_ptr;` (Safely swap buffer pointers).

## 5. When NOT to use `std::atomic`
- **Large Structs:** `std::atomic<NetworkConfig>` will compile, but because the CPU hardware cannot atomically move 100 bytes in a single cycle, the C++ compiler will secretly inject a hidden Mutex under the hood. You lose all performance benefits. Only use `std::atomic` on data types that match your CPU's native word size (e.g., 8-bit, 16-bit, 32-bit on an ARM Cortex-M4).
- **Multiple Variables:** If you need to update `x` and `y` together atomically, `std::atomic` cannot help you. You must use a Mutex.

## 6. Example
*(See `examples/` for a comparison of Mutex vs Atomic performance).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
