# Solutions: std::string_view

## Solution 1: C API Compatibility
**Answer:** No, it is **not safe**, and it will print `"HELLO WORLD"`.
**Why:** `std::string_view` is **not guaranteed to be null-terminated**. When you call `message.substr(0, 5)`, it creates a view where `data` points to the 'H' and `length` is 5. It does *not* insert a `\0` after the 'O'. 
When you pass `.data()` to `lcd_print`, the C function ignores the length of 5. It starts at 'H' and keeps reading memory until it hits the original null terminator at the very end of `"HELLO WORLD"`.
*(Fix: If you need a null-terminated string for a C-API, you must copy the `string_view` into a temporary `std::string` or a fixed-size buffer first).*

## Solution 2: Pass by Value vs Reference
**Answer:** Passing `string_view` by value does **not** copy the underlying string text. A `string_view` is simply a struct containing two things: a pointer (4 or 8 bytes) and a length (4 or 8 bytes). 
Passing it by value just copies those two numbers into CPU registers, which is incredibly fast (faster than passing a pointer to the struct, which requires memory dereferencing). The junior developer is confusing it with `std::string`, which *would* copy the entire text if passed by value.
