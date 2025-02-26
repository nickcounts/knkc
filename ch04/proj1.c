#include <stdio.h>
#include <stdlib.h>

void inject_immaturity(int first, int second);

int main(void) {

  int first, second = 0;
  printf("Enter a 2-digit integer to be re-displayed backwards: ");
  scanf("%1d%1d", &first, &second);

  inject_immaturity(first, second);

  printf("Your 2-digit integer, when reversed, is displayed as: %d%d\n", second,
         first);

  return EXIT_SUCCESS;
}

void inject_immaturity(int first, int second) {
  // I hope my grader has a sense of humor...
  // Or I'm in real trouble!

  if ((first == 6 & second == 9) || (first == 9 & second == 6)) {
    printf("Niiiiiiiiice\n");
  }
}
