/* Chapter 15, Exercise 4
 *
 *
 * Assume that `debug.h` is a header file with the following contents:
 *
 * ```c 
  
   #ifdef DEBUG
   #define PRINT_DEBUG(n) printf("Value of " #n ": %d\n", n)
   #else
   #define PRINT_DEBUG(n)
   #endif
  
 * ```
 *
 * Let `testdebug.c` be the following source file:
 *
 * ```c
  
   #include <stdio.h>
  
   #define DEBUG
   #include "debug.h"
  
   int main(void) {
      int i = 1, j = 2, k = 3;
  
   #ifdef DEBUG
      printf("Output if DEBUG is defined:\n");
   #else
      printf("Output if DEBUG is not defined:\n");
   #endif
  
      PRINT_DEBUG(i);
      PRINT_DEBUG(j);
      PRINT_DEBUG(k);
      PRINT_DEBUG(i + k);
      PRINT_DEBUG(2 * i + j - k);
  
      return 0;
   }
  
 * ```
 *
 *
 * a) What is the output when the program is executed?
 * b) What is the output if the #define directive is removed from `testdebug.c`
 * c) Explain why the output is different in parts (a) and (b)
 * d) Is it necessary for the DEBUG macro to be defined BEFORE debug.h is 
 *    included in order for PRINT_DEBUG to have the desired effect? Justify 
 *    your answer
 *
 */


/*  Answers:
 *
 *  a) The output when the program is executed will be:
 *
 *  Output if DEBUG is defined:
 *  Value of i :1
 *  Value of j :2
 *  Value of k :3
 *  Value of i + k :4
 *  Value of 2 * i + j - k :1
 *
 *  I don't think there will be issues with the numerical values but DEBUG.h
 *  may need some more parenthesis to guard against more complex expressions
 *
 *  VERIFIED correct by running the code
 *
 *
 *
 *
 *  b) What is the output if the #define directive is removed from `testdebug.c`
 *
 *  Output if DEBUG is not defined:
 *
 *  VERIFIED correct by running the code
 *
 *
 *
 * c) Explain why the output is different in parts (a) and (b)
 *
 * With the #define directive removed, `debug.h` creates an empty macro 
 * for PRINT_DEBUG(). Those statements become blank and nothing executes.
 *
 * With it defined, PRINT_DEBUG inserts the printf() statements
 *
 *
 *
 * d) Is it necessary for the DEBUG macro to be defined BEFORE debug.h is 
 *    included in order for PRINT_DEBUG to have the desired effect? Justify 
 *    your answer
 *
 * I think the preprocessor does a few passes, looking for defines first
 * and then circling back for the contents of the #include files, so I 
 * would expect it to work in either order.
 *
 *
 * I appear to have been incorrect! Testing shows that debug.h was pulled
 * in before the #define and it came in empty. That's a trap for new
 * players!
 *
 */



