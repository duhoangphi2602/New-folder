# noexcept (C++11, tăng cường C++17)

## Khái niệm
`noexcept` cam kết rằng hàm **sẽ KHÔNG BAO GIỜ throw exception**. Nếu hàm vi phạm cam kết này (throw bên trong noexcept), chương trình gọi `std::terminate()` và chết ngay lập tức.

## Code
```cpp
// Hàm cam kết không throw — compiler tối ưu hóa tốt hơn
void gpio_toggle(uint8_t pin) noexcept {
    GPIOA->ODR ^= (1U << pin);
    // Nếu ai đặt throw ở đây → chương trình crash (std::terminate)
}

// Move constructor nên luôn noexcept
class Buffer {
    uint8_t* data;
    size_t size;
public:
    Buffer(Buffer&& other) noexcept  // noexcept cho phép std::vector tối ưu
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }
};

// Conditional noexcept (C++17 style)
template<typename T>
void swap_items(T& a, T& b) noexcept(std::is_nothrow_move_constructible_v<T>) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}
```

## Khi nào cần dùng
- **Destructor** — luôn phải noexcept (throw trong destructor = UB).
- **Move constructor/assignment** — `std::vector` chỉ dùng move nếu noexcept.
- **ISR và callback** — không được throw trong hardware interrupt context.
- **Embedded** — hầu hết firmware tắt exception hoàn toàn (`-fno-exceptions`), đánh dấu noexcept để compiler biết tối ưu.

## Ưu/nhược điểm

| Ưu | Nhược |
|----|-------|
| Compiler tối ưu hóa tốt hơn (không cần tạo exception unwind table) | Nếu throw bên trong → crash không debug được |
| Binary nhỏ hơn (loại bỏ exception metadata) | Phải đảm bảo 100% không throw |
| Tài liệu hóa ý định (hàm này safe) | |

## Ở C có tồn tại không?
**Không cần.** C không có exception mechanism, nên mọi hàm C đều "noexcept" mặc định. `noexcept` chỉ có ý nghĩa trong C++ nơi exception tồn tại.
