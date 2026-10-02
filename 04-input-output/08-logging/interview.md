# Interview Questions: Professional Logging

## 1. Why do we use Preprocessor Macros (`#define`) for logging instead of standard C++ functions?
**Answer:** Macros provide two critical advantages:
1. **Zero-Overhead Compilation:** By wrapping the log in an `#if` block, we can completely remove the log statement from the compiled binary based on a build flag. A standard function would still require evaluating arguments and executing a function call before checking a runtime boolean.
2. **Context Injection:** Macros expand exactly at the location they are called. This allows compiler built-ins like `__FILE__`, `__LINE__`, and `__func__` to capture the exact file and line number of the code that called the log, which is impossible to do seamlessly with standard C++17 functions.

## 2. What does `##__VA_ARGS__` do in a variadic macro?
**Answer:** `__VA_ARGS__` represents the "variable arguments" passed to the macro (everything after the `format` string). The `##` is a specific compiler extension (supported by GCC and Clang) that deletes the preceding comma if exactly zero variable arguments are provided. Without `##`, writing `LOG_INFO("Hello")` would expand to `printf("Hello", )`, which causes a syntax error.

## 3. Why is it dangerous to call a function with side-effects inside a logging macro?
**Answer:** Consider `LOG_DEBUG("Sensor: %d", read_sensor_and_clear_flag());`. If the build is set to "Release", the `LOG_DEBUG` macro is preprocessed into nothing. Therefore, `read_sensor_and_clear_flag()` is **never executed**. This creates a catastrophic bug where the code works perfectly in Debug mode but completely fails in Release mode. You should never put active logic inside a log parameter.
