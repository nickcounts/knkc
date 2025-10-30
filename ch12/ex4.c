#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Rewrite the make_empty, is_empty, and is_full functions from 10.2
// to use the pointer variable `top_ptr` instead of the integer 
// variable `top`


#define STACK_SIZE 100

// External variables
char contents[STACK_SIZE];
char *top_ptr = contents; // Changed from global int to char* pointer

void stack_underflow(void) {
  // Braces aren't properly nested or something's gone wrong
  printf("Improperly nested braces\n");
  exit(EXIT_FAILURE);
}

void stack_overflow() {
  printf("Stack overflow!\n");
  exit(EXIT_FAILURE);
}

void make_empty(void) { top_ptr = contents; }

bool is_empty(void) { return top_ptr == contents; }

bool is_full(void) { return top_ptr - contents == STACK_SIZE; }

void push(char c) {
  if (is_full())
    stack_overflow();
  else
    *top_ptr++ = c;
}

char pop(void) {
  if (is_empty()) {
    stack_underflow();
    exit(EXIT_FAILURE);
  } else
    return *--top_ptr;
}

int main(int argc, char *argv[]) {
  char this_char;
  int count = 0;

  printf("Enter parentheses and/or braces: ");
  for (;;) {
    fflush(stdin);
    this_char = getchar();

    switch (this_char) {
    case '\n':
      if (is_empty()) {
        printf("Parentheses are nested properly.\n");
        return EXIT_SUCCESS;
      } else {
        printf("Improperly nested braces.\n");
        return EXIT_FAILURE;
      }
    case '(':
      count++;
      push(this_char);
      break;
    case '{':
      count++;
      push(this_char);
      break;
    case ')':
      while (1) {
        printf("unwinding ) : count = %d\n", count);
        if (pop() != ')') {
          break;
        }
        count--;
      }
      break;
    case '}':
      while (1) {
        printf("unwinding } : count = %d\n", count);
        if (pop() != '}') {
          break;
        }
        count--;
      }
      break;
    default:
      break;
    }
  }

  return EXIT_SUCCESS;
}
