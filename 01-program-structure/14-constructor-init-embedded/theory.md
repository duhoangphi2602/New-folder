# Constructor Initialization in Embedded

## 1. Concept
In C++, if you declare an object at the global scope, its constructor must be executed before `main()` starts. The compiler places a pointer to every global constructor into a special section of the binary called `.init_array`. 

During the startup sequence, after memory is copied to RAM, the startup code calls a function `__libc_init_array()`, which loops through `.init_array` and executes every constructor.

## 2. Why
Global objects are sometimes necessary in embedded systems to represent singleton hardware peripherals (like `SystemClock` or `MainUart`). However, initializing them globally creates massive hidden risks.

## 3. Syntax (The Static Initialization Order Fiasco)
The C++ standard **does not guarantee the order** in which global constructors run across different translation units (`.cpp` files). 

```cpp
// file_a.cpp
Uart g_uart;           // Constructor runs first? or second?

// file_b.cpp
Logger g_logger(g_uart);  // Constructor depends on g_uart being ready!
```
If the compiler happens to place `g_logger` before `g_uart` in the `.init_array`, `g_logger` will try to use `g_uart` before it has been initialized. The system will likely crash, and the bug will randomly appear/disappear based on how you order your files during linking.

## 4. Example
*(See `examples/` for runnable code demonstrating Meyer's Singleton as a solution).*

**The Solution: Construct-on-First-Use (Meyer's Singleton)**
Instead of global variables, use a function containing a `static` local variable. The C++ standard guarantees that a `static` local variable is initialized exactly once, **the first time the function is called**.

```cpp
Uart& get_uart() {
    static Uart instance;  // Initialized safely upon first request
    return instance;
}

Logger::Logger() {
    get_uart().send("Logger initialized\n"); // 100% safe!
}
```

## 5. Embedded usage
### Cost of Global Constructors
- **Flash Bloat:** The `.init_array` section consumes Flash memory to store function pointers.
- **Boot Delay:** Executing complex code before `main()` delays the start of your actual application.
- **Hardware Traps:** Constructors might try to configure hardware (like UART or SPI) *before* the startup code has enabled the core system clocks, causing an immediate Hard Fault.

### Modern C++ Solutions
To avoid these issues entirely, modern embedded C++ relies heavily on `constexpr` constructors (C++11/17) or `constinit` (C++20).

```cpp
// C++17: constexpr constructor — initialized at COMPILE TIME!
struct Config {
    std::uint32_t baud;
    constexpr Config(std::uint32_t b) : baud(b) {}
};

constexpr Config g_config{115200};  // Zero runtime cost. Not in .init_array!
```

## 6. Trade-offs

| Global Init Strategy | Pros | Cons |
|----------------------|------|------|
| **Raw Global Objects** | Easy to write. | Fatal initialization order bugs. Hardware might not be ready. |
| **Meyer's Singleton** | Guarantees safe initialization order. Lazy loading. | Slight runtime overhead on every access (compiler checks a hidden `is_initialized` flag). |
| **`constexpr` Objects** | Zero runtime overhead. Perfectly safe. | Can only be used for simple types, not complex hardware drivers. |
| **Manual `init()` in `main()`** | Explicit, predictable, 100% safe. | Requires calling `init()` manually. Not "pure OOP". |

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
