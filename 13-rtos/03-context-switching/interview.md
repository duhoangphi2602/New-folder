# Interview Questions: Context Switching

## 1. What physically happens during an RTOS Context Switch?
**Answer:** During a Context Switch, the RTOS executes a low-level Assembly routine. It halts the currently executing Task and pushes all current CPU registers (the "Context" - R0-R15, Program Counter, Status Registers) onto that specific Task's dedicated RAM Stack. It then saves the current Stack Pointer address into that Task's Task Control Block (TCB). Next, the RTOS retrieves the Stack Pointer for the *new* Task from its TCB, updates the physical CPU Stack Pointer, and pops the saved registers out of the new Task's RAM Stack back into the physical CPU. Finally, it jumps to the restored Program Counter, seamlessly resuming the new Task.

## 2. Why does implementing an RTOS drastically increase the RAM footprint of an embedded system?
**Answer:** In a Bare-Metal system, the entire program operates within a single execution thread and utilizes one contiguous Stack in RAM. When using an RTOS, every single Task created (and the OS Idle task) requires its own mathematically isolated, dedicated Stack in RAM to safely store its Context (CPU registers) and local variables when it is preempted. If you have 10 tasks, and you allocate 1KB of stack for each, you immediately consume 10KB of RAM just for task infrastructure, which is a massive footprint for a 32KB microcontroller.

## 3. What is a "Task Control Block" (TCB)?
**Answer:** The TCB is a C-struct internally maintained by the RTOS in RAM for every task created. It acts as the task's identity card. The RTOS uses it to track the Task's current State (Running, Ready, Blocked), its Priority level, its human-readable string name (for debugging), and most importantly, the pointer to the absolute top of the Task's dedicated Stack. When the Scheduler iterates through the Ready List to find the next task to run, it is iterating through an array or linked list of these TCBs.
