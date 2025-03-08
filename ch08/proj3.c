// MOdify repdigit.c so the user can enter more than one number
// to be tested for repeated digits. THe program should terminate
// when the user enters a number that is less than or = to 0
//
// Check numbers for repeated digits
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int digit_seen[10] = {0};
  int digit;
  long number, n;

  printf("0 or negative number to terminate\n");

  printf("Enter a number: ");
  scanf("%ld", &number);

  while (number > 0) {
    n = number;
    // count each digit and add to hashmap
    while (n > 0) {
      digit = n % 10; // gets "ones place"
      digit_seen[digit] += 1;
      n /= 10;
    }

    printf("Digit:        ");
    for (digit = 0; digit < 10; digit++) {
      printf("%3d", digit);
    }
    printf("\n");

    printf("Occurrences:  ");
    for (digit = 0; digit < 10; digit++) {
      printf("%3d", digit_seen[digit]);
    }
    printf("\n\n");

    // Reset digit_seen !!!
    for (digit = 0; digit < 10; digit++)
      digit_seen[digit] = 0;

    printf("Enter a number: ");
    scanf("%ld", &number);
  }

  return EXIT_SUCCESS;
}
