// Modify the `find_middle` function of section 11.5 so that it uses pointer
// arithmetic to calculate the return value

#include <stdio.h>
#include <stdlib.h>

#define N 10

// Returns a pointer to the middle element of the n-element array a[]
int *find_middle(int a[], int n) { return &a[n / 2]; }

// Returns a pointer to the middle element of the n-element array a[]
int *find_middle_ptr(int a[], int n) { 
  return a + n/2;
  // return &a[n / 2]; 
}

int main() {
  int array1[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int *old_way = find_middle(array1, N);
  int *new_way = find_middle_ptr(array1, N);

  printf("The old way was %d and the new way is %d\n", *old_way, *new_way);

  return EXIT_SUCCESS;
}
