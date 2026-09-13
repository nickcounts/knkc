#include <stdio.h>
#include "word.h"


int read_char(void){
  int ch = getchar();
  return (ch == '\n' || ch == '\t') ? ' ' : ch;
  // if (ch == '\n' || ch == '\t')
  //   return ' ';
  // return ch;
}


// Reads user keyboard input to a buffer.
// Word is done when character is a space
// Truncates word if it exceeds length `len`
// EOF is `^d` on MacOS/Linux and `^z` on Windows
int read_word(char *word, int len){
  int ch, pos = 0;

  // Skip any leading spaces
  while ((ch = read_char()) == ' ')
    ;

  while (ch != ' ' && ch != EOF) {
    if (pos < len)
      word[pos++] = ch;
    ch = read_char();
  }
  word[pos] = '\0';

  // Append the '*' to any words that are too long
  if (pos > len-1)
    word[len-1] = '*';

  return pos;
}


