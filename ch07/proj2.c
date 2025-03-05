// Copy of square from chapter 6
// Modify to pause every 24 lines and prompt to continue

#include <stdio.h>

int main(void) {
  int entries;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &entries);

  int line_count = 1;
  for (int n = 1; n <= entries; n++) {

    printf("%10d %10d\n", n, n * n);
    line_count++;

    if (line_count > 24) {
      printf("Press Enter to continue...");
      fflush(stdin); // Some extra newline was stuck in the stdin buffer?:
      while (getchar() != '\n')
        ;
      line_count = 1;
    }
  }

  return 0;
}
