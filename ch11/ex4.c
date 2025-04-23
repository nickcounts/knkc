// Write the following function:

void swap(int *p, int *q);

// When passed the addresses of two variables, swap should exchange
// the values of the variables:
// swap(&i, &j); // exchanges values of i and j

#include <stdio.h>

#define DEBUG 0

void swap(int *p, int *q) {
  int temp = *p;
  if (DEBUG) {
    printf("In swap()\n");
    printf("swap(%p, %p)\n", p, q);
    printf("int temp = %d\n", temp);
  }
  *p = *q;
  *q = temp;
  if (DEBUG)
    printf("q = %p\n", q);
}

int main(int argc, char *argv[]) {
  int p = 10;
  int q = 20;
  printf("p = %d, q = %d\n", p, q);
  swap(&p, &q);
  printf("p = %d, q = %d\n", p, q);
  return 0;
}
