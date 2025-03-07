// Write a program that calculates the average word length for a sentence

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tok_struct {
  char token[128];
  int first;
  int last;
};

typedef struct tok_struct tok_struct;

void get_next_tok(char *input, int i_start, tok_struct *ret_tok) {

  // Reset the token struct contents, in case of reuse
  memset(ret_tok, 0, sizeof(tok_struct));
  ret_tok->last = 0;
  ret_tok->first = 0;

  int pos = i_start;
  int i_tok = 0;
  while (input[pos] == ' ') {
    pos++;
  }
  ret_tok->first = pos;
  while (input[pos] != ' ' && input[pos] != '\n' && input[pos] && i_tok < 128) {
    ret_tok->token[i_tok] = input[pos];
    i_tok++;
    pos++;
  }
  ret_tok->last = pos - 1;
}

int main(int argc, char *argv[]) {
  char c;
  char sentence[256];
  int i = 0;
  int num_toks = 0;
  int num_chars = 0;

  // This gets the input but doesn't handle backspace... whole thing is a tad
  // scary. I may try to write extra logic to handle backspace
  printf("Enter a sentence: ");
  while ((c = getchar()) != '\n' && i < 256) {
    sentence[i] = c;
    i++;
  }

  tok_struct *this_tok = malloc(sizeof(tok_struct));

  i = 0;
  int safety = 0;
  while (safety < sizeof(sentence)) {
    get_next_tok(sentence, i, this_tok);
    if (this_tok->first > this_tok->last) {
      break;
    }
    printf("%d\t%d\t%s\n", this_tok->first, this_tok->last, this_tok->token);

    num_toks++;
    num_chars += (this_tok->last - this_tok->first + 1);
    i = this_tok->last + 1;
    safety++;
  }

  printf("Average token length: %f\n", (float)num_chars / (float)num_toks);

  free(this_tok);

  return EXIT_SUCCESS;
}
