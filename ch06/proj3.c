#include <stdio.h>

// Write a program that asks the user to enter a fraction, then reduces the
// fraction to lowest terms

int gcd(int a, int b) {
  // return the greatest common divisor of any two integers
  // this is a functionalized version of proj2.c
  int temp, r;

  do {
    // Keep a as the larger number
    if (a < b) {
      temp = a;
      a = b;
      b = temp;
    }

    r = a % b;

    if (r == 0 || b == 0) {
      break;
    }

    if (r) {
      a = b;
      b = r;
    }

  } while (1);

  return b;
}

int main(void) {
  int num, den, divisor;
  printf("Enter a fraction: ");
  scanf("%d/%d", &num, &den);

  divisor = gcd(num, den);

  printf("In lowest terms: %d/%d\n", num / divisor, den / divisor);
  return 0;
}
