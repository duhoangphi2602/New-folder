# Interview Questions: Bin and Hex

## 1. What tool is used to convert an `.elf` file into a flashable `.bin` or `.hex` file, and what exactly does it do?
**Answer:** The `objcopy` tool (e.g., `arm-none-eabi-objcopy`). It takes the structured `.elf` database file, strips away the ELF headers, the Symbol Tables, and all the DWARF Debugging metadata, and extracts only the loadable sections (specifically `.text` and `.data`). It then formats this raw payload into either a flat binary stream (`.bin`) or an ASCII-encoded structured text file (`.hex`).

## 2. Compare the advantages of a `.bin` file versus a `.hex` file.
**Answer:** 
- **`.bin` Advantage:** It is the smallest possible representation of the firmware. It has zero overhead, making it ideal for OTA (Over-The-Air) updates where bandwidth is limited or expensive.
- **`.hex` Advantage:** It inherently contains the physical memory addresses for every byte of data, making it safer and easier for factory programming tools (you don't have to manually specify the target address). It also elegantly handles non-contiguous memory spaces (large gaps between code and data) without wasting disk space on millions of padding bytes.

## 3. If you open a `.bin` file in Notepad, what will you see? What if you open a `.hex` file?
**Answer:** If you open a `.bin` file in Notepad, you will see completely unreadable, garbled characters. Notepad tries to interpret the raw machine code (bytes like `0xDE`, `0x8C`) as ASCII characters, which results in gibberish. 
If you open a `.hex` file in Notepad, you will see perfectly readable text. It will look like rows of hexadecimal strings starting with a colon (`:`), because it is specifically encoded as an ASCII text file to be universally readable and easily transferred over legacy serial protocols.
