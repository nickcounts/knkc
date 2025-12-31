// Modify the read_line function
#include <ctype.h>
int read_line_orig(char str[], int n);

#include <stdio.h>
#include <stdlib.h>

#define BUFF_LEN 80
#define DEBUG 0

int read_line_orig(char str[], int n){
  int ch, i = 0;

  while ((ch = getchar()) != '\n'){
    if (DEBUG) printf("%d : %c\n", i, ch);
    if (i < n)
      str[i++] = ch;
  }
  str[i] = '\0';            // Add null-terminator
  return i;                 // number of characters stored
}

// A) Have it skip whitespace before beginning to store input characters
int read_line_a(char str[], int n){
  int ch, i = 0;
  int skip_initial_ws = 1;

  fflush(stdin);
  while ((ch = getchar()) != '\n'){
    if (DEBUG) printf("%d : %c\n", i, ch);
    if (i < n){
      if (skip_initial_ws & !isspace(ch)){
        skip_initial_ws = 0;
        str[i++] = ch;
      } else if(skip_initial_ws & isspace(ch)){
      } else {
        str[i++] = ch;
      }
    }
  }
  str[i] = '\0';            // Add null-terminator
  return i;                 // number of characters stored
}


// B) Have it stop reading at the first white-space character
int read_line_b(char str[], int n){
  int ch, i = 0;

  fflush(stdin);
  while ((ch = getchar()) != '\n'){
    if (DEBUG) printf("%d : %c\n", i, ch);
    if (( i < n ) & !isspace(ch)){
        str[i++] = ch;
    } else {
      fflush(stdin);
      while ((ch = getchar()) != '\n' && ch != EOF) {
        if (DEBUG) printf("Whitespace detected, flush input and save\n");
        ;
      }
      break;
    }
  }
  str[i] = '\0';            // Add null-terminator
  return i;                 // number of characters stored
}

// C) Have it stop reading at the first new-line character and store \n in the string
// This function keeps the newline unless the buffer string is out of space, in which
// case it stores the null-terminator and omits the newline
int read_line_c(char str[], int n){
  int ch, i = 0;

  fflush(stdin);
  while ((ch = getchar()) != '\n'){
    if (DEBUG) printf("%d : %c\n", i, ch);
    if (i < n)
      str[i++] = ch;
  }
  if (i<n)
    str[i++] = '\n';        // Add new-line if enough room
  str[i] = '\0';            // Add null-terminator
  return i;                 // number of characters stored
}

// D) Have it leave behind characters that it doesn't have room to store
//
// I don't know what this means. If "Leave behind" means doesn't store, then
// they all do this. Does it mean print instead of store? I'm going to not
// do this one


int main(){
  char new_str[BUFF_LEN];
  int chars_read = 0;
  printf("Demo of read_line_orig()\n");
  chars_read = read_line_orig(new_str, BUFF_LEN);
  printf("read_line_orig() read %d chars: %s\n\n", chars_read, new_str);

  printf("Demo of read_line_a()\n");
  chars_read = read_line_a(new_str, BUFF_LEN);
  printf("read_line_a() read %d chars: %s\n\n", chars_read, new_str);

  printf("Demo of read_line_b()\n");
  chars_read = read_line_b(new_str, BUFF_LEN);
  printf("read_line_b() read %d chars: %s\n\n", chars_read, new_str);

  printf("Demo of read_line_c()\n");
  chars_read = read_line_c(new_str, BUFF_LEN);
  printf("read_line_c() read %d chars: %s\n\n", chars_read, new_str);


  return EXIT_SUCCESS;
}
