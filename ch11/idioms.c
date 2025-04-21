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

void decompose(double x, long *int_part, double *frac_part) {
  // we are passed pointers, and we use them with standard indirection
  *int_part = (long)x;
  *frac_part = x - *int_part;
}

void sec_11_4(void) {
  // Pointers as Arguments
  printf("\nPointers as Arguments\n--------------------\n");

  // C passes arguments by value. If you need a function to modify a variable
  // outside the function (Functional bros will NOT be happy about this) then
  // you can pass a pointer to the variable as an argument.

  long int_part;
  double frac_part;
  decompose(3.1592935, &int_part, &frac_part);
  printf("\nThe integer part is: %ld\n", int_part);
  printf("The decimal part is: %f\n", frac_part);

  // See the maxmin.c example

  // Using Const to protect arguments:
  //
  // If we pass a pointer as an argument to a function, we normally
  // expect the function will modify the variable. If we see:
  //
  // f(&x);
  //
  // we'd expect `f()` to change the value of `x`
  //
  // We can use the word `const` to document that a function won't change
  // an object whose address is passed to the funtion. `const` goes in the
  // parameter's declaration, just before the type specification:
  //
  // void f(const int *p) {
  //   *p = 0; // WRONG!!! Should produce compiler error?
  // }
}

int *max(int *a, int *b) {
  // Returns a pointer to the larger dereferenced integer
  if (*a > *b)
    return a;
  else
    return b;
}

int *find_middle_element(int a[], int n) {
  // Returns a pointer to the middle element of the n-element array a[]
  return &a[n / 2];
}

void sec_11_5(void) {
  // Pointers as Return Values
  printf("\nPointers as return Values\n--------------------\n");

  // We can return a pointer from a function - more on this in ch13
  //
  /* Example Program
   * -------------------------------
      int *max(int *a, int *b) {
        if (*a > *b)
          return a;
        else
          return b;
      }
  * -------------------------------- */

  // Invoke as follows:
  int *p, i, j;
  i = 5;
  j = -3;
  p = max(&i, &j);

  printf("Set two integer values: i=%d and j=%d\n", i, j);
  printf("Called p = max(&i, &j);\n");
  printf("p = %p and *p = %d\n", (void *)p, *p);

  // DANGER!!!
  //
  // Never return a pointer to an automatic local variable:
  /* Example of a bad function:
  * ------------------------------
      int *f(void) {
        int auto_local;
        return &auto_local;
      }
  * ------------------------------ */

  // the auto_local variable doesn't exist when the function returns,
  // so you end up with a pointer to invalid memory (it's been freed)

  // Pointers are useful with arrays, too. This is covered in chapter 12
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *me = find_middle_element(a, 10);
  printf("\nPointers and arrays:\n");
  printf("a[10] = {1,2,3,4,5,6,7,8,9,10}\n");
  printf("&a = %p, me = %p and *me = %d\n", &a, me, *me);

  // Note: The "find middle" doesn't actually do that good a job. Maybe it's
  // the zero-based index
}

int main(int argc, char *argv[]) {
  sec_11_2();
  sec_11_3();
  sec_11_4();
  sec_11_5();
  return EXIT_SUCCESS;
}
