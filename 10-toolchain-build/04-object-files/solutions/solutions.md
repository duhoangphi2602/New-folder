# Solutions: Object Files

## Solution 1: The Static Keyword
**Answer:** The `static` keyword removes the function from the public Symbol Table (or marks it as a local 't' instead of a global 'T'). 
This means the function is strictly invisible to the outside world. If another file `main.cpp` tries to call `calculate_baud_rate()`, the Linker will fail, because `uart.o` refuses to advertise that it possesses that function. 
This is incredibly useful in large projects to prevent "Namespace Pollution". If two different `.cpp` files both happen to use a helper function named `init()`, the Linker will crash with a "Multiple Definition" error. Making them `static` hides them, safely allowing both files to have their own private `init()` functions.

## Solution 2: Header Implementations
**Answer:** 
Because of the Preprocessor, the full implementation of `add()` is literally copy-pasted into both `main.cpp` and `sensor.cpp` before compilation.
Therefore, the compiler perfectly generates the machine code for `add()` twice.
- Inside `main.o`, the Symbol Table will have: `T add` (I define the add function).
- Inside `sensor.o`, the Symbol Table will have: `T add` (I also define the add function).
When the Linker tries to merge them, it will see two completely different pieces of machine code both claiming to be the global `add` function. It will instantly crash with a **Multiple Definition of 'add'** error. (The fix is to either declare it `inline`, or put the implementation in a `.cpp` file).
