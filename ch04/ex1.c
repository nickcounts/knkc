#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i, j;

  i = 5;
  j = 3;
  printf("%d %d\n", i / j, i % j);

  i = 2;
  j = 3;
  printf("%d\n", (i + 10) % j);

  i = 7;
  j = 8;
  int k = 9;
  printf("%d\n", (i + 10) % k / j);

  return EXIT_SUCCESS;
}
