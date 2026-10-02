# Templates (C++ Generic Programming)

## Khái niệm
Template cho phép viết **hàm hoặc class hoạt động với nhiều kiểu dữ liệu** mà chỉ viết code 1 lần. Compiler sẽ **sinh ra (instantiate)** phiên bản cụ thể cho mỗi kiểu tại compile-time. Không có runtime overhead — đây là compile-time code generation.

## Code
```cpp
// Function template
template<typename T>
T clamp(T value, T min_val, T max_val) {
    if (value < min_val) return min_val;
    if (value > max_val) return max_val;
    return value;
}

uint8_t pwm = clamp<uint8_t>(raw_adc, 0, 255);
float voltage = clamp<float>(reading, 0.0f, 3.3f);
// Compiler sinh ra 2 hàm riêng biệt, tối ưu cho từng kiểu

// Class template — RingBuffer tái sử dụng
template<typename T, size_t Capacity>
class RingBuffer {
    T buffer[Capacity];  // Kích thước cố định, stack-allocated
    size_t head = 0, tail = 0, count = 0;
public:
    bool push(const T& item) {
        if (count >= Capacity) return false;
        buffer[head] = item;
        head = (head + 1) % Capacity;
        ++count;
        return true;
    }
    std::optional<T> pop() {
        if (count == 0) return std::nullopt;
        T item = buffer[tail];
        tail = (tail + 1) % Capacity;
        --count;
        return item;
    }
};

RingBuffer<uint8_t, 256> uart_rx;
RingBuffer<SensorData, 16> sensor_queue;

// Non-type template parameter — compile-time config
template<uint32_t BaudRate>
class UartDriver {
    static_assert(BaudRate >= 9600 && BaudRate <= 921600, "Invalid baud rate");
    static constexpr uint16_t brr = 84'000'000 / BaudRate;
public:
    void init() { UART->BRR = brr; }
};

UartDriver<115200> debug_uart;
UartDriver<9600> gps_uart;
```

## Khi nào cần dùng
- **Container** — RingBuffer, StaticVector, Pool Allocator.
- **Driver** — GPIO<Port, Pin>, UART<BaudRate>, Timer<Channel>.
- **Utility** — `min()`, `max()`, `clamp()`, `swap()`.
- **Type traits** — `std::is_integral_v<T>`, `std::is_pointer_v<T>`.

## Ưu/nhược điểm

| Ưu | Nhược |
|----|-------|
| Zero runtime overhead (compile-time) | Code bloat: mỗi instantiation sinh code riêng |
| Type safety (không cần void*) | Compile time chậm hơn |
| Compile-time validation (static_assert) | Error message khó đọc |
| Tái sử dụng code cực mạnh | Binary size tăng nếu quá nhiều instantiation |

## Ở C có tồn tại không?
**Không.** C dùng 2 cách thay thế, cả 2 đều kém hơn:
1. `void*` — mất hoàn toàn type safety, dễ crash.
2. Macro (`#define RING_BUFFER(type, name, cap)`) — text replacement, không debug được, không scope.
