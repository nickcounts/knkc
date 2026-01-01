// Write a function named censor that modifies a string by replacing every 
// occurrence of foo by xxx. For example, the string "food fool" would become
// "xxxd xxx1" Make the function as short as possible without sacrificing
// clarity.

#include <string.h>
#define BUFF_LEN 256
#define DEFAULT_STR "Only a fool would censor"

#import <stdio.h>
#import <stdlib.h>

// Copy the in string to the buff string. If in is longer than BUFF_LEN the
// extra characters will be truncated. buff[] will always be null-terminated
void copy_to_string_buffer(char in[], char buff[]){
  printf("in   : %p\n", in);
  printf("buff : %p\n", buff);
  return;

  char *bp = buff;
  char *ip = in;

  while (bp - buff < BUFF_LEN){
    if (*ip) {
      *bp = *ip;  // Copy char to buff
      bp++;       // increment buff pointer
      ip++;       // increment input pointer
    } else {
      break;
    }
  }

  // Ensure null-termination
  if (bp - buff < BUFF_LEN) 
    *bp = '\0';
  else
    *(buff + BUFF_LEN - 1) = '\0';
}

typedef struct {
  int token_found;
  char* first;
  char* last;
} t_token_pos;

// Returns a struct with first and last char of matching token in buff
t_token_pos find_token_in_string(char tok[], char *buff){
  printf("tok  : %p\n", tok);
  printf("buff : %p\n", buff);

  printf("Searching: %s\n", buff);
  printf("For token: %s\n", tok);
  t_token_pos this_tok;
  this_tok.token_found = 0;
  this_tok.first = 0;
  this_tok.last = 0;

  char *tp = tok;
  char *bp = buff;
  
  // Start at beginning of buff, look for first char of token
  while (bp - buff < BUFF_LEN - strlen(tok)) {
    printf("Testing buffer char: %c\n", *bp);
    if (*bp == *tok) {
      printf("Match first tok char: %c\n", *tok);
      // We have a match on the first character
      this_tok.first = bp;
      tp = tok + 1;
      while (*tp) {
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



int main(int argc, char *argv[]){

  char buff[BUFF_LEN] = "";

  printf("Address of original buff: %p\n", &buff);
  char *bp = &buff[BUFF_LEN];
  printf("Address of char *bp=buff: %p\n", bp);
  *bp = 'T';
  printf("modified buff = %s\n", buff); 




  if ( argc - 1 ){
    copy_to_string_buffer(argv[argc-1], buff);
    printf("buff set to: %s\n", buff);
  } else {
    copy_to_string_buffer(DEFAULT_STR, buff);
  }

  t_token_pos this_token = find_token_in_string("foo", buff);
  printf("Match found: %s\n", this_token.token_found ? "YES" : "NO");


  return EXIT_SUCCESS;
}



