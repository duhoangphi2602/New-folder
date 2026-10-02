# Interview Questions: Mutex

## 1. What is the difference between a Mutex and a Spinlock?
**Answer:** If a resource is locked, a Mutex interacts with the RTOS Scheduler to put the waiting task into a "Blocked" (sleeping) state, yielding the CPU to other tasks and wasting no CPU time. A Spinlock does not use the Scheduler; it simply runs a `while(!resource_free);` loop. A Spinlock burns 100% of the CPU's time while waiting. Spinlocks are generally only used in multi-core systems where the wait time is expected to be just a few nanoseconds, whereas Mutexes are used in single-core or multi-core RTOS systems.

## 2. Can a Mutex be taken multiple times by the same Task?
**Answer:** A standard Mutex cannot. If Task A takes a Mutex, and then calls a function that tries to take the *same* Mutex again, Task A will deadlock itself (it goes to sleep waiting for itself to release the Mutex). To solve this, RTOSs provide a **Recursive Mutex**. A Recursive Mutex keeps a count. Task A can take it 3 times, but it must give it back 3 times before any other task is allowed to take it.

## 3. Why is C++ `std::lock_guard` (RAII) preferred over manually calling `xSemaphoreTake()` and `xSemaphoreGive()`?
**Answer:** Because it prevents Deadlocks caused by early exits. If a function manually takes a Mutex, but then encounters an error and executes a `return;` statement, the manual `give()` at the bottom of the function is skipped. The Mutex remains permanently locked, and the entire system will eventually freeze as other tasks queue up waiting for it. With `std::lock_guard`, the Mutex is tied to a local object on the Stack. When the function returns (for any reason, including an exception), the object goes out of scope, its Destructor fires, and the Mutex is mathematically guaranteed to be unlocked.
