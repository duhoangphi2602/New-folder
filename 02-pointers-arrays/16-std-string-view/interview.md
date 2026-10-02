# Interview Questions: std::string_view

## 1. What problem does `std::string_view` solve compared to passing `const std::string&`?
**Answer:** If a function takes `const std::string&` and the caller passes a string literal (e.g., `"Hello"`), the C++ compiler must dynamically allocate memory (heap allocation) to construct a temporary `std::string` object before passing it to the function. `std::string_view` avoids this completely by simply wrapping the existing literal's pointer and calculating its length at compile time, resulting in zero dynamic allocations and zero copying.

## 2. Is `std::string_view` guaranteed to be null-terminated? Why or why not?
**Answer:** No, it is not guaranteed to be null-terminated. A `string_view` can be a substring of a larger string (created via `.substr()`). In this case, it just points to the middle of a string and specifies a restricted length; it does not insert a `\0` character. Therefore, you must be extremely careful when passing `.data()` to legacy C APIs like `printf` or `strlen`.

## 3. How should `std::string_view` be passed to functions? By value or by reference?
**Answer:** It should be passed by **value**. Under the hood, it is usually just two words of memory (a pointer and a size integer). Passing it by value allows the compiler to pass those two words directly in CPU registers, which is more efficient than passing a pointer/reference to them.
