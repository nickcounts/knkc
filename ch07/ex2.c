#include <stdio.h>

int a = 010E2; // undefined? ^0 should be octal, but E means float
int aa = 010;
float b = 32.1E+5;
// int c = 0790;      // 0 prefix indicates octal, contains invalid digit (9)
// int d = 100_000;   // underscore not valid (works in Python)
float e = 3.978e-2;

int main(void) {
  printf("Printing valid constant definitions.\n");
  printf("a = 010E2    \t%d\n", a);
  printf("a = 010      \t%d\n", aa);
  printf("b = 32.1E+5  \t%f\n", b);
  printf("e = 3.978e-2 \t%f\n", e);

  return 0;
}
