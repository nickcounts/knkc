// Reverses a series of numbers using variable-length array
// C99 only!

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i, n;

  printf("How many numbers do you want to reverse? ");
  scanf("%d", &n);

  int a[n]; // C99 only - length of array depends on n

  printf("Enter %d numbers: ", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  printf("In reverse order:");
  for (i = n - 1; i >= 0; i--) {
    printf(" %d", a[i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
