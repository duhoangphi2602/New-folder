# Interview Questions: Critical Section

## 1. Mechanically, how does a Critical Section prevent an RTOS Task from being preempted?
**Answer:** A Critical Section writes to the CPU's hardware interrupt masking register (e.g., `PRIMASK` or `BASEPRI` on ARM Cortex-M) to physically disable hardware interrupts. Because the RTOS Scheduler relies on a hardware interrupt (the SysTick timer) to trigger Context Switches, disabling interrupts mathematically guarantees that the SysTick cannot fire, meaning the Scheduler cannot run, meaning the current task cannot be preempted by any other task.

## 2. Why must a Critical Section be kept as short as possible?
**Answer:** Because it globally blinds the CPU to all hardware events. If a Critical Section takes 500 microseconds to run, any hardware interrupt (UART byte arrival, GPIO button press, Motor timer) that occurs during that time will be delayed by 500 microseconds. This is called "Interrupt Latency". High latency destroys the "Real-Time" guarantees of an RTOS, leading to dropped network packets or physical hardware failures. A Critical Section should typically only last long enough to copy a variable (e.g., 3-5 CPU cycles).

## 3. What is the advantage of using a Mutex instead of a Critical Section to protect data shared between two Tasks?
**Answer:** A Mutex protects data purely through software logic. When Task A locks a Mutex, hardware interrupts remain fully enabled. Therefore, a high-priority Task C (which doesn't care about the Mutex) can instantly preempt Task A if it needs to. A Critical Section is a blunt instrument that stops *everything*. Mutexes provide surgical protection, preserving system responsiveness and low Interrupt Latency.
