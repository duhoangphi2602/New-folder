# std::atomic (C++11)

## What is this topic?
This topic introduces `<atomic>`, the C++ standard library feature for lock-free, thread-safe memory access. 

## Why is it important?
When sharing variables between RTOS tasks, the traditional approach is to use a Mutex. However, a Mutex blocks the thread. If you just want to safely increment a counter (`count++`) or toggle a boolean flag (`is_ready = true`), using a Mutex is incredibly slow and completely overkill. `std::atomic` allows you to perform these simple operations safely at the maximum possible hardware speed, without ever blocking the CPU.

## Prerequisites
- [02-volatile-vs-atomic](../02-volatile-vs-atomic/README.md)
- [08-mutex](../../07-rtos-concurrency/08-mutex/README.md)

## Learning Outcomes
1. Understand how `std::atomic` leverages specialized hardware instructions (like `LDREX`/`STREX`).
2. Replace simple Mutex locks with lock-free `std::atomic` variables.
3. Understand the specific use cases for `std::atomic_flag`.
