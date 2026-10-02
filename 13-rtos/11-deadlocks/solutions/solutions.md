# Solutions: Deadlocks

## Solution 1: Single Task Deadlock
**Answer:** 
1. The Task calls `xSemaphoreTake(uart_mutex)` and successfully gets the lock.
2. It calls the `print_to_console()` helper function.
3. Inside the helper function, it calls `xSemaphoreTake(uart_mutex)` *again*.
4. Because the standard Mutex is already locked (by the task itself!), the RTOS puts the task to sleep infinitely waiting for the Mutex to be released. 
5. But the task is the one holding the Mutex, and it is now asleep, so it can never release it! Deadlock.
**Recursive Mutex:** A Recursive Mutex allows the *same* task to "Take" the mutex multiple times without blocking. The RTOS just increments a counter (e.g., Taken 2 times). The task must then "Give" it 2 times before it is actually unlocked for other tasks.

## Solution 2: The Watchdog Safety Net
**Answer:** The hardware Watchdog will **NOT** reset the system. 
A Deadlock only freezes the specific tasks involved. The RTOS Scheduler continues running perfectly. The `Task_Watchdog` (which is highest priority and not involved in the Mutex dispute) will happily wake up every 1 second, see that it has CPU time, and kick the hardware dog. The system will stay permanently powered on, but the UI and Sensors will be completely dead.
**The Fix:** `Task_Watchdog` must not blindly kick the hardware dog. It must use Event Groups or boolean flags updated by `Task_UI` and `Task_Sensors`. If `Task_Watchdog` notices that `Task_UI` hasn't updated its "I am alive" flag in the last 2 seconds, `Task_Watchdog` intentionally stops kicking the hardware dog, forcing a hard system reboot to clear the deadlock.
