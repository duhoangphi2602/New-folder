# Function Pointers

## 1. Concept
A **function pointer** is a variable that stores the memory address of a function. Just like a normal pointer can be used to read/write data dynamically at runtime, a function pointer can be used to *execute code* dynamically at runtime.

## 2. Why
Without function pointers, a hardware driver (like a UART driver) would have to hardcode the names of the application functions it needs to call when data arrives. This breaks modularity (the driver becomes coupled to the application). Function pointers allow the application to pass a "callback" to the driver. The driver simply says: *"I don't know what this function does, but I will call it when data arrives."*

## 3. Syntax

The C syntax for function pointers is notoriously difficult to read because the pointer name is buried in the middle of the signature.

```c
// C-style declaration
// 'callback_t' is a TYPE: pointer to a function taking an int and returning void.
typedef void (*callback_t)(int);

// C++11 modern syntax (Much more readable)
using callback_t = void (*)(int);
```

**Assigning and Calling:**
```cpp
void my_handler(int status) { }

int main() {
    // 1. Assign the address of the function to the pointer
    callback_t func_ptr = &my_handler; // The '&' is optional
    
    // 2. Call the function via the pointer
    func_ptr(42); 
    // Equivalent to: (*func_ptr)(42);
}
```

## 4. Example
*(See `examples/` for runnable code demonstrating Callbacks and Dispatch Tables).*

## 5. Embedded usage (Callbacks & ISRs)
Function pointers are the backbone of event-driven embedded systems.

```c
// Common pattern in embedded C drivers (e.g., STM32 HAL)
typedef void (*uart_rx_callback_t)(uint8_t byte);

static uart_rx_callback_t rx_callback = NULL;

// The Application calls this during setup
void uart_register_rx_callback(uart_rx_callback_t cb) {
    rx_callback = cb;
}

// The Hardware Interrupt calls this when a byte physically arrives
void UART_IRQHandler(void) {
    uint8_t byte = UART->DR; // Read hardware register
    
    // If the application registered a callback, execute it!
    if (rx_callback != NULL) {
        rx_callback(byte);
    }
}
```

## 6. Trade-offs (C++ Alternatives)

In modern C++, you have alternatives to raw function pointers:

| Mechanism | Pros | Cons | Embedded Suitability |
|-----------|------|------|----------------------|
| **Raw Function Pointer** | Zero overhead. 100% C-compatible. | Cannot hold state (closures). Ugly syntax. | **Excellent**. The standard for driver boundaries. |
| **`std::function`** | Can hold stateful lambdas and class member functions. | Heavy overhead. Might allocate heap memory! | **Poor/Avoid**. Heap allocation is dangerous in hard RTOS environments. |
| **Stateless Lambda** | Extremely clean syntax inline. | - | **Excellent**. Automatically decays to a raw function pointer! |

## 7. Exercises
Please proceed to the `exercises/` folder to practice implementing a Dispatch Table.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
