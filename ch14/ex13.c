/* Chapter 14, Exercise 13

   A) Show what the follwoing program will look like after preprocessing. You
   may ignore any lines added to the program as a result of including the
   <stdio.h> header.

      #include <stdio.h>

      #define N 100
      void f(void);

      int main(void) {
         f();
      #ifdef N
      #undef N
      #endif 
         return 0;
      }


   B) What will be the output of this program?

   NOTE: use `clang -E ex06.c` to view the result of the preprocessor
 */



#include <stdio.h>

#define N 100

void f(void);

int main(void) {
  f();
#ifdef N
#undef N
#endif 
  return 0;
}


void f(void) {
#ifdef N
  printf("N is defined: %d\n", N);
#endif
#ifndef N
  printf("N is not defined\n");
#endif
}







