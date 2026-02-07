#include <string.h>
#define EXT_BUFF_LEN 8
#define FILENAME_BUFF_LEN 256
// Write the following function:

// `file_name` points to a string containing a file name. The function should 
// store the `extension` on the file name in the string poiunted to by 
// 'extension'. 
// For example, if the file name is "memo.txt" the function will store "txt" 
// in the string pointed to by `extension`. 
void get_extension(const char *file_name, char *extension);

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

  char* extension = malloc(sizeof(char) * EXT_BUFF_LEN);
  char* filename = malloc(sizeof(char) * FILENAME_BUFF_LEN);

  if (argc > 1){
    strcpy(filename, argv[1]);
  } else {
    strcpy(filename, "memo.txt");
  }

  get_extension(filename, extension);
  printf("Found extension: %s\n", extension);

  return EXIT_SUCCESS;
}

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
  
  return;
}

