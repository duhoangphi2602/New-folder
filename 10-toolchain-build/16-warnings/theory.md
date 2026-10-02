# Compiler Warnings

## 1. The Danger of Silence
If you write: `uint8_t count = 300;`
The maximum value of an 8-bit unsigned integer is 255. If you compile this without flags, GCC will silently overflow the value to `44`. It will **not** throw an error. The code compiles successfully. This is how billion-dollar spacecraft crash.

## 2. The Core Warning Flags
To force the compiler to complain about suspicious code, you must explicitly enable warning flags.
- **`-Wall` (Warning All):** Enables all of the most common, universally agreed-upon warnings (e.g., unused variables, returning a pointer to a local stack variable, format string mismatches). *Note: Despite the name, it does NOT enable "all" warnings.*
- **`-Wextra`:** Enables additional, stricter warnings that `-Wall` missed (e.g., comparing a signed integer with an unsigned integer, which can cause severe logic bugs).
- **`-Wpedantic`:** Enforces strict adherence to the ISO C++ standard, rejecting custom GCC extensions.

## 3. The Professional Standard: `-Werror`
Even with `-Wall` enabled, warnings do not stop the build process. A lazy developer will see the warning text, ignore it, and flash the code anyway.
- **`-Werror` (Warnings as Errors):** This is the most important flag in professional software engineering. It instructs the compiler: *"If you detect even a single Warning, immediately halt the build and declare a fatal Error."* 
This physically prevents bad code from ever being flashed or pushed to a production server.

## 4. Disabling Specific Warnings
Sometimes, you are forced to use a 3rd-party hardware library (like an old STMicroelectronics HAL) that contains bad code. You cannot modify their code, but it triggers warnings, breaking your `-Werror` build.
You can explicitly silence specific warnings by appending `no-` to the warning name.
- Example: `-Wno-unused-parameter`. 
This tells the compiler to treat all warnings as errors, *except* for unused parameters, which it should silently ignore.

## 5. Example
*(See `examples/` for a demonstration of a warning-triggered build failure).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
