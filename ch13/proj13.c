/* Chapter 13, Project 13

   Modify Programming Project 15 from Chapter 8 so that it includes the following function:

   void encrypt (char *message, int shift);

   The function expects message to point to a string containing the message to be encrypted;
   shift represents the amount by which each letter in the message is to be shifted.
 */

// Couldn't find old encrypt project, rewriting from scratch

#include <stdio.h>
#include <stdlib.h>

#define STR_BUFF_LEN 512
typedef char ntb_buff_str[STR_BUFF_LEN];


// Modify message in place. pointer to mutable *message string
void encrypt (char *message, int shift);


int main(int argc, char *argv[])
{
  ntb_buff_str message = {0}; 
  int offset = 0;

  int message_ind = 0;
  char this_char;

  printf("Enter a message up to %d characters long to be shifted:\n", STR_BUFF_LEN);
  while ((this_char = getchar()) != '\n' && message_ind < STR_BUFF_LEN){
    message[message_ind++] = this_char;
  }
  message[message_ind] = 0;

  printf("Enter the shift amount: \n");
  scanf("%d", &offset);
  
  printf("\nMessage with shift=%d applied:\n", offset);

  encrypt(message, offset);

  printf("%s\n", message);

  return EXIT_SUCCESS;
}


void encrypt (char *message, int shift){
  puts("In `encrypt` function");
  char * this_char = message;
  while ((this_char - message) < STR_BUFF_LEN){
    printf("%ld, ",this_char - message);
    if (*this_char){
      // Apply to all but null-terminator
      *this_char += shift;
    } else {
      puts("Found null-terminator");
      return;
    }
    this_char++;
  }
}

