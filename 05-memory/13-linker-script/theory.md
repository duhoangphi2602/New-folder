# The Linker Script

## 1. Concept
The GNU Linker Script (usually `STM32F401RETX_FLASH.ld`) acts as the bridge between Software Concepts and Physical Silicon. 
It consists of two main parts:
1. **The `MEMORY` command:** Defines the physical start addresses and exact sizes of the RAM and Flash chips.
2. **The `SECTIONS` command:** Defines the rules for taking the compiler's output (`.text`, `.data`) and stuffing them into the regions defined in `MEMORY`.

## 2. Why
If you try to write a program that uses 30KB of RAM, but the `MEMORY` command in the Linker Script says `RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 20K`, the Linker will mathematically calculate that it won't fit, and it will intentionally fail the build with an overflow error *before* you try to flash the board.

## 3. Syntax (A Basic Linker Script)

```ld
/* 1. Define the physical hardware boundaries */
MEMORY
{
  FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 512K
  RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 96K
}

/* 2. Define the exact layout of the final binary */
SECTIONS
{
  /* The Vector Table MUST be at the very start of Flash! */
  .isr_vector :
  {
    KEEP(*(.isr_vector)) /* Don't let the optimizer delete this! */
  } >FLASH

  /* The actual code */
  .text :
  {
    *(.text)           /* Take all .text from all .cpp files */
    *(.rodata)         /* Take all constants */
  } >FLASH

  /* Initialized variables */
  .data :
  {
    _sdata = .;        /* Create a variable here to mark the START */
    *(.data)
    _edata = .;        /* Create a variable here to mark the END */
  } >RAM AT> FLASH     /* Live in RAM, but store the initial values in FLASH! */

  /* Uninitialized variables */
  .bss :
  {
    _sbss = .;
    *(.bss)
    _ebss = .;
  } >RAM
}
```

## 4. Example
*(See `examples/` for a C++ code snippet that uses Linker Script variables).*

## 5. Embedded usage (Connecting to Startup Code)
Look at the `_sdata` and `_edata` lines in the script above. The `.` means "The Current Memory Address". 
By declaring `_sdata = .;`, the Linker Script is literally creating a memory address pointer. 
Your Startup Code (from Topic 11) imports these exact variables (`extern uint32_t _sdata;`) so it knows exactly where the `.data` section begins and ends in RAM, allowing it to execute the physical copy loop!

## 6. Trade-offs (Custom Linker Scripts)
Editing a Linker Script is dangerous. If you misalign the `.isr_vector` section, the CPU will read garbage on boot and instantly Hard Fault. 
However, editing it is required for advanced features. For example, if you want to save user settings to Flash memory, you must edit the Linker Script to carve out a 4KB chunk of the `FLASH` region (e.g., `USER_DATA (rx) : ORIGIN = 0x0807F000, LENGTH = 4K`) so the Linker doesn't accidentally put `.text` code in the same area you plan to erase!

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
