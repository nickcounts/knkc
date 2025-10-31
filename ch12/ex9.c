#include <stdlib.h>
#include <stdio.h>

#define N 10

// Write the following function:

// This function does element-wise multiplication and sums the result.
// Requires that both arrays are of the same length. No checking is performed
double inner_product(const double *a, const double *b, int n);

// a and b both point to arrays of length n. The function should return 
// a[0] * b[0] + a[1] * b[1] + ... + a[n] * b[n]
//
// Use pointer arithmetic, not subscripting, to visit array elements


int main() {

  const double array1[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const double array2[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  double result = inner_product(array1, array2, N);
  printf("Result is: %f\n", result);


  return EXIT_SUCCESS;
}



double inner_product(const double *a, const double *b, int n) {

  double result = 0;
  const double *ptr_a = a;
  const double *ptr_b = b;
  while (ptr_a - a < n) {
    result += *ptr_a++ * *ptr_b++; 
  }
  return result;
}
