# Exercises: Critical Section

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Missing Exit
A C programmer writes the following code to protect a shared buffer:
```c
void write_buffer() {
    taskENTER_CRITICAL();
    if (buffer_full()) {
        return;
    }
    buffer[index++] = 0xFF;
    taskEXIT_CRITICAL();
}
```
**Task:** If the buffer is full, what exact sequence of mechanical failures will occur in the microcontroller?

## Exercise 2: Latency Analysis
You have a motor control ISR that MUST run every 1,000 microseconds (1ms) to keep the motor balanced. 
In a low-priority UI task, a developer wraps a slow screen-clearing function in a Critical Section. The screen-clearing function takes 3,000 microseconds (3ms) to execute.
**Task:** Even though the UI task is "Low Priority" and the Motor ISR is a "Hardware Interrupt", what will happen to the motor, and why?
