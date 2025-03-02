#include <stdio.h>

// Write a program that asks the user to enter two integers, then calculates
// and displays their greatest common divisor

int main(void) {
  int temp, a, b, r;
  printf("Enter two inegers: ");
  scanf("%d %d", &a, &b);

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

  printf("The Greatest Common Divisor is %d\n", b);
  return 0;
}
