/* Chapter 14, Exercise 5

   Let TOUPPER be the following macro:
   TOUPPER(c) ('a'<=(c)&&(c)<='z'?(x)-'a'+'A':(c))

   Let s be a string and let i be an int variable. 

   Show the output produced by each of the following program
   fragments:

   (a) 
      strcpy(s, "abcd");
      i = 0;
      putchar(TOUPPER(s[++i]));

   (b) 
      strcpy(s, "0123");
      i = 0;
      putchar(TOUPPER(s[++i]));
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

int main(int argc, char *argv[]) {
  int i;
  char s[128];


  // I believe that a) will output `B`
  strcpy(s, "abcd");
  printf("Part A)\n");
  printf("After strcpy: s = '%s'\n", s);

  i = 0;
  printf("++i evaluates as : %d\n", ++i);

  printf("i = 0; putchar(TOUPPER(s[1])) : ");
  putchar(TOUPPER(s[1]));
  printf("\n");

  i = 0;
  printf("i = 0; putchar(TOUPPER(s[++i])) : ");
  putchar(TOUPPER(s[++i]));
  printf("\n");

  printf("This counterintuitive result is caused by the text replacement\n");
  printf("evaluating ++i at each instance of the variable inside the macro:\n");
  printf("(++i) && (++i) ... (++i) ... (++1)\n");
  printf("( 1 ) && ( 2 ) ... ( 3 ) ... ( 4 )\n");

  printf("If index 1 and 2 are alphabetic, then returns modified 3\n");
  printf("otherwise returns original 4\n");
  


  // I believe that b) will output `1`
  // After completing part A, I now believe it will return s[4] = 3
  strcpy(s, "0123");
  i = 0;

  printf("\nPart B)\n");
  putchar(TOUPPER(s[++i]));
  printf("\n");




  return EXIT_SUCCESS;
}




