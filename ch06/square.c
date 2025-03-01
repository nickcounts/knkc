#include <stdio.h>

int main(void) {
  int entries;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &entries);

  for (int n = 1; n <= entries; n++) {
    printf("%10d %10d\n", n, n * n);
  }

  return 0;
}
