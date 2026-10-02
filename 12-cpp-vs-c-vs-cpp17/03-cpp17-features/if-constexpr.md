# if constexpr (C++17)

## Khái niệm
`if constexpr` cho phép **rẽ nhánh tại compile-time**. Nhánh không thỏa điều kiện bị compiler loại bỏ hoàn toàn — không tạo ra machine code, không chiếm Flash. Khác biệt cốt lõi so với `if` thường: `if` thường tạo ra cả 2 nhánh trong binary.

## Code
```cpp
// Viết 1 hàm print() hoạt động cho mọi kiểu dữ liệu
template<typename T>
void print(T value) {
    if constexpr (std::is_integral_v<T>) {
        printf("%d", static_cast<int>(value));
    } else if constexpr (std::is_floating_point_v<T>) {
        printf("%.2f", static_cast<double>(value));
    } else if constexpr (std::is_same_v<T, const char*>) {
        printf("%s", value);
    }
    // Nhánh không phù hợp bị XÓA HOÀN TOÀN khỏi binary
}

// Ứng dụng Embedded: Chọn driver tại compile-time dựa trên config
template<bool USE_DMA>
void uart_send(const uint8_t* data, size_t len) {
    if constexpr (USE_DMA) {
        dma_start_transfer(data, len);  // Zero-copy, hardware DMA
    } else {
        for (size_t i = 0; i < len; ++i) {
            while (!(UART->SR & TX_EMPTY)) {}
            UART->DR = data[i];
        }
    }
}
// uart_send<true>(buf, 10);  — chỉ có DMA code trong binary
// uart_send<false>(buf, 10); — chỉ có polling code trong binary
```

## Khi nào cần dùng / Bối cảnh
- **Platform abstraction:** Viết 1 driver hoạt động trên cả STM32 và ESP32, compiler tự chọn nhánh phù hợp.
- **Feature toggle:** Bật/tắt DMA, bật/tắt logging, bật/tắt encryption — không cần `#ifdef`.
- **Type dispatch trong template:** Xử lý khác nhau tùy theo kiểu dữ liệu mà không cần SFINAE phức tạp.

## Ưu/nhược điểm, so sánh

| | `#ifdef` (C/C++) | `if` thường | `if constexpr` (C++17) |
|-|-------------------|-------------|------------------------|
| Đánh giá lúc nào | Preprocessing | Runtime | Compile-time |
| Nhánh thừa trong binary | ❌ Không | ✅ Có | ❌ Không |
| Type-safe | ❌ Không | ✅ Có | ✅ Có |
| Dùng trong template | ❌ Không (text replace) | ⚠️ Có nhưng cả 2 nhánh phải compile | ✅ Nhánh thừa không cần compile |

## Ở C có tồn tại không?
**Không.** C chỉ có `#ifdef` / `#if` (preprocessor). Chúng hoạt động ở mức text, không hiểu kiểu dữ liệu. `if constexpr` hoạt động ở mức compiler, hiểu type system, và loại bỏ code chết một cách an toàn.
