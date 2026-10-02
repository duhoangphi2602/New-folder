# Solutions: Professional Logging

## Solution 1: Zero Overhead
**Answer:** It will consume **Zero (0)** CPU cycles.
**Why:** Macros are evaluated by the C Preprocessor *before* the code is actually compiled. Because `ACTIVE_LOG_LEVEL` is set to `INFO`, the `#if` condition for `DEBUG` evaluates to false. The preprocessor literally replaces `LOG_DEBUG("Speed is: %d", speed);` with an empty string. By the time the compiler sees the code, that line does not exist. There is zero binary size overhead and zero CPU execution time.

## Solution 2: `__func__`
**Answer:**
```c
#define LOG_ERROR(fmt, ...) \
    printf("[ERROR] In %s(): " fmt "\r\n", __func__, ##__VA_ARGS__)
```
*(If you call this macro inside `void calculate_pid()`, it will print: `[ERROR] In calculate_pid(): ...`)*
