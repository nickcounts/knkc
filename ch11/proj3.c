// Modify project 3 from chapter 6 so that it includes the following
// function:
void reduce(int numerator, int denominator, int *reduced_num, int *reduced_den);

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

void reduce(int numerator, int denominator, int *reduced_num,
            int *reduced_den) {
  int divisor = gcd(numerator, denominator);
  *reduced_num = numerator / divisor;
  *reduced_den = denominator / divisor;
}

int main(void) {
  int num, den, lcn, lcd;
  printf("Enter a fraction: ");
  scanf("%d/%d", &num, &den);

  reduce(num, den, &lcn, &lcd);

  printf("In lowest terms: %d/%d\n", lcn, lcd);
  return 0;
}
