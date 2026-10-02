# Solutions: FreeRTOS Config

## Solution 1: The Tick Rate Dilemma
**Answer:** Setting the Tick Rate to 50,000 Hz means the CPU is interrupted 50,000 times a second to run the RTOS Kernel. A Context Switch takes CPU cycles (pushing/popping 16 registers). At 50kHz, an 84 MHz CPU will spend over 50% of its entire processing power just jumping in and out of the OS Scheduler, leaving almost no CPU time for actual application math. The system will grind to a halt.
**The Fix:** Keep the Tick Rate at 1000 Hz. To achieve a 50us response, you use a **Hardware Interrupt (ISR)**. You configure a GPIO interrupt. When the event happens, the CPU physically preempts the RTOS, runs the ISR instantly (within ~1 microsecond), processes the event, and returns to the RTOS. Hardware interrupts completely bypass the OS Tick limitations.

## Solution 2: Stack Overflow Detection
**Answer:** The task declares a local array: `float data_history[200];`.
In C, local variables are stored on the Stack. 
A `float` is 4 bytes. 200 floats = 800 bytes.
You only allocated 512 bytes of Stack memory for this entire Task. 
The moment the C compiler tries to push that array onto the stack, it blows 288 bytes past the end of the allocated memory, corrupting whatever task stack or OS data is sitting adjacent to it in RAM. 
When a context switch occurs, the RTOS sees the memory boundary was breached and correctly fires the Overflow Hook.
**The Fix:** Either increase the task's stack size to `(300)` Words (1200 bytes), or make the array `static` so it is stored in the global `.bss` section instead of the Task Stack.
