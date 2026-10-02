# Interview Questions: Static Storage Duration

## 1. What does the `static` keyword do when applied to a local variable inside a function?
**Answer:** It changes the variable's storage duration from Automatic (Stack) to Static. The variable is stored in global memory and is initialized only once when the program boots. It retains its value between subsequent calls to the function, effectively giving the function persistent "state" without polluting the global namespace.

## 2. What does the `static` keyword do when applied to a global variable outside of a function?
**Answer:** It changes the variable's linkage from External to Internal. This means the variable is only visible to the specific `.c` or `.cpp` file (Translation Unit) where it is defined. It prevents other files from accessing it via the `extern` keyword, avoiding naming collisions and enforcing encapsulation in C.

## 3. Why is Static Memory allocation fundamentally safer than the Heap for embedded systems?
**Answer:** Static memory is allocated entirely at compile time. The compiler and linker calculate exactly how many bytes are required for all static/global variables. If the required memory exceeds the physical RAM of the microcontroller, the build fails instantly, catching the error on the developer's laptop. Dynamic allocation (Heap) fails at runtime, causing unpredictable Out-Of-Memory crashes on the physical hardware while it is operating in the field.
