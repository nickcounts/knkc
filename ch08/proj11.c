// Modify ch7 proj5 so the program output matches the following:
//    Enter Phone Number: 1-800-COL-LECT
//    In numeric form: 1-800-265-5328
//
// The program will need to store the phone number in an array until it can
// be printed. You can assume the phone number is no more than 15 characters
// long.
//
// Original Prompt:
// Write a program that translates an alphabetic phone number into numeric
// form. Assume all letters are capital. If the number includes punctuation
// (-,. etc) preserce it.
// 2=ABC, 3=DEF, 4=GHI, 5=JKL, 6=MNO, 7=PRS, 8=TUV, 9=WXY

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void print_alpha_to_num(char c) {
  // If the char isn't a capital letter that maps to a phone number/letter
  // key, then it drops through and simply prints the character

  c = toupper(c);

  if ('A' <= c && c <= 'C') {
    printf("2");
  } else if ('D' <= c && c <= 'F') {
    printf("3");
  } else if ('G' <= c && c <= 'I') {
    printf("4");
  } else if ('J' <= c && c <= 'L') {
    printf("5");
  } else if ('M' <= c && c <= 'O') {
    printf("6");
  } else if ('P' <= c && c <= 'S') {
    printf("7");
  } else if ('T' <= c && c <= 'V') {
    printf("8");
  } else if ('W' <= c && c <= 'Y') {
    printf("9");
  } else {
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

  printf("In numeric form: ");
  // Print the output
  for (int i = 0; i < 64; i++) {
    if (!inputs[i])
      break;
    print_alpha_to_num(inputs[i]);
  }

  printf("\n");

  return EXIT_SUCCESS;
}
