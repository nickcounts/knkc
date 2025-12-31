#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]){
  int i, j;
  char s[256];

  // suppose we call scanf as follows:
  printf("Enter some text to parse as %%d%%s%%d: \n");
  scanf("%d%s%d", &i, s, &j);

  // If the user enters: "12ab34 56def78" what will be the values of i, s, and j?
  //
  // %d will parse up to the first non-numeric characters: 12
  // %s will parse all up to the first whitespace        : ab34
  // %d will parse up to the next non-numeric characters : 56
  printf("First %%d = %d\n", i);
  printf("Next  %%s = %s\n", s);
  printf("Last  %%d = %d\n", j);

  return EXIT_SUCCESS;
}

