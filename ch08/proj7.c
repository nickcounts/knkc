// Write a program that reads a 5x5 array of integers and then prints
// the row sums and the column sums

#include <stdio.h>
#include <stdlib.h>

#define ELEMENTS(a) (int)(sizeof(a) / sizeof(a[0]))

int main(int argc, char *argv[]) {
  int m[5][5];
  int row_sum[5] = {0};
  int col_sum[5] = {0};
  int r, c;

  for (r = 0; r < 5; r++) {
    printf("Enter row %d: ", r + 1);
    for (c = 0; c < 5; c++) {
      // We could do this without saving the 2-d array.
      // Save each int to a temp variable, then add it to the
      // running total the same way. I saved the values because
      // it seemed to be in the spirit of the chapter
      scanf("%d", &m[r][c]);

      row_sum[r] += m[r][c];
      col_sum[c] += m[r][c];
    }
  }

  printf("\nRow totals: ");

  int i = 0;
  while (i < ELEMENTS(row_sum))
    printf(" %d", row_sum[i++]);

  printf("\nColumn totals: ");
  i = 0;
  while (i < ELEMENTS(col_sum))
    printf(" %d", col_sum[i++]);

  printf("\n\n");

  return EXIT_SUCCESS;
}
