/**
 * @file FreeRTOSConfig_sim.h
 * @brief Conceptual snippet of crucial FreeRTOSConfig.h settings.
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

// ==================================================
// 1. CORE KERNEL SETTINGS
// ==================================================
#define configUSE_PREEMPTION                    1
#define configTICK_RATE_HZ                      (1000) // 1ms Tick
#define configMAX_PRIORITIES                    (5)    // Priority 0 to 4
#define configMINIMAL_STACK_SIZE                (128)  // Words (not bytes). 128 * 4 = 512 Bytes.

// ==================================================
// 2. MEMORY ALLOCATION
// ==================================================
// Allocate exactly 15 Kilobytes of RAM for the OS to use.
// All Tasks, Queues, and Semaphores are allocated from this pool.
#define configTOTAL_HEAP_SIZE                   ((size_t)(15 * 1024))

// ==================================================
// 3. HOOKS (DEBUGGING)
// ==================================================
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configCHECK_FOR_STACK_OVERFLOW          2  // Advanced Stack checking
#define configUSE_MALLOC_FAILED_HOOK            1  // Alert me if OS RAM is full

// ==================================================
// 4. FEATURE INCLUSION
// ==================================================
#define configUSE_MUTEXES                       1
#define configUSE_COUNTING_SEMAPHORES           1
#define configUSE_TIMERS                        1 // Enable Software Timers
#define configTIMER_TASK_PRIORITY               (configMAX_PRIORITIES - 1) // High Prio for Daemon
#define configTIMER_TASK_STACK_DEPTH            (256)

#endif /* FREERTOS_CONFIG_H */
