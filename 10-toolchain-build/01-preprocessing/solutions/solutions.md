# Solutions: Preprocessing

## Solution 1: The Macro Trap
**Answer:** The preprocessor is a dumb text-replacer. It takes `5 + 1` and pastes it exactly where `x` is.
The resulting translation unit sent to the compiler is:
`int result = 5 + 1 * 5 + 1;`
According to standard order of operations (PEMDAS), multiplication happens first: `1 * 5 = 5`.
Then addition: `5 + 5 + 1 = 11`.
**The Fix:** You must wrap every parameter and the entire macro in parentheses to protect the math:
`#define SQUARE(x) ((x) * (x))`
Now it expands to `((5 + 1) * (5 + 1))`, which safely equals 36. (Or better yet, use C++ `inline` functions instead of macros).

## Solution 2: Include Guards
**Answer:** The Preprocessor enters an infinite copy-paste loop. 
It opens `A.h`, sees the include for `B.h`, so it opens `B.h`. In `B.h`, it sees the include for `A.h`, so it opens `A.h` again. It continues copy-pasting back and forth infinitely until the preprocessor runs out of computer RAM and crashes (often throwing a "Maximum Include Depth Reached" error). 
Include Guards (`#ifndef A_H \n #define A_H \n ... \n #endif`) solve this by ensuring the preprocessor only ever copy-pastes the contents of a specific header file exactly once per translation unit.
