# Interview: C Language

## 1. Vì sao C vẫn là ngôn ngữ thống trị trong Embedded dù C++ đã ra đời hơn 40 năm?
**Answer:** C tạo ra binary cực nhỏ với runtime overhead gần bằng 0, phù hợp chip có vài KB Flash. C compiler tồn tại cho mọi kiến trúc CPU (ARM, RISC-V, AVR, PIC, 8051). Hệ sinh thái driver/HAL/SDK từ các nhà sản xuất chip (ST, NXP, TI) đều cung cấp API bằng C. Các chuẩn an toàn (MISRA C, DO-178C) có bộ quy tắc kiểm tra C rõ ràng hơn C++.

## 2. Trong C, `#define PI 3.14` và `const float PI = 3.14;` khác nhau thế nào? C++17 giải quyết vấn đề này ra sao?
**Answer:** `#define` là text replacement bởi preprocessor — không có type, không có scope, không debug được (debugger không thấy symbol `PI`). `const float` trong C thực chất không phải compile-time constant (không thể dùng làm kích thước mảng). C++17 cung cấp `constexpr float PI = 3.14f;` — vừa type-safe, vừa guaranteed compile-time, vừa có symbol trong debugger.

## 3. C không có `namespace`. Làm sao tránh xung đột tên khi project có 100 file?
**Answer:** Convention phổ biến nhất là dùng prefix: `uart_init()`, `spi_init()`, `i2c_init()`. Kết hợp `static` để giấu hàm internal trong file scope. C++ giải quyết bằng `namespace uart { void init(); }`.
