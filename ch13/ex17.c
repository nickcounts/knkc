// Wrote the following function:

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* `file_name` points to a string containing a file name. The function should
 * return `true` if the file's extension matches the string pointed to by 
 * `extension`, ignoring the case of letters.
 *
 * Incorporate the `search for end of string` idiom and use `toupper` before comparison
 */
bool test_extension(const char *file_name, const char * extension);


int main(int argc, char* argv[]){
  char *default_filename = "test.ext";
  char *default_ext = "EXT";
  char *test_filename, *test_ext;

  if (argc > 2){
    test_filename = argv[1];
    test_ext = argv[2];

  } else {
    test_filename = default_filename;
    test_ext = default_ext;
  }

  printf("Evaluated filename  : %s\n", test_filename);
  printf("Evaluated extension : %s\n", test_ext);

  bool same_extension = test_extension(test_filename, test_ext);
  printf("Extensions match    : %s\n", same_extension ? "YES" : "NO");

  return EXIT_SUCCESS;
}

bool test_extension(const char *file_name, const char *extension){
  const char *pf = file_name;
  const char *pe = extension;

  // Move pointers to last character
  while (*pf) pf++; pf--;
  while (*pe) pe++; pe--;

  // Back up until either string is at the beginning
  while (pe >= extension && pf >= file_name){
    // printf("Testing %c == %c\n", *pf, *pe);
    if (toupper(*pe) != toupper(*pf)) 
      return false;
    pe--;
    pf--;
  }

  // printf("Last character of extension : %c\n", *pe);
  return true;
}
