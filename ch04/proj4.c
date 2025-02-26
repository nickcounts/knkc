#include <stdio.h>
#include <stdlib.h>

#define MIN_VAL 0
#define MAX_VAL 32767

int main(void) {

  printf("Enter a number between %d and %d: ", MIN_VAL, MAX_VAL);
  int number;
  scanf("%d", &number);

  if ((MIN_VAL > number) | (number > MAX_VAL)) {
    printf("The number was outside the allowable range\n");
    return EXIT_FAILURE;
  }

  printf("Your number, in oclal, is: 0o%o\n", number);

  return EXIT_SUCCESS;
}
