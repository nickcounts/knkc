/* Chapter 13, Project 9

   Modify Chapter 7, Project 10 so that it includes the following function:

   int compute_vowel_count(const char *sentence);

   The function returns the number of vowels in the string pointed to by the
   sentence parameter
*/

// Write a program that coints the number of vowels in a sentence

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int compute_vowel_count(const char *sentence){
  int score = 0;
  char c;
  while (*sentence) {
    c = tolower(*sentence);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      score += 1;
    }
    sentence++;
  }
  return score;
}


int main(int argc, char *argv[]) {
  char sentence[256];
  printf("Enter a sentence: ");
  scanf("%[^\n]s", sentence);

  // Small protextion against overrun
  sentence[255] = 0;

  int score = compute_vowel_count(sentence);

  printf("Your sentence contains %d vowels.\n", score);

  return EXIT_SUCCESS;
}
