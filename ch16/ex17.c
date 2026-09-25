/* Chapter 16, Exercise 17
 *
 * Suppose that `b` and `i` are declared as follows:
 *
 *   enum { FALSE, TRUE } b;
 *   int i;
 *
 * Which of the following statements are legal? Which ones are
 * "safe" (always yield a meaningful result)?
 *
 *
 * a) b = FALSE;
 *
 * b) b = i;
 *
 * c) b++;
 *
 * d) i = b;
 *
 * e) i = 2 * b + 1;
 *
 */

#include <stdio.h>
#include "colors.h"

enum { FALSE, TRUE } b;
int i;

void answer(char part, char *question, int value){
  printf(MAGENTA "Part <" LIGHT_GREEN "%c" MAGENTA "> :" RESET "\n", part);
  printf(CYAN "  %s" RESET, question);
  printf(" : " LIGHT_YELLOW "%d" RESET "\n", value);
}


int main(void){
  // a) 
  b = FALSE; // This is valid and behaves consistently
  answer('A', "b = FALSE", b);

  // b)
  b = i; // This is allowed, but behaves inconsistently based on
         // the uninitialized values of `i`
  answer('B', "b = i", b);

  // c)
  b++;   // This is allowed, but it is not guaranteed to behave 
         // well. You can easily create an enum value for which there 
         // is no matching member.
  answer('C', "b++", b);

  // d)
  i = b; // This is allowed and consistent behavior. `i` will always take 
         // the integer value of the enum member. If b is not initilaied, 
         // this is squirrely 
  answer('D', "i = b", i);

  // e)
  i = 2 * b + 1; // This is allowed and consistent. I don't know why you 
                 // would do this, symantically speaking.
  answer('E', "i = 2 * b + 1", i);

  return 0;
}

// Answer from KNKing:
//
// All the statements are legal, since C allows integers and enumeration values
// to be mixed without restriction. Only (a), (d), and (e) are safe. (b) is not
// meaningful if i has a value other than 0 or 1. (c) will not yield a
// meaningful result if b has the value 1.
