# Exercises: Exceptions, RTTI, Move Semantics, Templates

## Exercise 1: Exception-free Error Handling
Viết lại hàm sau để không dùng exception, chỉ dùng `std::optional` và `std::variant`:
```cpp
float divide(float a, float b) {
    if (b == 0.0f) throw std::runtime_error("Division by zero");
    return a / b;
}
```

## Exercise 2: Move vs Copy
Bạn có class `Packet` chứa buffer 512 bytes. Hàm `create_packet()` tạo 1 Packet và return.
```cpp
Packet create_packet() {
    Packet p;
    p.fill_data();
    return p;
}
Packet my_pkt = create_packet();
```
**Task:** Nếu `Packet` chỉ có copy constructor (không có move constructor), compiler sẽ copy 512 bytes. Viết move constructor cho `Packet` để tránh copy.

## Exercise 3: Template Bloat
Bạn viết `RingBuffer<T, N>` template. Trong project, bạn dùng:
```cpp
RingBuffer<uint8_t, 64> buf1;
RingBuffer<uint8_t, 128> buf2;
RingBuffer<uint8_t, 256> buf3;
RingBuffer<uint16_t, 64> buf4;
```
**Task:** Compiler sẽ sinh ra bao nhiêu phiên bản class riêng biệt? Giải thích vì sao template có thể gây "code bloat" và cách giảm thiểu.
