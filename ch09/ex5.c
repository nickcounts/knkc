// Ex. 5
// Write a function num_digits(n) that returns the number of digits in n
// (a positive integer)

#include <stdio.h>
#include <stdlib.h>

int num_digits(unsigned int n) {
  int d = 1;
  while (n /= 10) {
    d++;
  }
  return d;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Please enter a number as an argument: \n");
    printf("\tExample: %s 123\n", argv[0]);
    return EXIT_FAILURE;
  }
  int n;
  n = atoi(argv[1]);
  if (n < 0)
    n *= -1;
  printf("There are %d digits in %d\n", num_digits(n), n);
  return EXIT_SUCCESS;
}
