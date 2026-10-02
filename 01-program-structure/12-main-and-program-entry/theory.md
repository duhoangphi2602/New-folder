# main() and Program Entry

## 1. Concept
In C/C++, `main()` is the standardized entry point for the *application logic*. However, it is **never** the first piece of code executed by the CPU. There is always a layer of "Startup Code" that prepares the environment before `main()` is called.

## 2. Why
Before C/C++ code can run, it needs a stack to push local variables onto. It needs global variables to be initialized in RAM. It needs the C++ standard library (or hardware clocks) to be initialized. The startup code does all of this heavy lifting.

## 3. Desktop vs Embedded Flow

### Desktop (`main` with OS)
On a PC (Windows/Linux/Mac), the Operating System's loader does most of the hard work.
```text
OS Loader (sets up memory) → C Runtime Startup (crt0) → Calls main(argc, argv) → OS cleans up
```

### Embedded (Bare-Metal)
On a microcontroller, there is no OS. The CPU wakes up, reads the Reset Vector to find where the code starts, and executes custom assembly/C code written by the hardware vendor (or you).
```text
Power On → Hardware Reset Vector → Startup Code (copies Flash to RAM) → Calls main()
```

## 4. Example
*(See `examples/` for a demonstration of a bare-metal `main()` template).*

```cpp
int main(void) {
    // 1. Hardware Initialization
    system_clock_init();
    gpio_init();

    // 2. The Super Loop
    while (true) {
        // Read sensors
        // Process data
        // Update outputs
    }

    // 3. NEVER REACHED
    return 0; 
}
```

## 5. Embedded usage (The Super Loop)
In bare-metal embedded programming, `main()` must **never return**. 
If a desktop program returns from `main()`, control is handed gracefully back to the OS. 
If an embedded program returns from `main()`, it hands control back to... nothing. The CPU will likely crash, throw a hardware fault, or jump to an invalid memory address. 
Therefore, all embedded firmware relies on an infinite loop (the "Super Loop" or an RTOS task scheduler) to keep the CPU continuously executing valid code.

## 6. Trade-offs

| Architecture | Entry Point | Exit Behavior |
|--------------|-------------|---------------|
| **Desktop / Linux OS** | `int main(int argc, char** argv)` | `return 0;` (OS reclaims memory) |
| **Bare-Metal MCU** | `int main(void)` | `while(1) {}` (Must never exit) |
| **RTOS (FreeRTOS)** | `int main(void)` | Starts the task scheduler (`vTaskStartScheduler()`); never returns. |

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
