# Context Switching

## 1. Concept
What exactly is a "Context"?
At any given microsecond, the state of the CPU is entirely defined by its **Registers**:
- `R0 - R15` (General purpose math registers)
- The **Program Counter (PC)** (Which line of code is executing)
- The **Stack Pointer (SP)** (Where the local variables are)
- The **Status Register (PSR)** (ALU flags like Negative/Zero)

When the Scheduler pauses Task A to run Task B, it must take a "snapshot" of all these registers so Task A can be perfectly resumed later. This snapshot is the Context.

## 2. The Mechanical Sequence
A Context Switch is almost entirely written in pure Assembly language inside the RTOS (e.g., `port.c` in FreeRTOS). The sequence is:

1. **Hardware Interrupt:** The SysTick timer fires. Hardware automatically pushes the Program Counter and some critical registers onto Task A's Stack.
2. **Save Context:** The RTOS assembly code executes `PUSH`, pushing the remaining CPU registers (`R4-R11`) onto Task A's Stack.
3. **Save Stack Pointer:** The RTOS reads the physical CPU Stack Pointer and saves it into Task A's Task Control Block (TCB).
4. **The Scheduler Algorithm:** The C code runs (`vTaskSwitchContext`), deciding that Task B should run next.
5. **Restore Stack Pointer:** The RTOS reads Task B's TCB to find where Task B's Stack is located, and updates the physical CPU Stack Pointer.
6. **Restore Context:** The RTOS assembly code executes `POP`, pulling Task B's registers off Task B's stack and into the CPU.
7. **Resume:** The ISR returns. The CPU automatically loads Task B's Program Counter, instantly resuming Task B exactly where it left off weeks ago.

## 3. The Cost (Overhead)
On an ARM Cortex-M4, a context switch takes roughly 150 to 300 clock cycles depending on the FPU (Floating Point Unit) state.
If your CPU runs at 100 MHz, a context switch takes about 3 microseconds.
This sounds fast, but consider the math:
- If SysTick is 1000 Hz (1ms): You spend 3us out of 1000us switching (0.3% CPU Overhead). This is excellent.
- If SysTick is 100,000 Hz (10us): You spend 3us out of 10us switching (30% CPU Overhead). Your CPU is wasting a third of its power just shuffling registers.

## 4. Example
*(See `examples/` for a demonstration of measuring context switch time).*

## 5. Voluntary vs Involuntary Switching
- **Involuntary (Preemption):** The SysTick timer fires, or a hardware interrupt wakes a higher priority task.
- **Voluntary (Yielding):** A Task calls `vTaskDelay()` or `taskYIELD()`. The task is manually asking the RTOS to trigger a Context Switch immediately without waiting for the SysTick.

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
