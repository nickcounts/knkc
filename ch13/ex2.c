// Which of the following function calls are legal? Show the poutput produced 
// by each call and explain why the others are illegal
#include <stdio.h>
#include <stdlib.h>

char *p = "abc";

int main(int argc, char *argv[])
{
  // putchar(p); // Expects a char/int argument, but gets a pointer. This won't compile
  putchar(*p); // This will print 'a' since the pointer points to the first char 
  puts(p); // This will print "abc" to the screen with a newline
  // puts(*p); // This will fail to compile: expects a pointer/string literal, gets a single char

  return EXIT_SUCCESS;
}
