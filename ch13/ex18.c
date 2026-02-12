// Write the following function:

/* `url` points to a string containing a URL (Uniform Resource Locator) that
 * ends with a filename, such as "http://www.knking.com/index.html". The 
 * function should modify the string by removing the file name and the 
 * preceeding slash.
 */
#include <string.h>
void remove_filename(char *url);

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STR_BUFF_LEN 512
#define DEBUG_PRINT false

int main(int argc, char* argv[]) {

  char url[STR_BUFF_LEN];
  char default_url[STR_BUFF_LEN] = "http://www.knking.com/index.html";

  if (argc > 1){
    strcpy(url, argv[1]);
  } else {
    strcpy(url, default_url);
  }

  printf("Evaluating URL    : %s\n", url);
  remove_filename(url);
  printf("Extension removed : %s\n", url);

  return EXIT_SUCCESS;
}


void remove_filename(char *url){
  char *pu = url;
  if (DEBUG_PRINT) printf("url: %p\n pu: %p\n",url, pu);

  // "fast-forward" to end of string
  while (*pu)
    pu++;

  // Find the first `/` from the end (last `/`)
  while (pu >= url){
    if (*pu == '/'){
      *pu = 0;
      return;
    }

    if (DEBUG_PRINT){
      printf("%c != '/'\n", *pu);
      printf("%p\n", pu);
    }

    pu--;
  }

  // No / was found if you made it here
  return;

}
