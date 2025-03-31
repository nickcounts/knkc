
#include <stdio.h>
#include <stdlib.h>

// The following program outluine shows only function
// definitions and variable declarations:
// int b, c;
int b = 1;
int c = 2;

void f(void) {
  int b, d;
  // printf("in f(): b=%d, d=%d\n", b, d);
}

void g(int a) {
  int c;
  { int a, d; }
}

int main(void) {
  int c, d;
  f();
  return EXIT_SUCCESS;
}

// FOr each of the following scopes, list all variable and
// parameter names visible in that scope. If there's more
// than one variable or param with the same name, indicate
// which one is visible.
//
// a) the `f()` function:
//    c - global variable
//    b - b initialized in the function takes precedence
//    over global b
//
// b) the `g()` function:
//    a - function parameter
//    b - global
//    c - local variable clobbers global
//
//  c) the block in which a and d are declared:
//    a - from {} block
//    b - global
//    c - local to function
//    d from {} block
//
// d) the `main()` function:
//    b - global
//    c - local
//    d - local
