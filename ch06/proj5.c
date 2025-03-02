#include <limits.h>
#include <stdio.h>
// Write a program that accepts an integer from the user and prints it
// reversed. Unlike chapter 4, this program should accept an integer with
// more than 2 digits!

int main(void) {
  unsigned int number, remainder;
  number = 0;
  printf("Ensure number is smaller than %u\n", UINT_MAX);
  printf("Enter an integer to be reversed: ");
  scanf("%d", &number);

  do {
    remainder = number % 10;
    printf("%u", remainder);
    if (number < 10) {
      break;
    }
    number /= 10;
  } while (1);

  printf("\n");
  return 0;
}
