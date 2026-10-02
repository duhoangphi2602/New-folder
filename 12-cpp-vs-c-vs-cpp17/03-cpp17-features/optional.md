# std::optional (C++17)

## Khái niệm
`std::optional<T>` là container chứa **một giá trị kiểu T hoặc không chứa gì cả** (`std::nullopt`). Nó thay thế pattern truyền thống "trả về -1 nếu lỗi" hoặc "truyền pointer output + return bool" bằng một giải pháp type-safe.

## Code
```cpp
#include <optional>

// TRƯỚC (C style): hàm trả int, -1 nghĩa là lỗi
int read_temperature_c(float* out) {
    if (sensor_disconnected) return -1;  // Error
    *out = 25.5f;
    return 0;  // Success
}

// SAU (C++17): hàm trả optional<float>
std::optional<float> read_temperature() {
    if (sensor_disconnected) return std::nullopt;  // Không có giá trị
    return 25.5f;  // Có giá trị
}

// Sử dụng
void task() {
    auto temp = read_temperature();
    
    if (temp.has_value()) {
        printf("Temp: %.1f\n", temp.value());  // hoặc *temp
    } else {
        printf("Sensor error!\n");
    }
    
    // Hoặc dùng value_or() để cung cấp giá trị mặc định
    float safe_temp = temp.value_or(0.0f);  // Nếu nullopt → dùng 0.0
}
```

## Khi nào cần dùng / Bối cảnh
- **Hàm có thể thất bại** — thay vì trả `-1` hoặc magic number.
- **Giá trị chưa được khởi tạo** — thay vì dùng flag `bool is_valid`.
- **Config/Setting tùy chọn** — `std::optional<uint32_t> timeout_ms;` (có thể không cần timeout).
- **Lookup/Search** — tìm kiếm trong bảng, có thể không tìm thấy.

## Ưu/nhược điểm, so sánh

| | Return code (C) | Pointer output (C) | `std::optional` (C++17) |
|-|-----------------|---------------------|------------------------|
| Type safety | ❌ int trả -1 dễ nhầm | ⚠️ Pointer có thể NULL | ✅ Compiler enforce check |
| Ý nghĩa rõ ràng | ❌ -1 = lỗi gì? | ❌ NULL = lỗi gì? | ✅ nullopt = không có giá trị |
| Heap allocation | ❌ Không | ❌ Không | ❌ Không (stack-based) |
| Kích thước | 4 bytes (int) | 4 bytes (pointer) | sizeof(T) + 1 byte (flag) |
| Kết hợp [[nodiscard]] | ❌ Không | ❌ Không | ✅ Compiler cảnh báo nếu bỏ qua |

## Ở C có tồn tại không?
**Không.** C truyền thống dùng:
1. Return code: `int result = func();` — caller dễ bỏ qua.
2. Output pointer: `int func(float* out);` — `out` có thể NULL, không kiểm tra được.
3. Struct kèm flag: `struct Result { bool ok; float val; };` — giải pháp thủ công, không chuẩn hóa.

`std::optional` chuẩn hóa tất cả thành 1 pattern duy nhất, type-safe, zero-heap.
