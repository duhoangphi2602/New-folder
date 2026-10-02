# Exercises: The Linker Script

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Bootloader Partitioning
You are writing a Custom Bootloader. The microcontroller has 512KB of Flash, starting at `0x08000000`.
You want to give the first 64KB (64 * 1024 bytes) of Flash to the Bootloader, and the remaining space to the Main Application.
**Task:** 
1. Write the `MEMORY` block for the **Bootloader's** linker script.
2. Write the `MEMORY` block for the **Main Application's** linker script.
*(Hint: 64KB = `0x10000` in Hex).*

## Exercise 2: `>RAM AT> FLASH`
In the theory section, the `.data` section definition ends with this strange command:
`} >RAM AT> FLASH`
The `.text` section only has `} >FLASH`. The `.bss` section only has `} >RAM`. 
**Task:** Based on your knowledge of the `.data` segment from previous topics, why does `.data` uniquely require *two* memory regions to be specified in the Linker Script?
