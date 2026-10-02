# Chapter 05 — Interview Questions

## Beginner

1. **What is the difference between stack and heap?**
   Stack: automatic storage, allocated/freed with function calls, LIFO, fast, size limited. Heap: dynamic storage, allocated/freed explicitly (`malloc`/`new`), slower, risk of fragmentation.

2. **What is the `.bss` section?**
   The memory section for zero-initialized or uninitialized global/static variables. It's not stored in Flash — the startup code fills it with zeros at boot.

3. **What is the `.data` section?**
   The section for global/static variables initialized to non-zero values. Their initial values are stored in Flash and copied to RAM by the startup code.

## Intermediate

4. **Why does `.data` cost both Flash AND RAM?**
   The initial values must be stored in Flash (persistent). At runtime, the variables need to be in RAM (writable). The startup code copies from Flash to RAM.

5. **What is a linker script?**
   A file that tells the linker how to map code and data sections to physical memory regions (Flash, RAM). It defines memory origins, sizes, and section placement.

6. **What happens if you declare a large local array inside a function?**
   It's allocated on the stack. If the array is too large, it causes a stack overflow — the stack pointer goes past the allocated stack region, corrupting other memory.

7. **What is heap fragmentation and why is it dangerous in embedded?**
   After many allocations and frees of different sizes, the heap develops many small "holes" that can't satisfy larger allocation requests. In long-running embedded systems, this can cause allocation failures even when total free memory is sufficient.

## Advanced

8. **Walk through the firmware memory lifecycle from compilation to execution.**
   Compile → Object files → Linker (with linker script) → ELF → objcopy → BIN → Flash to MCU → Power on → CPU reads vector table → Reset_Handler → Copy `.data` from Flash to RAM → Zero `.bss` → SystemInit → Global constructors → `main()`.

9. **What are `_sidata`, `_sdata`, `_edata` symbols?**
   Linker-exported symbols: `_sidata` = start of `.data` initial values in Flash, `_sdata` = start of `.data` in RAM, `_edata` = end of `.data` in RAM. Used by startup code to copy initialized data from Flash to RAM.

10. **What is the vector table?**
    An array of addresses at the start of Flash. Index 0 = initial stack pointer value. Index 1 = Reset_Handler address. Remaining entries = addresses of interrupt service routines.

11. **How do you check the memory usage of a firmware binary?**
    Use `arm-none-eabi-size firmware.elf` which shows `text` (code+rodata in Flash), `data` (initialized data, costs Flash+RAM), and `bss` (zero-init data, RAM only).
