# Preprocessing

## 1. The Text-Replacement Robot
When you click "Build", the Toolchain does not send your `.cpp` file directly to the compiler. First, it sends it to the Preprocessor.
The Preprocessor reads your file line by line. If a line starts with a `#` (a Preprocessor Directive), it executes a text-manipulation command.
The output of the Preprocessor is a massive, temporary text file called a **Translation Unit** (often with a `.i` extension). This translation unit is what is actually fed to the compiler.

## 2. `#include` (Copy and Paste)
When the preprocessor sees `#include "sensor.h"`, it:
1. Opens `sensor.h`.
2. Copies every single line of text inside it.
3. Deletes the `#include` line in your `.cpp` file.
4. Pastes the copied text exactly where the `#include` line used to be.

If `sensor.h` is 500 lines long, and you include it in `main.cpp`, the Preprocessor makes your `main.cpp` 500 lines longer before the compiler even sees it.

## 3. `#define` (Find and Replace)
```c
#define MAX_SPEED 100
int current_speed = MAX_SPEED;
```
When the preprocessor sees this, it uses a literal "Find and Replace" tool. It finds every instance of `MAX_SPEED` in your file and physically replaces it with the text `100`. 
The compiler eventually sees:
```c
int current_speed = 100;
```
**The Danger:** The preprocessor doesn't know what an `int` or a `float` is. If you write `#define MAX_SPEED "Hello"`, it will blindly replace it, and the *Compiler* (Step 2) will crash when it tries to put the string "Hello" into an `int`.

## 4. Conditional Compilation (`#ifdef`)
You can tell the preprocessor to delete chunks of your code before the compiler sees them.
```c
#define DEBUG_MODE

#ifdef DEBUG_MODE
    printf("This will be compiled.\n");
#else
    printf("The preprocessor will literally delete this line.\n");
#endif
```
This is heavily used in embedded systems to compile the exact same `.cpp` file for different hardware (e.g., `#ifdef STM32` vs `#ifdef ESP32`).

## 5. Example
*(See `examples/` for a simulated Preprocessor output file).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
