# Interview Questions: Warnings

## 1. Why is compiling with `-Werror` considered mandatory in professional CI/CD pipelines?
**Answer:** In a professional environment, developers frequently work in teams. If warnings are allowed to accumulate, the build logs become cluttered with hundreds of messages. Eventually, developers suffer from "Warning Fatigue" and stop reading them entirely. If a new, critical warning appears (like an uninitialized pointer), it will be lost in the noise, leading to production crashes. By enforcing `-Werror` in the CI/CD pipeline, the build server physically rejects any Pull Request that generates even a single warning. This guarantees a perpetually clean codebase and forces developers to fix ambiguity immediately.

## 2. You enabled `-Wall`, but the compiler did not warn you when you compared a signed `int` to an unsigned `uint32_t`. Why?
**Answer:** Despite its name, `-Wall` (Warning All) does *not* enable all warnings. It only enables a curated subset of warnings that the GCC developers considered universally uncontroversial. Stricter checks, such as `sign-compare` (checking for signed/unsigned mismatch) or `unused-parameter`, require additional flags. To catch these, you must explicitly enable the `-Wextra` flag in addition to `-Wall`.

## 3. What is the `#pragma GCC diagnostic` directive used for?
**Answer:** Sometimes you need to disable a specific warning (like a deprecated function warning) for only *one specific line of code*, while keeping `-Werror` active for the rest of the file. You cannot do this from the command line. Instead, you use `#pragma` directives directly in the C++ source code to temporarily pause the compiler's warning engine, execute the problematic code, and then immediately turn the engine back on.
```cpp
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    legacy_function_call(); // Warning ignored ONLY for this line
#pragma GCC diagnostic pop
```
