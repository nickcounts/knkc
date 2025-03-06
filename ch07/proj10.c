// Write a program that coints the number of vowels in a sentence

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char sentence[256];
  printf("Enter a sentence: ");
  scanf("%[^\n]s", sentence);

  // Small protextion against overrun
  sentence[255] = 0;

  int i = 0;
  int score = 0;
  char c;
  while (sentence[i]) {
    // printf("Testing character %03d : '%c'\n", i, sentence[i]);
    c = tolower(sentence[i]);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      score += 1;
    }
    i++;
  }

  printf("Your sentence contains %d vowels.\n", score);

  return EXIT_SUCCESS;
}
