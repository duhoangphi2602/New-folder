# std::string_view (C++17)

## 1. Concept
`std::string_view` is a read-only, non-owning reference to a contiguous sequence of characters. It acts as a lightweight wrapper around a `const char*` pointer and a `size_t` length. 

## 2. Why
Before C++17, if you wanted to write a function that accepted a string, you had two bad choices:
1. `void print(const char* s)`: Forces you to run `strlen(s)` to find the length (O(N) performance).
2. `void print(const std::string& s)`: If the caller passes a string literal like `"Hello"`, the compiler secretly calls `new` to allocate heap memory, copies "Hello" into it, and then passes the reference. This is slow and fragments embedded memory.

`std::string_view` gives you the best of both worlds: it knows its length instantly (O(1)), and it never allocates heap memory.

## 3. Syntax (How it works under the hood)
Logically, it is just a simple struct:
```cpp
struct string_view {
    const char* data;
    size_t length;
};
```
Because it is so small (usually 8 bytes on a 32-bit system), you should **pass it by value**, not by reference.
```cpp
#include <string_view>

void print_str(std::string_view sv) {
    // sv.length() is instant. sv.data() gives the raw pointer.
}
```

## 4. Example
*(See `examples/` for runnable code demonstrating zero-allocation parsing).*

## 5. Embedded usage (Zero-Copy Parsing)
In embedded systems, you frequently parse AT Commands (e.g., from a Cellular/WiFi modem) or JSON. `std::string_view` is the perfect tool for slicing these strings without copying them into new buffers.

```cpp
#include <string_view>

// Simulated AT command buffer: "AT+TEMP=42\r\n"
void parse_at_command(std::string_view cmd) {
    // O(1) substring! It just changes the internal pointer and length.
    // It DOES NOT copy the string.
    if (cmd.substr(0, 8) == "AT+TEMP=") {
        std::string_view value_str = cmd.substr(8, 2); // "42"
        // Convert value_str to integer...
    }
}
```

## 6. Trade-offs (The Dangling Pointer Danger)

| Feature | `std::string` | `std::string_view` |
|---------|---------------|--------------------|
| **Memory Allocation** | Yes (Heap, usually). | None (Zero allocation). |
| **Ownership** | Owns its data (Safe). | Non-owning (Dangerous). |
| **Null-terminated?** | Always. | **Not guaranteed** (Substrings aren't). |

**DANGER:** Because `string_view` does not own its memory, you must guarantee that the underlying text outlives the `string_view`. If the underlying string is destroyed, the `string_view` becomes a dangling pointer!

```cpp
std::string_view get_name() {
    std::string local_name = "Sensor1";
    return local_name; // BUG! Returns a view pointing to destroyed stack memory!
}
```

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
