#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int num1, denom1, num2, denom2, result_num, result_denom;

  printf("Enter the first fraction: ");
  scanf("%d/%d", &num1, &denom1);

  printf("Enter the second fraction: ");
  // Modified to allow spaces per ex 3.6
  scanf("%d / %d", &num2, &denom2);

  result_num = num1 * denom2 + num2 * denom1;
  result_denom = denom1 * denom2;

  printf("The sum is %d/%d\n", result_num, result_denom);

  return EXIT_SUCCESS;
}
