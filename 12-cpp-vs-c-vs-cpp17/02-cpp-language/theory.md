# C++ Language — Tổng quan

## 1. Khái niệm
C++ là ngôn ngữ **đa mô hình (multi-paradigm)**: hỗ trợ cả Procedural (như C), Object-Oriented (class/inheritance), và Generic Programming (template). C++ được thiết kế với triết lý **"Zero-cost abstraction"** — bạn không trả chi phí runtime cho tính năng bạn không dùng.

**6 tính năng C++ bổ sung so với C:**

### 1.1 Class & Encapsulation
```cpp
class UartDriver {
private:
    volatile uint32_t* const base_addr;  // Chỉ class này mới truy cập được
    uint32_t baud_rate;
public:
    UartDriver(uint32_t base, uint32_t baud) 
        : base_addr(reinterpret_cast<volatile uint32_t*>(base)), baud_rate(baud) {
        init();  // Constructor tự gọi init
    }
    ~UartDriver() { disable(); }  // Destructor tự cleanup
    void send(uint8_t byte);
};
```
**Ở C có không?** Không. C dùng struct + function pointer để mô phỏng, nhưng không có private/public, không có constructor/destructor tự động.

### 1.2 RAII (Resource Acquisition Is Initialization)
```cpp
void process_data() {
    MutexLock lock(i2c_mutex);   // Constructor: lock mutex
    read_i2c_sensor();
    // Nếu exception hoặc return ở đây, destructor vẫn TỰ ĐỘNG unlock!
}  // Destructor tự gọi: unlock mutex
```
**Ở C có không?** Không. C phải gọi `mutex_unlock()` thủ công trên MỌI đường exit (return, goto, error). Quên gọi = deadlock.

### 1.3 Template (Generic Programming)
```cpp
template<typename T, size_t N>
class RingBuffer {
    T data[N];        // Kiểu dữ liệu và kích thước do người dùng quyết định
    size_t head = 0;
public:
    void push(const T& item) { data[head++ % N] = item; }
};

RingBuffer<uint8_t, 256> uart_rx;  // RingBuffer cho UART, 256 bytes
RingBuffer<float, 32>    adc_buf;  // RingBuffer cho ADC, 32 floats
```
**Ở C có không?** Không thực sự. C dùng `void*` + macro để mô phỏng, nhưng mất hoàn toàn type safety.

### 1.4 Function Overloading
```cpp
void print(int x)         { printf("%d", x); }
void print(float x)       { printf("%.2f", x); }
void print(const char* s) { printf("%s", s); }
// Compiler chọn đúng phiên bản dựa trên kiểu tham số
```
**Ở C có không?** Không. C bắt buộc tên hàm khác nhau: `print_int()`, `print_float()`, `print_str()`.

### 1.5 Reference (`&`)
```cpp
void swap(int& a, int& b) { int tmp = a; a = b; b = tmp; }
// Gọi: swap(x, y);  — không cần &x, &y như C
```
**Ở C có không?** Không. C phải dùng pointer: `void swap(int* a, int* b)` và caller gọi `swap(&x, &y)`.

### 1.6 Namespace
```cpp
namespace uart { void init(); void send(uint8_t b); }
namespace spi  { void init(); void send(uint8_t b); }
// Không xung đột dù cả 2 module đều có hàm init() và send()
```
**Ở C có không?** Không. C dùng prefix thủ công: `uart_init()`, `spi_init()`.

## 2. Khi nào cần dùng / Bối cảnh
- **MCU trung bình trở lên** (ARM Cortex-M3/M4/M7 với 64KB+ Flash, 20KB+ RAM) — đủ dư để chứa C++ runtime.
- **Project lớn** (>10,000 dòng code) — Class/Namespace giúp tổ chức code module hóa.
- **Driver tái sử dụng** — Template cho phép viết 1 RingBuffer dùng cho UART, SPI, CAN.
- **Safety-critical** — RAII đảm bảo resource không bao giờ bị leak.

## 3. Ưu và Nhược điểm

| Ưu điểm | Nhược điểm |
|----------|-----------|
| Type safety mạnh (template thay cho void*) | Binary size lớn hơn C nếu dùng exception/RTTI |
| RAII tự động cleanup resource | Compiler C++ chậm hơn C |
| Namespace ngăn xung đột tên | Một số tính năng (virtual, dynamic_cast) có runtime cost |
| Code ngắn gọn hơn (overloading, reference) | Đường cong học tập dốc hơn C |
| Zero-cost abstraction nếu dùng đúng | Không phải mọi Embedded C++ compiler đều support đầy đủ |

## 4. Zero-cost Abstraction — Giải thích
```cpp
// C code
gpio_set_mode(GPIOA, 5, OUTPUT);
gpio_write(GPIOA, 5, HIGH);

// C++ code
Gpio led(GPIOA, 5, Gpio::Output);
led.set(true);
```
Sau khi compiler tối ưu hóa (`-O2`), cả 2 đoạn code trên sinh ra **assembly giống hệt nhau**. Class `Gpio` không tạo ra bất kỳ overhead nào so với C. Đây là "zero-cost" — bạn có thêm encapsulation, type safety, và RAII mà không trả thêm một CPU cycle nào.

## 5. Exercises
Xem `exercises/` folder.

## 6. Interview
Xem `interview.md`.
