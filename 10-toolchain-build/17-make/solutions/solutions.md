# Solutions: Makefiles

## Solution 1: The Hidden Header Bug
**Answer:** The prerequisite list for the `main.o` target only listed `main.cpp`. 
When you typed `make`, it checked the timestamp of `main.cpp`. Because you only edited `config.h`, the timestamp of `main.cpp` was older than `main.o`. `make` legally concluded that `main.o` did not need to be rebuilt.
To fix this, you must explicitly declare the header file as a prerequisite:
```make
main.o: main.cpp config.h
	$(CXX) $(CFLAGS) -c main.cpp -o main.o
```
Now, if *either* `main.cpp` or `config.h` is modified, `make` will trigger the recompilation. (Modern build systems auto-generate these header dependencies).

## Solution 2: The `clean` Target
**Answer:** `make` thinks every Target in the file is a physical file that needs to be built on the hard drive.
When you typed `make clean`, `make` looked at the hard drive and saw a physical file named `clean`. It checked the prerequisites (there are none). Because the physical file `clean` already exists, `make` concluded the build was successfully completed, so it didn't run the `rm` command recipe!
The **`.PHONY: clean`** declaration tells `make`: *"The word 'clean' is a fake target. It is just a command name, not a physical file. Do not look for it on the hard drive, just execute the recipe unconditionally."*
