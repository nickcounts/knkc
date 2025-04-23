// Write the following function:
int *find_largest(int a[], int n);

// When passed an array a of length n, the function will return a pointer
// to the array's largest element

#include <stdio.h>
#include <stdlib.h>
#define N 10

int *find_largest(int a[], int n) {
  // array a[] is length n
  int largest;
  int *p_largest;

  largest = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] > largest) {
      largest = a[i];
      p_largest = &a[i];
    }
  }
  return p_largest;
}

int main(int argc, char *argv[]) {
  int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *p_largest;
  p_largest = find_largest(a, N);
  printf("The largest element is %d \n", *p_largest);
  return EXIT_SUCCESS;
}
