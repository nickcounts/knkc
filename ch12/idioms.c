#include <stdio.h>
#include <stdlib.h>

void sec_12_1(void) {
  // Pointers and Arrays
  printf("12.1: Pointer Arithmetic\n----------------------------\n");

  int a[10], *p, *q, i;

  // We can make p point to a[0] by writing:
  p = &a[0];

  // p [ ]
  //    v
  // a [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
  //    0  1  2  3  4  5  6  7  8  9

  // We can now access a[0] throught p. For example, we can store `5` in
  // a[0] by
  *p = 5;

  // p [ ]
  //    v
  // a [5][ ][ ][ ][ ][ ][ ][ ][ ][ ]
  //    0  1  2  3  4  5  6  7  8  9

  // C supports three (and only three) forms of pointer arithmetic:
  //    - Adding an integer to a pointer
  //    - Subtracting an integer from a pointer
  //    - Subtracting one pointer from another
  //
  // our examples assume that the following dexlarations are in effect:
  //
  printf("These examples assume the following declarations:\n");
  printf("int a[10], *p, *q, i;\n\n");

  printf("Adding an integer to a pointer\n");
  p = &a[2];

  //       p [ ]
  //          v
  // a [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
  //    0  1  2  3  4  5  6  7  8  9

  q = p + 3;

  //       p [ ]    q [ ]
  //          v        v
  // a [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
  //    0  1  2  3  4  5  6  7  8  9

  p += 6;

  //                q [ ]    p [ ]
  //                   v        v
  // a [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
  //    0  1  2  3  4  5  6  7  8  9
}

int main(int argc, char *argv[]) {
  printf("Chapter 12: Pointers and Arrays\n----------------------------\n\n");
  sec_12_1();

  return EXIT_SUCCESS;
}
