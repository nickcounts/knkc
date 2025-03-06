// Modify addfrac from chapter 3 so that the user may add, subtract, multiply
// or divide fractions by typing +-*/ between the fractions
// Page 158 (182 pdf)
#include <stdio.h>
#include <stdlib.h>

// modified from chapter example to accept entire sum in one read statement.
// Include the + operator

int main(void) {
  int num1, denom1, num2, denom2, result_num, result_denom;
  char operator;

  printf("Enter a fraction addition problem: ");
  scanf("%d / %d %c %d / %d", &num1, &denom1, &operator, & num2, &denom2);

  switch (operator) {
  case '+':
    result_num = (num1 * denom2) + (num2 * denom1);
    break;
  case '-':
    result_num = (num1 * denom2) - (num2 * denom1);
    break;
  case '*':
    result_num = (num1 * denom2) * (num2 * denom1);

    break;
  case '/':
    result_num = (num1 * denom2) / (num2 * denom1);
    break;
  }
  result_denom = denom1 * denom2;

  printf("The sum is %d/%d\n", result_num, result_denom);

  return EXIT_SUCCESS;
}
