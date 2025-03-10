// Write a program fragment that declares an array named fib_numbers of
// length 40 and fills the array with the first 40 fibonacci numbers.
#include <stdio.h>
#include <stdlib.h>

#define LENGTH(a) ((int)(sizeof(a) / sizeof(a[0])))

int main(int argc, char *argv[]) {
  int fib_numbers[40] = {0, 1};

  for (int i = 2; i < LENGTH(fib_numbers); i++) {
    fib_numbers[i] = fib_numbers[i - 2] + fib_numbers[i - 1];
  }

  for (int i = 0; i < LENGTH(fib_numbers); i++) {
    printf("%d\n", fib_numbers[i]);
  }

  printf("\n");

  return EXIT_SUCCESS;
}
