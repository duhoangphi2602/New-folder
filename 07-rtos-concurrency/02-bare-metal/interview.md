# Interview Questions: Bare-Metal Programming

## 1. What is the fundamental difference between a Blocking function and a Non-Blocking function in a Bare-Metal environment?
**Answer:** A blocking function halts the execution of the CPU until a task is completely finished (e.g., `delay_ms(100)`, or a `while(!UART_READY);` loop waiting for a transmission to complete). This paralyzes the entire system. A non-blocking function checks the state of the hardware or a timer, does a tiny piece of work if ready, and immediately returns, allowing the main Super Loop to continue executing other tasks.

## 2. In a Bare-Metal Super Loop, how do you handle tasks that have vastly different timing requirements (e.g., blinking an LED every 1 second, and reading a fast sensor every 5 milliseconds)?
**Answer:** You use non-blocking State Machines driven by a hardware System Tick Timer (usually ticking every 1 millisecond). Inside the `while(1)` loop, the LED function checks if 1000 ticks have passed since its last execution. If not, it returns instantly. The sensor function checks if 5 ticks have passed. This ensures both tasks execute at their required frequencies without blocking one another.

## 3. At what point does a project become too complex for a Bare-Metal architecture, requiring an RTOS?
**Answer:** A Bare-Metal architecture fails when you have asymmetric workloads coupled with strict timing deadlines. If you have a math-heavy calculation (like FFT audio processing or networking encryption) that takes 200ms to compute, the Super Loop will be frozen for 200ms. If you also have a motor-control loop that mathematically requires an update every 10ms to prevent the motor from stalling, the bare-metal architecture cannot satisfy both. An RTOS is required because its Preemptive Scheduler can force the 200ms math calculation to pause every 10ms, give CPU time to the motor, and then resume the math calculation.
