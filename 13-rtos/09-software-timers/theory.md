# Software Timers

## 1. What is a Software Timer?
A Software Timer is an RTOS object that waits for a specified number of SysTick interrupts to occur. When the time expires, it executes a specific C function you provided, known as a **Callback Function**.
- **One-Shot:** The timer expires, runs the callback exactly *once*, and goes dormant. (e.g., A 5-second LCD backlight timeout).
- **Auto-Reload:** The timer expires, runs the callback, and instantly restarts itself. (e.g., Blinking an LED every 500ms forever).

## 2. How it works (The Daemon Task)
Software timers do NOT execute inside a hardware ISR. 
When you enable Software Timers in `FreeRTOSConfig.h` (`configUSE_TIMERS = 1`), FreeRTOS silently creates a hidden, high-priority background task called the **Timer Service Task** (or Daemon Task).
When the SysTick detects that 5 seconds have passed, it doesn't run your callback immediately. Instead, it sends a command to the Timer Service Task. The Timer Service Task wakes up and executes your callback function.

## 3. The Golden Rule of Timer Callbacks
Because your callback function is actually being executed by the shared Timer Service Task, **you must never, ever put the callback to sleep!**
If you call `vTaskDelay(100)` inside your timer callback, you are putting the entire OS Timer Service Task to sleep. Every other software timer in the entire system will immediately freeze. 
Timer callbacks must be lightning fast: set a flag, turn off an LED, or send to a Queue, and then immediately return.

## 4. Why use them? (RAM Savings)
If you want to blink an LED, you *could* create a Task:
```cpp
void vBlinkTask() { while(1) { toggle_led(); vTaskDelay(500); } }
```
This requires creating a TCB and a 512-byte Stack in RAM.
If you use a Software Timer, it requires **0 bytes of extra Stack**. It borrows the Stack of the Timer Service Task. You can create 50 Software Timers and they will all share the exact same Daemon stack, saving tens of kilobytes of RAM.

## 5. Example
*(See `examples/` for FreeRTOS Software Timer syntax).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
