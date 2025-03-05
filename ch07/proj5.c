// Write a program that scores scrabble words:
//    1: AEILNORSTU
//    2: DG
//    3: BCMP
//    4: FHVWY
//    5: K
//    8: JX
//   10: QZ
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int letter_score(int c) {
  if (c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' || c == 'O' ||
      c == 'R' || c == 'S' || c == 'T' || c == 'U')
    return 1;

  if (c == 'D' || c == 'G')
    return 2;

  if (c == 'B' || c == 'C' || c == 'M' || c == 'P')
    return 3;

  if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
    return 4;

  if (c == 'K')
    return 5;

  if (c == 'J' || c == 'X')
    return 8;

  if (c == 'Q' || c == 'Z')
    return 10;

  return 0;
}

int main(int argc, char *argv[]) {
  int word[64];
  int points = 0;
  char c;

  printf("Enter a SCRABBLE word: ");

  int i = 0;
  while ((c = getchar()) != '\n') {
    if (i >= 63) {
      word[63] = 0;
      break;
    }
    points += letter_score(toupper(c));
    word[i] = c;
  }

  printf("Word score: %d\n", points);

  return EXIT_SUCCESS;
}
