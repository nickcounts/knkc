/* Chapter 14, Exercise 6

   A) Write a macro DISP(f,x) that expands into a call of printf that
   displays the value of the function `f` when called with argument `x` 
   For example:

   DISP(sqrt, 3.0);

   should expand into

   printf("sqrt(%g) = %g\n", 3.0, sqrt(3.0));

   B) Write a macro DISP2(f,x,y) that's similar to DISP but works for
      functions with two arguments

   NOTE: use `clang -E ex06.c` to view the result of the preprocessor 
 */

#define DISP(f,x) printf(#f "(%g) = %g\n", (x), (f(x)))
#define DISP2(f,x,y) printf(#f "(%g,%g) = %g\n", (x),(y), (f(x,y)))

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){

  // The intention:
  printf("sqrt(%g) = %g\n", 3.0, sqrt(3.0));

  DISP(sqrt, 3.0);
  DISP2(atan2f, 3.9, 4.5);

  return EXIT_SUCCESS;
}

