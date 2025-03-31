#include <stdio.h>
#include <stdlib.h>

// The following program outline shows only function definitions and variable
// declarations:
int a;

void f(int b) { int c; }

void g(void) {
  int d;
  { int e; }
}

int main(void) {
  int f;
  return EXIT_SUCCESS;
}

/* Questions
 *
 * For each of the following scopes, list all variable and parameter
 * names visible in that scope:
 *
 * a) the `f` function
 *    a - global
 *    b - parameter
 *    c - defined in the scope
 *
 * b) the `g()` function
 *    a - global
 *    d - defined in the scope
 *    e - only available in the braces in `g`
 *
 * c) the block in which e is declared
 *    a, d, e
 *
 * d) the `main` function
 *  a - global
 *  f - defined in `main`
 *
 * */
