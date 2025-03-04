#include <stdio.h>

char c = 'a';
int i = 5;

int main(void) {
  i += c;        // valid math
  c = 2 * c - 1; // valid math
  putchar(c);
  // printf(c);  // invalid printf statement (missing fmtstr)

  return 0;
}
