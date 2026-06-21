/* Chapter 14, Exercise 11

   C programmers often use the `fprintf` function to write error messages:

      fprintf(stderr, "Range error: index = %d\n", index);

    `stderr` is C's "standard error" stream. Write a macro named ERROR that generates the above call of `fprintf` when given a format strintg and the items to be displayed:

      ERROR("Range error: index = %d\n", index);

 */

#include <stdio.h>

#define ERROR(fmt,...) fprintf(stderr, fmt, __VA_ARGS__)

int main(int argc, char **argv) {

  ERROR("Range error: index = %d\n", 3);

  return 0;
}

