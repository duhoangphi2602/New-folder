# The NVIC (Nested Vectored Interrupt Controller)

## 1. Concept
The ARM Cortex-M CPU core does not handle hardware signals directly. Instead, all hardware peripherals (UART, Timers, GPIO) wire their interrupt signals into a dedicated hardware block called the **NVIC**.
The NVIC receives these signals, evaluates them, and then tells the CPU core: *"Stop what you are doing, jump to this specific memory address right now."*

## 2. "Vectored" Interrupts
In old 8-bit microcontrollers, all hardware interrupts caused the CPU to jump to a *single* ISR function. Inside that single function, you had to write a giant `switch` statement to figure out who caused the interrupt.
The NVIC is **Vectored**. This means it maintains a table of memory addresses (The Vector Table). When UART1 fires, the NVIC directly forces the CPU to jump to the `UART1_IRQHandler` function. When Timer2 fires, it jumps directly to `TIM2_IRQHandler`. No software `switch` statements are needed, making it incredibly fast.

## 3. "Nested" Interrupts (Preemption)
What happens if you are currently executing the UART ISR, and suddenly the Motor Timer interrupt fires?
The NVIC uses **Hardware Priority Levels** (usually 0 to 15, where 0 is the HIGHEST priority).
- If the Timer has Priority 5, and the UART has Priority 10: The Timer is higher priority (5 < 10). The NVIC will actually **preempt the UART ISR**. The CPU will save context, jump to the Timer ISR, finish the Timer ISR, return to finish the UART ISR, and finally return to the main `while(1)` loop. This is a **Nested Interrupt**.
- If the Timer has Priority 10, and the UART has Priority 5: The Timer is lower priority. The NVIC will put the Timer interrupt into a "Pending" state. The CPU finishes the UART ISR first, and then immediately runs the Timer ISR.

## 4. Hardware Priority vs RTOS Task Priority
This is a massive source of confusion for beginners.
- **RTOS Task Priority:** Managed by Software (The FreeRTOS Scheduler). Higher number = Higher priority. Only applies to Tasks.
- **NVIC Hardware Priority:** Managed by Silicon (The NVIC chip). Lower number = Higher priority. Applies only to ISRs.
**The Golden Rule:** *ANY* Hardware Interrupt, even the lowest priority one (Priority 15), will instantly preempt the highest priority RTOS Task in the system. Hardware ALWAYS beats Software.

## 5. Example
*(See `examples/` for a conceptual simulation of NVIC nesting).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
