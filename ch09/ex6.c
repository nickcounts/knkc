// Ex 6
// Write a function digit(n, k) that returns the kth digit (from the right)
// in n, which is a positive integer. digit(829, 1) returns 9.
// If k is greater than the number of digits, return 0;

#include <stdio.h>
#include <stdlib.h>

// Using num_digits from ex5
int num_digits(int n) {
  int d = 1;
  while (n /= 10) {
    d++;
  }
  return d;
}

int digit(int n, int k) {
  int digits, i;

  // Ensure valid request
  digits = num_digits(n);
  if (k > digits)
    return 0;

  i = 1;
  while (i < k) {
    n /= 10;
    i++;
  }

  // Now we have the target in the ones place. Return ones using modulo
  return n % 10;
}

int main(int argc, char *argv[]) {
  printf("digit(54321, 3) = %d\n", digit(54321, 3));
  return EXIT_SUCCESS;
}
