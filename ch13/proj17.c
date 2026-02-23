/* Chapter 13, Project 17
 
   Modify Programming Project 2 from Chapter 12 so that it includes the following function:

   bool is_palindrome (const char *message) :

   The function returns true if the string pointed to by message is a palindrome.
 */



/* NOTE: I inadvertently did Proj 17 from a previous chapter again, with new
 * string functionality. Leaving it here as part of my journey
 */

#include <ctype.h>

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define STR_BUFF_LEN 512
typedef char ntb_buff_str[STR_BUFF_LEN];

bool case_sensitive = false;
bool skip_non_alphabetic = true;
bool DEBUG = false;



/*
   +-----------------------------------------------+
   |              Function Declarations            |
   +-----------------------------------------------+
 */

// Returns true if the string pointed to by `message` is a palindrome.
bool is_palindrome (const char *message);

// returns true if character is a-z or A-Z - English only
bool is_alphabetic(char c);


void usage(char *prog_name){
  printf("Usage %s [options]\n", prog_name);
  puts("--debug    Print all the comparison steps");
  puts("--help     Print this usage message");
  puts("--strict   Whitespace, punctuation, and capitalization count");
  exit(1);
}




int main(int argc, char *argv[])
{

  if (argc > 1){
    for (int i = 1; i<argc; i++){
      if (!strcmp(argv[i], "--debug")) DEBUG = true;
      if (!strcmp(argv[i], "--help")) usage(argv[0]);
      if (!strcmp(argv[i], "--strict")) {
        case_sensitive = true;
        skip_non_alphabetic = false;
      }

    }
  }


  ntb_buff_str buffer = {0};
  char ch;
  int b_ind = 0;

  puts("PALINDROME TESTER");
  puts("-------------------------------------------------------------");
  puts("Please enter a string to evaluate:");
  while ((ch = getchar()) != '\n' ) {
    if (b_ind < STR_BUFF_LEN - 1 )
      buffer[b_ind++] = ch;
  }

  printf("\nThe message %s a palindrome.\n", is_palindrome(buffer) ? "is" : "is NOT");

  return EXIT_SUCCESS;
}



bool is_palindrome(const char *message){
  const char *p1, *p2;
  p1 = message;
  p2 = message;

  if (DEBUG) printf("Testing message: %s\n", message);


  // Fast-forward to last character
  while( *p2 ){ 
    // printf("%p := ", p2);
    // printf("%c\n", *p2++);
    p2++;
  }
  p2--;

  if (DEBUG) printf("After fast-forward: *p1='%c' *p2='%c'\n", *p1, *p2);

  while (p2 > p1){
    if (DEBUG){
      printf("%c == %c  ([%ld] , [%ld])\n" , *p1, *p2, p1-message, p2-message);
    } 
    
    if (skip_non_alphabetic) {
      if (!is_alphabetic(*p1)){
        if (DEBUG) printf("Skipping *p1='%c'\n", *p1);
        if (DEBUG) puts("Incrementing p1");
        p1++;
        continue;
      }

      if (!is_alphabetic(*p2)){
        if (DEBUG) printf("Skipping *p2='%c'\n", *p2);
        if (DEBUG) puts("Incrementing p2");
        p2--;
        continue;
      }
    }

    if (case_sensitive){
      if (*p1++ != *p2--) return false;
    } else {
      if (tolower(*p1++) != tolower(*p2--)) return false;
    }
    
  }
  return true;
}


bool is_alphabetic(char c){
  if (('a' <= c && c <= 'z') ||('A' <= c && c <= 'Z')){
    if (DEBUG) printf("'%c' is alphabetic = true\n", c);
    return true;
  }
  if (DEBUG) printf("'%c' is alphabetic = false\n", c);
  return false;
}


