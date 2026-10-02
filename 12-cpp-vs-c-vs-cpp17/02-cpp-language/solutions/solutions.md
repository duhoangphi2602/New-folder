# Solutions: C++ Language

## Solution 1
```cpp
class TempSensor {
    uint8_t addr;
    bool initialized = false;
public:
    explicit TempSensor(uint8_t i2c_addr) : addr(i2c_addr) {
        if (temp_sensor_init(addr) == 0) { initialized = true; }
    }
    ~TempSensor() {
        if (initialized) { temp_sensor_deinit(); } // RAII: tự cleanup
    }
    // Cấm copy để tránh double-deinit
    TempSensor(const TempSensor&) = delete;
    TempSensor& operator=(const TempSensor&) = delete;

    std::optional<float> read() {
        float temp;
        if (temp_sensor_read(&temp) == 0) return temp;
        return std::nullopt;
    }
};
// Sử dụng:
void task() {
    TempSensor sensor(0x48);
    auto temp = sensor.read();
    if (temp) { log(*temp); }
}  // sensor bị hủy → deinit() tự gọi, dù return hay exception
```

## Solution 2
**Có**, với `-O2`, compiler hiện đại (GCC, Clang) sẽ inline toàn bộ constructor và method `on()`. Assembly output sẽ chỉ là 1 lệnh `ORR` vào địa chỉ `0x40020014`, giống hệt phiên bản C. Không có vtable lookup, không có heap allocation, không có function call overhead. Đây chính là "zero-cost abstraction": bạn có thêm class, encapsulation, type safety mà không trả thêm runtime cost nào.
