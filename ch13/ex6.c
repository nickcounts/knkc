// Write a function named censor that modifies a string by replacing every 
// occurrence of foo by xxx. For example, the string "food fool" would become
// "xxxd xxx1" Make the function as short as possible without sacrificing
// clarity.

#include <string.h>
#define BUFF_LEN 256
#define DEFAULT_STR "Only a fool would censor"
#define CENSOR_CHAR 'x'
#define TOKEN "foo"
#define DEBUG 0

#import <stdio.h>
#import <stdlib.h>

// Copy the in string to the buff string. If in is longer than BUFF_LEN the
// extra characters will be truncated. buff[] will always be null-terminated
void copy_to_string_buffer(char in[], char (*buff)[BUFF_LEN]){
  if (DEBUG) printf("in   : %p\n", in);
  if (DEBUG) printf("buff : %p\n", buff);

  char *ip = in;
  char *bp = buff[0];

  while (bp - buff[0] < BUFF_LEN){
    if (*ip) {
      *bp = *ip;  // Copy char to buff
      bp++;       // increment buff pointer
      ip++;       // increment input pointer
    } else {
      break;
    }
  }

  // Ensure null-termination
  if (bp - buff[0] < BUFF_LEN) 
    *bp = '\0';
  else
    *(buff[0] + BUFF_LEN - 1) = '\0';
}
// uses pointers to first and last character of token match
typedef struct {
  int token_found;
  char* first;
  char* last;
} t_token_pos;

// Returns a struct with first and last char of matching token in buff
t_token_pos find_token_in_string(char tok[], char *buff){
  if (DEBUG) printf("tok  : %p\n", tok);
  if (DEBUG) printf("buff : %p\n", buff);

  if (DEBUG) printf("Searching: %s\n", buff);
  if (DEBUG) printf("For token: %s\n", tok);
  t_token_pos this_tok;
  this_tok.token_found = 0;
  this_tok.first = 0;
  this_tok.last = 0;

  char *tp = tok;
  char *bp = buff;
  
  // Start at beginning of buff, look for first char of token
  while (bp - buff < BUFF_LEN - strlen(tok)) {
    if (DEBUG) printf("Testing buffer char: %c\n", *bp);
    if (*bp == *tok) {
      // We have a match on the first character
      if (DEBUG) printf("Match first tok char: %c\n", *tok);
      this_tok.first = bp++;
      tp = tok + 1;
      while (*tp) {
        if (DEBUG) printf("Testing buffer char: %c == %c\n", *bp, *tp);
        if (*tp == *bp) {
          // Still matching
          tp++;
          bp++;
        } else {
          // Match broken
          // bp could still match first char, don't increment
          break;
        }
      }
      // Out of tok-loop: if tp is on null, then we did the whole thing and
      // we have a match!
      if (*tp == 0) {
        this_tok.token_found = 1;
        this_tok.last = bp;
        return this_tok;
      } else {
        // Clean up from bad match
        // set bp to next char from outer loop to ensure all possible matches
        bp = this_tok.first +1;
        this_tok.first = 0;
        continue;
      }
    } else if (*bp == 0) {
      return this_tok;
    }
    bp++;
  }


  return this_tok;
}


// Replaces all instances of the tok chars with CENSOR_CHAR 
// Expects a string literal or standard c-string/char array 
// as tok and a BUFF_LEN fixed size buffer array 
//
// :tok:  char *
// :buff: char (*)[BUFF_LEN]
void replace_all_tokens_in_buffer(char tok[], char *buff){
  t_token_pos this_token = find_token_in_string(tok, buff);
  while (this_token.token_found){
    char *rp = this_token.first;
    while (rp < this_token.last){
      *rp++ = CENSOR_CHAR;
    }
    this_token = find_token_in_string(tok, buff);
  }
}


/* In this exercise, replace all instances of the target token's 
 * characters with 'x'. So "foolish" -> "xxxlish"
 *
 * Created a token finder that returns a t_token_pos, with a 
 * t_token_pos.token_found field and pointers to the first and last
 * characters of the match
 *
 * */

int main(int argc, char *argv[]){

  char buff[BUFF_LEN] = "";

  if (DEBUG) printf("Address of original buff: %p\n", &buff);
  char *bp = &buff[0];
  if (DEBUG) printf("Address of char *bp=buff: %p\n", bp);
  if (DEBUG) printf("modified buff = %s\n", buff); 


  // Use command line argument or default buffer string
  if ( argc - 1 ){
    copy_to_string_buffer(argv[argc-1], &buff);
    printf("buff set to: %s\n", buff);
  } else {
    copy_to_string_buffer(DEFAULT_STR, &buff);
  }

  replace_all_tokens_in_buffer(TOKEN, buff);
  printf("buff set to: %s\n", buff);

  return EXIT_SUCCESS;
}



