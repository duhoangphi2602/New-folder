# Fold Expressions (C++17)

## Khái niệm
Fold expression cho phép **áp dụng một toán tử lên tất cả tham số** của một variadic template (template nhận số lượng tham số bất kỳ) trong MỘT dòng code. Trước C++17, phải dùng đệ quy template phức tạp.

## Code
```cpp
// TRƯỚC C++17: Đệ quy template để in nhiều giá trị
template<typename T>
void print(T t) { std::cout << t; }  // Base case

template<typename T, typename... Args>
void print(T t, Args... args) {
    std::cout << t;
    print(args...);  // Đệ quy
}

// SAU C++17: Fold expression — 1 dòng
template<typename... Args>
void print(Args... args) {
    (std::cout << ... << args);  // Left fold với operator<<
}

print(1, " Hello ", 3.14, " World");  // Output: 1 Hello 3.14 World

// Ứng dụng Embedded: Kiểm tra nhiều điều kiện
template<typename... Flags>
bool all_ready(Flags... flags) {
    return (... && flags);  // flag1 && flag2 && flag3 && ...
}

bool ok = all_ready(wifi_ready, gps_ready, battery_ok);

// Ứng dụng: Tính tổng
template<typename... Ts>
auto sum(Ts... vals) {
    return (... + vals);  // val1 + val2 + val3 + ...
}
auto total = sum(1, 2, 3, 4, 5);  // 15
```

## Khi nào cần dùng
- **Logging/Debug** — in nhiều giá trị kiểu khác nhau trong 1 lời gọi.
- **Combine flags** — OR/AND nhiều bit flags: `auto mask = (... | flags);`
- **Variadic initialization** — khởi tạo nhiều peripheral cùng lúc.

## Ưu/nhược điểm

| Ưu | Nhược |
|----|-------|
| Code ngắn gọn, dễ đọc | Cần hiểu variadic template |
| Thay thế đệ quy template phức tạp | Compile-time cost nếu quá nhiều tham số |
| Zero runtime overhead (mọi thứ resolved at compile-time) | |

## Ở C có tồn tại không?
**Không.** C có `va_list` (variadic function), nhưng nó hoàn toàn runtime, không type-safe, và dễ crash nếu sai format string (ví dụ: `printf("%d", 3.14)` = UB).
