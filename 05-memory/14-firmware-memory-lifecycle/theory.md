# Firmware Memory Lifecycle (Summary)

## The Journey of `int x = 5;`

Imagine you write this code in `main.cpp`:
```cpp
int x = 5; // Global variable
int main() { x++; }
```
What actually happens to the number `5`? Let's trace its journey through the 5 phases of the Embedded Lifecycle.

### Phase 1: Compilation (The Toolchain)
You click "Build". 
The **Compiler** (GCC) looks at `int x = 5;` and says: "This is an initialized global variable. I will put this in the `.data` bucket." It turns `x++` into assembly instructions and puts them in the `.text` bucket.

### Phase 2: Linking (The Linker Script)
The **Linker** reads the `STM32F4.ld` Linker Script. 
It looks at the `MEMORY` block and sees that Flash starts at `0x08000000` and RAM starts at `0x20000000`.
It takes the `.data` bucket containing our `5`. The Linker Script says: `>RAM AT> FLASH`. 
The Linker calculates: "I will assign `x` the execution address of `0x20000000` (RAM). But I will physically store the number `5` in the firmware file at address `0x08000100` (Flash)."
It packages everything into a `firmware.bin` file.

### Phase 3: Flashing (The Programmer)
You plug in your ST-Link USB debugger and click "Flash".
The debugging software reads `firmware.bin` from your PC hard drive. It sends the bits over the SWD wires into the microcontroller. The microcontroller physically burns the number `5` into the Flash memory chip at physical address `0x08000100`. 
Power is turned off. The `5` remains trapped in the Flash silicon forever.

### Phase 4: The Boot Sequence (The Startup Code)
You plug a battery into the microcontroller.
1. **Hardware:** The CPU wakes up. It reads address `0x00000000` to set the Stack Pointer, then reads address `0x00000004` and jumps to the `Reset_Handler`.
2. **Startup Code:** The CPU begins executing the Startup Assembly. It reaches the `.data` copy loop.
3. **The Transfer:** The CPU reads the number `5` from Flash address `0x08000100` and writes it into RAM address `0x20000000`. 
4. **C++ Init:** The Startup Code calls `main()`.

### Phase 5: Execution (The Hardware Bus)
The CPU begins executing `main()`. It hits the instruction for `x++`.
1. The CPU places the address `0x20000000` on the Data Bus.
2. The RAM chip responds by sending the number `5` back to the CPU.
3. The CPU's ALU (Arithmetic Logic Unit) increments the `5` to a `6`.
4. The CPU places the address `0x20000000` and the data `6` on the buses. The RAM chip overwrites the memory. `x` is now `6`.

If the battery is unplugged, the RAM instantly loses power. The `6` is destroyed forever. But the `5` is still safely waiting in Flash, ready for Phase 4 to begin again.

---

## Conclusion of Chapter 05
You have mastered the hardest concepts in bare-metal programming. You now know why the Stack is fast, why the Heap is dangerous, why padding wastes RAM, and how the hardware actually boots. 
**You are now ready to write real-time, hardware-level code.**
