/* Chapter 14, Exercise 2

   Write a macro `NELEMS (a)` that computes the number of elements in a
   one-dimensional array a.

   Hint: See the discussion of the `sizeof` operator in Section 8.1.

 */

#define NELEMS(a) (int)(sizeof(a)/sizeof(a[0]))

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int x[123];
  printf("Array `x` has %d elements\n", NELEMS(x));

  return EXIT_SUCCESS;
}
