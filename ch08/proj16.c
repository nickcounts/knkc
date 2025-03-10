// Write a program that tests whether two words are anagrams:

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define ELEMENTS(a) (int)(sizeof(a) / sizeof(a[0]))

int ischar(char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return 1;
  return -1;
}

int main(int argc, char *argv[]) {
  char w1[128];
  char w2[128];
  int cc[26] = {0};

  printf("Enter first word: ");
  scanf("%s", w1);

  printf("Enter second word: ");
  scanf("%s", w2);

  // count letters in word 1
  for (int i = 0; i < ELEMENTS(w1); i++) {
    if (!w1[i])
      break; // stop at null termination
    if (ischar(w1[i])) {
      // count characters
      cc[tolower(w1[i]) - 'a'] += 1;
    }
  }

  // decrement letter count with word 2
  for (int i = 0; i < ELEMENTS(w2); i++) {
    if (!w2[i])
      break; // stop at null termination
    if (ischar(w2[i])) {
      // count characters
      cc[tolower(w2[i]) - 'a'] -= 1;
    }
  }

  // check equality
  for (int i = 0; i < ELEMENTS(cc); i++) {
    if (cc[i] != 0) {
      printf("The words are not anagrams.\n");
      return EXIT_SUCCESS;
    }
  }

  printf("The words are anagrams.\n");
  return EXIT_SUCCESS;
}
