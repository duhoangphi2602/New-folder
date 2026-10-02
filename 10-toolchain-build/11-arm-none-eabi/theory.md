# arm-none-eabi

## 1. The Toolchain Tuple
Every cross-compiler in the GCC family follows a standard naming convention called a "Tuple" (even if it has 3 or 4 parts).
The format is: `<architecture>-<vendor>-<os>-<abi>`

Let's break down the standard microcontroller toolchain: `arm-none-eabi-gcc`

## 2. Part 1: `<architecture>` = `arm`
This tells the compiler which physical silicon instruction set (dictionary) to use. 
- `arm`: 32-bit ARM processors (like Cortex-M on STM32).
- `aarch64`: 64-bit ARM processors (like modern Raspberry Pi or Apple Silicon).
- `x86_64`: 64-bit Intel/AMD processors.

## 3. Part 2: `<vendor>` = `none`
This specifies the company that built the toolchain or the specific hardware board it is locked to.
- `none`: It is generic. It doesn't care if it's an STMicroelectronics board or an NXP board. It works on any generic ARM chip.
- `apple`: Customized for Apple's specific hardware ecosystem (e.g., `x86_64-apple-darwin`).

## 4. Part 3: `<os>` = `none` (Implied)
Wait, the name is `arm-none-eabi`. Where is the OS?
If the OS field is missing (or baked into the vendor field as `none`), it means **Bare-Metal**.
- **Bare-metal (`none`):** There is no Linux. There is no Windows. Your code runs directly on the raw hardware. The compiler will *not* link standard OS libraries (like POSIX threads or file systems).
- **Linux (`linux`):** Example: `arm-linux-gnueabihf-gcc`. This compiler assumes your chip is running a full Linux OS. It will dynamically link your code to the Linux kernel API. If you run this code on an STM32, it will crash instantly.

## 5. Part 4: `<abi>` = `eabi`
ABI stands for **Application Binary Interface**. 
An API defines how C++ functions interact *in the source code*. An ABI defines how C++ functions interact *at the hardware level*.
For example: If Function A calls Function B and passes an integer, does Function A put the integer in Register `R0`? Or does it push it onto the Stack? The ABI sets the rules.
- `eabi`: Embedded Application Binary Interface. The standard rulebook for ARM Cortex-M.
- `gnueabihf`: GNU EABI with **H**ard **F**loat. Tells the compiler that the chip has a physical hardware Floating Point Unit (FPU), so it passes decimals in special `S0`-`S31` floating-point registers.

## 6. Example
*(See `examples/` for a breakdown of common toolchain names).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
