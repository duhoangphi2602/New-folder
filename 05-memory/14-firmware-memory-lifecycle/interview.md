# Interview Questions: Firmware Memory Lifecycle

## 1. Trace the physical memory lifecycle of a global variable declared as `int state = 42;`.
**Answer:** 
1. **Compilation:** The compiler marks `state` as belonging to the `.data` segment.
2. **Linking:** The linker assigns `state` a virtual execution address in RAM, but packs the actual value `42` into the Flash payload of the `.bin` file.
3. **Flashing:** The `42` is permanently burned into the silicon of the Flash ROM chip.
4. **Booting (Startup):** Upon power-up, the Assembly Startup Code loops through the Flash payload and physically copies the `42` over the hardware bus into the variable's designated RAM address.
5. **Execution:** The CPU reads and modifies the variable purely from the RAM chip. If power is lost, the RAM resets, but the original `42` remains safe in Flash for the next boot.

## 2. In a bare-metal embedded system, why does a C++ program usually require a heavier Startup Code than a pure C program?
**Answer:** While both C and C++ require the startup code to initialize the Stack Pointer, copy `.data`, and zero-out `.bss`, C++ introduces Object-Oriented paradigms. Specifically, global and static C++ objects may have custom Constructors that must execute to set up their internal state. The C++ Startup Code must iterate through an array of function pointers (usually `.init_array`) and manually execute every single global object's Constructor *before* branching to `main()`. If this step is missing, global C++ objects will be completely broken at runtime.

## 3. What is the difference between a Compiler Error, a Linker Error, and a Runtime Hardware Fault in the context of memory?
**Answer:** 
- **Compiler Error:** Fails during the translation of a single `.cpp` file. (e.g., trying to write to a `const` variable stored in `.rodata`).
- **Linker Error:** Fails when combining all files into the final binary. (e.g., "RAM overflow" because the sum of all `.data` and `.bss` global variables exceeds the physical RAM limits defined in the `.ld` Linker Script).
- **Runtime Hardware Fault:** Compiles and links perfectly, but crashes on the physical chip. (e.g., A "Hard Fault" caused by a Stack Overflow overwriting global memory, or an Unaligned Memory Access exception).
