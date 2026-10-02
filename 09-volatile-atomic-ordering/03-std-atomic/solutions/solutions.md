# Solutions: std::atomic

## Solution 1: The Multiple Flag Problem
**Answer:** `std::atomic` guarantees that reading *one* variable is thread-safe. It does **not** guarantee that reading *multiple* variables together is thread-safe. 
The `if` statement evaluates in two steps.
1. Task B evaluates `is_water_hot` and gets `true`.
2. Before Task B can check the cup, the RTOS preempts it.
3. Task A runs. The user pulls the cup away. Task A sets `is_cup_present = false`.
4. Task B resumes. It evaluates `is_cup_present`... Wait, no it doesn't! If the code was written as `if (is_water_hot) { if (is_cup_present) { ... } }`, it might fail safely. But in C++, `&&` evaluates left-to-right. It evaluates water (true), then cup (now false). It fails safely. 
Wait, what if the user pulls the cup away *after* Task B evaluates both variables as `true`, but *before* `dispense_coffee()` executes? 
The core issue is that the two variables are not tied together. If state must be evaluated together atomically, you must pack them into a single `std::atomic<uint8_t>` using bitmasks, or you must use a Mutex.

## Solution 2: `is_lock_free()`
**Answer:** 
- `counter.is_lock_free()` will return `true`. The compiler mapped it to native 32-bit hardware instructions (`LDREX`/`STREX`). It is incredibly fast and safe to use in an ISR.
- `config.is_lock_free()` will return `false`. Because the struct is too large for a 32-bit CPU to move in one clock cycle, the compiler secretly injected a hidden, standard Mutex under the hood to protect it. Calling `.load()` or `.store()` on this variable will actually invoke an OS Mutex lock. If you call this inside an ISR, the system will crash instantly.
