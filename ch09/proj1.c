// Proj 1
//
// Write a program that reads n user entered integers and then
// sorts the integers by calling selection_sort().
// selection_sort() must do the following:
//    1. Search the array to find the largest element
//    2. Move it to the last position in the array
//    3. Call itself recursively on the remaining n-1 elements

#include <stdio.h>
#include <stdlib.h>

#define MAX_INTS 64

void selection_sort(int a[], int n) {

  // Base case: only 1 element, it's sorted!
  if (n == 1) {
    return;
  }
  int i_largest, temp, i;

  // Find largest element
  temp = a[0];
  i_largest = 0;
  for (i = 0; i < n; i++) {
    if (a[i] > temp) {
      i_largest = i;
      temp = a[i];
    }
  }

  // Swap largest to last position
  a[i_largest] = a[n - 1];
  a[n - 1] = temp;

  // Call recursively on 0 ... n-1
  selection_sort(a, n - 1);
}

int main(int argc, char *argv[]) {
  int arr[MAX_INTS] = {0};
  int n = 0;
  int N;
  printf("How many integers will you enter (up to %d): ", MAX_INTS);
  scanf("%d", &N);

  while (n < N) {
    printf("Enter integer number %2d: ", n + 1);
    scanf("%d", &arr[n]);
    n++;
  }

  selection_sort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}
