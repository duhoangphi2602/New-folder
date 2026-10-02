# Solutions: ELF Format

## Solution 1: The Size Panic
**Answer:** The ELF file contains vast amounts of data that is *never* sent to the microcontroller. The file on Windows contains the ELF Header, Section Headers, Symbol Tables, and massive amounts of DWARF Debugging Metadata (mapping memory addresses to human-readable C++ variable names and file paths). All of this metadata accounts for the vast majority of the 845 KB. The flasher tool (like OpenOCD or J-Link) will parse the ELF file, extract *only* the `.text` (code), `.rodata` (constants), and `.data` (initial variable values) sections, and physically burn those sections into the 64 KB Flash. The actual code payload is likely only 10 or 20 KB.

## Solution 2: Entry Point
**Answer:** The Entry Point address in the ELF header is `0x08000004`. 
This perfectly matches the ARM Cortex-M hardware rules. Flash memory on STM32 starts at `0x08000000`. The first 4 bytes (`0x08000000`) hold the Initial Stack Pointer. The next 4 bytes (`0x08000004`) hold the Reset Vector. The Linker intentionally set the ELF Entry Point to point exactly to the Reset Vector, telling any debugging tool that execution physically begins right there.
