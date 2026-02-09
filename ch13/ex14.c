// What does the following program print?

#include <stdio.h>

int main(void){
  char s[] = "Hsjodi", *p;
  //          Grinch

  // p starts pointing to start of s (char arra)
  // loop if char pointed to by p is > 0
  // increment pointer
  for (p = s; *p; p++)
    // decrement the character at p
    --*p;
  // Will print "Grinch", which is each char - 1 (shifted)
  puts(s);
  return 0;
}
