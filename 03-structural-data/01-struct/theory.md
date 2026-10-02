# Struct Basics

## 1. Concept
A `struct` is a blueprint. It tells the compiler how to group multiple variables (called **members**) together. Declaring a struct does not take up memory; it only defines a new data type. Instantiating (creating) a variable of that struct type is what allocates memory.

## 2. Why
Without structs, a function to process sensor data might look like this:
`void process_sensor(float temp, float hum, uint32_t time);`
If the sensor gains a pressure reading, you must rewrite the function signature across your entire codebase. 
With structs, you just pass `void process_sensor(const SensorData& data);`. It is infinitely more scalable.

## 3. Syntax (Declaration and Usage)

**Declaration:**
```cpp
// This defines the blueprint
struct SensorData {
    float temperature;
    float humidity;
    uint32_t timestamp;
}; // ALWAYS REMEMBER THE SEMICOLON!
```

**Instantiation and Access:**
```cpp
// 1. Uninitialized (Garbage data)
SensorData data1; 
data1.temperature = 25.5f; // Access via dot operator

// 2. C-Style Initialization (Order dependent)
SensorData data2 = {25.5f, 60.0f, 1000}; 

// 3. C++11 Uniform Initialization
SensorData data3{26.0f, 55.0f, 2000}; 

// 4. C++20 Designated Initializers (Highly Recommended)
SensorData data4{.temperature = 25.5f, .humidity = 60.0f, .timestamp = 3000};
```

## 4. Example
*(See `examples/` for runnable code demonstrating basic struct usage).*

## 5. Embedded usage (Grouping Configuration)
In embedded programming, structs are constantly used to group configuration parameters before passing them to a hardware initialization function.

```cpp
struct UartConfig {
    uint32_t baud_rate;
    uint8_t  word_length;
    uint8_t  stop_bits;
    bool     parity_enable;
};

void init_uart(const UartConfig& config) {
    // Configure hardware using config.baud_rate, etc.
}

int main() {
    // C++20 Designated Initializers make this extremely readable
    UartConfig my_uart = {
        .baud_rate = 115200,
        .word_length = 8,
        .stop_bits = 1,
        .parity_enable = false
    };
    init_uart(my_uart);
}
```

## 6. Trade-offs (Struct vs Class)

In C++, `struct` and `class` are almost exactly the same thing under the hood. 

| Feature | `struct` | `class` |
|---------|----------|---------|
| **Default Visibility** | `public` | `private` |
| **Best Used For** | Plain Old Data (POD). Passive data containers without complex logic or invariants. | Encapsulated objects with strict invariants, private data, and public methods. |

*In C, structs cannot contain functions at all. In C++, structs can contain functions, but conventionally we use them only for raw data grouping.*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
