# Enum (Legacy C-Style)

## 1. Concept
An `enum` (enumeration) is a set of named integer constants. By default, the compiler assigns the value `0` to the first name, `1` to the second, and so on.

## 2. Why
Enums drastically improve code readability and maintainability.
- **Without Enum**: `void set_uart_parity(int parity); // Is 0 None or 0 Even?`
- **With Enum**: `void set_uart_parity(UartParity parity); // Much clearer!`

## 3. Syntax (Declaration)

```cpp
// 1. Default numbering (0, 1, 2)
enum SensorState {
    STATE_IDLE,    // 0
    STATE_READING, // 1
    STATE_ERROR    // 2
};

// 2. Custom numbering
enum ErrorCode {
    ERR_NONE = 0,
    ERR_TIMEOUT = 10,
    ERR_DISCONNECTED = 20
};
```

## 4. Example
*(See `examples/` for runnable code demonstrating basic enum usage).*

## 5. Embedded usage (State Machines)
Enums are the foundation of Finite State Machines (FSMs), which govern almost all logic in bare-metal embedded systems.

```cpp
enum SystemState {
    BOOTING,
    CONNECTING_WIFI,
    MEASURING,
    SLEEPING
};

SystemState current_state = BOOTING;

void loop() {
    switch(current_state) {
        case BOOTING:
            // ...
            current_state = CONNECTING_WIFI;
            break;
        case CONNECTING_WIFI:
            // ...
            break;
    }
}
```

## 6. Trade-offs (The Namespace Pollution Flaw)
While C-style enums are useful, they have a massive flaw in C++: **Namespace Pollution**.
The names inside a C-style enum "leak" into the surrounding scope.

```cpp
enum TrafficLight { RED, YELLOW, GREEN };
enum NetworkState { DISCONNECTED, CONNECTING, CONNECTED, RED }; // ERROR!

// The compiler complains that 'RED' is already defined in this scope!
```
Furthermore, C-style enums implicitly convert to integers, destroying type safety.
```cpp
TrafficLight light = RED;
int math = light + 5; // Valid in C/C++, but makes no logical sense!
```

*(Because of these flaws, modern C++ introduced `enum class`, which is covered in the next topic: `08-enum-class`).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
