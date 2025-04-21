// If i is a variable and p points to i, which of the following
// expressions are aliases for i?
//

#include <stdio.h>
#include <stdlib.h>

int i, *p;

int main(int argc, char *argv[]) {
  i = 5;
  p = &i;

  printf("int i = 5;\nint *p = &i\n");

  printf("Find valid expressions that are aliases for i\n");

  printf("a) *p  is   VALID\t *p = %d\n", *p);
  printf("b) &p  is INVALID\t &p = %d\n", &p);  // is the address OF the pointer
  printf("c) *&p is INVALID\t*&p = %d\n", *&p); // is the address of i
  printf("d) &*p is INVALID\t&*p = %d\n", &*p); // the address of i
  printf("e)  *i is INVALID\t *i = ???\n");     // the value at address 5
  printf("f)  &i is INVALID\t &i = %d\n", &i);  // the address of i
  printf("g) *&i is   VALID\t*&i = %d\n", *&i); // is the value of i !!!
  printf("h) &*i is INVALID\t&*i = ???\n");     // a memory address of that = 5

  return EXIT_SUCCESS;
}
