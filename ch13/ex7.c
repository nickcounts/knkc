// Suppose str is an array of characters. Which of the following
// statements is not equivalent to the other three?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

  char str[] = "This is a test string";

  // A - Puts null-terminator in first element
  *str = 0;
  
  // B - Puts null-terminator in first element
  str[0] = '\0';

  // C - Puts null-terminator in first element
  strcpy(str, "");

  // D - puts a null-terminator at the last populated element
  strcat(str, "");
  // ^^^^^^^^^^^^ This one



  char str0[] = "This is a test string";
  char stra[] = "This is a test string";
  char strb[] = "This is a test string";
  char strc[] = "This is a test string";
  char strd[] = "This is a test string";

  *stra = 0;
  strb[0] = '\0';
  strcpy(strc, "");
  strcat(strd, "");

  printf("  Original: %s\n", str0);
  printf("A produces: %s\n", stra);
  printf("B produces: %s\n", strb);
  printf("C produces: %s\n", strc);
  printf("D produces: %s\n", strd);

  return EXIT_SUCCESS;

}
