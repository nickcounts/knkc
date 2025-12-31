// Write a function named capitalize that capitalizes all letters in its 
// argument. The argument will be a null-terminated string containing 
// arbitrary characters, not just letters. Use array subscripting to access 
// the characters in the string. 
//
// HINT: Use the toupper() function to convert each character to upper case

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_LEN 256

// Convert all alphabetic characters to upper case in s. 
// S can only be BUFF_LEN long
void capitalize(char s[], int n){
  int i = 0;
  while (i < n & i < BUFF_LEN){
    s[i] = toupper(s[i]);
    i++;
  }
}

// Convert all alphabetic characters to upper case in s. 
// S can only be BUFF_LEN long
void capitalize_ptr(char s[], int n){
  char *p = &s[0];

  while (*p && (p-s) < n && (p-s) < BUFF_LEN){
    *p = toupper(*p);
    p++;
  }
}

int main(){
  char test_str[] = "this is a test";
  capitalize(test_str, 14);
  printf("Result a: %s\n", test_str);

  char test_str2[] = "this is another test";
  capitalize(test_str2, strlen(test_str2));
  printf("Result b: %s\n", test_str2);

  return EXIT_SUCCESS;
}
