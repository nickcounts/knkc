#include <stdio.h>

short unsigned int a;
// short float b;     // float can't be short
long double c;
unsigned long d;

int main(void) {
  printf("Legal types in C.\n");
  printf("short unsigned int\n");
  printf("short float        - INVALID\n");
  printf("long double\n");
  printf("unsigned long\n");
  return 0;
}
