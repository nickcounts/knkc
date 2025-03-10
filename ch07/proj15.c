// Write a program that computes the factorial of a user-supplied value
// Calculate it as an int, long, long long, float, double, and long double
//
// See where the various data types overflow. How big can you calculate
// for each?

#include <stdio.h>
#include <stdlib.h>

short s_fact(short n) {
  short result = 1;
  while (n > 0) {
    result *= n;
    n--;
  }
  return result;
}

long l_fact(long n) {
  long result = 1;
  while (n > 0) {
    result *= n;
    n--;
  }
  return result;
}

int i_fact(int n) {
  int result = 1;
  while (n > 0) {
    result *= n;
    n--;
  }
  return result;
}

long long ll_fact(long long n) {
  long long result = 1;
  while (n > 0) {
    result *= n;
    n--;
  }
  return result;
}

float f_fact(float n) {
  float result = 1;
  while (n > 0) {
    result *= n;
    n--;
  }
  return result;
}

double d_fact(double n) {
  double result = 1;
  while (n > 0) {
    result *= n;
    n--;
  }
  return result;
}

long double lf_fact(long double n) {
  long double result = 1;
  while (n > 0) {
    result *= n;
    n--;
  }
  return result;
}

int main(int argc, char *argv[]) {
  unsigned int n;
  printf("Enter a positive integer: ");
  scanf("%ud", &n);

  printf("a)  %d! as a short =       %d\n", n, s_fact(n));
  printf("b)  %d! as a int =         %d\n", n, i_fact(n));
  printf("c)  %d! as a long =        %ld\n", n, l_fact(n));
  printf("d)  %d! as a long long =   %lld\n", n, ll_fact((long long)n));
  printf("e)  %d! as a float =       %f\n", n, f_fact((float)n));
  printf("f)  %d! as a double =      %f\n", n, d_fact((double)n));
  printf("g)  %d! as a long double = %Lf\n", n, lf_fact((long double)n));

  return EXIT_SUCCESS;
}
