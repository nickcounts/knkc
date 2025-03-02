#include <stdio.h>
// Write a program to approximate Euler's number to the nth term

int factorial(int n) {
  int sum = 1;
  for (int i = 2; i <= n; i++) {
    sum *= i;
  }
  return sum;
}

int main(void) {
  int n;
  float e = 1.0f;

  printf("Enter the number of terms to use in approximation: ");
  scanf("%d", &n);

  float term;
  for (int i = 1; i < n + 1; i++) {
    term = 1.0f / (float)factorial(i);
    e += term;
  }

  printf("Euler's number e = %f\n", e);

  return 0;
}
