# [[nodiscard]] (C++17)

## Khái niệm
`[[nodiscard]]` là một **attribute** đánh dấu rằng giá trị trả về của hàm **KHÔNG ĐƯỢC bỏ qua**. Nếu caller gọi hàm mà không kiểm tra return value, compiler sẽ phát ra warning.

## Code
```cpp
// TRƯỚC: Caller dễ bỏ qua lỗi
int i2c_write(uint8_t addr, const uint8_t* data, size_t len);
i2c_write(0x48, buf, 10);  // Return value bị bỏ qua — BUG âm thầm!

// SAU (C++17)
[[nodiscard]] int i2c_write(uint8_t addr, const uint8_t* data, size_t len);
i2c_write(0x48, buf, 10);  // ⚠️ Compiler warning: return value discarded!

// Buộc caller phải check:
if (i2c_write(0x48, buf, 10) != 0) {
    handle_error();  // OK — return value được sử dụng
}

// Có thể đánh dấu cả struct/class
struct [[nodiscard]] ErrorCode { int code; };
ErrorCode validate_packet(const uint8_t* pkt);
validate_packet(data);  // ⚠️ Warning!
```

## Khi nào cần dùng
- **Mọi hàm trả error code** — `init()`, `write()`, `read()` trong driver.
- **Hàm allocate resource** — `create_task()`, `open_file()`. Bỏ qua = resource leak.
- **Hàm trả `std::optional`** — bỏ qua = mất hoàn toàn thông tin lỗi.

## Ưu/nhược điểm

| Ưu | Nhược |
|----|-------|
| Bắt bug "quên check error" tại compile-time | Chỉ là warning, không phải error (trừ khi dùng -Werror) |
| Zero runtime cost (chỉ là attribute cho compiler) | Cần thêm vào từng hàm thủ công |
| Kết hợp tốt với std::optional, std::variant | |

## Ở C có tồn tại không?
**Không chuẩn.** GCC/Clang có extension: `__attribute__((warn_unused_result))`. Nhưng đây không phải C standard, không portable. `[[nodiscard]]` là C++ standard, mọi compiler đều support.
