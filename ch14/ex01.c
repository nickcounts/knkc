/* Chapter 14, Exercise 1
 *
 *
 * Write parameterized macros that compute the following values.
 *   (a) The cube of x.
 *   (b) The remainder when n is divided by 4.
 *   (c) 1 if the product of x and y is less than 100, 0 otherwise.
 * Do your macros always work? If not, describe what arguments would make them
 * fail.
*/

#define cube(x) x*x*x

// #define remainder(n) n%4
#define remainder(n) n-(4*(n/4))

#define REM1 7
#define REM2 -7
#define REM3 4

#define product_lt_100(x,y) (x*y)<100?1:0

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  printf("Cube Macro: ------------------------------------------------\n");
  printf("The value of 2^3 is %d\n", cube(2));

  printf("\nRemainder Macro: -------------------------------------------\n");
  printf("The remainder of %d / 4 = %d\n", REM1, remainder(REM1));
  printf("The remainder of %d / 4 = %d\n", REM2, remainder(REM2));
  printf("The remainder of %d / 4 = %d\n", REM3, remainder(REM3));

  printf("\nProduct Macro: ---------------------------------------------\n");
  printf("product_lt_100(10,10) = %d\n", product_lt_100(10, 10));
  printf("product_lt_100( 9,10) = %d\n", product_lt_100(9, 10));
  printf("product_lt_100(-9,20) = %d\n", product_lt_100(-9, 20));
  printf("product_lt_100( 0, 0) = %d\n", product_lt_100( 0,  0));

  return EXIT_SUCCESS;
}
