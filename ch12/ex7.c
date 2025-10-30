#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Write the following function:

bool search(const int a[], int n, int key);

// a is an array to be searched
// n is the number of elements
// key is the search key (term)
//
// `search` should return True of the key matches any element of a and
// false if it doesn't
//
// Use pointer arithmetic, not subscripting, to visit array elements.

bool search(const int a[], int n, int key) {
  const int *ptr = a;
  while (ptr - a < n) {
    if (*ptr++ == key)
      return true;
  }
  return false;
}

int main() {
  int array[10] = {1,2,3,4,5,6,7,8,9,10};
  printf("array[] is 1...10.\n");
  printf("search(array, 10,  5) : ");

  search(array, 10, 5) ? printf("True\n") : printf("False\n");

  printf("search(array, 10, 15) : ");
  search(array, 10, 15) ? printf("True\n") : printf("False\n");

  return EXIT_SUCCESS;
}
