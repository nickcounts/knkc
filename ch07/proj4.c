// Write a program that translates an alphabetic phone number into numeric
// form. Assume all letters are capital. If the number includes punctuation
// (-,. etc) preserce it.
// 2=ABC, 3=DEF, 4=GHI, 5=JKL, 6=MNO, 7=PRS, 8=TUV, 9=WXY

#include <stdio.h>
#include <stdlib.h>

void print_alpha_to_num(char c) {
  // If the char isn't a capital letter that maps to a phone number/letter
  // key, then it drops through and simply prints the character
  switch (c) {
  case 'A':
  case 'B':
  case 'C':
    printf("2");
    break;

  case 'D':
  case 'E':
  case 'F':
    printf("3");
    break;

  case 'G':
  case 'H':
  case 'I':
    printf("4");
    break;

  case 'J':
  case 'K':
  case 'L':
    printf("5");
    break;

  case 'M':
  case 'N':
  case 'O':
    printf("6");
    break;

  case 'P':
  case 'R':
  case 'S':
    printf("7");
    break;

  case 'T':
  case 'U':
  case 'V':
    printf("8");
    break;

  case 'W':
  case 'Y':
  case 'X':
    printf("9");
    break;

  default:
    printf("%c", c);
  }
}

int main(int argc, char *argv[]) {

  int inputs[64], c;
  printf("Enter phone number: ");

  int i = 0;
  while ((c = getchar()) != '\n') {
    inputs[i] = c;
    i++;

    // Guard against entering a number that's too long
    if (i >= 63) {
      inputs[63] = 0;
      break;
    }
  }

  // Print the output
  for (int i = 0; i < 64; i++) {
    if (!inputs[i])
      break;
    print_alpha_to_num(inputs[i]);
  }

  printf("\n");

  return EXIT_SUCCESS;
}
