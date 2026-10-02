# Exercises: ELF Format

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Size Panic
You are developing firmware for an STM32F103 microcontroller, which has exactly 64 KB (65,536 bytes) of Flash memory.
After running `make`, you look at the generated `firmware.elf` file on your Windows machine. Windows reports the file size is 845 KB.
Your manager panics and says the code is too big and will never fit on the chip.
**Task:** Explain to your manager exactly why a 845 KB ELF file can easily fit inside a 64 KB microcontroller.

## Exercise 2: Entry Point
When an ARM Cortex-M microcontroller powers on, it reads the memory address at `0x00000004` (The Reset Vector) to find out where the very first instruction is located.
**Task:** Look at the simulated `readelf -h` output in the `examples/` folder. What is the Entry Point Address of the ELF file? Does it match the hardware architecture rules?
