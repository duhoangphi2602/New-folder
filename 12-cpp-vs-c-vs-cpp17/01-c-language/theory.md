# C Language — Tổng quan

## 1. Khái niệm
C là ngôn ngữ lập trình **thủ tục (procedural)**, được thiết kế năm 1972 bởi Dennis Ritchie tại Bell Labs. C cung cấp quyền truy cập trực tiếp vào bộ nhớ thông qua con trỏ, cho phép lập trình viên kiểm soát phần cứng ở mức thấp nhất mà vẫn giữ được tính portable (chạy được trên nhiều CPU khác nhau).

**5 đặc trưng cốt lõi:**
1. **Procedural:** Code được tổ chức thành các hàm (function), không có class hay object.
2. **Manual Memory:** Lập trình viên tự quản lý bộ nhớ bằng `malloc()`/`free()`. Không có garbage collector.
3. **Pointer-centric:** Con trỏ là công cụ trung tâm để thao tác bộ nhớ, mảng, chuỗi, và thanh ghi phần cứng.
4. **Preprocessor Macros:** Sử dụng `#define` để tạo hằng số, hàm inline, và conditional compilation.
5. **Minimal Runtime:** Không có exception, không có RTTI, không có STL. Chương trình biên dịch ra rất nhỏ, phù hợp chip có 2KB Flash.

## 2. Ví dụ Code

```c
// C thuần: GPIO Driver
#include <stdint.h>

// Truy cập thanh ghi phần cứng bằng con trỏ
#define GPIOA_BASE  0x40020000UL
#define GPIOA_MODER (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR   (*(volatile uint32_t *)(GPIOA_BASE + 0x14))

// Hàm khởi tạo — không có constructor
void gpio_init(void) {
    GPIOA_MODER &= ~(0x3 << (5 * 2)); // Clear bits
    GPIOA_MODER |=  (0x1 << (5 * 2)); // Set output mode
}

// Hàm toggle — không có method, không có this pointer
void gpio_toggle(uint8_t pin) {
    GPIOA_ODR ^= (1U << pin);
}

// Callback bằng function pointer — không có lambda, không có std::function
typedef void (*callback_t)(void);

void register_callback(callback_t cb) {
    if (cb != NULL) {  // NULL, không phải nullptr
        cb();
    }
}
```

## 3. Khi nào cần dùng / Bối cảnh
- **Chip cực nhỏ** (ATTiny, PIC10F, MSP430) với 256 bytes RAM — C++ runtime quá nặng.
- **Legacy codebase:** Hàng triệu dòng code driver Linux Kernel, U-Boot, FreeRTOS kernel đều viết bằng C.
- **Yêu cầu chuẩn an toàn:** MISRA C (ngành ô tô) và DO-178C (hàng không) có quy chuẩn kiểm tra C rõ ràng hơn C++.
- **Interop:** Mọi thư viện phần cứng (HAL, SDK) từ STMicro, NXP, TI đều cung cấp API bằng C.

## 4. Ưu và Nhược điểm

| Ưu điểm | Nhược điểm |
|----------|-----------|
| Binary cực nhỏ, runtime tối thiểu | Không có type safety mạnh (void* dùng tràn lan) |
| Biên dịch nhanh, dễ debug assembly | Không có namespace → xung đột tên hàm giữa các module |
| Portable: chạy trên mọi CPU có C compiler | Quản lý tài nguyên thủ công → memory leak, dangling pointer |
| Dễ đọc ở mức thanh ghi (MMIO) | Không có template → code bị lặp lại (copy-paste) |
| Hệ sinh thái driver/library khổng lồ | Không có RAII → phải nhớ gọi `free()`, `close()` thủ công |

## 5. So sánh nhanh

| Tính năng | C | C++ | C++17 |
|-----------|---|-----|-------|
| Paradigm | Procedural | OOP + Generic | OOP + Generic + Constexpr |
| Encapsulation | Không (dùng `static` file-scope) | `class` private/public | Giống C++ |
| Polymorphism | Function pointer + void* | Virtual function | `std::variant` + `std::visit` |
| Error handling | Return code + errno | Exception (throw/catch) | `std::optional` |
| Constant | `#define`, `const` (không thực sự compile-time) | `const`, `constexpr` | `constexpr if`, `inline variable` |
| String | `char[]`, `strlen()` | `std::string` | `std::string_view` |

## 6. Exercises
Xem `exercises/` folder.

## 7. Interview
Xem `interview.md`.
