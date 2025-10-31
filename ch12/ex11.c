// Modify the `find_largest` function so that it uses pointer arithmetic 
// instead of subscripting to visit array elements.

#define N 10
#include <stdlib.h>
#include <stdio.h>

// Returns a pointer to the element containing the largest value in the array
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

// Returns a pointer to the element containing the largest value in the 
// array, using pointer arithmetic to traverse the array
int *find_largest_ptr(int a[], int n) {
  int *this_elem = a;
  int *p_largest = a;

  while (this_elem - a < n) {
    if (*this_elem > *p_largest) p_largest = this_elem;
    this_elem++;
  }
  return p_largest;
}


int main() {
  int array1[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int *old_way = find_largest(array1, N);
  int *new_way = find_largest_ptr(array1, N);

  printf("The old way found %d and the new way found %d\n", *old_way, *new_way);

  return EXIT_SUCCESS;
}
