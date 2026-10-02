# Solutions: Context Switching

## Solution 1: The Floating Point Penalty
**Answer:** The FPU on a Cortex-M4F contains an additional 32 massive registers (`S0-S31`). If a task uses the FPU, the RTOS is forced to `PUSH` all 32 of those floating-point registers onto the task's stack to save its context, and later `POP` them back. This requires pushing an extra 128 bytes of data over the memory bus every single time the task is paused, heavily increasing the latency of the context switch. Task A does not use the FPU, so the RTOS skips saving the `S` registers, making its context switch much faster.

## Solution 2: Stack Usage during Switching
**Answer:** The CPU registers are pushed directly onto **the currently running Task's private Stack** (and the new Stack Pointer is then saved to the TCB). 
They are NOT saved globally because an RTOS might have 50 tasks. If they were saved globally, the RTOS would need an enormous, complex global array to manage the snapshots. By pushing the registers onto the Task's own stack, the context data naturally stays physically bound to the task it belongs to. This is the primary reason why every RTOS task must be allocated enough Stack memory to hold its local variables *plus* the size of a full CPU register snapshot.
