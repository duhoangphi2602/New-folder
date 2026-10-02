# Interview: C++17 Features

## 1. Giải thích sự khác nhau giữa `constexpr` và `#define` trong bối cảnh Embedded. Khi nào dùng cái nào?
**Answer:** `#define` là text replacement bởi preprocessor — không có type, không có scope, không debug được. `constexpr` là compile-time evaluation bởi compiler — có type safety, có scope (namespace/class), debugger thấy symbol. Trong Embedded, dùng `constexpr` cho tất cả hằng số cấu hình (`BAUD_RATE`, `BUFFER_SIZE`). Chỉ dùng `#define` khi cần conditional compilation (`#ifdef DEBUG`) hoặc string concatenation (`#a`).

## 2. `std::optional` giải quyết vấn đề gì so với return code truyền thống?
**Answer:** Return code (`return -1`) có 2 vấn đề: (1) caller có thể bỏ qua mà compiler không cảnh báo, (2) giá trị lỗi (-1) không type-safe và dễ nhầm với dữ liệu hợp lệ. `std::optional<T>` buộc caller phải kiểm tra `.has_value()` hoặc dùng `.value_or()`. Kết hợp `[[nodiscard]]`, compiler sẽ cảnh báo nếu bỏ qua kết quả. Không heap allocation, kích thước = sizeof(T) + 1 byte flag.

## 3. `std::variant` khác `union` trong C như thế nào?
**Answer:** `union` trong C không track kiểu nào đang active — đọc sai field là Undefined Behavior. `std::variant` tự động track kiểu active bằng internal index, và throw `std::bad_variant_access` (hoặc compile error) nếu truy cập sai. Kết hợp `std::visit`, bạn có pattern matching type-safe, hoàn hảo cho State Machine.

## 4. Vì sao `std::string_view` đặc biệt phù hợp cho Embedded?
**Answer:** `std::string_view` không allocate heap (zero-copy). Nó chỉ lưu pointer + length, hoạt động như `const char*` nhưng biết sẵn length (O(1) thay vì O(n) strlen). Substring cũng zero-copy (chỉ di chuyển pointer). Trong Embedded nơi heap bị cấm, `string_view` là cách duy nhất để xử lý chuỗi an toàn mà không tốn RAM.

## 5. `if constexpr` khác `#ifdef` như thế nào?
**Answer:** `#ifdef` là preprocessor — hoạt động ở mức text, không hiểu type system của C++. `if constexpr` là compiler feature — hiểu type, có thể kiểm tra `std::is_integral_v<T>`, và nhánh bị loại bỏ không cần compile được (quan trọng trong template). `#ifdef` vẫn cần cho platform-specific code (`#ifdef STM32`, `#ifdef ESP32`).
