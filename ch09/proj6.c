// Proj 6
// Write a function that computes the value of the following
// polynomial:
//    3x^5 + 2x^4 - 5x^3 - x^2 +7x - 6
//
// Write a program that asks the user to enter a value for x, calls
// the function to compute the value of the polynomial, then displays
// the value returned by the function.

#include <stdio.h>
#include <stdlib.h>

double power(double base, int exponent) {
  if (exponent == 0)
    return 1;
  else
    return base * power(base, exponent - 1);
}

double compute_polynomial(double x) {
  double y = 0;
  y += 3 * power(x, 5);
  y += 2 * power(x, 4);
  y -= 5 * power(x, 3);
  y -= x * power(x, 2);
  y += 7 * power(x, 1);
  y -= 6;
  return y;
}

int main(int argc, char *argv[]) {
  double user_x;
  printf("Enter a value of x to evaluate 3x^5 + 2x^4 - 5x^3 - x^2 +7x - 6: ");
  scanf("%lf", &user_x);
  printf("The answer is: %lf\n", compute_polynomial(user_x));

  return EXIT_SUCCESS;
}
