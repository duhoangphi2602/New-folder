# Interview: C++ vs C vs C++17 (Tổng hợp chương)

## 1. Liệt kê 5 tính năng C++17 phù hợp nhất cho Embedded và giải thích vì sao.
**Answer:** (1) `constexpr` — lookup table compile-time, 0 CPU runtime. (2) `std::optional` — error handling không cần exception, không heap. (3) `std::string_view` — zero-copy string, thay `const char*`. (4) `if constexpr` — platform dispatch không cần `#ifdef`. (5) `[[nodiscard]]` — buộc check return value, bắt bug lúc compile.

## 2. Tại sao phải tắt exception (`-fno-exceptions`) trong Embedded C++?
**Answer:** Exception unwind table (`.eh_frame`) chiếm 10-30% binary. Stack unwinding là non-deterministic (không biết mất bao lâu), vi phạm real-time constraint. `throw` có thể allocate heap. Thay thế: `std::optional`, `std::variant<Result, Error>`, return code + `[[nodiscard]]`.

## 3. Template có phải "zero-cost" không?
**Answer:** Zero runtime cost: đúng — không có vtable, không có function pointer, compiler inline hoàn toàn. Nhưng NOT zero binary cost: mỗi instantiation (`RingBuffer<uint8_t, 64>`, `RingBuffer<uint16_t, 128>`) sinh code riêng biệt → binary size tăng. Mitigation: giới hạn số lượng instantiation, tách logic chung ra base class.

## 4. So sánh `std::variant` + `std::visit` với virtual function (inheritance).
**Answer:** Virtual function: runtime dispatch qua vtable, mỗi object cần vptr (4-8 bytes), cần heap allocation cho polymorphic container. `std::variant`: compile-time dispatch (nếu dùng `if constexpr` trong visitor), stack-allocated, kích thước = max(sizeof(types)), không cần heap. Nhược: số lượng type phải biết trước lúc compile, không extensible bằng inheritance.
