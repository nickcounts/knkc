/* Chapter 14, Exercise 3
 
   Let DOUBLE be the following macro:
       `#define DOUBLE (x) 2*x`

  (a) What is the value of DOUBLE (1+2)?
  (b) What is the value of 4/DOUBLE (2)?
  (c) Fix the definition of DOUBLE.

 */


#define DOUBLE(x) 2*x
#define FIXED_DOUBLE(x) (2*(x))

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  
  printf("a) DOUBLE(1+2) = 2*1+2 = 4 : Result = %d\n", DOUBLE(1+2));
  printf("b) 4/DOUBLE(2) = 4/2*2 = 4 : Result = %d\n", 4/DOUBLE(2));
  printf("c) FIXED_DOUBLE(1+2) = 2*(1+2) = 6 : Result = %d\n", FIXED_DOUBLE(1+2));
  printf("c) 4/FIXED_DOUBLE(2) = 4/(2*(2)) = 1 : Result = %d\n", 4/FIXED_DOUBLE(2));

  return EXIT_SUCCESS;
}


