/* Chapter 13, Project 5
   Write a program named `sum.c` that adds up its command-line arguments, which
   are assumed to be integers. Running the program by typing:

   sum 8 24 62

   should produce the following output:

   Total: 94
 */

#include <stdio.h>
#include <stdlib.h>
#include "../ncb/ncb.h"

int main(int argc, char *argv[]){
  if (argc == 1){
    printf("Nothing to sum\n");
    return EXIT_SUCCESS;
  }

  int total = 0;
  for (int i = 1; i < argc; i++){
    int this_arg = int_from_str(argv[i]);

    if ((argv[i][0] < '0') || (argv[i][0] > '9')){
      // non-numeric characters, probably missed by int_from_str
      this_arg = -1;
    }

    if (this_arg<0){
      printf("Argument #%d was non-numeric\n", i);
      return EXIT_FAILURE;
    } 
    total += this_arg;
  }
  printf("Total: %d\n", total);

  return EXIT_SUCCESS;
}
