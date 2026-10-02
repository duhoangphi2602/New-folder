# Exercises: C vs C++ vs C++17

## Exercise 1
Bạn nhận được yêu cầu: viết firmware cho một bộ điều khiển phanh ABS ô tô. Chip sử dụng ARM Cortex-M4 với 256KB Flash, 64KB RAM. Chuẩn an toàn: MISRA. Team gồm 3 người đã quen C, 1 người biết C++.
**Task:** Bạn chọn C, C++, hay C++17? Đưa ra 3 lý do kỹ thuật.

## Exercise 2
Viết lại đoạn code C sau bằng C++17 sử dụng `std::optional`, `[[nodiscard]]`, và `constexpr`:
```c
#define MAX_RETRIES 3
int read_sensor(float* out_temp) {
    for (int i = 0; i < MAX_RETRIES; ++i) {
        if (i2c_read(0x48, out_temp) == 0) return 0;
    }
    return -1;
}
// Caller:
float temp;
read_sensor(&temp);  // Có thể bỏ qua return value!
printf("%.1f\n", temp);  // temp có thể chưa được gán!
```
