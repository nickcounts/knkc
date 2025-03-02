#include <stdio.h>

// write a program that finds the largest in a series of numbers entered by
// the user. THe program must promp the user to enter numbers one by one.
// When the user enters - or a negative number, the program must display
// the largest non-negative number entered.

int main(void) {
  float input = 0, largest;

  do {
    printf("Enter a number: ");
    scanf("%f", &input);

    if (input <= 0) {
      break;
    }

    largest = (input > largest) ? input : largest;

  } while (1);

  printf("The largest number entered was %f\n", largest);

  return 0;
}
