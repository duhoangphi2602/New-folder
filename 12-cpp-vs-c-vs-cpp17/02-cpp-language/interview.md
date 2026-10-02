# Interview: C++ Language

## 1. "Zero-cost abstraction" nghĩa là gì? Cho ví dụ trong Embedded.
**Answer:** Zero-cost abstraction có nghĩa là sử dụng các tính năng trừu tượng hóa của C++ (class, template, RAII) mà không phải trả thêm bất kỳ chi phí runtime (CPU cycle, RAM) nào so với viết cùng logic bằng C thuần. Ví dụ: một class `Gpio` wrap thanh ghi phần cứng, sau khi compiler tối ưu hóa `-O2`, sinh ra assembly bit-set instruction giống hệt macro `#define` trong C.

## 2. RAII giải quyết vấn đề gì mà C không giải quyết được?
**Answer:** RAII đảm bảo resource (mutex, file handle, memory, peripheral) được giải phóng tự động khi object bị hủy (ra khỏi scope). Trong C, nếu một hàm có 5 điểm `return` khác nhau, lập trình viên phải gọi `free()`/`unlock()` ở mỗi điểm. Quên 1 điểm = leak. RAII đặt cleanup vào destructor, chỉ cần viết 1 lần, compiler tự đảm bảo nó được gọi trên mọi đường exit.

## 3. Khi nào KHÔNG nên dùng C++ trong Embedded?
**Answer:** (1) Chip cực nhỏ (<4KB Flash) không có C++ compiler hoặc runtime quá nặng. (2) Project bắt buộc tuân thủ MISRA C mà chưa có MISRA C++ guideline phù hợp. (3) Team toàn bộ chỉ biết C — ép dùng C++ tạo ra code tệ hơn C thuần vì dùng sai cách (allocate heap tràn lan, dùng `virtual` không cần thiết).
