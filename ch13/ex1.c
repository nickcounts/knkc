// The following function calls supposedly write a single new-line character, 
// but some are incorrect. Identify which calls don't work and explain why.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // A)
  puts("A)");
  printf("%c", '\n');

  // B)
  // double-quoting the '\n' symbol makes a string literal containing the 
  // newline character. The format specifier calls for a char, so this will
  // trigger compiler warnings and possible errors. If it prints, it will 
  // print a newline, since the first char in the string literal is a 
  // newline.
  puts("B)");
  printf("%c", "\n");

  // C)
  // The format specifier is for a c-string and we are passing a char. This 
  // will likely fail
  // puts("C)");
  // printf("%s", '\n'); // This segfaults - char passed to string format string
  
  // D)
  // This will compile, but it will print a backslash and 'n' since we are 
  // passing a string literal
  puts("D)");
  printf("%s", "\n");
  
  // E)
  // I'm not sure what this will do - I think printf requires 2 arguments
  // If only one arg, then it assumes the format string and that must be a 
  // string literal or a char* array
  // printf('\n'); // Fails to compile - wrong arg type
  
  // F)
  // This will print a newline character
  puts("F)");
  printf("\n");
  
  // G)
  // This will print a newline character
  puts("G)");
  putchar('\n');
  
  // H)
  // This is an error - expects a char, is given a 3-element c-string 
  // putchar("\n");
  
  // I)
  // This will fail to compile: requires a string literal or char* array
  // puts('\n');
  
  // J)
  // This will print a newline from the string literal followed by a second
  // newline from puts()
  puts("J)");
  puts("\n");
  
  // K) 
  // This will print a single newline character from the puts() command
  puts("K)");
  puts("");

  return EXIT_SUCCESS;
}
