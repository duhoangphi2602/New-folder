# Binary and Hex Files

## 1. The `objcopy` Tool
You have an `app.elf` file. It's huge, full of debugging data, and structured with headers. You want to flash it to a raw EEPROM chip on a production line. 
You use the `objcopy` tool (part of the toolchain) to strip away the container and extract just the executable meat (`.text` and `.data`).

```bash
arm-none-eabi-objcopy -O binary app.elf app.bin
arm-none-eabi-objcopy -O ihex app.elf app.hex
```

## 2. The `.bin` File (Raw Binary)
A `.bin` file is a 1-to-1 byte-for-byte copy of exactly what will exist in Flash memory.
- If your `.bin` file is exactly 10,000 bytes on your hard drive, it will occupy exactly 10,000 bytes of Flash memory.
- **The flaw:** It has no concept of memory addresses. It is just a flat stream of data. The flasher tool must manually be told: "Start flashing this `.bin` file at address `0x08000000`". 
- If you have two blocks of code separated by a massive empty gap in memory, a `.bin` file will literally fill the gap with millions of `0x00` padding bytes, creating an artificially massive file on your PC.

## 3. The `.hex` File (Intel Hex)
To solve the `.bin` limitations, Intel invented the `.hex` format.
It is **not** a binary file. It is a plain ASCII text file that you can open in Notepad.
Every line contains a structured packet of data:
`:[ByteCount][Address][RecordType][Data][Checksum]`
Example: `:1000000000040020090000081D0000081F00000885`

- **The advantage:** It explicitly states the physical memory address for every chunk of data. Flashing tools don't need to be told where to put it. It also effortlessly handles massive gaps in memory without padding.
- **The disadvantage:** Because it uses ASCII characters to represent hexadecimal numbers (using 2 characters like 'F' and 'F' to represent the single byte `0xFF`), plus formatting overhead, a `.hex` file is approximately 2.5x larger on your PC's hard drive than the equivalent `.bin` file.

## 4. Bootloaders and OTA Updates
When building an Over-The-Air (OTA) update via WiFi, you almost always transmit a `.bin` file. Transmitting a `.hex` file would waste 60% of your bandwidth transmitting ASCII formatting characters. The Bootloader already knows exactly where to flash the `.bin` data, so the address information in a `.hex` file is redundant.

## 5. Example
*(See `examples/` for a comparison of the exact same data in Bin vs Hex).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
