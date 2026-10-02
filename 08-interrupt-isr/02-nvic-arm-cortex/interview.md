# Interview Questions: The NVIC

## 1. What does the "Nested" in NVIC mean?
**Answer:** "Nested" means that an Interrupt Service Routine (ISR) can itself be interrupted by another ISR. If the CPU is currently executing an ISR, and a new hardware interrupt fires that has a *higher* hardware priority (a lower number on ARM) than the currently running ISR, the NVIC will force the CPU to pause the first ISR, push its state to the stack, execute the second ISR, and then return to finish the first. This allows ultra-critical systems (like motor control) to preempt less critical interrupts (like a button press).

## 2. In ARM Cortex-M processors, how does the NVIC priority numbering system differ from the FreeRTOS task priority system?
**Answer:** They are exact opposites. In FreeRTOS, a higher number means a higher software priority (e.g., Task Priority 5 preempts Task Priority 1). In the ARM NVIC, a lower number means a higher hardware priority (e.g., Hardware Priority 1 preempts Hardware Priority 5). Priority 0 is the absolute highest hardware priority and cannot be masked by the RTOS.

## 3. What happens if two interrupts with the exact same NVIC priority fire at the exact same microsecond?
**Answer:** The NVIC handles this using a secondary system called "Sub-Priorities" or by falling back to the hardcoded hardware Vector Table index. The interrupt that has the lower hardware exception number (e.g., it is physically listed earlier in the Vector Table in memory) will be serviced first. The other interrupt will be placed in a Pending state and executed immediately afterward.
