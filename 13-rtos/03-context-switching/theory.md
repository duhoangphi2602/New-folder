# Context Switching

## 1. What is a "Context"?
The CPU is just a calculator. It has internal hardware memory slots called **Registers** (e.g., `R0`, `R1`, `R2`). 
When a Task is doing math (`int z = x + y;`), `x` might be in `R0`, `y` in `R1`, and the result in `R2`.
The CPU also has a **Program Counter (PC)** (which line of code it's executing) and a **Stack Pointer (SP)** (where its local variables are in RAM).
The complete set of all these Registers at any exact nanosecond is called the **Task's Context**.

## 2. The Multi-Tasking Illusion
If Task A is doing math (using `R0`), and the RTOS suddenly preempts it to run Task B, Task B will *also* try to use `R0` for its own math. Task B will overwrite Task A's data! When the RTOS switches back to Task A, Task A will calculate the wrong number.
To prevent this, the RTOS must perform a **Context Switch**.

## 3. The Context Switch Process
When the SysTick interrupt fires and the Scheduler decides to switch from Task A to Task B, the RTOS Kernel executes raw Assembly code:
1. **Save Context:** The OS takes all 16 CPU Registers (`R0-R15`) currently holding Task A's data and physically pushes them into **Task A's dedicated Stack in RAM**.
2. **Save SP:** The OS saves Task A's current Stack Pointer address into a global internal variable (`TCB_A->pxTopOfStack`).
3. **Switch SP:** The OS reads Task B's Stack Pointer address from its internal variable (`TCB_B->pxTopOfStack`) and writes it into the physical CPU Stack Pointer register.
4. **Restore Context:** The OS physically pops all 16 CPU Registers out of **Task B's Stack in RAM** and puts them back into the physical CPU registers.
5. **Resume:** The OS jumps to Task B's Program Counter. Task B resumes execution completely unaware it was ever paused.

## 4. The TCB (Task Control Block)
How does the RTOS keep track of all this? Every time you create a task (`xTaskCreate`), the OS allocates a small C-struct in RAM called the **Task Control Block (TCB)**. 
The TCB holds the Task's Priority, its State (Ready/Blocked), and critically, the pointer to the top of its Stack.

## 5. Why Every Task Needs a Stack
In Bare-Metal, you have 1 stack. In RTOS, you have N stacks. 
Because a Context Switch involves dumping all 16 CPU registers into RAM, every single task *must* have a dedicated chunk of RAM (its own Stack) to store its Context safely while it sleeps. If you allocate 128 bytes for a Stack, but the Context + local variables exceed 128 bytes, it corrupts the memory of the adjacent Task, causing a catastrophic **Stack Overflow**.

## 6. Example
*(See `examples/` for a visual representation of RAM during a switch).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
