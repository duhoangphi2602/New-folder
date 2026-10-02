# Interview Questions: Atomic Operations

## 1. What does the `std::atomic` template do in C++11, and why is it crucial for ISRs?
**Answer:** `std::atomic` guarantees that reads and writes to a variable are indivisible at the CPU hardware level, meaning they can never suffer from Race Conditions. It is crucial for ISRs (Interrupt Service Routines) because ISRs cannot use Mutexes (which would cause deadlocks) and using Critical Sections inside an ISR is redundant and dangerous. Atomics allow an ISR to safely increment counters or set flags that are shared with RTOS Tasks without requiring any blocking OS API calls.

## 2. On an ARM Cortex-M processor, how does the compiler achieve Atomicity for an operation like `atomic_counter++`?
**Answer:** The compiler utilizes special exclusive memory access instructions, typically `LDREX` (Load Register Exclusive) and `STREX` (Store Register Exclusive). `LDREX` loads the value and places a hardware "monitor" on that RAM address. The CPU performs the addition. `STREX` attempts to write the new value back. If an interrupt occurred during the addition and modified that specific memory address, the hardware monitor forces the `STREX` to fail. The CPU will then automatically loop back and retry the `LDREX` operation until it succeeds uninterrupted.

## 3. What does `my_atomic_var.is_lock_free()` tell you?
**Answer:** It tells you whether the C++ compiler was able to translate the `std::atomic` variable into true hardware-level atomic assembly instructions (returning `true`), or if the data structure was too large/unaligned, forcing the compiler to secretly use a software Mutex or Critical Section to protect it (returning `false`). In embedded systems, using a non-lock-free atomic variable inside an ISR will cause a catastrophic system crash.
