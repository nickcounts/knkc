#include <stdio.h>
#include <stdlib.h>

int main(void) {

  float x = 839.21f;

  printf("|%-8.1f|%10.6e|%-8.3f|%6.0f|\n", x, x, x, x);

  return EXIT_SUCCESS;
}
