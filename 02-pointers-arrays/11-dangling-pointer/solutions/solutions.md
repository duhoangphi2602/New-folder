# Solutions: Dangling Pointer

## Solution 1: Spot the Bug
**Answer:** The code contains a catastrophic dangling pointer bug. `message` is a local array allocated on the stack. The function returns a pointer to this array (via array decay). When the function exits, the stack frame is destroyed, and the caller receives a pointer to invalid memory.
**The Fix:** 
1. **Pass a buffer in (Best for Embedded):**
```cpp
void get_status_message(int status_code, char* out_buffer) {
    if (status_code == 0) sprintf(out_buffer, "OK");
    else sprintf(out_buffer, "Error Code: %d", status_code);
}
```
2. **Make it static (If thread-safety isn't required):**
```cpp
const char* get_status_message(int status_code) {
    static char message[64]; // Lives in .bss/.data, not the stack!
    // ...
    return message;
}
```

## Solution 2: `std::string_view` Trap
**Answer:** `std::string_view` does not own the memory it points to; it is just a pointer and a length. 
Inside `create_header`, `header` is a local `std::string` object (living on the stack). When the function returns, the `std::string` object goes out of scope and its destructor is called, freeing the memory holding the text. The function returns a `std::string_view` that is holding a **dangling pointer** to that destroyed memory. When `main()` tries to print it, it reads garbage data.
