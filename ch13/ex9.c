// What will be the value of the string st1 after the following 
//  statements have been executed?

#include <string.h>
#include <stdio.h>

int main(){
  char s1[80] = "";
  char s2[80] = "";

  strcpy(s1, "computer");
  // s1 = [computer00000000]
  strcpy(s2, "science");
  // s2 = [science000000000]

  if (strcmp(s1, s2)<0){
    // s1 is "earlier" than "s2" so s1<s2
    strcat(s1, s2);
    // s1 = [computerscience0000]
  } else {
    strcat(s2, s1);
  }
  s1[strlen(s1)-6] = '\0';
  // s1 = [computerscience0000]
  // ind:  0123456789012345
  // len:  123456789012345
  //                *-----*
  // s1 = [computers0ience0000]
  //
  // Expect to print "computers"



  // Am I right?
  puts(s1);
  return 0;
}
