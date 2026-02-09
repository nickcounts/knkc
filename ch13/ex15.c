// Let f be the following function

#include <stdlib.h>
#include <stdio.h>

int f(char *s, char *t){
  char *p1, *p2;

  for (p1 = s; *p1; p1++){
    for (p2 = t; *p2; p2++)
      if (*p1 == *p2) break;
    if (*p2 == '\0') break;
  }
  return p1 - s;
}

int main(){
  puts("A) What is the value of f(\"abcd\", \"babc\") ?");
  puts("   Should be: 3");
  printf("          Is: %d\n\n", f("abcd", "babc"));

  puts("B) What is the value of f(\"abcd\", \"bcd\") ?");
  puts("   Should be: 0");
  printf("          Is: %d\n\n", f("abcd", "bcd"));

  puts("C) In general, what value does f return when passed two strings?");
  puts("   If all characters in s are found in t, returns 0");
  puts("   If a character in s is no found in t, returns the index to that char");
  
  return EXIT_SUCCESS;
}


