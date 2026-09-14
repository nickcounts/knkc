#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


int contents[STACK_SIZE];
int top = 0;


/* pushes a value onto the stack
 *
 * @param i the value to push onto the stack
 */
void push(int i) {
  if (is_full())
    stack_overflow();
  else
    contents[top++] = i;
}

/* pops a value off the top of the stack
 * returns the value and removes it from the stack 
 *
 * if the stack is empty, executes `stack_underflow()`
 *
 * @returns int 
 */
int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return contents[top];
  } else {
    return contents[--top];
  }
}

void stack_overflow(){
  puts("Expression is too complex");
  exit(EXIT_FAILURE);
}

void stack_underflow(){
  puts("Not enough operands in expression");
  exit(EXIT_FAILURE);
}

// reset the stack 
void make_empty(void) { 
  top = 0;
}

/* test stack for contents
 *
 * return `false` if contents are found
 * return `true` if empty 
 */
bool is_empty(void) { 
  return top == 0;
}


bool is_full(void) { 
  return top == STACK_SIZE;
}
