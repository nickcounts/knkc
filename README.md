# knkc

This repository contains my self-study of the C programming language.
I am working though the `K N King` book `C Programming: A Modern Approach`.

All in-chapter exercises will be completed and saved as `ex##.c`, while the
end-of-chapter problems will be saved as `proj##.c`. Source code is currently
organized by chapter.

## Building the exercises and projects

I will be maintaining chapter-specific makefiles as I work through the book.
To build any of the projects, you should be able to execute `make proj10`
from within a chapter directory and build to executable. Run the exercise by
`./proj10`

Early chapters did not include an `all` target, but I have included `all`
since chapter 6. (Perhaps I will go back and add to earlier chapters)

To build the entire chapter, you should be able to use `make all` and to clean
up all the executables and the debugger symbol link directories, use
`make clean`

# Toolchain

This work is being done on a ARM64 Mac Studio, using GNU Make and Apple's clang

```bash
 make --version
GNU Make 3.81
Copyright (C) 2006  Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.

This program built for i386-apple-darwin11.3.0
```

```bash
 make --version
GNU Make 3.81
Copyright (C) 2006  Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.

This program built for i386-apple-darwin11.3.0
```

# Debugging on MacOS w/ clang

I have had luck using `lldb`, the pre-installed debugger

```zsh
lldb ./ex4
Current executable set to '/Users/nick/Developer/c/knkc/ch11/ex4' (arm64).
(lldb) breakpoint set --file ex4.c --line 14
Breakpoint 1: where = ex4`swap + 12 at ex4.c:14:15, address = 0x000000010000046c
(lldb) run
Process 69513 launched: '/Users/nick/Developer/c/knkc/ch11/ex4' (arm64)
p = 10, q = 20
Process 69513 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = breakpoint 1.1
    frame #0: 0x000000010000046c ex4`swap(p=0x000000016fdfea6c, q=0x000000016fdfea68) at ex4.c:14:15
   11   #define DEBUG 0
   12
   13   void swap(int *p, int *q) {
-> 14     int temp = *p;
   15     if (DEBUG) {
   16       printf("In swap()\n");
   17       printf("swap(%p, %p)\n", p, q);
Target 0: (ex4) stopped.
(lldb) v
(int *) p = 0x000000016fdfea6c
(int *) q = 0x000000016fdfea68
(int) temp = 1
(lldb) s
Process 69513 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = step in
    frame #0: 0x0000000100000478 ex4`swap(p=0x000000016fdfea6c, q=0x000000016fdfea68) at ex4.c:20:9
   17       printf("swap(%p, %p)\n", p, q);
   18       printf("int temp = %d\n", temp);
   19     }
-> 20     *p = *q;
   21     *q = temp;
   22     if (DEBUG)
   23       printf("q = %p\n", q);
Target 0: (ex4) stopped.
(lldb)
```

# Pointers to Sized Arrays

There is a great [explanation](https://stackoverflow.com/questions/1810083/c-pointers-pointing-to-an-array-of-fixed-size) on Stack Overflow

Fixed-sized arrays are determined at compile time. `clang` and other compilers
can enforce type checking and prevent buffer overruns if the following 
conventions are followed:

```c
void foo(char (*p)[10]);
```

This is actually equivalent to typedef, though less explicit:

```c
typedef int t_myPair[2];

void foo(t_myPair *thisPair){
    /* Equivalent to: void foo(int (*thisPair)[2]) */
}

t_myPair a_pair;
foo(&a_pair);
```

The function definition/argument is the same if the type is an array or a 
struct.

This method is less commonly seen in most code because the syntax looks
trickier, and because not everyone considers passing fixed sized arrays 
as that worthwhile?


For runtime-sizing, the following method:

```
char (*p)[10] = malloc(sizeof(*p));

foo(p);
```
