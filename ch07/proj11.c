// Write a program that takes a first name and a last name entered by the user
// and displays the last name, a comma, and the first initial, followed by a
// period.
//
// The user's input may contain extra spaces before the first name, between
// the first and last names, and after the last name.

#include <stdio.h>
#include <stdlib.h>

struct tok_struct {
  char token[128];
  int first;
  int last;
};

typedef struct tok_struct tok_struct;

tok_struct *get_next_tok(char *input, int i_start) {
  // 128 byte char array to hold tokens. This is probably a tad big
  tok_struct *token;
  token = malloc(sizeof(tok_struct));

  int pos = i_start;
  int i_tok = 0;
  while (input[pos] == ' ') {
    pos++;
  }
  token->first = pos;
  while (input[pos] != ' ' && input[pos] != '\n' && input[pos] && i_tok < 128) {
    token->token[i_tok] = input[pos];
    i_tok++;
    pos++;
  }
  token->last = pos - 1;

  return token;
}

int main(int argc, char *argv[]) {
  char c;
  char fullname[256];
  int i = 0;

  // This gets the input but doesn't handle backspace... whole thing is a tad
  // scary. I may try to write extra logic to handle backspace
  printf("Enter a first and last name: ");
  while ((c = getchar()) != '\n' && i < 256) {
    fullname[i] = c;
    i++;
  }

  tok_struct *tok_first = get_next_tok(fullname, 0);
  tok_struct *tok_last = get_next_tok(fullname, tok_first->last + 1);

  printf("%s, %c.\n", tok_last->token, tok_first->token[0]);

  return EXIT_SUCCESS;
}
