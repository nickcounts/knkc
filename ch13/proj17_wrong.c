/* Chapter 13, Project 17

   Wite the following function:

   bool test_extension (const char *file_name, const char *extension) ;

   `file_name` points to a string containing a file name. The function should
   return true if the file's extension matches the string pointed to by
   `extension`, ignoring the case of letters. For example, the call 
   ```test_extension("memo. txt", "TXT");``` would return `true`. Incorporate
   the "search for the end of a string" idiom into your function. 
  
   > Hint: Use
 */


#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define EXT_BUFF_LEN 8
#define FILENAME_BUFF_LEN 256




// puts the file's extension into *extension
void get_extension(const char *file_name, char *extension) {
  const char *p_pos = file_name;
  const char *p_dot = file_name;
  const char *p_end = file_name;

  while (*p_pos && *p_pos != '.'){
    p_pos++;
  }
  
  if (*p_pos == 0){
    // End of string without '.' - no extension
    for (int epi = 0; epi < 3; epi++){
      *(extension + epi) = '\0';
    }
    return;
  }

  // Found the dot
  p_dot = p_pos;

  while (*p_pos){
    p_pos++;
  }
  p_end = p_pos;

  if (p_end == p_dot){
    // Dot was last character of filename, no extension
    for (int epi = 0; epi < 3; epi++){
      *(extension + epi) = '\0';
    }
    return;
  }

  p_dot++;

  while(p_dot < p_end){
    *extension++ = *p_dot++;
  }
  
  *extension = 0;
  
  return;
}



bool test_extension (const char *file_name, const char *extension) {
  int i = 0;
  char this_extension[EXT_BUFF_LEN];
  get_extension(file_name, this_extension);

  while ((this_extension[i] || extension[i]) && i < EXT_BUFF_LEN){
    printf("%2d : Testing %x == %x\n", i, this_extension[i], extension[i]);
    if (toupper(this_extension[i]) != toupper(extension[i])){
      printf("Returning false\n");
      return false;
    }
    i++;
  }
  printf("Returning true\n");
  return true;
}



int main(int argc, char* argv[]) {

  bool ext_matches = false;
  char* desired_extension = malloc(sizeof(char) * EXT_BUFF_LEN);
  char* filename = malloc(sizeof(char) * FILENAME_BUFF_LEN);

  if (argc > 1){
    strcpy(filename, argv[1]);
  } else {
    strcpy(filename, "memo.txt");
  }

  if (argc > 2){
    strcpy(desired_extension, argv[2]);
  } else {
    strcpy(desired_extension, "txt");
  }



  ext_matches = test_extension(filename, desired_extension);
  printf("ext_matches: %x\n", ext_matches);
  printf("File %s %s have extension: %s\n", filename, ext_matches ? "MATCHES" : "does NOT MATCH" ,desired_extension);

  return EXIT_SUCCESS;
}

