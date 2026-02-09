// Use the techniques of Section 13.6 to condense the count_spaces function of
// Section 13.4. In particular, replace the for statement by a while loop

#include <stdio.h>
#include <stdlib.h>

int count_spaces_knk(const char *s){
  int count = 0;

  for (; *s != '\0'; s++)
    if (*s == ' ') count ++;;
  return count;
}

// Exercise 13.16 version of count_spaces.
// Converts `for` to `while` using string idioms in 13.6
int count_spaces_ex(const char *s){ 
  int count = 0;

  while (*s)
    if (*s++ == ' ') count ++;;
  return count;
}


int main(int argc, char* argv[]){
  char *default_str = "This is a test with six spaces";
  char *test_string;

  if (argc > 1){
    test_string = argv[1];
  } else {
    test_string = default_str;
  }

  printf("Evaluated string: %s\n", test_string);
  printf("Original returns: %d\n", count_spaces_knk(test_string));
  printf("    Mine returns: %d\n", count_spaces_ex(test_string));

  return EXIT_SUCCESS;
  
}
