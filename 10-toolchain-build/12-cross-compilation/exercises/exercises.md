# Exercises: Cross Compilation

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Missing OS
You write a C++ program for an STM32 microcontroller. You need to delay execution for 1 second. You write `#include <thread>` and call `std::this_thread::sleep_for(std::chrono::seconds(1));`.
When you cross-compile this with `arm-none-eabi-g++`, the compiler throws a massive error stating that threading is not supported on the target.
**Task:** Why did this fail? The C++11 standard requires `<thread>` to be supported. Why does the cross-compiler refuse to compile it?

## Exercise 2: `newlib` vs `glibc`
You are migrating a 100 KB desktop C application to run on an embedded microcontroller. On your desktop, the compiled executable is 120 KB. 
When you cross-compile it for the microcontroller using the bare-metal `arm-none-eabi-gcc` toolchain, the final `.bin` file balloons to 600 KB! It no longer fits in the chip's Flash memory.
**Task:** The toolchain secretly linked the standard embedded library (`newlib`). Why did the file get so much larger on the embedded target than on the desktop? (Hint: Think about what `printf` relies on in Windows/Linux vs what it must carry with it in bare-metal).
