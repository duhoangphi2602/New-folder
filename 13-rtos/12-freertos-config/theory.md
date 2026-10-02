# FreeRTOS Config

## 1. The Kernel's Control Panel
When you include FreeRTOS in a project, you must provide a `FreeRTOSConfig.h` file. Before the compiler builds the OS Kernel, it reads this file. Every `#define` in this file uses C-preprocessor macros (`#if configUSE_MUTEXES == 1`) to physically include or exclude blocks of OS code. If you disable Mutexes, the Mutex code isn't just skipped; it is completely erased from the final `.bin` file, saving Flash memory.

## 2. Core Scheduling Parameters
- `configUSE_PREEMPTION`: Set to 1 for a modern, Preemptive RTOS (High priority tasks aggressively interrupt low priority tasks). Set to 0 for a Cooperative RTOS (tasks only switch when they voluntarily yield).
- `configTICK_RATE_HZ`: The heartbeat of the OS. Usually set to `1000` (1 millisecond per tick). Setting this to `10000` (100 microseconds) gives you much finer control over delays, but forces the CPU to waste massive amounts of time executing Context Switches.

## 3. Memory Management (The RTOS Heap)
When you call `xTaskCreate`, the OS needs RAM for the Task's Stack and TCB. It does NOT use the standard C `malloc()`. FreeRTOS implements its own highly deterministic memory allocator.
- `configTOTAL_HEAP_SIZE`: This is arguably the most important setting. It defines a massive global byte array (e.g., `(10 * 1024)` for 10 KB). The RTOS carves all Task Stacks, Queues, and Mutexes out of this single chunk of RAM. If you try to create a task and there isn't enough room left in this pool, the creation fails.

## 4. Debugging & Safety
- `configCHECK_FOR_STACK_OVERFLOW`: Set to 1 or 2. When the OS performs a Context Switch, it checks if the Task's Stack Pointer has crossed its memory boundary. If it has, it instantly calls a fatal error hook function, allowing you to catch RAM corruption before the system mysteriously crashes.
- `configUSE_MALLOC_FAILED_HOOK`: If you try to create a Queue but `configTOTAL_HEAP_SIZE` is exhausted, this triggers a callback so you know you ran out of RTOS RAM.

## 5. Example
*(See `examples/` for a standard configuration file).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
