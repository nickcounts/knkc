#include <stdio.h>
#include <stdlib.h>

int main() {
  int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
  int *low = &a[1], *high = &a[5];

  printf("Suppose that high, low, and middle are all pointer variables of the same\n");
  printf("type and that high and low point to elements of an array. Why is the\n");
  printf("following statement illegal, and how could it be fixed?\n");
  printf("\tmiddle = (low + high) / 2\n");

  printf("\tAdding pointers is undefined. Only pointer subtraction or integer\n");
  printf("\tarithmetic to pointers is valid. To fix this, we would need the\n");
  printf("\tdifference between pointers (which returns an integer) and then\n");
  printf("\tdetermine the middle value by offset:\n");
  printf("\tmiddle = low + ((high-low)/2)\n");

  int *middle = low + ((high - low) / 2);
  printf("\tmiddle = %p\n", middle);

  return EXIT_SUCCESS;
}
