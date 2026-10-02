# Embedded Startup

## 1. Concept
The **startup sequence** is the small program (usually written in a mix of Assembly and C) that runs immediately upon a CPU reset. It is responsible for setting up the hardware and memory so that the standard C/C++ execution environment functions correctly.

## 2. Why
When you compile `int my_var = 42;`, that `42` is burned into the Flash memory of the microcontroller. However, C/C++ guarantees that `my_var` is a mutable variable in RAM. Hardware doesn't automatically move that `42` from Flash to RAM; the startup code must manually copy it before `main()` starts. If this code fails, global variables will contain garbage data.

## 3. Syntax / Flow (ARM Cortex-M Boot Sequence)

1. **Power On / Reset**: Hardware reads the very first address in Flash (Vector Table `[0]`) to get the initial Stack Pointer (SP) and loads it into the CPU register.
2. **Jump to Code**: Hardware reads the second address (Vector Table `[1]`), which is the `Reset_Handler` function pointer, and jumps the CPU there.
3. **Copy `.data`**: The `Reset_Handler` loops through Flash memory and copies the initial values of global variables into RAM.
4. **Zero `.bss`**: The `Reset_Handler` loops through the `.bss` section in RAM and writes `0` to every byte (initializing unassigned global variables to 0).
5. **C++ Constructors**: Calls `__libc_init_array()` to execute global C++ constructors.
6. **Enter Application**: Calls `main()`.

## 4. Example
*(See `examples/` for a simulated C-implementation of a `Reset_Handler`).*

```text
Flash (ROM):                   RAM:
┌──────────────┐               ┌──────────────┐
│ Vector Table │               │ .data        │ ← Copied from Flash
│ .text (code) │               │ .bss         │ ← Zero-filled
│ .rodata      │               │              │
│ .data (init) │──── COPY ────→│              │
└──────────────┘               │ heap ↑       │
                               │ stack ↓      │
                               └──────────────┘
```

## 5. Embedded usage (The Linker Script)
How does the `Reset_Handler` know where `.data` starts and ends? 
It gets this information from the **Linker Script** (`.ld`). 
The linker script calculates the final memory addresses and exports them as symbols (e.g., `_sdata`, `_edata`). The startup code declares these symbols as `extern` variables so it can use them as pointers for the copy loops.

```c
// Provided by the Linker Script
extern uint32_t _sidata; // Source: Start of .data in Flash
extern uint32_t _sdata;  // Dest: Start of .data in RAM
extern uint32_t _edata;  // Dest: End of .data in RAM

// Inside Reset_Handler...
uint32_t* src = &_sidata;
uint32_t* dst = &_sdata;
while (dst < &_edata) {
    *dst++ = *src++;     // The actual copy operation
}
```

## 6. Trade-offs

| Startup Implementation | Pros | Cons |
|------------------------|------|------|
| **Vendor Provided (Assembly)** | Highly optimized. Usually flawless. | Very difficult to read or modify if you need custom boot behavior. |
| **Custom C Code** | Easy to read, debug, and modify. | Slower execution. Requires precise compiler flags to prevent using the stack before it's ready. |
| **Bootloader** | Allows OTA updates. Sets up RAM, then jumps to *another* application's startup. | Complex memory mapping required. |

## 7. Exercises
Please proceed to the `exercises/` folder to practice linking concepts with startup logic.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
