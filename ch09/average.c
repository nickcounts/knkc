// Computes pairwise averages of three numbers

#include <stdio.h>
#include <stdlib.h>

double average(double a, double b) { return (a + b) / 2.0; }

int main(int argc, char *argv[]) {
  double x, y, z;
  printf("Enter three numbers: ");
  scanf("%lf %lf %lf", &x, &y, &z);
  printf("Average of %g and %g: %g\n", x, y, average(x, y));
  printf("Average of %g and %g: %g\n", y, z, average(y, z));
  printf("Average of %g and %g: %g\n", x, z, average(x, z));

  return EXIT_SUCCESS;
}
