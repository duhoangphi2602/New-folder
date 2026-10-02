# Solutions: C Language

## Solution 1
**Vấn đề 1:** Caller có thể *bỏ qua* return code mà compiler không cảnh báo: `i2c_read(buf, 10);` — giá trị trả về bị bỏ rơi, lỗi âm thầm bị nuốt.
**Vấn đề 2:** Giá trị `-1` và `-2` là "magic number" — không type-safe, dễ nhầm lẫn.
**C++17 fix:**
- `[[nodiscard]]` — compiler sẽ cảnh báo nếu caller bỏ qua return value.
- `std::optional<Buffer>` — hàm trả về `std::nullopt` nếu lỗi, buộc caller phải check `.has_value()` trước khi dùng.

## Solution 2
```c
int   max_int(int a, int b)       { return (a > b) ? a : b; }
float max_float(float a, float b) { return (a > b) ? a : b; }
uint32_t max_uint32(uint32_t a, uint32_t b) { return (a > b) ? a : b; }
```
Logic hoàn toàn giống nhau, chỉ khác kiểu dữ liệu. Nếu cần thêm `int64_t`, phải copy-paste thêm 1 hàm nữa.
C++ template giải quyết bằng 1 hàm duy nhất:
```cpp
template<typename T>
T max(T a, T b) { return (a > b) ? a : b; }
// Compiler tự sinh ra max<int>, max<float>, max<uint32_t> tại compile-time.
```
