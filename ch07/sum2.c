// Sums a series of numbers usuing long-long valriables
#include <stdio.h>

int main(void) {
  long n, sum = 0;
  printf("This program sums a series of integers.\n");
  printf("Enter ingeter (0 to terminate): ");
  scanf("%ld", &n);
  while (n) {
    sum += n;
    scanf("%ld", &n);
  }
  printf("The sum is: %ld\n", sum);

  return 0;
}
