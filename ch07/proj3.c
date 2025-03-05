// Sums a series of numbers usuing long-long valriables
// Originally sum2.c
// For Proj3.c in Chapter 7:
//     - Modify to sum a series of `double` values
#include <stdio.h>

int main(void) {
  double n, sum = 0.0;
  printf("This program sums a series of double precision numbers.\n");
  printf("Enter double float (0 to terminate): ");
  scanf("%lf", &n);
  while (n) {
    sum += n;
    scanf("%lf", &n);
  }
  printf("The sum is: %lf\n", sum);

  return 0;
}
