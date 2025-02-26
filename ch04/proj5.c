#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Calculating the checksum of a barcode\n");

  int first, check_digit, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5 = 0;

  printf("Enter the first eleven digits of a UPC: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &first, &i1, &i2, &i3, &i4, &i5,
        &j1, &j2, &j3, &j4, &j5);

  int first_sum = first + i2 + i4 + j1 + j3 + j5;
  int second_sum = i1 + i3 + i5 + j2 + j4;
  int total = (3 * first_sum) + second_sum;
  check_digit = 9 - ((total - 1) % 10);

  printf("Check digit: %d\n", check_digit);

  return EXIT_SUCCESS;
}
