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


