# Interview Questions: I/O Buffering

## 1. Why do operating systems and standard libraries use buffering for I/O instead of writing directly to hardware every time?
**Answer:** Because context switching to the OS kernel or communicating with slow physical hardware (like UART or a hard drive) takes thousands of CPU cycles. If `printf("Hello")` wrote character by character, it would invoke the hardware driver 5 separate times. Buffering groups all 5 characters into a single RAM block and invokes the hardware driver exactly once, massively improving CPU throughput.

## 2. You have a `printf` statement right before a line of code that causes a Hard Fault, but the `printf` message never appears in your terminal. What happened?
**Answer:** The `printf` output was likely line-buffered, and the string did not contain a `\n` (newline). Because there was no newline to trigger a flush, the text was held in the standard library's RAM buffer. When the Hard Fault occurred, the system crashed before the buffer could be physically flushed to the UART peripheral, permanently losing the text.

## 3. What is the functional difference between `std::endl` and `\n` in C++ streams?
**Answer:** `\n` simply inserts the newline character into the stream's buffer. If the stream is line-buffered, this will trigger a flush. `std::endl` inserts the newline character AND explicitly forces a call to `stream.flush()`. While `std::endl` is safer for guaranteeing output, using it inside tight loops destroys performance because it forces physical hardware writes on every single iteration, bypassing the benefits of buffering.
