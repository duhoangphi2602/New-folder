# inline variables (C++17)

## Khái niệm
`inline variable` cho phép khai báo và **định nghĩa biến toàn cục trong header file** mà không bị lỗi "multiple definition" khi header được include bởi nhiều `.cpp` file. Trước C++17, đây là vấn đề kinh điển của C/C++.

## Code
```cpp
// TRƯỚC C++17 — phải tách khai báo và định nghĩa
// config.h
extern const uint32_t MAX_RETRIES;  // Khai báo

// config.cpp
const uint32_t MAX_RETRIES = 3;     // Định nghĩa (chỉ 1 file duy nhất!)

// SAU C++17 — tất cả trong header
// config.h
inline constexpr uint32_t MAX_RETRIES = 3;  // Khai báo + Định nghĩa
inline constexpr uint32_t BUFFER_SIZE = 256;
inline constexpr float VOLTAGE_REF = 3.3f;

// Mọi .cpp include config.h đều thấy giá trị, không bị multiple definition.
```

## Khi nào cần dùng
- **Header-only library** — toàn bộ code nằm trong `.h`, không cần `.cpp`.
- **Hằng số config** — `inline constexpr` thay thế `extern const` + `.cpp` file riêng.
- **Singleton pattern** — `inline static` instance trong header.

## Ưu/nhược điểm

| Ưu | Nhược |
|----|-------|
| Giảm boilerplate (không cần file .cpp riêng cho constant) | Chỉ C++17 trở lên |
| Header-only design sạch sẽ | Nếu lạm dụng → header bloat |
| Kết hợp hoàn hảo với constexpr | |

## Ở C có tồn tại không?
**Không.** C buộc phải dùng pattern `extern` + định nghĩa ở 1 `.c` file duy nhất. Hoặc dùng `#define` (mất type safety). C++17 `inline variable` loại bỏ hoàn toàn vấn đề này.
