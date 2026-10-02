# Exercises: C Language

## Exercise 1
Bạn viết một driver I2C bằng C thuần. Hàm `i2c_read()` trả về `0` nếu thành công, `-1` nếu thất bại, và `-2` nếu timeout.
Caller phải check return code mỗi lần gọi.
**Task:** Liệt kê 2 vấn đề kiến trúc với cách xử lý lỗi bằng "return code" này, và giải thích C++17 giải quyết vấn đề này bằng `std::optional` hoặc `[[nodiscard]]` như thế nào.

## Exercise 2
Bạn cần viết một hàm `max()` hoạt động cho cả `int`, `float`, và `uint32_t` trong C thuần.
**Task:** Viết 3 phiên bản hàm `max_int()`, `max_float()`, `max_uint32()`. Sau đó giải thích vì sao C++ template (`template<typename T> T max(T a, T b)`) giải quyết vấn đề code trùng lặp này.
