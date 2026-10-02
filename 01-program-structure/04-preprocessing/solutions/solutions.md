# Solutions: Preprocessing

## Solution 1: Spot the Macro Bug
**Answer:** The macro expands directly into the code. The resulting code becomes:
```c
if (condition)
    STATUS_REG &= ~(1 << 3);
else // ERROR: 'else' without a previous 'if' (because the ';' belongs to the macro usage, creating two statements).
```
**The Fix:** Use the `do { ... } while(0)` trick. This wraps the macro in a single statement block that safely absorbs the trailing semicolon.
```c
#define CLEAR_BIT(reg, bit) do { (reg) &= ~(1 << (bit)); } while(0)
```
*(Also, notice the added parentheses around `reg` and `bit` to prevent operator precedence bugs!)*

## Solution 2: C++17 Replacement
**Answer:** Use `constexpr` and typed variables.
```cpp
constexpr float pi = 3.14159f;
constexpr int seconds_in_hour = 60 * 60;
```
This guarantees type safety (e.g., `pi` is explicitly a `float`, not a `double`), and these values can be scoped inside namespaces or classes, unlike `#define` which pollutes the global scope globally.

## Solution 3: Cross-Platform Abstraction
**Answer:**
```cpp
void delay_ms(int ms) {
#if defined(TARGET_STM32)
    HAL_Delay(ms);
#elif defined(TARGET_ESP32)
    vTaskDelay(ms / portTICK_PERIOD_MS);
#else
    #error "Unknown target MCU defined for delay_ms!"
#endif
}
```
Using `#error` in the `#else` block is a crucial embedded practice—it intentionally breaks the build if the build system forgets to define a target, rather than silently compiling an empty function.
