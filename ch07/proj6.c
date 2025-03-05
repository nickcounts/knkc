#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("sizeof(int) = %lu \n", sizeof(int));
  printf("sizeof(short) = %lu \n", sizeof(short));
  printf("sizeof(long) = %lu \n", sizeof(long));
  printf("sizeof(float) = %lu \n", sizeof(float));
  printf("sizeof(double) = %lu \n", sizeof(double));
  printf("sizeof(long double) = %lu \n", sizeof(long double));
  return EXIT_SUCCESS;
}
