#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Example of C89 implementation-specific behavior. Integer division\n");
  printf("of a negative number with a remainder is hardware dependant.\n\n");

  int top, bot;
  top = -9;
  bot = 7;

  printf("Result of %d / %d = %d\n", top, bot, top / bot);

  return EXIT_SUCCESS;
}
