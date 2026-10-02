# Bare-Metal vs RTOS

## 1. The Bare-Metal Super Loop
In bare-metal programming, your entire system logic lives inside one infinite loop:
```cpp
int main() {
    while(1) {
        read_sensor();     // Takes 5ms
        update_screen();   // Takes 50ms
        process_wifi();    // Takes 200ms
    }
}
```
**The Problem:** Execution is strictly sequential. If `process_wifi()` gets stuck waiting for a server for 2 seconds, the screen will completely freeze for 2 seconds. The sensor will miss critical data. You can try to fix this with complex State Machines and Non-Blocking Delays, but as the project grows to 50,000 lines of code, the Super Loop becomes an unmaintainable "Spaghetti Code" nightmare.

## 2. Enter the RTOS
An RTOS (like FreeRTOS or Zephyr) is a tiny piece of software (often just 5-10 KB) that runs on the microcontroller. 
It completely replaces the concept of a single Super Loop. Instead, you write multiple, independent `while(1)` loops, called **Tasks** (or Threads).
```cpp
void Task_WiFi() { while(1) { process_wifi(); } }
void Task_Screen() { while(1) { update_screen(); } }
```
The RTOS acts as a traffic cop. It rapidly switches the CPU's attention between these tasks (thousands of times a second). To the human eye, it looks like the WiFi and the Screen are running perfectly in parallel on two separate CPUs, even though there is only one core.

## 3. What does "Real-Time" mean?
An RTOS is *not* necessarily "fast". Your laptop's Windows OS is a million times faster than a 16 MHz microcontroller running FreeRTOS.
"Real-Time" means **Deterministic**. 
In Windows, if you click a button, the OS might process it in 1ms, or it might decide to run an antivirus scan and process it in 500ms. Windows prioritizes overall system throughput (Fairness).
An RTOS prioritizes **Deadlines**. If you tell an RTOS that the Airbag Deployment Task is the highest priority, the RTOS guarantees mathematically that when a crash is detected, the Airbag Task will execute within exactly *X* microseconds, completely ignoring all other tasks.

## 4. The Cost of an RTOS
An RTOS is not free. 
- **RAM Overhead:** Every single Task requires its own dedicated Stack in RAM. If you have 10 tasks, you consume a massive chunk of RAM just to keep the OS running.
- **CPU Overhead:** The RTOS takes CPU cycles to figure out which task should run next (Scheduling).
If you only have 2 KB of RAM (like an Arduino Uno), an RTOS will crash. Bare-metal is still required for ultra-constrained chips.

## 5. Example
*(See `examples/` for a structural comparison of the code).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
