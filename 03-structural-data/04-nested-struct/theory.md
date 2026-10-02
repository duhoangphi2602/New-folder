# Nested Structs

## 1. Concept
A `struct` is simply a custom data type. Once defined, you can use it exactly like you use standard types (like `int` or `float`). Therefore, you can declare a struct as a member variable inside another struct. This is called **composition**.

## 2. Why
Composition (nesting) promotes code reuse and logical organization. If multiple parts of your system need to track 3D coordinates (X, Y, Z), you define a `Vector3D` struct once, and nest it inside both the `Drone` struct and the `Target` struct, rather than duplicating the X, Y, Z variables.

## 3. Syntax (Declaration and Initialization)

```cpp
// 1. Define the inner struct
struct Date {
    uint8_t day;
    uint8_t month;
    uint16_t year;
};

// 2. Define the outer struct, nesting the inner one
struct LogEntry {
    uint32_t id;
    Date timestamp; // Nested struct
    float temperature;
};

int main() {
    // 3. Initialization requires nested braces
    LogEntry entry = {
        .id = 1,
        .timestamp = {.day = 14, .month = 5, .year = 2026}, // Nested initialization
        .temperature = 22.5f
    };

    // 4. Access via chained dot operators
    uint16_t y = entry.timestamp.year; 
}
```

## 4. Example
*(See `examples/` for runnable code demonstrating memory layouts of nested structs).*

## 5. Embedded usage (Hardware Peripherals)
Nested structs are the standard way to map complex silicon hardware. For example, a microcontroller might have an advanced Timer peripheral that contains multiple identical "Capture/Compare Channels". Instead of writing `TIM_CCR1`, `TIM_CCR2`, etc., the vendor library defines a nested struct.

```cpp
// The reusable inner component
struct TimerChannel_t {
    volatile uint32_t CCR;  // Capture/Compare Register
    volatile uint32_t CCMR; // Mode Register
};

// The main peripheral
struct Timer_t {
    volatile uint32_t CR1;  // Control Register 1
    TimerChannel_t CH[4];   // Array of 4 nested structs!
};

// Clean access to Channel 2's compare register:
TIMER2->CH[1].CCR = 500;
```

## 6. Trade-offs (Memory Alignment Impact)
When you nest a struct, the inner struct is embedded directly into the outer struct's memory (it is **not** a pointer, it is physically in-line).
The alignment requirement of the *entire* inner struct is dictated by its largest member. The outer struct might be forced to inject padding *before* the inner struct to ensure the inner struct is properly aligned.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
