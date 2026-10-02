# Solutions: Exceptions, RTTI, Move Semantics, Templates

## Solution 1
```cpp
[[nodiscard]] std::optional<float> divide(float a, float b) {
    if (b == 0.0f) return std::nullopt;
    return a / b;
}
// Caller:
auto result = divide(10.0f, 0.0f);
float val = result.value_or(0.0f);  // 0.0f nếu chia cho 0
```

## Solution 2
```cpp
class Packet {
    uint8_t* data;
    size_t size;
public:
    Packet() : data(new uint8_t[512]), size(512) {}
    ~Packet() { delete[] data; }
    
    // Move constructor
    Packet(Packet&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }
    Packet& operator=(Packet&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data; size = other.size;
            other.data = nullptr; other.size = 0;
        }
        return *this;
    }
    // Cấm copy
    Packet(const Packet&) = delete;
    Packet& operator=(const Packet&) = delete;
};
```
Với move constructor, `create_packet()` chỉ chuyển pointer (4 bytes) thay vì copy 512 bytes.

## Solution 3
Compiler sinh ra **4 phiên bản** riêng biệt:
1. `RingBuffer<uint8_t, 64>` — code riêng
2. `RingBuffer<uint8_t, 128>` — code riêng (N khác)
3. `RingBuffer<uint8_t, 256>` — code riêng (N khác)
4. `RingBuffer<uint16_t, 64>` — code riêng (T khác)

Mỗi non-type parameter khác nhau = 1 instantiation mới.
**Giảm bloat:** Tách logic không phụ thuộc T/N ra base class không template, hoặc dùng `void*` internal + type-safe wrapper.
