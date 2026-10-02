# Exercises: FreeRTOS Config

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Tick Rate Dilemma
Your manager wants the system to respond to a hardware event within exactly 50 microseconds. 
They look at `FreeRTOSConfig.h` and see `configTICK_RATE_HZ = 1000;` (1 millisecond). 
They order you to change it to `configTICK_RATE_HZ = 50000;` (50,000 Hz, or 20 microseconds) so the Scheduler runs faster and can process the event.
**Task:** Explain why setting the SysTick to 50,000 Hz is a terrible idea for a 84 MHz microcontroller. How should you architect the system to achieve a 50 microsecond response time *without* changing the standard 1000 Hz OS Tick Rate?

## Exercise 2: Stack Overflow Detection
You enable `configCHECK_FOR_STACK_OVERFLOW = 2`.
During testing, the system randomly crashes, and your debugger catches the execution inside the `vApplicationStackOverflowHook()` function.
You trace it back to `Task_Sensor`, which you created with a stack size of 128 Words (512 bytes).
Inside `Task_Sensor`, you see this code:
```cpp
void Task_Sensor(void *pvParams) {
    while(1) {
        float data_history[200]; 
        // ... perform calculations ...
        vTaskDelay(10);
    }
}
```
**Task:** Why did this task trigger a Stack Overflow? Do the math to prove it.
