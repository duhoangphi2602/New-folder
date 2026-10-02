# STL Strategy cho Embedded

## Khái niệm
STL (Standard Template Library) là thư viện tiêu chuẩn của C++, cung cấp container, algorithm, và utility. Trong Embedded, **không phải mọi STL component đều an toàn** — một số dùng heap allocation, một số có runtime overhead không chấp nhận được.

## Phân loại: An toàn → Nguy hiểm

### ✅ AN TOÀN (Dùng thoải mái trong Embedded)
| Component | Lý do | Heap? | Runtime cost |
|-----------|-------|:-----:|:------------:|
| `std::array<T, N>` | Mảng cố định trên stack | ❌ | Zero |
| `std::string_view` | Tham chiếu chuỗi, zero-copy | ❌ | Zero |
| `std::optional<T>` | Nullable value, stack-based | ❌ | 1 byte flag |
| `std::variant<Ts...>` | Type-safe union, stack-based | ❌ | Tag byte |
| `std::byte` | Type-safe raw byte | ❌ | Zero |
| `std::tuple<Ts...>` | Fixed-size heterogeneous tuple | ❌ | Zero |
| `<algorithm>` (sort, find, transform) | Hoạt động trên array/pointer | ❌ | Zero |
| `<numeric>` (accumulate, iota) | Hoạt động trên array | ❌ | Zero |
| `<type_traits>` | Compile-time type checking | ❌ | Zero |
| `<utility>` (move, forward, swap) | Compile-time helper | ❌ | Zero |

### ⚠️ CẨN TRỌNG (Dùng được nếu kiểm soát chặt)
| Component | Rủi ro | Mitigation |
|-----------|--------|------------|
| `std::function<>` | Có thể heap allocate nếu lambda quá lớn | Dùng function pointer thay thế |
| `std::unique_ptr<T>` | Gọi delete → cần heap | Dùng placement new + static buffer |
| `<chrono>` | Một số implementation dùng syscall | Kiểm tra trên target compiler |

### ❌ TRÁNH (Heap-dependent, non-deterministic)
| Component | Vì sao nguy hiểm |
|-----------|------------------|
| `std::string` | `new`/`delete` nội bộ, resize = realloc |
| `std::vector<T>` | Heap allocation, resize gây fragmentation |
| `std::map<K,V>` | Mỗi node = 1 lần `new`, tree rebalancing |
| `std::unordered_map` | Hash table, heap allocation |
| `std::shared_ptr<T>` | Reference counting overhead, atomic ops |
| `std::list<T>` | Mỗi node = 1 lần `new` |
| `<iostream>` (cout) | Massive binary bloat (50KB+), heap buffering |
| `<regex>` | Heap-intensive, khổng lồ |

## Quy tắc vàng cho Embedded C++17
1. **Dùng `std::array` thay `std::vector`** — kích thước biết trước lúc compile.
2. **Dùng `std::string_view` thay `std::string`** — zero-copy, zero-heap.
3. **Dùng `std::optional` thay exception** — error handling không cần throw.
4. **Dùng `std::variant` thay inheritance** — zero-heap polymorphism.
5. **Tắt exception và RTTI** — `-fno-exceptions -fno-rtti`.
6. **Dùng `printf` thay `cout`** — nhỏ hơn 40KB binary.

## Ở C có tồn tại không?
**Không.** C không có STL. C dev tự viết mọi thứ (ring buffer, linked list, hash table) hoặc dùng thư viện bên thứ ba. C++ STL chuẩn hóa tất cả nhưng phải chọn lọc trong Embedded.

## Interview
Xem `interview.md`.
