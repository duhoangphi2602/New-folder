# Assembly (The Assembler)

## 1. The Input
The Assembler receives the `.s` file from the Compiler. This file contains human-readable instructions called **Mnemonics**. 
Example Mnemonic: `ADD R0, R1` (Add the contents of Register 1 to Register 0).

## 2. The Instruction Set Architecture (ISA)
A CPU is a physical arrangement of silicon transistors. It only understands binary patterns (e.g., `0100 0100`).
The **ISA** is the dictionary that translates a binary pattern into a physical action.
- On an ARM processor, `0100 0100` might mean `ADD`.
- On an Intel processor, `0100 0100` might mean `DIVIDE`.
This is why you cannot take a `.exe` file compiled for your Intel Windows PC and run it on an ARM Raspberry Pi. The silicon speaks a completely different language. 

## 3. The Assembler's Job (1-to-1 Translation)
Unlike the Compiler, which does complex logical analysis (ASTs, Optimizations), the Assembler is extremely simple. It acts like a lookup table.
It reads: `MOV R0, #5`
It looks in its ARM dictionary and finds the exact 16-bit binary pattern for "Move the number 5 into Register 0".
It outputs: `0010 0000 0000 0101` (In hex: `0x2005`).

Because the translation is 1-to-1, you can also easily reverse it (Disassembly). You can feed `0x2005` back into a Disassembler, and it will perfectly spit out `MOV R0, #5`. (You cannot perfectly reverse C++ code).

## 4. Addressing and Labels
The Assembler also calculates relative jumps.
If your C++ code has a `while` loop, the compiler generates a Label:
```assembly
.LoopStart:
    ADD R0, #1
    CMP R0, #10
    BNE .LoopStart   // Branch if Not Equal
```
The CPU silicon doesn't know what `.LoopStart` is. The Assembler calculates the physical distance in bytes (e.g., jump backwards by 4 bytes) and translates `BNE .LoopStart` into a binary command meaning `Jump -4`.

## 5. The Output: Object File (`.o`)
The Assembler takes all these raw binary instructions and packages them into an **Object File**. 
It is no longer a text file. If you open a `.o` file in Notepad, you will just see random gibberish characters because it is pure binary data.

## 6. Example
*(See `examples/` for a simulated dictionary translation).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
