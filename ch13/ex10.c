// Rewrite the example strcmp() to use pointers instead of indices

#include <stdio.h>

int k_strcmp(char *s, char* t){
  int i;

  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == 0)
      return 0;
  return s[i] - t[i];
}


int p_strcmp(char *s, char* t){
  while (*s == *t){
    if (*s == 0)
      return 0;
    s++;
    t++;
  }
  return *s-*t;
}

int main(){
  char s1[] = "test";
  char s2[] = "test1";
  printf("Result: %d\n", p_strcmp(s1, s2));
}
