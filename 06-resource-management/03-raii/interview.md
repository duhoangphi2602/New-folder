# Interview Questions: RAII

## 1. What does RAII stand for, and what is its primary purpose in C++?
**Answer:** RAII stands for Resource Acquisition Is Initialization. Its primary purpose is to tie the lifecycle of a resource (like a memory allocation, a hardware mutex, or a file handle) to the lifetime of a local object on the Stack. By acquiring the resource in the object's constructor and releasing it in the destructor, C++ guarantees the resource will be perfectly cleaned up exactly when the object goes out of scope, preventing memory leaks and hardware deadlocks.

## 2. In an embedded system, why is RAII vastly superior to manual resource management (like C's `goto cleanup` pattern)?
**Answer:** Manual resource management requires the developer to perfectly track every possible execution path in a function (including every `if` statement that returns early, and every exception that might be thrown). Humans inevitably make mistakes, leading to missed `unlock()` or `free()` calls. RAII shifts this burden to the compiler. The compiler mathematically guarantees that the destructor is called on every single exit path from a scope, providing zero-overhead, mathematically provable safety.

## 3. Why is it standard practice to explicitly `delete` the copy constructor and copy assignment operator of a Hardware RAII Guard class?
**Answer:** Hardware Guards map to unique physical states (like a locked Mutex or powered peripheral). If you were allowed to copy a `MutexGuard`, you would have two objects claiming to own the lock. When the first object goes out of scope, its destructor would unlock the physical Mutex. The second object would still believe it holds the lock, leading to catastrophic race conditions where multiple tasks access the protected hardware simultaneously. Deleting the copy constructors ensures strict, uncopiable "Exclusive Ownership".
