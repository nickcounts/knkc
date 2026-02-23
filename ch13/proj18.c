/* Chapter 13, Project 18

   Write a program that accepts a date from the user in the form mm/dd/yyyy and
   then displays it in the form month dd, yyyy. where month is the name of the
   month:

   Enter a date (mm/dd/yyyy): 2/17/2011
   You entered the date February 17, 2011

   Store the month names in an array that contains pointers to strings.
 */

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#include "../ncb/ncb.h"

#define TOK_SIZE 8

char *months[] = {
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December",
};

struct tok_struct {
  char token[TOK_SIZE];
  int first;
  int last;
};

typedef struct tok_struct tok_struct;

void get_next_tok(char *input, int i_start, tok_struct *ret_tok);

int main(int argc, char *argv[])
{
  ncb_buff_str buffer = {0};
  char ch;
  int b_ind = 0;
  int year, month_num, day;
  tok_struct *this_tok;
  int tok_num = 1;
  this_tok = malloc(sizeof(tok_struct));

  puts("DATE FORMATTER");
  puts("-------------------------------------------------------------");
  puts("Enter a date (mm/dd/yyyy):");
  while ((ch = getchar()) != '\n' ) {
    if (b_ind < STR_BUFF_LEN - 1 )
      buffer[b_ind++] = ch;
  }


  if (!is_string_valid_format("dd/dd/dddd", buffer)){
    puts("Please enter a date in the form mm/dd/yyyy");
    exit(1);
  }

  // Tokenize Buffer
  b_ind = 0;
  while (b_ind < STR_BUFF_LEN && tok_num < 4){
    get_next_tok(buffer, b_ind, this_tok);
    b_ind = this_tok->last + 1; // next character to parse!
    // printf("this_tok.token = %s  : %d\n", this_tok->token, this_tok->first);

    if (this_tok->last < this_tok->first) break;
    switch (tok_num) {
      case 1:
        month_num = int_from_str(this_tok->token);
        break;

      case 2:
        day = int_from_str(this_tok->token);
        break;

      case 3:
        year = int_from_str(this_tok->token);
        break;
    }

    tok_num++;

  }

  printf("%s %d, %d\n", months[month_num-1], day, year);

  return EXIT_SUCCESS;
}



// populates *ret_tok with the token string, a start and stop index
// maximum token size of 128
void get_next_tok(char *input, int i_start, tok_struct *ret_tok) {
#define MAX_TOK_LEN TOK_SIZE
#define TOK_CHAR '/'

  // Reset the token struct contents, in case of reuse
  memset(ret_tok, 0, sizeof(tok_struct));
  // for (int ti = 0; ti<TOK_SIZE; ti++) {ret_tok->token[ti] = 0;}
  ret_tok->last = 0;
  ret_tok->first = 0;

  int pos = i_start;
  int i_tok = 0;

  // Skip leading whitespace
  while (input[pos] == ' ' || input[pos] == TOK_CHAR) {
    pos++;
  }

  // first non-whitespace character found
  ret_tok->first = pos;
  while (input[pos] != TOK_CHAR && input[pos] != '\n' && input[pos] && i_tok < MAX_TOK_LEN) {
    ret_tok->token[i_tok] = input[pos];
    i_tok++;
    pos++;
  }
  ret_tok->last = pos - 1;
}

