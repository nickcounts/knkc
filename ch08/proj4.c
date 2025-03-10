// Modify the reverse.c program from 8.1 to uyse the expression:
// (int) (sizeof(a) / sizeof(a[0]))      or a macro with this value
// for the array length.
//
// Reverses a series of numbers
#include <stdio.h>
#include <stdlib.h>

#define N 10

#define ELEMENTS(a) (int)(sizeof(a) / sizeof(a[0]))

int main(int argc, char *argv[]) {
  int a[N], i;

  printf("Enter %d numbers: ", N);
  for (i = 0; i < ELEMENTS(a); i++) {
    scanf("%d", &a[i]);
  }

  printf("In reverse order:");
  for (i = ELEMENTS(a) - 1; i >= 0; i--) {
    printf(" %d", a[i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
