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
