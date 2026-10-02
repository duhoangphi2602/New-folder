# Interview Questions: std::atomic

## 1. What is the main performance advantage of using `std::atomic` over an RTOS Mutex?
**Answer:** An RTOS Mutex is a software construct. Locking it requires making a system call to the RTOS Scheduler, temporarily disabling interrupts, checking lists of blocked tasks, and potentially triggering a context switch. This takes hundreds or thousands of CPU cycles. `std::atomic` is a lock-free hardware construct. It relies on dedicated silicon instructions (like ARM's `LDREX/STREX`) to guarantee memory bus exclusivity in just a handful of CPU cycles, completely bypassing the OS and completely avoiding the possibility of thread blocking or Deadlock.

## 2. You need to safely share a large 256-byte `struct` between two RTOS Tasks. Should you use `std::atomic<MyStruct>` or a Mutex? Why?
**Answer:** You must use a Mutex. While the compiler will allow you to write `std::atomic<MyStruct>`, it is a trap. A 32-bit CPU hardware bus physically cannot read or write 256 bytes simultaneously. To fulfill the C++ standard's requirement for atomicity, the compiler will secretly instantiate a hidden Mutex and use software locking behind the scenes. It is always better practice to explicitly define your own Mutex for large data structures so the locking behavior is explicitly visible and manageable in your code architecture.

## 3. Can `std::atomic` variables be safely used inside an Interrupt Service Routine (ISR)?
**Answer:** Yes, but strictly conditionally. If the variable returns `true` for `is_lock_free()` (e.g., `std::atomic<int>`), it is perfectly safe to use in an ISR because it relies entirely on non-blocking hardware instructions. However, if `is_lock_free()` is `false` (meaning the compiler injected a hidden software Mutex), using it inside an ISR is a fatal error, as ISRs are not allowed to call blocking OS APIs.
