/* Chapter 14, Exercise 7

   Let GENERIC_MAX be the following macro:

      #define GENERIC_MAX(type)       \
      type type##_max(type x, type y) \
      {                               \
        return x > y ? x : y;         \
      }                               \

   A) Show the preprocessor's expansion of GENERIC_MAX(long)
   B) Explain why GENERIC_MAX doesn't work for basic types such as 
      unsigned long
   C) Describe a technique that would allow us to use GENERIC_MAX 
      with basic types such as unsigned long (Hint: Don't change 
      the definition of GENERIC_MAX)

   NOTE: use `clang -E ex06.c` to view the result of the preprocessor
 */

#include <stdlib.h>
#include <stdio.h>

#define DISP2(f,x,y) printf(#f "(%ld,%ld) = %ld\n", (x),(y), (f(x,y)))

#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
  return x > y ? x : y;         \
}                               \

typedef unsigned long ulong ;
GENERIC_MAX(long)
GENERIC_MAX(ulong)

int main(int argc, char **argv){
  printf("A) Use the basic GENERIC_MAX(long) macro to create long long_max(a,b)\n");
  DISP2(long_max,40l,1l);
  printf("%ld\n", long_max(40l,1l));

  /* B) 
   *
   * Generic types are challenging because of the whitespace character
   * maybe you could do one of the multi-variable expansions and concat
   * with underscores so it would become unsigned_long_max()
   */

  /* C)
   *
   * We can also typedef the generics so they are a single token:
   */

  ulong x = 303;
  ulong y = 202;

  DISP2(ulong_max, x, y);

  return EXIT_SUCCESS;
}
