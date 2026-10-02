# Exercises: Bare-Metal vs RTOS

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Infinite Loop Trap
You just learned RTOS. You write a Task to control a motor based on a hardware button.
```cpp
void vTaskMotor(void *pvParameters) {
    while(1) {
        if (button_is_pressed()) {
            motor_run();
        }
    }
}
```
You assign this Task a high priority. When you run the RTOS, the entire microcontroller completely freezes. No other tasks run, the WiFi drops, and the screen goes blank.
**Task:** Look at the `while(1)` loop. What critical RTOS function did you forget to call? Why does forgetting this completely destroy the RTOS?

## Exercise 2: When NOT to use an RTOS
Your manager asks you to design the firmware for a smart thermometer. 
- It uses an STM32 with 8 KB of RAM.
- It wakes up once an hour, reads the temperature, updates a low-power E-Ink display, and goes back to deep sleep.
- Total active time is 100 milliseconds per hour.
**Task:** Should you use FreeRTOS or a Bare-Metal Super Loop for this specific project? Provide two technical reasons for your choice.
