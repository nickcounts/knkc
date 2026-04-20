/* Chapter 14, Exercise 4

   For each of the following macros, give an example that illustrates a problem
   with the macro and show how to fix it. 

   (a) #define AVG (x, y) • (x+y) /2 
   (b) #define AREA (x,y) (x) *(y)

 */


#define AVG(x,y) (x+y)/2
#define AREA(x,y) (x)*(y)

#define FIX_AVG(x,y) ( ((x)+(y)) / 2 )

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  printf("a) AVG(x,y) Macro:\n");
  printf("----------------------------------------------------------------\n");
  printf("AVG(x,y) doesn't keep the x and y arguments properly segregated,\n");
  printf("so the return value can get calculated badly if either argument\n");
  printf("is an expression: \n");
  // (a+b)/2+1 
  printf("   AVG(3, 6/3+1) = (3+6/3+1)/2 = (3+2+1)/2 5/2 = 1\n");
  printf("   AVG(13, 15)/2 = %d\n",     AVG(13,15)/2);
  printf("Fix by surrounding arguments and the expression in ()\n");
  printf("   AVG(3, 6/3+1) = %d\n", FIX_AVG(3, 6/3+1));

  // I don't understand what's wrong with these macros... they seem fine  




  return EXIT_SUCCESS;
}
