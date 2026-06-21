/* Chapter 14, Exercise 12

   Suppose that the macro `M` has been defined as follows:

#define M 10

   Which of the following tests will fail?

      a) #if M
      b) #ifdef M
      c) #ifndef M
      d) #if defined(M)
      e) #if !defined(M)

 */

#define M 10

#include <stdio.h>

int main(int argc, char **argv) {

#if M
  printf("#if M works\n");
#endif
    
#ifdef M
  printf("#ifdef M works\n");
#endif

  printf("#ifndef will fail, M is defined\n");
#ifndef M
  printf("#ifndef M works\n");
#endif

#if defined (M)
  printf("#if defined M works\n");
#endif

  printf("#if !defined(m) will fail, M is defined\n");
#if !defined (M)
  printf("#if !defined(M) works\n");
#endif


  return 0;
}
