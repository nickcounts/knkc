/* Chapter 13, Project 15

   Modify Programming Project 6 from Chapter 10 so that it includes the
   following function:

   int evaluate_RPN_expression (const char *expression) ;

   The function returns the value of the RPN expression pointed to by
   expression.
 */


/* Chapter 10, Project 6 

   Implement a Reverse Polish Notation calculator. 
   Use the stack.c code from the chapter
 */

#define STACK_SIZE 100

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h> /* C99 only */
#include "../ncb/ncb.h"

#define STR_BUFF_LEN 512
typedef char ntb_buff_str[STR_BUFF_LEN];

struct tok_struct {
  char token[128];
  int first;
  int last;
};

typedef struct tok_struct tok_struct;

// External variables
int contents[STACK_SIZE];
int top = 0;


void get_next_tok(char *input, int i_start, tok_struct *ret_tok);
int evaluate_RPN_expression (const char *expression) ;
void stack_overflow();
void stack_underflow();

void make_empty(void) { top = 0; }
bool is_empty(void) { return top == 0; }
bool is_full(void) { return top == STACK_SIZE; }

void push(int i) {
  if (is_full())
    stack_overflow();
  else
    contents[top++] = i;
}

int pop(void) {
  if (is_empty()) {
    // stack_underflow();
    return contents[top];
  } else {
    return contents[--top];
  }
}

int main(int argc, char *argv[])
{
  tok_struct *this_tok = malloc(sizeof(tok_struct));

  ntb_buff_str buffer = {0};
  char ch;
  int i = 0;
  int first_val, second_val;

  // User Input:
  puts("Please enter an integer expression in RPN to evaluate:");
  while ((ch = getchar()) != '\n' && i < STR_BUFF_LEN - 1) {
    buffer[i] = ch;
    i++;
  }


  // Tokenize Buffer
  i = 0;
  while (i < STR_BUFF_LEN){
    get_next_tok(buffer, i, this_tok);
    i = this_tok->last + 1; // next character to parse!

    if (this_tok->last < this_tok->first) break;

    if (this_tok->token[0] >= '0' && this_tok->token[0] <= '9'){
      // Number was entered, push onto the stack and go to next token
        push(int_from_str(this_tok->token));
        continue;
    }

    if (this_tok->token[0] == '='){
        push(pop());
        break;
    }

    second_val = pop();
    first_val = pop();

    switch (this_tok->token[0]){
      case '/':
        push(first_val/second_val);
        break;

      case '*':
        push(first_val*second_val);
        break;

      case '-':
        push(first_val-second_val);
        break;

      case '+':
        push(first_val+second_val);
        break;
    }
  }

  printf("Result = %d\n", pop());

  free(this_tok);
  return EXIT_SUCCESS;
}

void stack_overflow(){
  puts("Expression is too complex");
  exit(EXIT_FAILURE);
}

void stack_underflow(){
  puts("Not enough operands in expression");
  exit(EXIT_FAILURE);
}



// populates *ret_tok with the token string, a start and stop index
// maximum token size of 128
void get_next_tok(char *input, int i_start, tok_struct *ret_tok) {
#define MAX_TOK_LEN 128

  // Reset the token struct contents, in case of reuse
  memset(ret_tok, 0, sizeof(tok_struct));
  ret_tok->last = 0;
  ret_tok->first = 0;

  int pos = i_start;
  int i_tok = 0;

  // Skip leading whitespace
  while (input[pos] == ' ') {
    pos++;
  }

  // first non-whitespace character found
  ret_tok->first = pos;
  while (input[pos] != ' ' && input[pos] != '\n' && input[pos] && i_tok < MAX_TOK_LEN) {
    ret_tok->token[i_tok] = input[pos];
    i_tok++;
    pos++;
  }
  ret_tok->last = pos - 1;
}
