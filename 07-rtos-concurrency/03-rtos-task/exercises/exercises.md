# Exercises: RTOS Task

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Starvation Bug
A junior engineer writes a Motor Control Task. The motor must be updated as fast as physically possible.
```c
void MotorTask(void* pvParameters) {
    while(1) {
        update_pid_loop();
        set_pwm();
        // Note: No vTaskDelay here! We want maximum speed!
    }
}
```
This task is assigned Priority 5. The Wi-Fi Task is assigned Priority 2.
**Task:** What will happen to the Wi-Fi connection, and why?

## Exercise 2: Task Return Values
In Desktop C++, a `main()` function returns an `int`. 
In FreeRTOS, a task is defined as `void TaskName(void* pvParameters)`.
**Task:** Why doesn't an RTOS task return a value? If an RTOS task executes the `return;` statement, what happens to the system?
