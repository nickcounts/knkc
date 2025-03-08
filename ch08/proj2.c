// Modify the repdigit.c program so that it displays a table showing
// how many times each digit appears in the number
//
// Check numbers for repeated digits
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int digit_seen[10] = {0};
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

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
  printf("\n");

  return EXIT_SUCCESS;
}
