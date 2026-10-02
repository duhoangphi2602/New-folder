# Exercises: Deadlocks

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Single Task Deadlock
Deadlocks usually involve two or more tasks. However, it is possible for a single task to deadlock itself using only one Mutex.
```cpp
void vTaskSelfDestruct(void *pvParams) {
    while(1) {
        xSemaphoreTake(uart_mutex, portMAX_DELAY);
        
        // Call a helper function to print
        print_to_console("Hello");
        
        xSemaphoreGive(uart_mutex);
    }
}

void print_to_console(char* str) {
    xSemaphoreTake(uart_mutex, portMAX_DELAY);
    printf("%s\n", str);
    xSemaphoreGive(uart_mutex);
}
```
**Task:** Trace the execution of this code. What exactly happens on the very first loop, and why does the task freeze forever? (Note: FreeRTOS has a special type of Mutex called a "Recursive Mutex" designed specifically to fix this exact architectural mistake. What do you think a Recursive Mutex allows a task to do?)

## Exercise 2: The Watchdog Safety Net
You have an RTOS system with an Independent Hardware Watchdog Timer (IWDG) configured to reset the system if it isn't kicked every 2 seconds.
You have a low-priority `Task_UI` and a high-priority `Task_Sensors` that share Mutexes.
You put the "Kick Watchdog" command inside a dedicated highest-priority `Task_Watchdog` that wakes up every 1 second, checks if the system is okay, and kicks the dog.
**Task:** If `Task_UI` and `Task_Sensors` enter a Deadlock, will the hardware Watchdog reset the system? Why or why not? How must you architect `Task_Watchdog` so it can actually detect a Deadlock?
