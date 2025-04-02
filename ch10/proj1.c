// Project 1:
//
// Modify the stack example of section 10.2 so that it stores characters
// instead of integers.
// Next, add a main() function that asks the user to enter a series of
// parentheses and/or braces, then indicate whether or not they are
// properly nested:
//
// Enter parentheses and/or braces: ((){}{()})
// Parenthesis/braces are nested properly
//

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// External variables
char contents[STACK_SIZE];
int top = 0;

void stack_underflow(void) {
  // Braces aren't properly nested or something's gone wrong
  printf("Improperly nested braces\n");
  exit(EXIT_FAILURE);
}

void stack_overflow() {
  printf("Stack overflow!\n");
  exit(EXIT_FAILURE);
}

void make_empty(void) { top = 0; }

bool is_empty(void) { return top == 0; }

bool is_full(void) { return top == STACK_SIZE; }

void push(char c) {
  if (is_full())
    stack_overflow();
  else
    contents[top++] = c;
}

char pop(void) {
  if (is_empty()) {
    stack_underflow();
    exit(EXIT_FAILURE);
  } else
    return contents[--top];
}

int main(int argc, char *argv[]) {
  char this_char;

  printf("Enter parentheses and/or braces: ");
  for (;;) {
    this_char = getchar();
    switch (this_char) {
    case '\n':
      if (is_empty()) {
        printf("Parentheses are nested properly.\n");
        break;
      }
    case '(':
      push(this_char);
      break;
    case '{':
      push(this_char);
      break;
    case ')':
      while (pop() != ')') {
        ;
      }
      break;
    }
  }

  return EXIT_SUCCESS;
}
