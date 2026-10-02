# Process, Thread, and Task

## 1. Process (The Desktop Heavyweight)
A **Process** is an instance of an executing program (e.g., Google Chrome or Microsoft Word).
- **Isolation:** Every process has its own private Virtual Memory Space provided by the MMU (Memory Management Unit).
- **Security:** Process A cannot read or write the memory of Process B. If Process A crashes, Process B is completely unaffected.
- **Resource Heavy:** Creating a process takes significant time and RAM. Context switching between processes requires flushing MMU caches, which takes thousands of CPU cycles.
*Note: Cortex-M microcontrollers do not have an MMU, so they cannot run true isolated Processes (meaning they cannot run standard Linux).*

## 2. Thread (The Shared Worker)
A **Thread** is a unit of execution *inside* a Process.
- **Shared Memory:** All threads inside a Process share the exact same global variables (`.data` / `.bss`) and the same Heap.
- **Private Memory:** Each thread gets its own private **Stack** to store its local variables.
- **Danger:** Because memory is shared, Thread 1 can easily overwrite a variable that Thread 2 is currently reading. This causes Race Conditions.

## 3. RTOS Task (The Embedded Thread)
In a Real-Time Operating System (like FreeRTOS), we don't have Processes. The entire firmware binary is one giant, single program. 
Within this single program, the RTOS creates **Tasks**.
- **Definition:** An RTOS Task is conceptually identical to a Desktop Thread. 
- **Memory Layout:** All Tasks share the same global memory, but each Task is assigned its own private piece of RAM to act as its Stack.
- **C++ Note:** Desktop C++ uses `std::thread`. Bare-metal embedded systems do not support `std::thread`. You must use the specific RTOS API (e.g., `xTaskCreate` in FreeRTOS) to spawn tasks.

## 4. The Memory Diagram

```text
DESKTOP SYSTEM (Linux/Windows)
---------------------------------
[ Process 1 (App A) ]  [ Process 2 (App B) ]
|-- Thread 1           |-- Thread 1
|-- Thread 2           |-- Thread 2
(MMU ISOLATED)         (MMU ISOLATED)

EMBEDDED RTOS (Cortex-M)
---------------------------------
[ Single Firmware Binary ]
|-- Task 1 (Sensors)      <-- Has its own Stack
|-- Task 2 (Display)      <-- Has its own Stack
|-- Task 3 (Networking)   <-- Has its own Stack
(ALL MEMORY IS SHARED)
```

## 5. Example
*(See `examples/` for a visual simulation of shared memory between Tasks).*

## 6. Trade-offs (Isolation vs Speed)
Because RTOS Tasks share all memory, an embedded system is incredibly fast. Context switching between Tasks is blazing fast because there is no MMU to configure. However, the trade-off is security and stability: If Task 1 has a dangling pointer and overwrites random memory, it might corrupt Task 2's data, causing the entire microcontroller to crash.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
