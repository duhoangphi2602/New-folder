# constexpr (C++11, mở rộng mạnh ở C++14/17)

## Khái niệm
`constexpr` đánh dấu một biến hoặc hàm có thể được **tính toán hoàn toàn tại compile-time** (lúc biên dịch). Kết quả được nhúng trực tiếp vào binary dưới dạng hằng số, không tốn CPU cycle lúc runtime.

## Code
```cpp
// Hàm tính CRC tại compile-time
constexpr uint8_t crc8(const uint8_t* data, size_t len) {
    uint8_t crc = 0xFF;
    for (size_t i = 0; i < len; ++i) {
        crc ^= data[i];
        for (int j = 0; j < 8; ++j) {
            crc = (crc & 0x80) ? ((crc << 1) ^ 0x31) : (crc << 1);
        }
    }
    return crc;
}

// Bảng CRC lookup table — được tính TOÀN BỘ tại compile-time
constexpr auto make_crc_table() {
    std::array<uint8_t, 256> table{};
    for (int i = 0; i < 256; ++i) {
        uint8_t val = static_cast<uint8_t>(i);
        table[i] = crc8(&val, 1);
    }
    return table;
}
constexpr auto CRC_TABLE = make_crc_table(); // 0 CPU cycle at runtime!

// constexpr variable thay thế #define
constexpr uint32_t UART_BAUD_RATE = 115200;
constexpr uint32_t SYS_CLOCK = 84'000'000;  // C++14 digit separator
constexpr uint16_t BRR_VALUE = SYS_CLOCK / UART_BAUD_RATE;
```

## Khi nào cần dùng / Bối cảnh
- **Lookup table** (CRC, sine wave, gamma correction) — tính sẵn lúc compile, không tốn RAM/CPU runtime.
- **Hằng số cấu hình** — thay thế `#define` bằng `constexpr` có type safety.
- **Tính toán địa chỉ thanh ghi** — `constexpr uint32_t GPIOA_ODR = GPIOA_BASE + 0x14;`

## Ưu/nhược điểm, so sánh

| | `#define` (C) | `const` (C) | `constexpr` (C++17) |
|-|---------------|-------------|---------------------|
| Type safety | ❌ Không | ✅ Có | ✅ Có |
| Scope | ❌ Global | ✅ Block | ✅ Block |
| Debug symbol | ❌ Không thấy | ✅ Có | ✅ Có |
| Compile-time guaranteed | ✅ Có (text replace) | ❌ Không (C) | ✅ Có |
| Dùng được trong hàm phức tạp | ❌ Không | ❌ Không | ✅ Có (C++14 cho phép loop, if) |

## Ở C có tồn tại không?
**Không.** C chỉ có `#define` (không type-safe) và `const` (trong C, `const int x = 5;` không phải compile-time constant — bạn không thể dùng làm kích thước mảng: `int arr[x];` là lỗi trong C89).
