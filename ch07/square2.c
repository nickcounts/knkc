// Copy of square from chapter 6
// this fails if i * i exceeds the max storage capacity of int
// try with short and long - see what my computer's default int is

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
