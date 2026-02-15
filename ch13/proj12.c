
/* Chapter 13, Project 12

   Modify Chapter 8, Project 14 so that it stores the words in a two-dimensional
   char array as it reads the sentence, with each `row` of the array storing a
   single word. Assume that the sentence contains no more than 30 words and no
   word is more than 20 characters long. Be sure to store a null character at
   the end of each word so that it can be treated as a string.

   Note:
   > Writing from scratch - earlier project was too different
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 30
#define MAX_WORD_LEN 20

int main(){
  char words[MAX_WORDS][MAX_WORD_LEN];

  char this_char = '\0';
  int this_word_ind = 0;
  int this_char_ind = 0;

  while(this_word_ind < MAX_WORDS){

    while (this_char_ind < MAX_WORD_LEN){
      // Get Input
      this_char = getchar();
      words[this_word_ind][this_char_ind] = this_char;

      if (this_char == ' '){
        // Change word if space
        if (this_char_ind == 0) continue; // ignore space at beginning of word
        words[this_word_ind][this_char_ind] = '\0'; // null-terminate!

        // Go to next word input, reset char_ind
        this_char_ind++;
        this_char_ind = 0;
        break;
      } 
      else if (this_char == '\n') {
        // End input if enter
        words[this_word_ind][this_char_ind] = '\0'; // null-terminate!
        break;
      }
      this_char_ind++;
    } // END word user input
    if (this_char == '\n') break; // END all user input 

    this_word_ind++;
  }

  // Ended on last word and last character. Check for punctuation and store
  char last_char = 0;
  if (strlen(words[this_word_ind])){
    last_char = words[this_word_ind][this_char_ind-1];
    if (last_char == '.' || last_char == '?' || last_char == '!'){
      // Replace final punctuation with null-terminator (erase it)
      words[this_word_ind][this_char_ind-1] = '\0';
    } else {
      last_char = '\0';
    }

  } 

  for (int wi = this_word_ind; wi >= 0; wi--){
    printf("%s", words[wi]);
    if (wi) printf(" ");
  }

  if (last_char) printf("%c", last_char);
  printf("\n");
  
  return EXIT_SUCCESS;
}
