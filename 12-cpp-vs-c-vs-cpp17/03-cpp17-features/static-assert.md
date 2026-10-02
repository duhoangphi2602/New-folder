# static_assert (C++11, message optional C++17)

## Khái niệm
`static_assert` kiểm tra một điều kiện **tại compile-time**. Nếu điều kiện sai, compilation thất bại với message lỗi rõ ràng. Dùng để bắt lỗi cấu hình, kích thước struct, alignment sai TRƯỚC KHI code chạy trên chip.

## Code
```cpp
// Đảm bảo struct không bị compiler thêm padding
struct __attribute__((packed)) UartPacket {
    uint8_t header;
    uint16_t length;
    uint32_t crc;
};
static_assert(sizeof(UartPacket) == 7, "UartPacket must be exactly 7 bytes!");

// Đảm bảo platform là 32-bit
static_assert(sizeof(void*) == 4, "This firmware requires a 32-bit platform!");

// Đảm bảo enum value hợp lệ
constexpr int MAX_TASKS = 16;
static_assert(MAX_TASKS <= 32, "FreeRTOS only supports up to 32 priorities");

// C++17: message là optional
static_assert(sizeof(int) == 4);  // OK trong C++17, lỗi trong C++11
```

## Khi nào cần dùng
- **Validate struct size** — protocol packet PHẢI đúng kích thước.
- **Validate platform** — code chỉ chạy trên 32-bit ARM.
- **Validate config** — hằng số cấu hình phải nằm trong range hợp lệ.
- **Template constraint** — kiểm tra T phải là POD type trước khi memcpy.

## Ưu/nhược điểm

| Ưu | Nhược |
|----|-------|
| Bắt lỗi sớm tại compile-time, không phải runtime | Chỉ kiểm tra biểu thức constexpr |
| Zero runtime cost (không tạo code) | Không thể kiểm tra giá trị runtime |
| Message lỗi rõ ràng | |

## Ở C có tồn tại không?
**Có, từ C11.** C11 thêm `_Static_assert(expr, msg)`. Nhưng C11 không phổ biến trên mọi embedded compiler. Trước C11, dev dùng macro hack xấu xí: `#define STATIC_ASSERT(e) typedef char[(e)?1:-1]`.
