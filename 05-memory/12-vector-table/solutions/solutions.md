# Solutions: The Vector Table

## Solution 1: The Initial Stack Pointer
**Answer:** The `Reset_Handler` is a function (usually written in C or Assembly). In order to execute *any* function call, or push *any* local variables, the CPU must have a valid Stack. If the Stack Pointer isn't configured *before* jumping to the `Reset_Handler`, the CPU cannot execute the `Reset_Handler` safely. By hardcoding the Initial Stack Pointer at address `0x00000000`, the hardware automatically initializes the `SP` register at the exact moment power is applied, guaranteeing a safe environment before a single line of software is executed.

## Solution 2: Infinite Loops
**Answer:** Unused interrupts shouldn't fire. If an unused interrupt fires, it means the developer made a critical configuration error in the hardware registers, or electrical noise triggered a ghost signal. If the `Default_Handler` simply returns, the system will continue operating with a broken, unpredictable hardware state, which could be catastrophic in a real-time system. By trapping the CPU in a `while(1)` loop, the system safely halts, and the developer can connect a debugger, pause the CPU, and look at the Call Stack to immediately identify exactly which rogue interrupt fired.
