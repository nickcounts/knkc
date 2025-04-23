// Write the following function:
void find_two_largest(int a[], int n, int *largest, int *second_largest);

// When passed an array a[n], the function will search a for its largest
// and second largest elements, storing them in the variables pointed to
// by `largest` and `second_largest`

#include <stdio.h>
#include <stdlib.h>
#define N 10

void find_two_largest(int a[], int n, int *largest, int *second_largest) {
  // array a[] is length n
  *largest = a[0];
  *second_largest = a[0];
  for (int i = 0; i < N; i++) {
    if (a[i] > *largest) {
      *second_largest = *largest;
      *largest = a[i];
    }
  }
}

int main(int argc, char *argv[]) {
  int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int largest, next_largest;
  find_two_largest(a, N, &largest, &next_largest);
  printf("The largest element is %d and the next largest is %d\n", largest,
         next_largest);
  return EXIT_SUCCESS;
}
