/* Chapter 13, Project 4
 
   Write a program named reverse.c that echoes its command-line arguments in
   reverse order. Running the program by typing: 

   reverse void and null 

   should produce the following output: 

   null and void
 */

#include "../ncb/ncb.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
  if (argc < 2){
    puts("No arguments");
    return EXIT_SUCCESS;
  }

  for (int i = argc-1; i > 0; i--) {
    printf("%s ", argv[i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
