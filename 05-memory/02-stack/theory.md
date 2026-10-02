# The Stack

## 1. Concept
The Stack is a contiguous block of RAM allocated by the compiler. It operates on a **LIFO (Last-In, First-Out)** principle, exactly like a stack of plates in a cafeteria. 
When a function is called, a "Stack Frame" (a new plate) is pushed onto the top of the stack. This frame holds the function's local variables, arguments, and the return address. When the function finishes, the frame is popped off, instantly freeing the memory.

## 2. Why
The Stack is the fastest memory allocation mechanism in computer science. Allocating memory on the Stack takes exactly 1 clock cycle: the CPU simply subtracts a number from a dedicated hardware register called the Stack Pointer (SP). Deallocating takes 1 clock cycle: it adds the number back. There is no searching, no fragmentation, and no Garbage Collector.

## 3. How it Works (The Stack Pointer)
Assume the Stack Pointer (`SP`) starts at the very top of RAM (`0x20001000`). On ARM Cortex-M, the stack grows *downwards* toward `0x20000000`.

```cpp
void calculate() {
    int x = 5;      // SP moves down 4 bytes. x is stored at SP.
    int y = 10;     // SP moves down 4 bytes. y is stored at SP.
    
    // Do math...
    
} // Function ends! SP instantly moves UP 8 bytes. x and y are gone!
```

## 4. Example
*(See `examples/` for runnable code demonstrating memory addresses changing as the Stack grows).*

## 5. Embedded usage (Stack Limits)
In a C++ PC program, your Stack is usually 8 Megabytes. You never think about it.
In an RTOS (Real-Time Operating System) on a microcontroller, every single task gets its own private Stack, which might be exactly **256 Bytes**!

```cpp
void read_sensor() {
    // FATAL ERROR! 
    // This array takes 1024 bytes. If your RTOS task stack is only 256 bytes,
    // the Stack Pointer will plow through the bottom of the stack and overwrite
    // the variables of other tasks, causing a massive system crash.
    uint8_t buffer[1024]; 
    
    // ...
}
```
**Golden Rule of Embedded:** Never allocate large arrays or complex objects on the Stack. If you need a large buffer, allocate it globally (Static Storage) so the compiler can track it.

## 6. Trade-offs (Stack vs Global Memory)
If the Stack is so dangerous for large items, why not just make every variable global?
1. **Memory Inefficiency:** Global variables consume RAM permanently, forever. Stack variables only consume RAM while their specific function is running, allowing different functions to reuse the exact same RAM.
2. **Reentrancy:** If an Interrupt fires and calls a function that uses Global variables, it will overwrite the data the main loop was working on. Stack variables are inherently thread-safe because every function call gets a brand-new, unique Stack Frame.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
