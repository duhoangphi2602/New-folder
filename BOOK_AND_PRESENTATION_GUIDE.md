# 📖 CẨM NANG SỬ DỤNG NHƯ MỘT CUỐN SÁCH & HƯỚNG DẪN THUYẾT TRÌNH C++17

Bộ tài liệu này được thiết kế như một cuốn giáo trình thực chiến. Dưới đây là cách bạn đọc nó theo thứ tự tuyến tính (từ trang đầu đến trang cuối) và cách trích xuất nội dung để tạo slide thuyết trình (Present) bám sát 100% yêu cầu Syllabus của bạn.

---

## PHẦN 1: ĐỌC NHƯ MỘT CUỐN SÁCH (READING ORDER & MAPPING)

Hãy đọc lần lượt theo thứ tự dưới đây. Bảng này đã mapping chính xác các chương trong kho tài liệu với yêu cầu trong ảnh Syllabus của bạn.

### TẬP 1: Basic (Nền tảng C/C++ cho Nhúng)
*Tương ứng với mục "Basic" trong Syllabus.*

| Thứ tự đọc | Chủ đề Syllabus | Đọc ở Thư mục nào? | Nội dung cốt lõi bạn sẽ học |
|:---:|---|---|---|
| **1** | **Functions & Program Structure** | `01-program-structure/` | Cách tổ chức 1 chương trình C/C++, compiler pipeline (từ .cpp ra mã máy), cách hàm hoạt động ở mức CPU, và quá trình khởi động (startup) của firmware. |
| **2** | **Pointer and Array** | `02-pointers-arrays/` | Nắm vững con trỏ, phép toán con trỏ, mảng. **Đặc biệt:** Cách dùng con trỏ để ép kiểu và can thiệp trực tiếp vào địa chỉ RAM/thanh ghi phần cứng. |
| **3** | **Structural Data** | `03-structural-data/` | Memory layout, Padding, Alignment. Cách dùng Struct, Bit-field, Union để đóng gói dữ liệu truyền qua UART hoặc cấu hình thanh ghi mà không bị sai lệch byte. |
| **4** | **Input and Output** | `04-input-output/` | Hiểu tại sao `printf` mặc định không chạy trên chip, cách "redirect" IO xuống cổng UART, và tư duy Non-blocking I/O. |
| **5** | *(Bổ sung C++17)* | `12-cpp-vs-c-vs-cpp17/` | **RẤT QUAN TRỌNG:** Sau khi hiểu C, bạn đọc chương này để nâng cấp toàn bộ tư duy lên C++17 (constexpr, std::optional, std::string_view) áp dụng cho Nhúng. |

### TẬP 2: Advanced (Hệ điều hành OS / RTOS)
*Tương ứng với mục "Advanced (OS)" trong Syllabus.*

| Thứ tự đọc | Chủ đề Syllabus | Đọc ở Thư mục nào? | Nội dung cốt lõi bạn sẽ học |
|:---:|---|---|---|
| **6** | **Memory Layout** | `05-memory/` | Bản đồ bộ nhớ của vi điều khiển (Stack, Heap, .data, .bss). Nguy cơ Stack Overflow và Heap Fragmentation (lý do cấm dùng `malloc`/`new` tùy tiện). |
| **7** | **Process and Threads** | `07-rtos-concurrency/` & `13-rtos/` | Hiểu khái niệm Đa nhiệm (Concurrency), Context Switch (lưu trạng thái CPU), Task Scheduler, và vòng đời của Task. |
| **8** | **Mutual Exclusion** | `13-rtos/05-mutexes/` & `06-semaphores/`| Cách bảo vệ tài nguyên chung (UART, biến global) bằng Mutex. Phân biệt Mutex (có tính sở hữu) và Semaphore (dùng để báo hiệu từ Ngắt - ISR). |
| **9** | *(Bổ sung OS)* | `13-rtos/` (Các bài còn lại)| Deadlock, Priority Inversion (Nghịch lý ưu tiên) và cách cấu hình FreeRTOS Config. |

---

## PHẦN 2: CHIẾN LƯỢC THUYẾT TRÌNH (PRESENTATION GUIDE)

Với mỗi chủ đề trong Syllabus, khi bạn chuẩn bị slide hoặc nói trước ban giám khảo, **hãy bám sát khung 5 bước (5-Point Framework)** sau đây. 

*(Dưới đây là một ví dụ mẫu hoàn chỉnh về cách bạn thuyết trình nội dung `std::optional` trong C++17)*

### 1. Khái niệm (Concept)
*Luôn bắt đầu bằng 1 câu định nghĩa ngắn gọn, đi thẳng vào bản chất.*
> **Ví dụ thuyết trình:** "Hôm nay em trình bày về `std::optional` trong C++17. Khái niệm của nó là một container an toàn-kiểu (type-safe), chứa ĐÚNG MỘT giá trị kiểu T, hoặc KHÔNG CHỨA GÌ CẢ (`std::nullopt`). Nó sinh ra để thay thế việc trả về các mã lỗi (magic numbers như -1, 0) khi một hàm thất bại."

### 2. Bối cảnh & Hoạt động trong Embedded (Context & Embedded Use)
*Giải thích vì sao vi điều khiển lại cần cái này.*
> **Ví dụ thuyết trình:** "Trong lập trình nhúng, khi đọc cảm biến nhiệt độ qua I2C, quá trình này rất dễ thất bại (do nhiễu hoặc lỏng dây). Việc biểu diễn sự thất bại này rất quan trọng. Thay vì throw exception (gây phình to kích thước Firmware và khó đoán thời gian thực thi) hoặc dùng con trỏ (có nguy cơ NULL), `std::optional` là giải pháp hoàn hảo cho Embedded vì nó lưu trữ trực tiếp trên bộ nhớ Stack (hoàn toàn không dùng Heap - 0 malloc)."

### 3. Nêu ví dụ, Code, Giải thích (Example & Code)
*Đưa code lên slide, giải thích từng dòng.*
> **Ví dụ thuyết trình:** "Mời anh/chị xem đoạn code C++17 sau:"
> ```cpp
> [[nodiscard]] std::optional<float> read_temperature_sensor() {
>     float temp;
>     if (i2c_read(0x48, &temp) == SUCCESS) {
>         return temp; // Có giá trị
>     }
>     return std::nullopt; // Lỗi phần cứng, không có giá trị
> }
> 
> // Sử dụng
> auto result = read_temperature_sensor();
> if (result.has_value()) {
>     printf("Nhiệt độ: %.1f\n", result.value());
> }
> ```
> "Compiler sẽ ép lập trình viên phải kiểm tra `.has_value()` trước khi lấy dữ liệu ra, giúp triệt tiêu hoàn toàn lỗi phần mềm do truy cập dữ liệu rác."

### 4. Bổ sung so sánh với C (C Comparison)
*Nhấn mạnh sự vượt trội so với C (vì bạn đang ứng tuyển vị trí C/C++).*
> **Ví dụ thuyết trình:** "Nếu ở ngôn ngữ C thuần, chúng ta không có optional. Chúng ta thường phải giải quyết bằng 2 cách:
> 1. Trả về `-1` để báo lỗi: `float read_temp()`. Rất nguy hiểm vì nhỡ nhiệt độ âm 1 độ thì sao?
> 2. Truyền con trỏ đầu ra: `int read_temp(float* out)`. Cách này an toàn hơn nhưng code rườm rà và lập trình viên vẫn có thể quên kiểm tra mã lỗi trả về (return code).
> Trong C++17, `std::optional` giải quyết triệt để sự nhập nhằng này."

### 5. Ưu/Nhược điểm & So sánh với các tính năng tương tự (Pros/Cons & Alternatives)
*Chốt lại vấn đề để thể hiện góc nhìn của Senior.*
> **Ví dụ thuyết trình:** 
> - **Ưu điểm:** Type-safe, Zero-heap allocation (chạy tốt trên chip nhỏ), dễ đọc.
> - **Nhược điểm:** Kích thước struct sẽ lớn hơn 1 chút (thường tốn thêm 1 byte cho cờ boolean `has_value` và vài byte padding so với kiểu T gốc).
> - **So sánh:** Nếu so với `std::variant<float, ErrorCode>`, thì `variant` mang được chi tiết mã lỗi (lỗi I2C hay lỗi Timeout), trong khi `std::optional` chỉ biết là có lỗi chứ không biết lỗi gì. Tùy yêu cầu hệ thống mà em sẽ chọn `optional` cho đơn giản, hoặc `variant` nếu cần log lỗi chi tiết.

---

## 3. CÁCH LẤY TÀI LIỆU ĐỂ LÀM SLIDE NHANH NHẤT

Với cấu trúc thư mục hiện tại của bạn, để làm Slide Thuyết trình theo đúng 5 bước trên, bạn chỉ cần mở các file sau trong từng thư mục chủ đề:

1. **Khái niệm & Bối cảnh:** Mở file `theory.md` và `README.md`.
2. **Code & Ví dụ:** Mở file `theory.md` (phần code snippet) hoặc copy code chạy thật trong thư mục `examples/`.
3. **Ưu/Nhược & So sánh với C:** Mở file `theory.md` (luôn có sẵn bảng so sánh) và file `interview.md` (nơi chứa các câu hỏi phản biện cực gắt từ góc độ chuyên gia).

Hãy bám sát `GUIDE` này, bài thuyết trình C++17 Embedded của bạn sẽ cực kỳ thuyết phục và mang đậm tính kỹ thuật thực chiến!
