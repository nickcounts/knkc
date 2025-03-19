// Project 7
// The recursive power/exponent function from section 9.6 can be sped up by
// returning squares as a direct multiplication. Odd numbered powers can be
// returned as x * power(x, n-1), which reduces the number of recursions by
// 3

#include <stdio.h>
#include <stdlib.h>

int power(int x, int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0) {
    // n is power of 2: x^n = (x^n/2)^2
    int tmp = power(x, n / 2);
    return tmp * tmp;
  } else {
    // n is odd: x^n = x * x^n-1
    return x * power(x, n - 1);
  }
}

int main(int argc, char *argv[]) {

  for (int i = 0; i < 32; i++) {
    printf("2^%d\t= %8d\n", i, power(2, i));
  }
  return EXIT_SUCCESS;
}
