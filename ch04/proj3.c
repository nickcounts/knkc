#include <stdio.h>
#include <stdlib.h>

void inject_immaturity(int first, int second);

int main(void) {

  int first, second, third = 0;
  printf("Enter a 3-digit integer to be re-displayed backwards: ");
  scanf("%1d%1d%d", &first, &second, &third);

  inject_immaturity(first, second);
  inject_immaturity(third, second);

  printf("Your 3-digit integer, when reversed, is displayed as: %d%d%d\n",
         third, second, first);

  return EXIT_SUCCESS;
}

void inject_immaturity(int first, int second) {
  // I hope my grader has a sense of humor...
  // Or I'm in real trouble!

  if ((first == 6 & second == 9) || (first == 9 & second == 6)) {
    printf("Niiiiiiiiice\n");
  }
}
