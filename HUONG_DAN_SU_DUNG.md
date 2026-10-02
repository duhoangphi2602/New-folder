# 📖 HƯỚNG DẪN SỬ DỤNG - Embedded C/C++17 Learning Repository

---

## 1. TỔNG QUAN CÂY THƯ MỤC SAU KHI RENAME

```
00-getting-started/           → Cài đặt môi trường
01-program-structure/         → Functions & Program Structure
02-pointers-arrays/           → Pointer & Array
03-structural-data/           → Struct, Union, Bit Field, Typedef, Enum
04-input-output/              → Input / Output (printf, UART, Serial)
05-memory/                    → Memory Layout (Stack, Heap, .bss, .data, Linker)
06-resource-management/       → RAII, Smart Pointers, malloc/free, new/delete
07-rtos-concurrency/          → Process & Threads, Mutex, Semaphore, Atomic
08-interrupt-isr/             → Interrupt & ISR
09-volatile-atomic-ordering/  → Volatile, Atomic, Memory Ordering
10-toolchain-build/           → Toolchain (Compiler, Linker, Make, CMake)
11-embedded-peripherals/      → GPIO, UART, SPI, I2C, DMA, ADC, Timer, PWM, RTC, Watchdog
12-cpp-vs-c-vs-cpp17/         → So sánh C vs C++ vs C++17, Templates, STL trong Embedded
13-rtos/                      → FreeRTOS chuyên sâu (Task, Scheduling, Deadlock...)
14-practical-projects/        → Các dự án thực hành tổng hợp
15-interview/                 → Ngân hàng câu hỏi phỏng vấn
16-exercises/                 → Bài tập tổng hợp theo cấp độ
17-reference/                 → Cheatsheet, Design Patterns, Checklist
```

---

## 2. MAPPING VỚI YÊU CẦU SYLLABUS (HÌNH ẢNH)

Syllabus yêu cầu **"Must-have knowledge"** cho vị trí **C/C++ Language - Embedded**. Dưới đây là bảng mapping chính xác giữa từng mục trong ảnh syllabus và các chương trong repository.

### 2.1 BASIC (Kiến thức Cơ bản)

| # | Yêu cầu trong Syllabus | Chương tương ứng | Trạng thái |
|---|------------------------|-------------------|:----------:|
| 1 | **Functions and Program Structure** | `01-program-structure/` (14 topics: source files, declaration vs definition, translation unit, preprocessing, compilation pipeline, functions, function pointer, inline/static/extern, namespace, class basics, lambda, main entry, embedded startup, constructor init) | ✅ ĐẦY ĐỦ |
| 2 | **Pointer and Array** | `02-pointers-arrays/` (16 topics: variables & addresses, pointer basics, pointer arithmetic, arrays, array vs pointer, pointer-to-pointer, void pointer, nullptr, const & pointer, pointer vs reference, dangling pointer, memory safety, alignment, memory-mapped register, std::array, std::string_view) | ✅ ĐẦY ĐỦ |
| 3 | **Structural Data (struct, union, bit field), typedef** | `03-structural-data/` (14 topics: struct, struct memory layout, padding alignment, nested struct, pointer to struct, typedef, fixed-width integers, enum, enum class, union, bit field, bit field vs bit mask, endianness, packet data representation) | ✅ ĐẦY ĐỦ |
| 4 | **Input and Output** | `04-input-output/` (9 topics: C standard I/O, C++ I/O, buffering, embedded I/O overview, UART serial, printf redirect UART, semihosting, logging, blocking vs nonblocking) | ✅ ĐẦY ĐỦ |

### 2.2 ADVANCED (OS) (Kiến thức Nâng cao)

| # | Yêu cầu trong Syllabus | Chương tương ứng | Trạng thái |
|---|------------------------|-------------------|:----------:|
| 5 | **Memory Layout** | `05-memory/` (14 topics: memory concepts, stack, heap, static storage, .text/.rodata/.data/.bss, memory map, alignment, padding, stack overflow, heap fragmentation, startup, vector table, linker script, firmware memory lifecycle) | ✅ ĐẦY ĐỦ |
| 6 | **Process and Threads** | `07-rtos-concurrency/` (13 topics: process/thread/task, bare-metal, RTOS task, scheduler, context switch, race condition, critical section, mutex, semaphore, atomic, comparison, deadlock, priority inversion) + `13-rtos/` (12 topics chuyên sâu FreeRTOS) | ✅ ĐẦY ĐỦ |
| 7 | **Mutual Exclusion (mutex, semaphore)** | `07-rtos-concurrency/08-mutex/`, `07-rtos-concurrency/09-semaphore/`, `07-rtos-concurrency/11-mutex-vs-semaphore-vs-atomic/`, `13-rtos/05-mutexes/`, `13-rtos/06-semaphores/` | ✅ ĐẦY ĐỦ |

### 2.3 KIẾN THỨC BỔ SUNG (Cần cho C++17 Embedded)

| # | Chủ đề | Chương tương ứng | Trạng thái |
|---|--------|-------------------|:----------:|
| 8 | Resource Management (RAII, Smart Ptr) | `06-resource-management/` (9 topics) | ✅ ĐẦY ĐỦ |
| 9 | Interrupt & ISR | `08-interrupt-isr/` (6 topics) | ✅ ĐẦY ĐỦ |
| 10 | Volatile & Atomic & Memory Ordering | `09-volatile-atomic-ordering/` (4 topics) | ✅ ĐẦY ĐỦ |
| 11 | Toolchain & Build System | `10-toolchain-build/` (18 topics) | ✅ ĐẦY ĐỦ |
| 12 | Embedded Peripherals | `11-embedded-peripherals/` (10 topics) | ✅ ĐẦY ĐỦ |
| 13 | C vs C++ vs C++17 Features | `12-cpp-vs-c-vs-cpp17/` (8 topics) | ⬜ CHƯA TRIỂN KHAI NỘI DUNG |
| 14 | RTOS (FreeRTOS) chuyên sâu | `13-rtos/` (12 topics) | ✅ ĐẦY ĐỦ |

> **[!WARNING]**
> Chương `12-cpp-vs-c-vs-cpp17/` là chương quan trọng nhất cho mục tiêu **C++17 Embedded** của bạn, nhưng hiện tại thư mục chỉ được tạo cấu trúc, **chưa có nội dung theory/examples/exercises**. Đây là chương cần được triển khai tiếp.

---

## 3. FORMAT MỖI TOPIC (GOLD STANDARD)

Mỗi topic đều tuân thủ cấu trúc 6 file chuẩn, đáp ứng đúng yêu cầu của bạn:

| File | Đáp ứng yêu cầu nào |
|------|---------------------|
| `README.md` | Giới thiệu, vì sao quan trọng, prerequisites |
| `theory.md` | **Khái niệm** + **Khi nào cần dùng, bối cảnh** + **Ưu/nhược điểm, so sánh** + **Ở C có tồn tại cái này không** |
| `examples/` | **Ví dụ, code** |
| `exercises/` | Bài tập tự luyện (không có lời giải) |
| `solutions/` | Lời giải chi tiết |
| `interview.md` | Câu hỏi phỏng vấn thực tế |

---

## 4. THỨ TỰ HỌC CHO TỪNG CHƯƠNG

### ⚡ QUY TẮC VÀNG: Trong mỗi topic, luôn đọc theo thứ tự:
```
README.md → theory.md → examples/ → exercises/ → (tự làm) → solutions/ → interview.md
```

---

### PHASE 1: NỀN TẢNG C/C++ (Tuần 1–3)

#### Chương 01: Program Structure
```
Thứ tự đọc các topic:
01-source-files → 02-declaration-vs-definition → 03-translation-unit 
→ 04-preprocessing → 05-compilation-pipeline → 06-functions 
→ 07-function-pointer → 08-inline-static-extern → 09-namespace 
→ 10-class-object-basics → 11-lambda → 12-main-and-program-entry 
→ 13-embedded-startup → 14-constructor-init-embedded
```
**Mục tiêu:** Hiểu được từ khi viết code đến khi nó chạy trên chip, mỗi bước xảy ra điều gì.

#### Chương 02: Pointers & Arrays
```
01-variables-and-addresses → 02-pointer-basics → 03-pointer-arithmetic 
→ 04-arrays → 05-array-vs-pointer → 06-pointer-to-pointer 
→ 07-void-pointer → 08-nullptr → 09-const-and-pointer 
→ 10-pointer-vs-reference → 11-dangling-pointer → 12-memory-safety 
→ 13-alignment → 14-memory-mapped-register → 15-std-array 
→ 16-std-string-view
```
**Mục tiêu:** Thành thạo con trỏ là kỹ năng #1 của Embedded. Từ topic 14 trở đi là cầu nối sang thế giới phần cứng.

#### Chương 03: Structural Data
```
01-struct → 02-struct-memory-layout → 03-padding-alignment 
→ 04-nested-struct → 05-pointer-to-struct → 06-typedef 
→ 07-fixed-width-integers → 08-enum → 09-enum-class 
→ 10-union → 11-bit-field → 12-bit-field-vs-bit-mask 
→ 13-endianness → 14-packet-data-representation
```
**Mục tiêu:** Hiểu cách dữ liệu nằm trong RAM đến từng byte, từng bit. Đây là nền tảng để đọc/ghi thanh ghi phần cứng.

#### Chương 04: Input/Output
```
01-c-standard-io → 02-cpp-io → 03-buffering 
→ 04-embedded-io-overview → 05-uart-serial 
→ 06-printf-redirect-uart → 07-semihosting 
→ 08-logging → 09-blocking-vs-nonblocking
```
**Mục tiêu:** Chuyển giao từ `printf` trên PC sang giao tiếp UART trên chip.

---

### PHASE 2: BỘ NHỚ & QUẢN LÝ TÀI NGUYÊN (Tuần 3–5)

#### Chương 05: Memory
```
01-memory-concepts → 02-stack → 03-heap → 04-static-storage 
→ 05-text-rodata-data-bss → 06-memory-map → 07-alignment 
→ 08-padding → 09-stack-overflow → 10-heap-fragmentation 
→ 11-startup → 12-vector-table → 13-linker-script 
→ 14-firmware-memory-lifecycle
```
**Mục tiêu:** Đây là chương quan trọng nhất. Phải hiểu hoàn toàn cách firmware nằm trong Flash, được copy vào RAM, Stack/Heap hoạt động ra sao.

#### Chương 06: Resource Management
```
01-malloc-free → 02-new-delete → 03-raii 
→ 04-ownership-lifetime → 05-smart-pointers 
→ 06-static-allocation → 07-pool-allocation 
→ 08-heap-fragmentation-embedded → 09-dynamic-alloc-embedded
```
**Mục tiêu:** Hiểu vì sao `malloc()` bị cấm trong Embedded và các phương án thay thế (RAII, Pool, Static Allocation).

---

### PHASE 3: CONCURRENCY & INTERRUPT (Tuần 5–7)

#### Chương 07: RTOS Concurrency (Lý thuyết đa nhiệm)
```
01-process-thread-task → 02-bare-metal → 03-rtos-task 
→ 04-scheduler → 05-context-switch → 06-race-condition 
→ 07-critical-section → 08-mutex → 09-semaphore 
→ 10-atomic → 11-mutex-vs-semaphore-vs-atomic 
→ 12-deadlock → 13-priority-inversion
```
**Mục tiêu:** Nắm vững khái niệm nền tảng về đa nhiệm trước khi học FreeRTOS thực hành ở Chương 13.

#### Chương 08: Interrupt & ISR
```
01-interrupt-concept → 02-nvic-arm-cortex → 03-isr-best-practices 
→ 04-volatile-in-isr → 05-rtos-isr-api → 06-isr-buffer-pattern
```
**Mục tiêu:** Hiểu cách CPU bị ngắt, tại sao ISR phải ngắn gọn, cách truyền dữ liệu từ ISR sang Task.

#### Chương 09: Volatile & Atomic
```
01-volatile → 02-volatile-vs-atomic 
→ 03-std-atomic → 04-memory-ordering
```
**Mục tiêu:** Phân biệt rõ ràng `volatile` (chống Compiler tối ưu hóa) vs `std::atomic` (chống Race Condition). Đây là câu hỏi phỏng vấn kinh điển.

---

### PHASE 4: TOOLCHAIN & PHẦN CỨNG (Tuần 7–9)

#### Chương 10: Toolchain & Build System
```
01-preprocessing → 02-compilation → 03-assembly 
→ 04-object-files → 05-linking → 06-elf → 07-bin-hex 
→ 08-symbols → 09-linker-script → 10-gcc-gpp 
→ 11-arm-none-eabi → 12-cross-compilation 
→ 13-compiler-flags → 14-optimization 
→ 15-debug-vs-release → 16-warnings → 17-make → 18-cmake
```
**Mục tiêu:** Hiểu toàn bộ quá trình từ file .cpp → .o → .elf → .bin → Flash vào chip.

#### Chương 11: Embedded Peripherals
```
01-gpio → 02-uart → 03-spi → 04-i2c → 05-dma 
→ 06-adc-dac → 07-timers → 08-pwm → 09-rtc → 10-watchdog
```
**Mục tiêu:** Điều khiển phần cứng ở mức thanh ghi. Hiểu nguyên lý hoạt động của từng loại giao tiếp.

---

### PHASE 5: C++ VÀ C++17 TRONG EMBEDDED (Tuần 9–10)

#### Chương 12: C vs C++ vs C++17
```
01-c-language → 02-cpp-language → 03-cpp17-features 
→ 04-c-vs-cpp-vs-cpp17-comparison → 05-exceptions-rtti 
→ 06-move-semantics → 07-templates → 08-stl-strategy-embedded
```
**Mục tiêu:** 
- **Khái niệm:** Mỗi feature C++17 là gì (constexpr, if constexpr, std::optional, std::variant, structured binding, [[nodiscard]], noexcept...).
- **Ví dụ, code:** Code mẫu thực tế cho từng feature.
- **Khi nào cần dùng, bối cảnh:** Dùng trong Embedded hay chỉ trên Desktop?
- **Ưu/nhược điểm, so sánh:** So sánh với phương án C thuần tương đương.
- **Ở C có tồn tại không?** Giải thích rõ.

> **[!IMPORTANT]**
> **CHƯƠNG NÀY HIỆN CHƯA CÓ NỘI DUNG.** Đây là chương tiếp theo cần triển khai.

---

### PHASE 6: RTOS THỰC HÀNH (Tuần 10–12)

#### Chương 13: FreeRTOS chuyên sâu
```
01-bare-metal-vs-rtos → 02-task-scheduling → 03-context-switching 
→ 04-priorities-preemption → 05-mutexes → 06-semaphores 
→ 07-queues → 08-event-groups → 09-software-timers 
→ 10-priority-inversion → 11-deadlocks → 12-freertos-config
```
**Mục tiêu:** Thực hành FreeRTOS với code thực tế. Hiểu cách debug Deadlock, Priority Inversion, Stack Overflow.

---

### PHASE 7: THỰC HÀNH & ÔN TẬP (Tuần 12+)

#### Chương 14–17: Practical Projects, Interview, Exercises, Reference
```
14-practical-projects/ → Làm từng project một
15-interview/          → Ôn tập câu hỏi phỏng vấn
16-exercises/          → Làm bài tập tổng hợp
17-reference/          → Tra cứu nhanh khi cần
```

---

## 5. TỔNG KẾT TRẠNG THÁI HIỆN TẠI

| Chương | Số topic | Nội dung (theory + examples + exercises + solutions + interview) | Trạng thái |
|--------|----------|--------------------------------------------------------------|:----------:|
| 00 | - | Cấu trúc thư mục | ⬜ Chưa có nội dung |
| 01 | 14 | ✅ Đầy đủ 6 file/topic | ✅ |
| 02 | 16 | ✅ Đầy đủ 6 file/topic | ✅ |
| 03 | 14 | ✅ Đầy đủ 6 file/topic | ✅ |
| 04 | 9 | ✅ Đầy đủ 6 file/topic | ✅ |
| 05 | 14 | ✅ Đầy đủ 6 file/topic | ✅ |
| 06 | 9 | ✅ Đầy đủ 6 file/topic | ✅ |
| 07 | 13 | ✅ Đầy đủ 6 file/topic | ✅ |
| 08 | 6 | ✅ Đầy đủ 6 file/topic | ✅ |
| 09 | 4 | ✅ Đầy đủ 6 file/topic | ✅ |
| 10 | 18 | ✅ Đầy đủ 6 file/topic | ✅ |
| 11 | 10 | ✅ Đầy đủ 6 file/topic | ✅ |
| **12** | **8** | **⬜ Chỉ có thư mục, chưa có nội dung** | **⬜ CẦN LÀM** |
| 13 | 12 | ✅ Đầy đủ 6 file/topic | ✅ |
| 14 | 11 | ⬜ Chỉ có thư mục | ⬜ Chưa có nội dung |
| 15 | - | ⬜ Chỉ có thư mục | ⬜ Chưa có nội dung |
| 16 | - | ⬜ Chỉ có thư mục | ⬜ Chưa có nội dung |
| 17 | - | ⬜ Chỉ có thư mục | ⬜ Chưa có nội dung |

**Tổng số topic đã hoàn thành nội dung:** 139 topics (Chương 01–11 + 13)
**Chương ưu tiên tiếp theo:** `12-cpp-vs-c-vs-cpp17/` (C++17 Features — Trọng tâm chính của bạn)

---

## 6. CÁCH SỬ DỤNG HÀNG NGÀY

1. **Mở chương theo Phase** (xem mục 4 ở trên).
2. **Trong mỗi topic:** Đọc `README.md` → `theory.md` → xem code trong `examples/` → tự làm `exercises/` → đối chiếu `solutions/` → ôn `interview.md`.
3. **Không nhảy cóc:** Các topic được sắp xếp theo dependency. Topic sau phụ thuộc kiến thức của topic trước.
4. **Khi ôn thi phỏng vấn:** Đọc tất cả `interview.md` trong các chương 01–13. Hoặc vào thẳng `15-interview/` để ôn theo cấp độ.
5. **Khi cần tra cứu nhanh:** Vào `17-reference/cheatsheets/`.
