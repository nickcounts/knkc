/* Chapter 13, Project 14

   Modify Programming Project 16 from Chapter 8 so that it includes the following function:

   bool are_anagrams (const char *wordl, const char *word2);

   The function returns true if the strings pointed to by word1 and word2 are anagrams.
 */

// Write a program that tests whether two words are anagrams:

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Added for Ch13, Proj14

#define ELEMENTS(a) (int)(sizeof(a) / sizeof(a[0]))


int ischar(char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return 1;
  return -1;
}


bool are_anagrams (const char *word1, const char *word2) {
  int cc[26] = {0};
  // count letters in word 1
  while (*word1) {
    if (!*word1)
      break; // stop at null termination
    if (ischar(*word1)) {
      // count characters
      cc[tolower(*word1++) - 'a'] += 1;
    }
  }

  // decrement letter count with word 2
  while (*word2){
    if (!*word2)
      break; // stop at null termination
    if (ischar(*word2)) {
      // count characters
      cc[tolower(*word2++) - 'a'] -= 1;
    }
  }

  // check equality
  for (int i = 0; i < ELEMENTS(cc); i++) {
    if (cc[i] != 0) {
      return false;
    }
  }

  return true;
}





int main(int argc, char *argv[]) {
  char w1[128];
  char w2[128];

  printf("Enter first word: ");
  scanf("%s", w1);

  printf("Enter second word: ");
  scanf("%s", w2);

  if (are_anagrams(w1, w2)) {
    printf("The words are anagrams.\n");
  } else {
    printf("The words are not anagrams.\n");
  }

  return EXIT_SUCCESS;
}
