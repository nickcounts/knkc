/* Chapter 14, Exercise 9

   Write the following macros:

   A) 
     CHECK(x,y,n) has value 1 if both x and y fall between 0 and n-1 inclusive

   B)
     MEDIAN(x,y,z) finds the median of x, y, and z

   C)
     POLYNOMIAL(x) computes the polynomial 3x^5 + 2x^4 - 5X^3 - x^2 + 7x - 6
 */

#define CHECK(x,y,n) ((0 <= (x)) && ((x) < (n)-1)) && ((0 <= (y)) && ((y) <= (n)-1)) ? 1 : 0

#define MEDIAN(x,y,z)                      \
   (((x) <= (y)) && ((y) <= (z))) ? (y) :  \
   (((y) <= (z)) && ((z) <= (x))) ? (z) :  \
   (x)                                     \
   
#define POLYNOMIAL(x) (3*(x)*(x)*(x)*(x)*(x)+ 2*(x)*(x)*(x)*(x) - 5*(x)*(x)*(x) - (x)*(x) + 7*(x) - 6)


#include <stdio.h>

int main(int argc, char **argv){

  printf("Part A)\n");

  int x,y,z,n;
  x = -1;
  y = 1;
  n = 5;
  printf("CHECK(-1,1,5) should return 0: %d\n", CHECK(x, y, n));

  x = 1;
  y = 1;
  n = 5;
  printf("CHECK( 1,1,5) should return 1: %d\n", CHECK(x, y, n));

  x = 1;
  y = 1;
  n = 5;
  printf("CHECK( 3,1,5) should return 1: %d\n", CHECK(x+2*y, y, n));


  printf("\n\nPart B)\n");

  x = 1;
  y = 2;
  z = 3;
  printf("MEDIAN(1,2,3) should return 2: %d\n", MEDIAN(x, y, z));

  x = 1;
  y = 1;
  z = 3;
  printf("MEDIAN(1,1,3) should return 1: %d\n", MEDIAN(x, y, z));

  x = 5;
  y = 1;
  z = 3;
  printf("MEDIAN(5,1,3) should return 3: %d\n", MEDIAN(x, y, z));
  
  x = 1;
  y = 1;
  z = 1;
  printf("MEDIAN(1,1,1) should return 1: %d\n", MEDIAN(x, y, z));


  printf("\n\nPart C)\n");

  x = 1;
  printf("POLYNOMIAL(1) should return 0: %d\n", POLYNOMIAL(x));

  x = 2;
  printf("POLYNOMIAL(2) should return 0: %d\n", POLYNOMIAL(4*3/2/3));

  return 0;
}

