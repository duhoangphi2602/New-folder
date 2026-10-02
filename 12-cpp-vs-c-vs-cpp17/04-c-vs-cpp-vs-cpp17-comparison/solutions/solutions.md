# Solutions: C vs C++ vs C++17

## Solution 1
**Chọn C++ (tắt exception/RTTI), cẩn trọng với C++17.**
1. **RAII bắt buộc** — phanh ABS là safety-critical. Mọi resource (mutex bảo vệ CAN bus, DMA buffer) phải được giải phóng tự động. Quên `unlock()` trong C = xe mất phanh.
2. **256KB Flash đủ dư** cho C++ runtime (không exception). ARM Cortex-M4 được GCC hỗ trợ C++ đầy đủ.
3. **Template** — Viết 1 PID controller template cho cả 4 bánh xe thay vì copy-paste 4 lần.
**Cẩn trọng C++17:** Kiểm tra MISRA C++ guideline trước. Một số tính năng C++17 chưa có MISRA rule → auditor có thể từ chối. `std::optional` và `constexpr` thường được chấp nhận.

## Solution 2
```cpp
inline constexpr int MAX_RETRIES = 3;  // type-safe, scoped, debug-visible

[[nodiscard]] std::optional<float> read_sensor() {
    for (int i = 0; i < MAX_RETRIES; ++i) {
        float temp;
        if (i2c_read(0x48, &temp) == 0) return temp;
    }
    return std::nullopt;
}

// Caller — compiler cảnh báo nếu bỏ qua return value
auto temp = read_sensor();
if (temp) {
    printf("%.1f\n", *temp);  // Chỉ truy cập khi có giá trị
} else {
    printf("Sensor failed after %d retries\n", MAX_RETRIES);
}
```
