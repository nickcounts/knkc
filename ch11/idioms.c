#include <stdio.h>
#include <stdlib.h>

void sec_11_2(void) {
  // Address and Indirection Operators
  printf("Pointer Operators\n--------------------\n");

  int *p; // points to nowhere in particular
  int i;

  // The Address Operator
  // ----------------------------------
  //
  // & is the address operator
  p = &i; // p now points to i

  // We can also initialize a pointer at declaration:
  int n;
  int *pn = &n;

  // The Indirection Operator
  // ----------------------------------
  //
  // * is the indirection operator. Once a pointer variable
  // points to an object, we use `*` to access what's stored
  // in that object. If `p` points to `i`, then `p*` gives
  // the value of `i`
  printf("The value of `i` is being accessed by `*p` and it is: %d\n", *p);

  // Note, that printed the value of `i`, not the address of `i`

  // As long as `p` points to `i`, `*p` is an alias to `i` - we can even
  // do assignment:
  *p = 2;

  printf(" i = %d\n", i);  // prints 2
  printf("*p = %d\n", *p); // prints 2

  // WARNING!!!
  // -----------------------------------
  //
  // Never assign a value to a pointer that is uninitialized (not
  // pointing at a real variable/object)
  //
  // If you do, you have no idea where that value is being assigned,
  // and it could really screw stuff up

  /* DO NOT DO THIS!!!
   *   int *bp;
   *   bp = 1;
   */
}

void sec_11_3(void) {
  // Pointer Assignment
  printf("\nPointer Assignment\n--------------------\n");

  int i, j, *p, *q;

  p = &i; // This is standard pointer assignment

  q = p; // This is also pointer assignment. It's like a copy
         // now pointer `q` points to the same address as pointer `p`

  i = 3;
  printf("\ni = 3; *p = &i; q = p\n");
  printf("Both p and q now point to i\n");
  printf("*p = %d\n", *p); // prints 2
  printf("*q = %d\n", *q); // prints 2

  *p = 1;
  *q = 2;
  printf("\n*p = 1; *q = 2\n");
  printf("*p = %d\n", *p); // prints 2
  printf("*q = %d\n", *q); // prints 2

  p = &i;
  q = &j;
  i = 1;
  printf("\np = &i; q = &j; i = 1;\n");
  printf("j was never assigned, so p is pointing to something random\n");
  printf("*p = %d\n", *p); // prints 1
  printf("*q = %d\n", *q); // prints random garbage

  // so far, `j` was uninitialized, so there was just random data in memory
  // being interpreted as an `int`
  *q = *p; // the value of the obj q points to (j) == the value of the obj
           // that q points to (i)
  printf("\n*q = *p;\n");
  printf("This assigns a value to `j` through the pointer, initializing it\n");
  printf("*p = %d\n", *p); // prints 1
  printf("*q = %d\n", *q); // prints 1
}

int main(int argc, char *argv[]) {
  sec_11_2();
  sec_11_3();
  return EXIT_SUCCESS;
}
