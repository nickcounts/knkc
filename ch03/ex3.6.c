#include <stdio.h>
#include <stdlib.h>

// modified from chapter example to accept entire sum in one read statement.
// Include the + operator

int main(void) {
  int num1, denom1, num2, denom2, result_num, result_denom;

  printf("Enter a fraction addition problem: ");
  scanf("%d / %d + %d / %d", &num1, &denom1, &num2, &denom2);

  result_num = num1 * denom2 + num2 * denom1;
  result_denom = denom1 * denom2;

  printf("The sum is %d/%d\n", result_num, result_denom);

  return EXIT_SUCCESS;
}
