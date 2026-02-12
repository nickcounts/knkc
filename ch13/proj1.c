/*
   Write a program that finds the "smallest" and "largest"| in a series of
   words. After the user enters the words, the program will determine which
   words would come first and last if the words were listed in dicitonary order.
   The progeram must stop accepting input when the user enters a four-letter
   word. Assume that no word is more than 20 letters long. An interactive
   seesion with the program might look like this:

   Enter a word: dog
   Enter a word: zebra
   Enter a word: rabbit
   Enter a word: catfish
   Enter a word: walrus
   Enter a word: cat
   Enter a word: fish

   Smallest word: cat
   Largest word: zebra
 */

#define BUFF_STR_LEN 32
#define MAX_WORDS 16

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  // Display --help message for the nice user
  if (argc > 1){
    if (!strcmp("--help", argv[1])){
      printf("The maximum length of a word is %d\n", BUFF_STR_LEN - 1);
      printf("The maximum number of words is %d\n", MAX_WORDS);
      printf("Enter a 4-letter word (not vulgar) to finish input\n");
      return EXIT_SUCCESS;
    }
  }

  char input_buffer[BUFF_STR_LEN];
  char smallest_word[BUFF_STR_LEN];
  char largest_word[BUFF_STR_LEN];
  int word_length = 0;
  
  for (int w = 0; w < MAX_WORDS; w++){
    // Enter a word
    printf("Enter word: ");
    scanf("%s", input_buffer);
    word_length = strlen(input_buffer);

    // First loop: store as largest AND smallest
    if (w==0){
      strcpy(largest_word, input_buffer);
      strcpy(smallest_word, input_buffer);
      continue;
    }

    // if (this_score > score_word(largest_word))h
    if (strcmp(input_buffer, largest_word) > 0)
      strcpy(largest_word, input_buffer);

    // if (this_score < score_word(smallest_word))
    if (strcmp(input_buffer, smallest_word) < 0)
      strcpy(smallest_word, input_buffer);

    if (word_length == 4) break;
  }

  printf("Smallest Word: %s\n", smallest_word);
  printf(" Largest Word: %s\n", largest_word);


  return EXIT_SUCCESS; 
}


