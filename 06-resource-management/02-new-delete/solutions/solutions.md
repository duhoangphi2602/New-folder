# Solutions: new and delete

## Solution 1: The Array Delete Bug
**Answer:** The developer used `delete` instead of `delete[]`. When you allocate an array (`new[]`), the compiler secretly stores the number of elements right before the array in memory so it knows how many destructors to call. If you use standard `delete`, the compiler assumes you are only deleting a single object. It calls the destructor for `buffer[0]` and frees a tiny chunk of memory, permanently leaking the remaining 9,999 bytes.

## Solution 2: Out of Memory Handling
**Answer:** By default, if `new` fails, it throws a `std::bad_alloc` exception. In bare-metal embedded systems, exceptions are usually physically disabled via the `-fno-exceptions` compiler flag to save Flash memory and RAM. If `new` tries to throw an exception in an environment where exceptions are disabled, the compiler simply invokes `std::terminate()`, which instantly crashes/halts the entire microcontroller! 
*(Note: To fix this, embedded devs must use `new (std::nothrow) Type();` which forces C++ to return `nullptr` instead of crashing).*
