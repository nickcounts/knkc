// Modify the repdigit.c program so that it shows which digits (if any)
// were repeated
//
// Check numbers for repeated digits
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  bool digit_seen[10] = {false};
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  printf("Repeated digit(s): ");
  while (n > 0) {
    digit = n % 10; // gets "ones place"
    if (digit_seen[digit])
      printf("%2d", digit);
    digit_seen[digit] = true;
    n /= 10;
  }

  printf("\n");

  return EXIT_SUCCESS;
}
