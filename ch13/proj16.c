/* Chapter 13, Project 16

   Modify Programming Project 1 from Chapter 12 so that it includes the
   following function:

   void reverse (char *message) ;

   The function reverses the string pointed to by `message`.

   > Hint: Use two pointers, one initially pointing to the first character
   of the string and the other initially pointing to the last character. Have
   the function reverse these characters and then move the pointers toward each
   other, repeating the process until the pointers meet.

 */

// Write a program that reads a message then prints the reversal of the message
// Read message one char at a time using getchar() and store the chars in an
// array. Stop reading when the array is full or the char read is '\n'

#include <stdio.h>

#define STR_BUFF_LEN 512
typedef char ntb_buff_str[STR_BUFF_LEN];

// reverses the order of the message string in place
void reverse (char *message) {
  char *p1, *p2;
  char temp;
  p1 = message;
  p2 = message;


  // Fast-forward to last character
  while( *p2 ){ 
    // printf("%p := ", p2);
    // printf("%c\n", *p2++);
    p2++;
  }
  p2--;

  while (p2 > p1){
    temp = *p1;
    *p1++ = *p2;
    *p2-- = temp;
  }
}

int main(){
  ntb_buff_str buffer = {0};
  char ch;
  int b_ind = 0;

  puts("Please enter a string to reverse:");
  while ((ch = getchar()) != '\n' ) {
    if (b_ind < STR_BUFF_LEN - 1 )
      buffer[b_ind++] = ch;
  }

  printf("Buffer contents:\n%s\n", buffer);

  // At the end of input, "thisChar" points at null terminator if used entire
  // buffer or the next empty spot in the array

  if (b_ind == 0){
    // still at the beginning of the buffer - the string is empty
    puts("Empty string was entered, nothing to do\n");
    return 1;
  }

  reverse(buffer);

  printf("%s\n", buffer);

  return 0;
}


