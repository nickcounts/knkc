// What will be the value of the string str after the following 
//  statements have been executed?

#include <string.h>
#include <stdio.h>

int main(){
  char str[80] = "";

  strcpy(str, "tire-bouchon");
  // str = [tire-bouchon00000000]
  strcpy(&str[4], "d-or-wi");
  // str = [tired-or-wi000000000]
  strcat(str, "red?");
  // str = [tired-or-wired?00000]

  // Am I right?
  puts(str);
  return 0;
}
