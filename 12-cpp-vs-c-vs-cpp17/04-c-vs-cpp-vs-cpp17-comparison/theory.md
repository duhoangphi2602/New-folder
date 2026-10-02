# C vs C++ vs C++17 — Comparison

## Khái niệm
Bảng so sánh tổng hợp để trả lời câu hỏi: "Tôi đang viết Embedded firmware, nên dùng C, C++, hay C++17?"

## Bảng so sánh toàn diện

| Tính năng | C (C99/C11) | C++ (C++11/14) | C++17 | Ghi chú Embedded |
|-----------|-------------|----------------|-------|-------------------|
| **Hằng số** | `#define` | `const`, `constexpr` | `inline constexpr` | C++17: header-only constant, type-safe |
| **Rẽ nhánh compile-time** | `#ifdef` | SFINAE (phức tạp) | `if constexpr` | C++17 gọn gàng nhất |
| **Xử lý lỗi** | return code (-1, 0) | exception (throw/catch) | `std::optional` + `[[nodiscard]]` | C++17: exception-free error handling |
| **Union** | `union` (unsafe) | `union` (unsafe) | `std::variant` | C++17: type-safe, compiler enforce |
| **Chuỗi** | `char*`, `strlen()` | `std::string` (heap!) | `std::string_view` (zero-copy) | C++17: embedded-friendly |
| **Destructuring** | Không | `std::tie` (verbose) | Structured binding | C++17 sạch nhất |
| **Check return** | Convention | Convention | `[[nodiscard]]` | C++17: compiler enforce |
| **Generic code** | `void*` + macro | Template | Template + fold expression | C++ template = zero-cost |
| **Resource mgmt** | `malloc`/`free` thủ công | RAII, `unique_ptr` | Giống C++ | RAII = must-have |
| **Encapsulation** | `static` file scope | `class` private/public | Giống C++ | Class = zero-cost abstraction |
| **Polymorphism** | Function pointer | Virtual (runtime cost) | `std::variant` + `std::visit` | C++17: zero-runtime poly |
| **Byte thô** | `uint8_t` | `uint8_t` | `std::byte` | C++17: type-safe raw data |
| **Compile-time check** | Macro hack | `static_assert` (C++11) | `static_assert` (no msg OK) | Bắt lỗi trước khi flash |

## Khi nào dùng C?
- Chip < 4KB Flash (8-bit AVR, PIC10F)
- Team chỉ biết C
- Bắt buộc MISRA C compliance
- Viết Linux kernel driver (kernel = C thuần)

## Khi nào dùng C++?
- Chip ARM Cortex-M (64KB+ Flash)
- Project > 10,000 dòng code
- Cần RAII, template, namespace
- Tắt exception/RTTI (`-fno-exceptions -fno-rtti`)

## Khi nào dùng C++17?
- Compiler hỗ trợ (GCC 7+, Clang 5+, `arm-none-eabi-g++` 7+)
- Muốn `constexpr` lookup table, `optional` error handling, `string_view` zero-copy
- Muốn `if constexpr` thay cho SFINAE/`#ifdef` phức tạp
- `std::variant` state machine thay cho enum+switch

## Exercises
Xem `exercises/` folder.

## Interview
Xem `interview.md`.
