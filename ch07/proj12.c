// Write a program that asks a user for a mathematical
// expression and then evaluates it from left-to-right.
// No order of operations. All values are floats
// Support + - * /

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 128

char c;
char operand = '\n';
char buffer[BUFFER_SIZE];
char user_input[BUFFER_SIZE];
double result, value;
int i_buf = 0;
int first_entry = 1;

void perform_operation(double res, char op, double val) {

  switch (op) {
  case '+':
    result = res + val;
    break;
  case '-':
    result = res - val;
    break;
  case '*':
    result = res * val;
    break;
  case '/':
    result = res / val;
    break;
  case '\n':
    result = val;
  }
}

int main(int argc, char *argv[]) {
  printf("Enter an expression to evaluate: ");
  scanf("%[^\n]s", user_input);

  int i_user = 0;
  // Parse input buffer in order
  // loop-and-a-half. Every operator detection calls the calc
  // code with the **LAST** operand.
  //
  // That means the first one is called with a number and the
  // SENTINEL OPERATOR, which simply sets the result value
  // (it's the starting point of the calc)
  //
  // Subsequent operator detections trigger a value creation
  // and call calculate using the PREVIOUS OPERAOR.
  //
  // That means we need one final calculate call after the
  // loop is completed.
  while (user_input[i_user]) {
    c = user_input[i_user];

    if ((c >= '0' && c <= '9') || c == '.') {
      // User is entering a value
      buffer[i_buf] = c;
      i_buf++;

    } else if (c == '+' || c == '-' || c == '*' || c == '/') {

      value = atof(buffer);
      // Reset buffer and index
      memset(buffer, 0, BUFFER_SIZE);
      i_buf = 0;

      perform_operation(result, operand, value);

      operand = c;
    }
    i_user++;
  }

  value = atof(buffer);
  perform_operation(result, operand, value);
  printf("Result: %f\n", result);
  return EXIT_SUCCESS;
}
