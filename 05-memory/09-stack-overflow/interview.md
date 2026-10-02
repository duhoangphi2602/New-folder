# Interview Questions: Stack Overflow

## 1. What is a Stack Overflow in a bare-metal embedded system, and why is it so difficult to debug?
**Answer:** A Stack Overflow occurs when the call stack grows beyond its allocated memory boundary, moving downwards and overwriting the global `.data` and `.bss` memory segments. It is extremely difficult to debug because the microcontroller lacks a Memory Management Unit (MMU) to throw a Segmentation Fault. The system simply continues executing with silently corrupted global state variables, causing unpredictable and seemingly random logical failures elsewhere in the code.

## 2. What is a "Stack Canary" (or Watermark), and how does it help detect overflows?
**Answer:** A Stack Canary is a specific "magic number" (like `0xDEADBEEF`) written into the memory address at the exact boundary limit of the Stack. A background monitoring task periodically reads this address. If the value is still `0xDEADBEEF`, the Stack is safe. If the value has changed, it proves the Stack Pointer dropped past the boundary and overwrote the canary, indicating a Stack Overflow has occurred. The system can then safely trigger an emergency shutdown.

## 3. How does the presence of an MPU (Memory Protection Unit) solve the Stack Overflow problem at the hardware level?
**Answer:** An MPU allows the developer to define strict hardware access rules for specific memory regions. The developer can configure a small 32-byte region exactly at the bottom boundary of the Stack and mark it as "No Access" (`XN` / `No-Read/Write`). If the Stack Pointer ever overflows and attempts to write to this boundary, the MPU hardware will intercept the write and instantly trigger a `MemManage` exception. This immediately halts the CPU *before* any global variables are corrupted, providing a safe, guaranteed crash.
