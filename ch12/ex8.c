#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Rewrite the following function to use pointer arithmetic instead of array
// subscripting. Make as few changes as possible

void store_zeros(int a[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    a[i] = 0;
  }
}

void store_zeros_ptr(int a[], int n) {
  int *ptr = a;
  while (ptr - a < n) {
    *ptr++ = 0;
  }
}

int main() {
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  store_zeros(array, 10);
  store_zeros_ptr(array, 10);

  return EXIT_SUCCESS;
}
