// Build the following function:

/* prepends http://www. and appends /index.html to a bare URL.
 * NO CHECKING is performed
 *
 * char* domain : a the bare URL string
 * char* index_url : a char array that will contain the new url string
 *
 */
void build_index_url(const char *domain, char *index_url);

// domain points to a string containing an Internet domain, such as "knking.com".
// The dunction should add "http://www." to the beginning of this string and 
// "/index.html" to the and of the string, storing the result in the string 
// pointed to by index_url. (In this example, the result will be 
// "http://www.knking.com/index.html")


#define URL_BUFF_LEN 256

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define HTTP "http://www."
#define INDEX "/index.html"

int main(int argc, char* argv[]) {

  char* base_url = malloc(sizeof(char) * URL_BUFF_LEN);
  char* index_url = malloc(sizeof(char) * URL_BUFF_LEN);

  if (argc > 1){
    strcpy(index_url, argv[1]);
  } else {
    strcpy(index_url, "knking.com");
  }

  build_index_url( index_url , base_url);
  printf("Formatted URL: %s\n", base_url);

  free(index_url);

  return EXIT_SUCCESS;
}


void build_index_url(const char *domain, char *index_url){
  int url_len = 0;
  char* url_head = HTTP;
  char* url_tail = INDEX;

  char * ip = index_url;
  while (*url_head){
    *ip++ = *url_head++;
    url_len++;
  }

  while (*domain) {
    if (url_len < URL_BUFF_LEN){
      *ip++ = *domain++;
      url_len++;
    }
  }

  while (*url_tail){
    if (url_len < URL_BUFF_LEN){
      *ip++ = *url_tail++;
      url_len++;
    }
  }

  index_url[URL_BUFF_LEN-1] = '\0';
}


