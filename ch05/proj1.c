#include <stdio.h>

int number;

int main(void) {
  printf("Enter a number: ");
  scanf("%d", &number);

  int digits = 0;
  int remaining = number;

  if (number == 0)
    digits += 1;

  while (remaining) {
    digits += 1;
    remaining = remaining / 10;
  }

  printf("%d has %d digits.\n", number, digits);

  return 0;
}
