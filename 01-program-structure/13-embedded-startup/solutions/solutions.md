# Solutions: Embedded Startup

## Solution 1: Identifying Memory Sections
**Answer:**
- `system_status`: Belongs to `.bss` (initialized to 0). Startup code will zero-fill it in RAM.
- `max_retries`: Belongs to `.data` (initialized to non-zero). Startup code will copy the value `5` from Flash to RAM.
- `buffer`: Belongs to `.bss` (uninitialized global arrays default to 0). Startup code will zero-fill it in RAM.
- `hardware_id`: Belongs to `.rodata` (Read-Only Data). Startup code does **nothing** to this. It remains in Flash memory, and the CPU reads it directly from Flash.

## Solution 2: The Missing Startup File
**Answer:** You forgot to compile and link the **Startup Assembly File** (usually named something like `startup_stm32.s`).
**Why it fails:** When the Cortex-M powers on, it blindly reads address `0x08000000` (Vector Table `[0]`) for the Stack Pointer, and address `0x08000004` (Vector Table `[1]`) for the address of the `Reset_Handler`. Because the startup file wasn't linked, these addresses contain random garbage or data from your application. The CPU loads a random address into the PC and crashes immediately.

## Solution 3: Bootloader Interactions
**Answer:** 
1. **The Vector Table Offset Register (VTOR):** The bootloader must update this hardware register to point to `0x08040000` so that hardware interrupts trigger the application's handlers, not the bootloader's.
2. **The Main Stack Pointer (MSP):** The bootloader must read the first 4 bytes at `0x08040000` (the app's Vector Table `[0]`) and manually set the CPU's Stack Pointer to this value before jumping to the app's `Reset_Handler`.
