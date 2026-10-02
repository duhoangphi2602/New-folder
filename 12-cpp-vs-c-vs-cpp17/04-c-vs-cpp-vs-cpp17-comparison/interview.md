# Interview: C vs C++ vs C++17 Comparison

## 1. Trong một dự án Embedded, khi nào bạn chọn C thay vì C++?
**Answer:** Chọn C khi: (1) Chip có ≤4KB Flash — C++ runtime không fit. (2) Bắt buộc MISRA C compliance và chưa có MISRA C++ guideline được audit. (3) Viết Linux kernel module/driver — kernel là C thuần. (4) Toàn team chỉ biết C — C++ dùng sai còn nguy hiểm hơn C (heap allocation tràn lan, virtual function overhead).

## 2. C++17 thêm những tính năng nào đặc biệt hữu ích cho Embedded so với C++11/14?
**Answer:** (1) `if constexpr` — rẽ nhánh compile-time, thay thế SFINAE. (2) `std::optional` — error handling không cần exception. (3) `std::variant` — type-safe union, state machine. (4) `std::string_view` — zero-copy string, thay thế `const char*`. (5) `inline variable` — constant trong header không cần `.cpp`. (6) `[[nodiscard]]` — compiler enforce check return value. Tất cả đều zero-heap, zero-runtime-cost.

## 3. "Zero-cost abstraction" có thực sự zero-cost không?
**Answer:** Gần như, nhưng không tuyệt đối. Với `-O2`, class method được inline → assembly giống C. Template không có runtime overhead nhưng tăng binary size (mỗi instantiation sinh code riêng). `std::variant` lớn hơn `union` vì thêm tag byte. Tuy nhiên, so với alternative trong C (void* + cast + manual tag), C++ version vừa an toàn hơn vừa không chậm hơn.
