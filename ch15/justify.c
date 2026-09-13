


#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(void){
  char word[MAX_WORD_LEN+2];
  int word_len;

  

  clear_line();

  for (;;) {
    word_len = read_word(word, MAX_WORD_LEN+1);
    // word_len = strlen(word);
    // printf("word_len = %d\tword = '%s'\n", word_len, word);

    if (word_len == 0) {
      // printf("I am flushing the line\n");
      flush_line();
      return 0;
    }

    // Moved to word.c
    // if (word_len > MAX_WORD_LEN)
    //   word[MAX_WORD_LEN] = '*';

    if (word_len + 1 > space_remaining()) {
      write_line();
      clear_line();
    }

    add_word(word);
  }
}
