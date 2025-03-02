#include <stdio.h>
// Write a program to approximate Euler's number to the nth term
// Modify program so it continues to calculate until the term is
// less than a user specified epsilon value

int factorial(int n) {
  int sum = 1;
  for (int i = 2; i <= n; i++) {
    sum *= i;
  }
  return sum;
}

int main(void) {
  float epsilon;
  float e = 1.0f;

  printf("Enter the minimum term size to use in approximation: ");
  scanf("%f", &epsilon);

  float term = 1.0f;
  int i = 1;
  while (term > epsilon) {
    term = 1.0f / (float)factorial(i);
    e += term;
    i++;
  }

  printf("Euler's number e = %f\n", e);

  return 0;
}
