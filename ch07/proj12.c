// Write a program that asks a user for a mathematical
// expression and then evaluates it from left-to-right.
// No order of operations. All values are floats
// Support + - * /

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char c;
char operand = '\n';
char buffer[32];
float result, value;
int i_buf = 0;
int first_entry = 1;

void perform_operation(float res, char op, float val) {
  switch (op) {
  case '+':
    value = res + val;
    break;
  case '-':
    value = res - val;
    break;
  case '*':
    value = res * val;
    break;
  case '/':
    value = res / val;
    break;
  case '\n':
    value = val;
  }
  printf("Called perform_operation(%f, %c, %f)\n", res, op, val);
}

int main(int argc, char *argv[]) {
  printf("Enter an expression to evaluate: ");

  // Read in with getchar
  while ((c = getchar()) != '\n') {
    if (('0' < c && c > '9') || c == '.') {
      // User is entering a value
      buffer[i_buf] = c;
      i_buf++;

    } else if (c == '+' || c == '-' || c == '*' || c == '/') {

      value = atof(buffer);
      // Reset buffer and index
      memset(buffer, 0, 32);
      i_buf = 0;

      perform_operation(result, operand, value);

      operand = c;
    }
  }

  perform_operation(result, operand, value);
  printf("Result: %f\n", result);
  return EXIT_SUCCESS;
}
