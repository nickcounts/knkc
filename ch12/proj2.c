// Write a program that reads a message, then checks whether it's a palendrome
// or not.
//
// Examples ignore capitalization and punctuation.

#include <stdio.h>

#define BUFF_LEN 256 
// #define BUFF_LEN 8 
#define BUFF_LAST_EL_OFFSET  (BUFF_LEN - 1)
#define DEBUG 0

int main(){
  char buffer[BUFF_LEN];

  char ch;
  char* this_char = &buffer[0];
  *(this_char + BUFF_LAST_EL_OFFSET) = 0;

  printf("Enter a string up to %d characters long:\n", BUFF_LAST_EL_OFFSET);
  fflush(stdin);
  while ((ch = getchar()) != '\n' ) {
    if (this_char - &buffer[0] >= BUFF_LAST_EL_OFFSET) break;
    if (DEBUG) printf("This Char: %c\n", ch);

    if (ch >= 'A' && ch <= 'Z') {
      // Only add alphabetic characters, change to lower case
      *this_char++ = 'a' + (ch - 'A');
    } 
    else if (ch >= 'a' && ch <= 'z') {
      // Only add alphabetic characters
      *this_char++ = ch;
    } else {
      // this_char++;
    }
  }

  // At the end of input, "thisChar" points at null terminator if used entire
  // buffer or the next empty spot in the array

  if (this_char == &buffer[0]){
    // still at the beginning of the buffer - the string is empty
    puts("Empty string was entered, nothing to do\n");
    return 1;
  }

  if (DEBUG) printf("Stored char array: %s\n", buffer);

  this_char--; // Get the last character in the array
  char* fwd_char = &buffer[0];

  int is_palendrome = 1;

  while (this_char >= &buffer[0]){
    printf("%c", *this_char);
    if (*this_char != *fwd_char) {
      // mismatch! Not a palindrome!
      is_palendrome = 0;
      break;
    }
    this_char--;
    fwd_char++;
  }
  printf("\n");

  if (is_palendrome) {
    printf("Palendrome\n");
  } else {
    printf("Not Palindrome\n");
  }


  return 0;
}


