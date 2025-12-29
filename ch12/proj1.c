// Write a program that reads a message then prints the reversal of the message
// Read message one char at a time using getchar() and store the chars in an
// array. Stop reading when the array is full or the char read is '\n'

#include <stdio.h>

#define BUFF_LEN 256 
// #define BUFF_LEN 8 
#define BUFF_LAST_EL_OFFSET  (BUFF_LEN - 1)

int main(){
  char buffer[BUFF_LEN];

  char ch;
  char* this_char = &buffer[0];
  *(this_char + BUFF_LAST_EL_OFFSET) = 0;

  fflush(stdin);
  while ((ch = getchar()) != '\n' ) {
    if (this_char - &buffer[0] >= BUFF_LAST_EL_OFFSET) break;
    *this_char++ = ch;
  }

  // printf("Buffer contents:\n%s\n", buffer);
  // printf("this_char points to element: %ld\n", this_char-&buffer[0]);
  // printf("*this_char = %c\n", *this_char);

  // At the end of input, "thisChar" points at null terminator if used entire
  // buffer or the next empty spot in the array

  if (this_char == &buffer[0]){
    // still at the beginning of the buffer - the string is empty
    puts("Empty string was entered, nothing to do\n");
    return 1;
  }

  this_char--; // Get the last character in the array
  while (this_char >= &buffer[0]){
    printf("%c", *this_char);
    this_char--;
  }
  printf("\n");

  return 0;
}


