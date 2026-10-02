# Interview Questions: Interrupt Concept

## 1. What is the fundamental difference between Polling and Interrupt-driven architecture?
**Answer:** Polling is a synchronous, software-driven architecture where the CPU continuously checks a hardware register in a loop to see if an event occurred, wasting massive amounts of CPU cycles and power. Interrupt-driven architecture is asynchronous and hardware-driven; the CPU executes its main program normally (or goes to sleep) until a hardware peripheral sends a physical electrical signal to the CPU, forcing it to immediately pause and execute an Interrupt Service Routine (ISR) to handle the event.

## 2. When a hardware interrupt fires, what exactly does the CPU do with its current execution state?
**Answer:** The CPU performs an automatic, hardware-level Context Save. Before jumping to the ISR, it pushes the Program Counter (PC) of the currently executing instruction, the Status Register (PSR), and several General Purpose Registers (usually `R0-R3`, `R12`, and `LR` on ARM Cortex-M) onto the current active Stack. This snapshot guarantees that when the ISR finishes, the CPU can pop these registers off the stack and perfectly resume the interrupted code without corrupting any mathematical calculations that were in progress.

## 3. What is a "Software Interrupt" or "Exception"? Give an example.
**Answer:** A Software Interrupt (often called an Exception or a Trap) operates mechanically identical to a hardware interrupt (saving context and jumping to a Vector Table address), but it is triggered internally by the CPU executing a specific instruction or detecting an error. Examples include a "Divide by Zero" exception, a "Hard Fault" (attempting to write to read-only Flash memory), or explicitly executing the `SVC` (Supervisor Call) instruction, which is how RTOS tasks request the Scheduler to perform privileged operations.
